#include <vector>
#include <algorithm>
#include <iostream>

struct Foo
{
    int money;
    int length;
    double  unit_price;

    bool operator<(const Foo& foo)
    {
        if (unit_price != foo.unit_price)
        {
            return unit_price < foo.unit_price;
        }
        return length > foo.length;
    }
};

std::vector<Foo> foo_vector;

int main()
{
    int money; 
    double unit_price;
    for (int i = 1; i < 11; ++i)
    {
        std::cin >> money;
        unit_price = money / (float)i;
        foo_vector.push_back({money, i, unit_price});
    }

    sort(foo_vector.begin(), foo_vector.end());

    int sum_length;
    int sum_cost = 0;
    std::cin >> sum_length;

    for (const Foo& foo : foo_vector)
    {
        if (foo.length > sum_length)
        {
            continue;
        }

        sum_cost += (sum_length / foo.length) * foo.money;
        sum_length = sum_length % foo.length;
    }

    printf("%d\n", sum_cost);

    return 0;
}
