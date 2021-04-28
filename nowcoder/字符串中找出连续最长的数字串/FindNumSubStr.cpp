/*************************************************************************************************************************
问题描述：读一个字符串str，输出字符串str中的连续最长的数字串

思路分析：用一个临时变量记录当前最长子串的长度（循环遍历str,找数字字符）。
		  1.当str[i]为数字字符时，记录开始位置。
		  2.使用end向后继续遍历，直到非数字字符结束，此时end指向该子串中，最后一个数字字符之后的位置
		  3.判断该子串的长度是否大于之前子串的长度，若大于，则更新最长子串和最长子串长度。
    
**************************************************************************************************************************/

#include<iostream>
#include<string>
using namespace std;

string FindNumSubStr(const string & str)
{
    int max=0;         //数字子串的长度
    int begin=0,end=0;
    string substr;
    //循环遍历str,找数字字符
    for(int i=0;i<str.size();++i)
    {
        //1.当str[i]为数字字符时，记录开始位置。
        if(str[i]>='0' && str[i]<='9')
        {
            begin=i;
            end=i;
        }
        
        //2.使用end向后继续遍历，直到非数字字符结束，此时end指向该子串中，最后一个数字字符之后的位置
        while(str[end]!='\0' && str[end]>='0' && str[end]<='9')
        {
            end++;
        }
        //3.判断该子串的长度是否大于之前子串的长度，若大于，则更新最长子串和最长子串长度。
        if((end-begin)>max)
        {
           substr = str.substr(begin,end-begin);
           max=end-begin;
           //此时可以更新i位置，避免重复遍历
           i=end;
           continue;
        }        
    }
    return substr;
}
int main()
{
    string str;
    cin>>str;
    
    cout<< FindNumSubStr(str)<<endl;
    return 0;
}