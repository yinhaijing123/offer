// 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数
OJ:https://leetcode-cn.com/problems/palindrome-number/submissions/


bool isPalindrome(int x){
    //若x为负数，则其一定不是回文数
    if(x<0)
        return false;
    long long y=0;
    int tmp=x;
    //1.翻转x得数值y
    while(tmp)
    {
        y=y*10+tmp%10;
        tmp/=10;
    }
    //2.比较x与翻转后的x：y是否相等？
    if(x==y)
        return true;
    else
        return false;
}