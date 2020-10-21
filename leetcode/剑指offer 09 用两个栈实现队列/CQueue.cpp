/*************************************************************************************************************************
问题描述：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

思路分析：
		入队操作：判断元素是否在入队栈内，如果不在，需将出队栈的元素均移至入队栈中，最后将元素插入入队栈
		出队操作：判断出队栈是否为空，如果为空，将入队栈中元素均移至出队栈中，再进行出队操作。
**************************************************************************************************************************/

class CQueue {
    
    stack<int> inqueue;         //入队栈
    stack<int> outqueue;        //出队栈
public:
    CQueue() {
        while(!inqueue.empty())
        {
            inqueue.pop();
        }
        while(!outqueue.empty())
        {
            outqueue.pop();
        }
    }
    
    //判断元素是否在入队栈内，如果在，直接入队，如果不在，将出队栈的元素均移至入队栈中，最后将元素插入入队栈。
    void appendTail(int value) {
        while(!outqueue.empty())
        {
            int t=outqueue.top();
            inqueue.push(t);
            outqueue.pop();
        }
        inqueue.push(value);
    }

    //判断出队栈是否为空，如果为空，将入队栈中元素均移至出队栈中，再进行出队操作。
    int deleteHead() {
        if(inqueue.empty()&&outqueue.empty())
        {
            return -1;
        }
        while(!inqueue.empty())
        {
            int t=inqueue.top();
            outqueue.push(t);
            inqueue.pop();
        }
        int ret=outqueue.top();
        outqueue.pop();
        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */