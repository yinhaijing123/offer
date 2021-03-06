/*************************************************************************************************************************
问题描述：写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：
		  F(0) = 0,   F(1) = 1
		  F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
		  斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

		  答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
思路分析：
		  方法1：递归实现（开销太大）
		  方法2：循环实现。当n=0或n=1时，直接返回对应值即可。当n>=2时，则需进行累加计算。
		         假设计算第k个数的值，将第k-1个数的值赋值给pre2和第k-2个数的值赋值给pre1，将pre1和pre2求和取模(防止数据溢出)后赋给待返回数ret，再将第k-1个数赋值给pre2，将ret赋值给pre1，继续进行累加操作，直至累加n-1次后，返回ret即可。

**************************************************************************************************************************/

class Solution {
public:
    int fib1(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        return (fib(n-1)+fib(n-2))%1000000007;
    }

    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int pre2=0;
        int pre1=1;
        int ret=0;
        for(int i=1;i<n;i++)
        {

            ret=(pre1+pre2)%1000000007;
            pre2=pre1;
            pre1=ret;
        }
        return ret;
    }
};