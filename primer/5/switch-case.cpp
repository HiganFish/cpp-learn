#include <string>
#include <iostream>

int main()
{
    switch (true)
    {
        case true:
            {
            std::string v1;
            std::string v2 {};
            int v3 = 0;
            int v4;
            break;
            }
        case false:
            {
            std::cout << v1 << std::endl;
            std::cout << v2 << std::endl;
            std::cout << v3 << std::endl;
            std::cout << v4 << std::endl;
            break;
            }
    }

    return 0;
}
