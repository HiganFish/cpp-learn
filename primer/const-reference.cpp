#include <iostream>

class A
{
public:
    A()
    {

    }
    ~A()
    {

    }

    A(const A& a)
    {
        std::cout << "拷贝构造函数" << std::endl;
    }

    void operator=(const A& a)
    {
        std::cout << "复制运算符" << std::endl;
    }
};

void test1(A a)
{

}

void test2(const A& a)
{
    A a1 = a;

    std::cout << "--------------------" << std::endl;

    const A& a2 = a;
}

int main()
{
    A a;
    A b;

    a = b;
    std::cout << "--------------------" << std::endl;

    test1(a);

    std::cout << "-------------------" << std::endl;

    test2(a);


    return 0;
}
