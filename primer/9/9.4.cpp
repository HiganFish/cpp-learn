#include <vector>
#include <iostream>

bool Search(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int i)
{
    while (begin < end)
    {
        if (*begin == i)
        {
            return true;
        }
        begin++;
    }

    return false;
}

int main()
{

    std::vector<int> foo {1, 2, 3, 4, 5};

    std::cout << Search(foo.begin(), foo.end(), 3);
    return 0;
}
