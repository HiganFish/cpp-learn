#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    int listen_fd = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in listen_address{};
    listen_address.sin_family = AF_INET;
    listen_address.sin_port = htons(9123);

    int ret = bind(listen_fd, (struct sockaddr*)&listen_address,
            static_cast<socklen_t>(sizeof listen_address));
    if (ret == -1)
    {
        printf("%s\n", strerror(errno));
        exit(ret);
    }

    ret = listen(listen_fd, 5);

    struct sockaddr_in client_address{};
    socklen_t client_address_len = static_cast<socklen_t>(sizeof client_address);

    int client_fd = accept(listen_fd, (struct sockaddr*)&client_address,
            &client_address_len);

    sleep(5);

    char msg_first[20] = {"first message\n"};
    send(client_fd, msg_first, strlen(msg_first), 0);
    printf("first message send over\n");

    sleep(2);

    char msg_second[20] = {"second message\n"};
    send(client_fd, msg_second, strlen(msg_second), 0);

    return 0;
}
