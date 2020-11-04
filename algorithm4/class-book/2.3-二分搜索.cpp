#include <cstdio>

int Search(int* data, int length, int s)
{
    int begin = 0;
    int end = length - 1;

    while (begin <= end)
    {
        int mid = begin + (end - begin) / 2;

        if (s == data[mid])
        {
            return mid;
        }
        else if (s < data[mid])
        {
            end = mid - 1;
        }
        else if (s > data[mid])
        {
            begin = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int data[] = {4, 14, 24, 124, 124, 632, 1231, 1555, 2000, 2500, 10000};

    int length = sizeof(data) / sizeof(int);

    int s1 = 632;
    int s2 = 89;

    printf("s1-632: %d\n", Search(data, length, s1));
    printf("s2-89: %d\n", Search(data, length, s2));
    return 0;
}
