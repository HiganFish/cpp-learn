#include <iostream>
#include <map>
#include <array>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>

typedef std::array<int, 2> HL;
typedef std::vector<HL> Calculate;

int Solve1(int n, int* p)
{
    int m[n + 1][n + 1];
    int s[n + 1][n + 1];
    memset(m, 0, sizeof m);
    memset(s, 0, sizeof s);


	for (int r= 2; r <= n; r++)
	{  //r个矩阵连乘
		for (int i= 1; i<= n-r+1; i++)
		{
			int j= i+r-1;    //本轮循环的最后一个矩阵 
			m[i][j] = m[i][i]+m[i+1][j] + p[i-1] * p[i]* p[j];
			s[i][j] = i;      //假设最优划分位于i处；
			for(int k = i+1; k< j;k++)   //变化最优分割的位置，逐一测试
			{
				int t = m[i][k] + m[k+1][j] + p[i- 1] * p[k] * p[j]; 
				if ( t < m[i][j] )
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	} 

    return m[1][n];
}


int Solve(const Calculate& cal)
{
    int count = cal.size();
    int hls[count + 1];
    memset(hls, 0, sizeof hls);

    int i = 0;
	hls[0] = cal[0][0];
	int ll = cal[0][1];
	
    for (i = 1; i < count; ++i)
    {
        hls[i] = cal[i][0];
		if (ll != hls[i])
		{
			return -1;
		}
		ll = cal[i][1];
    }
    hls[i] = cal[i - 1][1];
	
    return Solve1(count, hls);
}

int main()
{
    int n;
    int m;
    std::cin >> n >> m;

    std::map<char, HL> input_map;

    char code;
    int h;
    int l;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> code >> h >> l;
        input_map[code] = {h, l};
    }


    std::vector<Calculate> calculates(m);
    std::string input;

    for (int i = 0; i < m; ++i)
    {
		std::cin >> input;
		for (int j = 0; j < input.length(); ++j)
		{
			calculates[i].push_back(input_map[input[j]]);
		}
    }

    for (int i = 0; i < m; ++i)
    {
		int result = Solve(calculates[i]);
        if (result == -1)
        {
            std::cout << "MengMengDa" << std::endl;
        }
        else
        {
            std::cout << result << std::endl;
        }
    }
    return 0;
}
