#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

int main()
{
    typedef std::vector<int> Vec;

    Vec vec;

    int temp = 0;
    while (std::cin >> temp)
    {
        vec.push_back(temp);
    }


    std::cin.clear();
    clearerr(stdin);
    std::cin >> temp;

    auto result = std::count(vec.cbegin(), vec.cend(), temp);

    std::cout << result << std::endl;

    return 0;
}
