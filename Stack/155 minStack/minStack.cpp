/*************************************************************************************************************************
问题描述：设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
		  push(x) —— 将元素 x 推入栈中。
		  pop() —— 删除栈顶的元素。
		  top() —— 获取栈顶元素。
		  getMin() —— 检索栈中的最小元素。

思路分析：在Minstack类中封装两个栈。其中一个是正常栈的操作，另外一个栈保存当前栈中最小值。
		  
**************************************************************************************************************************/

//最小栈的实现。
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
       
    }
    
    void push(int val) {
     s.push(val);
	 
	 
	 //当最小栈为空，或者插入的val<=最小栈栈顶元素时，向最小栈插入数据
     if(min.empty() || val<=min.top())
     {
         min.push(val);
     }
    }
    
    void pop() {
       int topval=s.top();
       s.pop();

	   //当弹出的元素为当前栈最小数据，则需要同时弹出min栈中的栈顶元素
       if(topval==min.top())
            min.pop();
       
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
private:
       stack<int> s;               //正常的栈
       stack<int> min;             //保存当前最小值的栈
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
