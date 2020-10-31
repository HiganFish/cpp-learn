#include <iostream>
#include <cmath>
#include <cstdio>

int n;
double data[50005][2];

double calc(double x)
{
    double result = 0.0f;
    double si;
    for (int i = 0; i < n; ++i)
    {
        si = fabs(data[i][0] - x);
        result += data[i][1] * si * si * si;
    }
    return result;
}

int main()
{
    int ca = 0;
    std::cin >> ca;

    for (int j = 1; j <= ca; j++)
    {
        std::cin >> n;

        double l = -1e6;
        double r = 1e6;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> data[i][0] >> data[i][1];
            if (data[i][0] < l)
            {
                l = data[i][0];
            }
            if (data[i][0] > r)
            {
                r = data[i][0];
            }
        }

        double mid;
        double mmid;
        while (l + 0.0000001 < r)
        {
            mid = l + (r - l) / 2.0;
            mmid = mid + (r - mid) / 2.0;
            if (calc(mid) > calc(mmid))
            {
                l = mid;
            }
            else
            {
                r = mmid;
            }
        }
        printf("Case #%d: %ld\n", j, static_cast<long long>(calc(r) + 0.5));
    }
    return 0;
}
