
//法一：先进行字符串单个字符的旋转，再进行n次操作。
//法二：将两个相同字符串拼接，再取该字符串的一部分
#include<iostream>
#include<string>

using namespace std;
string LeftRotateString(string str, int n)
{

    int length = str.size();
    if (length == 0)                       //进行判断字符串是否为空
    {
        return "";
    }

    n %= length;                            //防止n大于str的长度
    str += str;                             //拼接字符串
    return str.substr(n, length);           //通过str的成员函数substr()取子字符串
}

int main()
{
    string str;
    int n;
    while (getline(cin, str))               //多次测试
    {
        cin >> n;                       
        cout<<LeftRotateString(str, n);
    }

    system("pause");
    return 0;
}