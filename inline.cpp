#include <iostream>

inline int test()
{
    return 0;
}

int main()
{

    std::cout << 1;
    test();
    std::cout << 2;

    return 0;
}
