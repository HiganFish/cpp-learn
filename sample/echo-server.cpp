#include <sys/epoll.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdio>
#include <cassert>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("%s\n", "missing port");
    }

    int port = atoi(argv[1]);


    int epfd = epoll_create(5);


    struct sockaddr_in addr{};
    addr.sin_port = htonl(&port);
    addr.sin_family = AF_INET;


    int listenfd = socket(PF_INET, SOCK_STREAM, 0);

    int ret = bind(listenfd, (struct sockaddr*)&addr,
            static_cast<socklen_t>(sizeof addr));

    assert(ret >= 0);

    ret = epoll_ctl();
}
