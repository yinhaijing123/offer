/*************************************************************************************************************************
问题描述：请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

思路分析：空格只占一个字符，替换为%20占三个字符，故，每多一个空格，原字符串长度多2个字符。为避免每次替换空格都要将空格后面的字符移动带来的开销。
		  故，先统计字符串中空格字符的个数，自后向前替换空格即可。
**************************************************************************************************************************/

class Solution {
public:
    int CalSpace(string s)
    {
        if(s.size()==0)
        {
            return 0;
        }
        int space=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
                space++;
        }
        return space;
    }
    string replaceSpace(string s) {
        if(s.size()==0)
        {
            return s;
        }
        int length = s.size();
        int space=CalSpace(s);
        int totlelength=length+space*2;
		
        s.resize(totlelength);
		
        for(int i=length-1,j=totlelength-1;j>i;i--,j--)
        {
            if(s[i]==' ')
            {
                s[j--]='0';
                s[j--]='2';
                s[j]='%';
            }
            else
            {
                 s[j]=s[i];
            }
        }
        return s;
    }
};
