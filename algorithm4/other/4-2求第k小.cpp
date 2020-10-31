#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::priority_queue<int, std::vector<int>,
        std::greater<int>> heap;

    int temp;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> temp;
        heap.push(temp);
    }

    int result = 0;
    int k1 = 0;

    for (int i = 0; i < k - 1; ++i)
    {
        heap.pop();
    }

    std::cout << heap.top() << std::endl;

    return 0;
}
