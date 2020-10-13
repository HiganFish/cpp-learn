#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[])
{

    int sockfd = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr{};
    addr.sin_port = htons(13);
    addr.sin_family = AF_INET;

    int ret = bind(sockfd, (sockaddr*)&addr,
            static_cast<socklen_t>(sizeof addr));

    if (ret < 0)
    {
        exit(ret);
    }

    ret = listen(sockfd, 5);

    int clientfd = 0;
    char buffer[512]{};
    time_t ticks = 0;

    for (;;)
    {
        clientfd = accept(sockfd, nullptr, 0);

        ticks = time(nullptr);
        snprintf(buffer, sizeof buffer, "%0.24s\r\n", ctime(&ticks));

        send(clientfd, buffer, strlen(buffer), 0);
        close(clientfd);
    }

    return 0;
}
