#include <iostream>
#include <algorithm>
int main()
{
    int num;
    int mod;
    std::string result;
    while (std::cin >> num)
    {
        if (num == 0)
        {
            std::cout << 0 << std::endl;
            continue;
        }

        result.clear();
        while (num != 0)
        {
            mod = num % 8;
            num /= 8;
            result += mod + 48;
        }
        reverse(result.begin(), result.end());
        std::cout << result << std::endl;
    }
}
