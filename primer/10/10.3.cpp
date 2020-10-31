#include <vector>
#include <cstdio>
#include <numeric>

int main()
{

    std::vector<int> cost_money = {1, 2, 3, 4 ,5, 6};

    int sum_cost = std::accumulate(cost_money.cbegin(), cost_money.cend(), -1);

    printf("%d\n", sum_cost);

    return 0;
}
