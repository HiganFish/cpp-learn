#include <string>
#include <iostream>
#include <deque>
#include <list>

int main()
{
    std::list<std::string> list_string;

    std::string input;
    while (std::cin >> input)
    {
        list_string.push_back(input);
    }

    for (auto iter = list_string.cbegin();
            iter != list_string.cend(); ++iter)
    {
        std::cout << *iter << std::endl;
    }

    return 0;
}
