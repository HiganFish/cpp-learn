#include <iostream>

class Foo1
{};

class Foo2
{
    int a1;
    char a2;
};

class Foo3
{
    void Bar(){};
};

class Foo4Base
{
    virtual void Bar(){};
};

class Foo4 : public Foo4Base
{

};
int main()
{
    Foo1 foo1;
    Foo2 foo2;
    Foo3 foo3;
    Foo4 foo4;

    printf("Foo1: %ld, Foo2: %ld, Foo3: %ld, Foo4: %ld",
            sizeof foo1, sizeof foo2, sizeof foo3, sizeof foo4);
}
