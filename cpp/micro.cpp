#include <cstring>
#include <cstdio>

#define foo(r)\
printf("[%s:%d] %s\n", __func__, __LINE__, r);

int main()
{
    foo("???");
    return 0;
}
