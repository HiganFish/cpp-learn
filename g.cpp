#include <unistd.h>
#include <cstdio>
#include <string>
#include <cstring>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("wrong number of parameters.\n");
    }

    char* name = argv[1];
    *strrchr(name, '.') = '\0';

    char buffer[100];
    snprintf(buffer, sizeof buffer, "g++ -g -o g-%s %s.cpp",
            name, name);

    system(buffer);

    return 0;
}
