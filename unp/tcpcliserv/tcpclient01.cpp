#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <iostream>

int main(int argc, char* argv[])
{
    int connfd = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr{};

    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(8000);
    server_addr.sin_family = AF_INET;

    int ret = 0;
    ret = connect(connfd, (struct sockaddr*)&server_addr,
            static_cast<socklen_t>(sizeof server_addr));
    assert(ret != -1);

    char buffer[1024]{};

    while (std::cin >> buffer)
    {
        send(connfd, buffer, strlen(buffer), 0);
        recv(connfd, buffer, sizeof buffer, 0);

        printf("%s", buffer);
    }
    return 0;
}
