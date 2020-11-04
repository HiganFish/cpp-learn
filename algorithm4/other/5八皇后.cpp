#include <iostream>
#include <cstdio>

int data[8][8];



int main()
{
    int k = 0;
    
    std::cin >> k;

    while (--k > 0)
    {
        for (int h = 0; h < 8; ++h)
        {
            for (int l = 0; l < 8; ++l)
            {
                std::cin >> data[h][l];
            }
        }


    }
}
