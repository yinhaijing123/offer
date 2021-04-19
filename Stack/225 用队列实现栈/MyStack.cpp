/*************************************************************************************************************************
问题描述：请你仅使用两个队列实现一个后入先出（LIFO）的栈，
		  并支持普通队列的全部四种操作（push、top、pop 和 empty）。

思路分析：利用两个队列来实现栈，其中一个队列q1主要用于模拟栈，另一个队列q2主要临时保存要入栈的元素。
		  1.入栈。首先将要入栈元素插入队列q2中，再将q1中的所有元素出队再入队q2中，再将q2中的所有元素出队并入队到q1中，此时，q1中元素（类似逆置了）
		  此时操作q1即可。		  
**************************************************************************************************************************/

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    int topval;
    void push(int x) {
        q2.push(x);
        topval=x;
        while(!q1.empty())
        {
            int ele=q1.front();
            q2.push(ele);
            q1.pop();
        }

        while(!q2.empty())
        {
            int ele=q2.front();
            q1.push(ele);
            q2.pop();
        }  
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret=q1.front();
        q1.pop();
        topval=q1.front();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        //return topval;
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
    queue<int> q1;         //模拟栈
    queue<int> q2;         //保存临时入栈元素
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */