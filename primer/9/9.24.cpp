#include <vector>
#include <iostream>

int main()
{

    std::vector<int> vec;
    std::cout << vec.front();
    std::cout << *vec.begin();
    // vec.at(0);
    // vec[0];

    return 0;
}
