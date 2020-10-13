#include <cstdio>

class Book
{
public:
    virtual void PrintInfo()
    {
        printf("%s\n", "book");
    }
    virtual void PrintInfo1()
    {
        printf("%s\n", "book");
    }
};


class CppPrimer : public Book
{
public:


    int foo = 0x11111111;

    void PrintInfo() override
    {
        printf("%s\n", "cpp primer");
    }
    void PrintInfo1() override
    {
        printf("%s\n", "cpp primer");
    }

    int foo1 = 0x11111111;
};

int main()
{

    CppPrimer primer;

    printf("%ld\n", sizeof primer);

    return 0;
}
