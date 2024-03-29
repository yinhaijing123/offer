/*************************************************************************************************************************
问题描述：Fibonacci数列是这样定义的：
		  F[0] = 0
		  F[1] = 1
		  for each i ≥ 2: F[i] = F[i-1] + F[i-2]
		  因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, …，在Fibonacci数列中的数我们称为Fibonacci数。
		  给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
		  如：输入N ： 15，输出最小步数：2
			
思路分析：1. 从头开始计算斐波那契数，直到计算到的数值比n大时停止计算。
		  2. 比较恰好比n大的斐波那契数距离n的步数和恰好比n小的斐波那契数距离n的步数，取两者的较小值即为最少需要的步数。
**************************************************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

int Fib(int n)
{
    vector<int> F;
    F.push_back(0);
    F.push_back(1);
    int step = 0;
    int i = 2;
    //1. 从头开始计算斐波那契数，直到计算到的数值比n大时停止计算。
    while (n > F[F.size() - 1])
    {
        F.push_back(F[i - 1] + F[i-2]);
        i++;
    }
    //2. 比较恰好比n大的斐波那契数距离n的步数和恰好比n小的斐波那契数距离n的步数，取两者的较小值即为最少需要的步数。
    step = (F[F.size() - 1] - n) < (n - F[F.size() - 2]) ? (F[F.size() - 1] - n) : (n - F[F.size() - 2]);
    return step;
}

int main()
{
    int N;
    cin>>N;
    cout<<Fib(N)<<endl;
    return 0;
}