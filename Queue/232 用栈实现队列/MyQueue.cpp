/*************************************************************************************************************************
问题描述：请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

思路分析：利用两个栈来实现队列。
		  其中，一个栈用于入队in，一个栈用于出队out。
		  1. 入队：入队之前，先将出队栈中的元素入栈到入队栈中，然后再入队新元素
		  2. 出队：出队之前，先将入队元素全部移到出队队列中，再出队对头元素。
		  3. 取对头元素：先将入队元素全部移到出队队列中，再返回队头元素的值。
		  4. 判空：入队栈和出队栈同为空则说明该队列为空。		  		  
**************************************************************************************************************************/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!out.empty())
        {
            int t=out.top();
            out.pop();
            in.push(t);
        }
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!in.empty())
        {
            int t=in.top();
            in.pop();
            out.push(t);
        }
        int ret = out.top();
        out.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        while(!in.empty())
        {
            int t=in.top();
            in.pop();
            out.push(t);
        }
        return out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty() &&out.empty();
    }
    stack<int> in;         //用于入队
    stack<int> out;        //用于出队
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */