#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>

#define MAXLINE 1024

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("%s\n", "./x.out <serverip>");
        exit(1);
    }

    int sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("%s\n", "socket error");
    }

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(13);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0)
    {
        printf("%s\n", "inet_pton error");
    }

    if (connect(sockfd, (sockaddr*)&server_addr,
                static_cast<socklen_t>(sizeof server_addr)) < 0)
    {
        printf("%s\n", "connect error");
    }

    int n = 0;
    char recv_buffer[MAXLINE + 1]{};
    while ((n = read(sockfd, recv_buffer, MAXLINE)) > 0)
    {
        recv_buffer[n] = 0;

        if (fputs(recv_buffer, stdout) == EOF)
        {
            printf("%s\n", "fputs error");
        }
    }


    return 0;
}
