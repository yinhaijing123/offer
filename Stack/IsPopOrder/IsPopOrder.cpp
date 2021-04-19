/*************************************************************************************************************************
问题描述：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
		  假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
		  但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

思路分析：利用栈来模拟入栈出栈。
		  1.将入栈顺序表中元素挨个入栈。每入栈一个元素，和出栈顺序表的第j个元素进行比较。
		  2.当栈顶元素和出栈顺序表元素相等时，出栈栈顶元素，++j。
		  3.重复步骤2。
		  4.判断栈是否为空？如果栈为空，则返回真，否则，返回假
		  时间复杂度：O(n)
**************************************************************************************************************************/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;                  //利用栈来模拟入栈出栈
        for(int i=0,j=0;i<pushV.size();++i)
        { 
            s.push(pushV[i]);      //1234     1235
            while(!s.empty() && s.top()==popV[j])
            {
                s.pop();           //123
                ++j;
            }    
        }
        return s.empty();
    }
};