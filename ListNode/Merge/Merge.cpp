/****************************************************************************************
问题描述：输入两个单调递增的链表，输出两个链表合成后的链表（该链表满足单调不减规则）

思路分析：
		法一：粗暴式逆转（实现代码见下面）：
		  1.首先对参数合法性进行检查；
		  2.以一个链表作为基准链表，将另一个链表插入该链表，即:最终得到的基准链表就是所求链表
		  3.遍历链表。
			当基准链表的某节点值大于另一个链表节点值时，将小的节点从第二个链表上摘下来，并插入到基准链表的那个节点之前。
			直到遍历到某一个链表的尾部。
		  4.若是基准链表先走到了尾部。则：直接将另一个链表剩下的节点插到基准链表尾部即可。
		法二：可使用栈实现链表逆置。
****************************************************************************************/


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == NULL || pHead2 == NULL)
    {
        return pHead1 != NULL ? pHead1 : pHead2;
    }

    ListNode *cur = pHead1;

    while (cur->next != NULL && pHead2 != NULL)
    {
        if((cur->val)<=(pHead2->val))
        {
            cur = cur->next;
        }

        else
        {
            ListNode *to_insert = pHead2;
            ListNode *insert_pre = cur;
            cur = cur->next;
            pHead2 = pHead2->next;

            to_insert->next = cur;
            insert_pre->next = to_insert;
            swap(insert_pre->val, to_insert->val);
        }
    }

    if (cur->next == NULL)                                         //表示是基准链表先遍历结束
    {
        cur->next = pHead2;
        while((cur->val) > (pHead2->val)&&pHead2!=NULL)
        {
            swap(cur->val, pHead2->val);
            cur = cur->next;
            pHead2 = pHead2->next;
        }
    }
    return pHead1;
}