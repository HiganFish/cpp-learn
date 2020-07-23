#include <iostream>
#include <string>

int main()
{

    std::string replace_string;

    std::cin >> replace_string;

    decltype(replace_string.size()) string_sub = 0;
    while (string_sub < replace_string.size())
    {
        replace_string[string_sub++] = 'x';
    }

    std::cout << replace_string << std::endl;

    for (string_sub = 0; string_sub < replace_string.size(); ++string_sub)
    {
        replace_string[string_sub] = 'X';
    }

    std::cout << replace_string << std::endl;

    return 0;
}
