/*************************************************************************************************************************
问题描述：请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法。
		  要求不能走回头路，即：只能往右和往下走，不能往左和往上走
			
思路分析：使用动态规划
		  0.定义v[n+1][m+1]保存从坐标(0,0)走到坐标(i,j)有多少种走法；
		  1.假设到第i行第j列的方法有v[i][j]个，
		    则有：第一行和第一列均有一种方法，即v[0][j]=1,v[i][0]=1;
			而当i>0，j>0时，v[i][j]=v[i][j-1]+v[i-1][j];
		  2.v[n][m]即为从坐标(0,0)走到坐标(n,m)总共有多少走法
牛客链接：https://www.nowcoder.com/questionTerminal/e2a22f0305eb4f2f9846e7d644dba09b
**************************************************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

int CalWays(int n, int m)
{
    vector<vector<int>> v;
    v.resize(n+1);
    for (int i = 0; i <= n; ++i)
    {
        v[i].resize(m+1);
    }
    for (int i = 0; i <= n; ++i)
    {
        v[i][0] = 1;
    }
    for (int j = 0; j <= m; ++j)
    {
        v[0][j] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            v[i][j] = v[i][j - 1] + v[i - 1][j];
        }
    }
    return v[n ][m ];
}

int main()
{

    int n, m;
    while(cin >> n >> m)
        cout << CalWays(n, m) << endl;
    
    return 0;
}