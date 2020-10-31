#include <string>
#include <iostream>
#include <deque>
#include <list>

int main()
{
    std::deque<std::string> deque_string;

    std::string input;
    while (std::cin >> input)
    {
        deque_string.push_back(input);
    }

    for (std::deque<std::string>::const_iterator iter = deque_string.cbegin();
            iter != deque_string.cend(); ++iter)
    {
        std::cout << *iter << std::endl;
    }

    return 0;
}
