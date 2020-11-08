#include <netinet/in.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <sys/select.h>
#include <sys/socket.h>
#include <cassert>

constexpr int MAX_CLIENT = 2;
constexpr int DEFAULT_FD = -1;
constexpr char FULL_CLIENT[] = "too many clients\n";
constexpr int READ_BUFFER_SIZE = 1024;

int main(int argc, char* argv[])
{
    int listenport = 4000;
    int opt;
    while ((opt = getopt(argc, argv, "p:")) != -1)
    {
        switch (opt)
        {
            case 'p':
                listenport = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s [-p port]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    printf("listenport: %d\n", listenport);

    struct sockaddr_in listenaddr{};
    listenaddr.sin_family = AF_INET;
    listenaddr.sin_port = htons(listenport);

    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    int on = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEPORT, &on, sizeof on);


    int ret = bind(listenfd, (sockaddr*)&listenaddr, sizeof listenaddr);
    assert(ret != -1);

    ret = listen(listenfd, 5);


    int clientfds[MAX_CLIENT];

    for (int i = 0; i < MAX_CLIENT; ++i)
    {
        clientfds[i] = DEFAULT_FD;
    }

    fd_set read_sets;
    int max_fd = listenfd;
    int client_sub = -1;
    FD_ZERO(&read_sets);

    FD_SET(listenfd, &read_sets);

    char buffer[READ_BUFFER_SIZE];

    for(;;)
    {
        int select_result = select(max_fd + 1, &read_sets, nullptr, nullptr, nullptr);

        if (FD_ISSET(listenfd, &read_sets))
        {
            int connfd = accept(listenfd, nullptr, nullptr);

            if (client_sub >= MAX_CLIENT - 1)
            {
                send(connfd, FULL_CLIENT, sizeof FULL_CLIENT, 0);
                close(connfd);
            }
            else
            {
                int i;
                for (i = 0; i < MAX_CLIENT; ++i)
                {
                    if (clientfds[i] == DEFAULT_FD)
                    {
                        clientfds[i] = connfd;
                        break;
                    }
                }

                max_fd = connfd > max_fd ? connfd : max_fd;
                client_sub = client_sub > i ? client_sub : i;

                FD_SET(connfd, &read_sets);

                if (--select_result <= 0)
                {
                    continue;
                }
            }
        }


        for (int i = 0; i <= client_sub; ++i)
        {
            int clientfd = clientfds[client_sub];
            if (clientfd == DEFAULT_FD)
            {
                continue;
            }

            if (FD_ISSET(clientfd, &read_sets))
            {
                ssize_t read_size = 0;
                if ((read_size = read(clientfd, buffer, READ_BUFFER_SIZE)) == 0)
				{
                	close(clientfd);
                	clientfds[client_sub] = DEFAULT_FD;
                	FD_CLR(clientfd, &read_sets);
				}
                write(clientfd, buffer, read_size);

                if (--select_result <= 0)
				{
					break;
				}
            }
        }
    }

    return 0;
}
