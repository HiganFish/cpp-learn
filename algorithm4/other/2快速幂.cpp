#include <iostream>

int Pow(int i, int j)
{
    long long result = 1;
    for (int s = 1; s <= j; ++s)
    {
        result *= i;
    }
    return result % 100000007;
}

int main()
{
    long long cache[26000]{1};

    int max_x = 0;
    int input;
    long long  result = 0;
    while (std::cin >> input)
    {
        if (input <= max_x)
        {
            result = cache[input];
        }
        else
        {
            for (int i = max_x + 1; i <= input; ++i)
            {
                cache[i] = (cache[i - 1] + Pow(i, i)) % 100000007;
            }
            max_x = input;
            result = cache[input];
        }

        std::cout << result << std::endl;
    }

    return 0;
}
