
/*******************************************************************************************************************************************
问题描述：输入两个链表，输出他们的第一个公共节点

思路分析：
        法一：遍历比较(遍历一个链表，用该链表的每个节点与另一个链表的进行比较，第一次相同的节点即为所求节点) 时间复杂度O(nm)
        法二：使用栈实现(分别将两个链表节点进行压栈，再同时进行出栈操作，最后一个相同的节点，即为所求节点)   时间复杂度O(n+m),空间复杂度O(n)
        法三：利用快慢指针进行比较。时间复杂度O(n+m),空间复杂度O(1)
*******************************************************************************************************************************************/

#include<iostream>

using namespace std;

struct ListNode 
{
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {
    }
};

class Solution 
{
public:
    ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) 
    {
        int Length1 = ListLength(pHead1);
        int Length2 = ListLength(pHead2);

        ListNode *quick = pHead1;
        ListNode *slow = pHead2;
        int k = Length1 - Length2;

        if (Length1 < Length2)
        {
            quick = pHead2;
            slow = pHead1;
            k *= -1;
        }
        
        while (k != 0 )                           //快指针先走k步
        {
            quick = quick->next;
            k--;
        }

        while (quick != NULL && slow != NULL && quick != slow)
        {
            quick = quick->next;
            slow = slow->next;
        }
		return quick;
    }

    int ListLength(ListNode * pHead)
    {
        int Length = 0;
        while (pHead != NULL)
        {
            Length++;
            pHead = pHead->next;
        }
        return Length;
    }
};