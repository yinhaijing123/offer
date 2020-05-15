/*****************************************************************************
问题描述：输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

思路分析：由于单链表只能从前向后遍历，故可使用栈来保存链表内元素，根据栈先进后出的特点，完成单链表的逆向打印功能。
（也可使用递归实现，但如果链表过长，递归调用层数太多，可能导致堆栈溢出）	  
*****************************************************************************/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
//思路：由于单链表只能从前向后遍历，故可使用栈来保存链表内元素，根据栈先进后出的特点，完成单链表的逆向打印功能。
//（法2：也可使用递归实现，但如果链表过长，递归调用层数太多，可能导致堆栈溢出）

vector<int> printListFromTailToHead1(ListNode* head) {
    if(head==NULL)
        return vector<int>();
    stack<int> s;
    ListNode* cur=head;
    while(cur!=NULL)
    {
        s.push(cur->val);
        cur=cur->next;
    }
    vector<int> ret;
    while(!s.empty())
    {
        ret.push_back(s.top());
        s.pop();
    }
    return ret;
}
vector<int> printListFromTailToHead2(struct ListNode* head) {
    vector<int> ret;
    if(head != NULL)
    {
        ret.insert(ret.begin(),head->val);
        if(head->next != NULL)
        {
            vector<int> tmp = printListFromTailToHead(head->next);
            if(tmp.size()>0)
                ret.insert(ret.begin(),tmp.begin(),tmp.end());  
        }         
    }
    return ret;
}
