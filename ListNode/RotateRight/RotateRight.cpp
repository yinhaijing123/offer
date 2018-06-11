/*******************************************************************************************
问题描述：右旋K次链表

思路分析：1.找到倒数第K个节点(快慢指针)
          2.将链表分为两部分，一个为倒数K个节点，另一个为原始头部
          3.让原始链表的尾节点指向NULL；再将倒数的K个链表的尾节点指向原始的链表头部
*******************************************************************************************/
#include<iostream>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) 
        : val(x), next(NULL) 
    {}
};

ListNode *rotateRight(ListNode *head, int k) 
{
    if (head == NULL||head->next == NULL||k<=0)
    {
        return head;
    }
    ListNode *quick = head;
    ListNode *slow = head;

    int size = 0;
    while (quick != NULL)
    {
        size++;
        quick = quick->next;
    }
    
    int i = k % size;                  //防止k大于链表长度
    quick = head;

    if (i == 0)
    {
        return head;
    }

    while ( i!=0)
    {
        quick = quick->next;
        i--;
    }

    while (quick->next != NULL)
    {
        quick = quick->next;
        slow = slow->next;
    }
    //此时slow->next为倒数第k个节点，quick->next为尾部NULL。
    ListNode *new_head = slow->next;
    slow->next = NULL;
    quick->next = head;
    head = new_head;
    return head;
}