
/**********************************************************************************
问题描述：删除链表中倒数第n个节点

思路分析：1.参数判断；
          2.快慢指针查找倒数第n个节点；
          3.删除第n个节点，并返回头节点。
**********************************************************************************/

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head == NULL)
    {
        return NULL;
    }

    ListNode *quick = head;
    ListNode *slow = head;
    while (n != 0)
    {
        quick = quick->next;
        --n;
    }

    if (n == 0)
    {
        if (quick == NULL)
        {
            head = head->next;
            delete slow;
            return head;
        }

        while (quick->next != NULL)
        {
            quick = quick->next;
            slow = slow->next;
        }
        ListNode *to_delete = slow->next;
        slow->next = to_delete->next;
        delete to_delete;
        return head;
    }
    return NULL;
}