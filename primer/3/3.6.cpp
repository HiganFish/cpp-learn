#include <iostream>
#include <string>

int main()
{

    std::string replace_string;

    std::cin >> replace_string;

    for (char& c : replace_string)
    {
        c = 'X';
    }

    std::cout << replace_string << std::endl;

    return 0;
}
