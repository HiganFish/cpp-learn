#include <cstdio>

int main()
{
    union
    {
        short s;
        char c[sizeof(short)];
    } un;

    un.s = 0x0102;


    //printf("%s: ", CPU_VENDOR_OS);

    if (un.c[0] == 2)
    {
        printf("little-end\n");
    }
    else if (un.c[0] == 1)
    {
        printf("big-end\n");
    }
    else
    {
        printf("unknow\n");
    }

    return 0;
}
