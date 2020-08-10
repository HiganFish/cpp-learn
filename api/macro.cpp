#include <cstdio>


#define FOO()\
{\
    const char* file = __FILE__;\
    int line = __LINE__;\
    const char* func = __FUNCTION__;\
    printf("%s\n%d\n%s\n", file, line, func);\
}

int main()
{
    FOO();

    return 0;
}
