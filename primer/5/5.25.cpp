#include <iostream>
#include <stdexcept>

int main()
{
    int add_a = 0, add_b = 0;

    std::cin >> add_a >> add_b;

    try
    {
        if (add_b == 0)
        {
            throw std::runtime_error("divide zero");
        }
        std::cout << add_a / add_b << std::endl;
    }
    catch (std::runtime_error error)
    {
        std::cout << error.what();
    }
    return 0;
}
