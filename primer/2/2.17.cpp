#include <iostream>
#include <vector>

int main()
{
    int i, &ri = i;
    i = 5;
    ri = 10;

    std::cout << i << " " << ri <<std::endl;

    std::vector<int> int_vector(10);
    std::cout << int_vector.size() << std::endl;
    return 0;
}
