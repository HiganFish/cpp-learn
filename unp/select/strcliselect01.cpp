#include <sys/socket.h>
#include <algorithm>
#include <cstdio>
#include <unistd.h>

constexpr int BUFFER_SIZE = 1024;

void StrClient(FILE* fp, int sockfd)
{
    fd_set rsets;
    int fpfd = fileno(fp);

    char sendbuffer[BUFFER_SIZE];
    char recvbuffer[BUFFER_SIZE];

    FD_ZERO(&rsets);

    for (;;)
    {
        FD_SET(fpfd, &rsets);
        FD_SET(sockfd, &rsets);

        int maxfdp = 1 + std::max(fpfd, sockfd);

        int ret = select(maxfdp, &rsets, nullptr, nullptr, nullptr);

        if (FD_ISSET(fpfd, &rsets))
        {
            for(;;)
            {
                ssize_t read_size = read(fpfd, sendbuffer, sizeof sendbuffer);
                if (read_size == 0)
                {
                    return;
                }
                write(sockfd, sendbuffer, read_size);
            }
        }

        if (FD_ISSET(sockfd, &rsets))
        {
            ssize_t read_size = read(sockfd, recvbuffer, sizeof recvbuffer);
            if (read_size <= 0)
            {
                printf("sockfd read error");
            }
            fputs(recvbuffer, stdout);
        }
    }
}

int main()
{
    return 0;
}
