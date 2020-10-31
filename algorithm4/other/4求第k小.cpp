#include <iostream>
#include <cstdio>

int data[1000010];
int n;

int main()
{
    int k;
    scanf("%d%d", &n, &k);
    k--;

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &data[i]);
    }

    int begin = 0;
    int end = n - 1;

    int i = 0;
    int j = end;

    int div = 0;

    int result = 0;
    while (true)
    {
        begin = i;
        end = j;

        int temp = data[i];

        while (i < j && data[j] >= temp)
        {
            j--;
        }
        data[i] = data[j];

        while (i < j && data[i] <= temp)
        {
            i++;
        }
        data[j] = data[i];

        data[i] = temp;

        if (i == k)
        {
            result = data[i];
            break;
        }
        else if (i > k)
        {
            i = begin;
            j--;
        }
        else
        {
            j = end;
            i++;
        }
    }

    printf("%d\n", result);

    return 0;
}
