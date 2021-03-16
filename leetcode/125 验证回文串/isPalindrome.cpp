/*************************************************************************************************************************
问题描述：给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

思路分析：分别从前和从后遍历字符串。找到字符/数字字符比较。
		  注意：字母不区分大小写
**************************************************************************************************************************/

#include<iostream>
#include<string>
using namespace std;

bool isIntChar(const char& ch)
{
    return (ch >= '0' && ch <= '9');
}
bool isChar(const char& ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}
bool isCharorInt(const char& ch)
{
    return (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}
bool isPalindrome(string s) {
    int begin = 0;
    int end = s.size() - 1;
    while (begin < end)
    {
        //从头向后找第一个为字母/数字字符
        // while(begin<end && !isCharorInt(s[begin]))
        while (begin < end && !isIntChar(s[begin]) && !isChar(s[begin]))
            ++begin;
        //从后向前找第一个为字母/数字字符
        // while(begin<end && !isCharorInt(s[end]))
        while (begin < end && !isIntChar(s[end]) && !isChar(s[end]))
            --end;
        if (s[begin] != s[end])
        {
            //不相等再判断是否均为字母，若为字母相差32，则继续；相差不为32则直接返回false
            if (isIntChar(s[begin]) || isIntChar(s[end]))
                return false;
            else if (abs(s[begin] - s[end]) != 32)  //isChar(s[begin])&&isChar(s[end])&&
                return false;
        }

        begin++;
        end--;
    }
    return true;
}

int main()
{
    string str;
    getline(cin, str);
    cout<<isPalindrome(str);

    system("pause");
    return 0;
}