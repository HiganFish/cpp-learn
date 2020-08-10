#include <cstdarg>
#include <cstdio>

void Print(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

int Sum(int count, ...)
{
    int result = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i)
    {
        result += va_arg(args, int);
    }
    va_end(args);

    return result;
}

int main(int argc, char* argv[])
{
    Print("sum is: %d", Sum(4, 1, 2, 3, 4));

    return 0;
}
