/*****************************************************************************
问题描述：输入一个链表，反转链表后，输出链表的所有元素

思路分析：首先将此问题可分为两种情况：
		  1.空链表/只有一个节点的链表，直接返回其头节点即可。即：不需要进行翻转		  
		  2.多个节点的链表，可定义三个指针，进行逆置操作。	  
*****************************************************************************/


struct ListNode 
{
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* ReverseList(ListNode* pHead) 
{
    if (pHead == NULL || pHead->next == NULL)             //1.空链表或者一个节点的链表。
    {
        return pHead;
    }

    ListNode *cur = pHead;
    ListNode *p = NULL;
    ListNode *n = cur->next;

    while (cur->next != NULL)
    {
        
        cur->next = p;
        p = cur;
        cur = n;
        n = n->next;
    }
    cur->next = p;                                        //勿忘将最后一个节点也链接起来。
    pHead = cur;
    return pHead;
}