#include <vector>
#include <cstdio>

int main()
{

    std::vector<int> vec{1, 2, 3};

    auto begin = vec.begin();
    while (begin != vec.end())
    {
        ++begin;
        //begin = vec.insert(begin, 42);
        vec.insert(begin, 42);
        ++begin;
    }


    for (const int& i : vec)
    {
        printf("%d ", i);
    }

    return 0;
}
