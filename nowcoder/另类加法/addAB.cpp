/*************************************************************************************************************************
问题描述：给定两个int A和B。编写一个函数返回A+B的值，但不得使用+或其他算数运算符。
		  测试样例：1,2；返回：3
			
思路分析：1 ^1=0 1 ^0=1 0 ^0=0(这是异或) 1 +1=0 1+0=1 0+0=0（这是加）,然后你就会发现这两种结果一致；
	      而&运算和‘进位’结果一致，我们知道A ^B是不考虑进位的‘加’，（A &B）<<1 即是进位结果。
	      因此A ^B+(A&B)<<1的结果就是A+B的结果，只要进位结果为0，即（A&B）<<1=0,则就完成了加法！。 
		  如：A：1=001、 B：3=011 ；则A+B=4=（001^011）本位之和 +（001&011）<<1进位
牛客链接：https://www.nowcoder.com/practice/e7e0d226f1e84ba7ab8b28efc6e1aebc?tpId=8&tqId=11065&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fcracking-the-coding-interview%2Fquestion-ranking&tab=answerKey
**************************************************************************************************************************/

class UnusualAdd {
public:   
    int addAB(int A, int B) {
        // write code here
        while(A)             //假设A为进位
        {
            int val=A^B;
            A=(A&B)<<1;
            B=val;
        }
        return B;
    }
};