#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <cassert>


int main()
{
    int listenfd = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in listen_addr{};

    listen_addr.sin_port = htons(8000);
    listen_addr.sin_family = AF_INET;

    int ret = bind(listenfd, (struct sockaddr*)&listen_addr,
            static_cast<socklen_t>(sizeof listen_addr));
    assert(ret != -1);

    listen(listenfd, 5);

    int newfd = -1;

    for (;;)
    {
        newfd = accept(listenfd, nullptr, nullptr);

        if (fork() == 0)
        {
            close(listenfd);

            char buffer[1024];
            ssize_t recv_len = 0;

            while ((recv_len = recv(newfd, buffer, sizeof buffer, 0)) != 0)
            {
                send(newfd, buffer, recv_len, 0);
            }

            close(newfd);
        }

        close(newfd);
    }

    return 0;
}
