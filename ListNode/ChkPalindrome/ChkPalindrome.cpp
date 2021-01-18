
/*******************************************************************************************************************************************
问题描述：对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
		  给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。

		  测试样例：1->2->2->1
		  返回：true
思路分析：
          法1：分割链表。1.将链表分为两部分（中间节点之前+中间节点之后）；2.逆转后半部分链表；3.遍历两链表比较。时间复杂度O(n);空间复杂度O(1)
		  法2:重新创建一个新链表。保存逆置后的链表内容；然后遍历比较原链表和逆置后的链表。
*******************************************************************************************************************************************/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

/*法1：分割链表。1.将链表分为两部分（中间节点之前+中间节点之后）；2.逆转后半部分链表；3.遍历两链表比较。时间复杂度O(n);空间复杂度O(1)
  法2:重新创建一个新链表。保存逆置后的链表内容；然后遍历比较原链表和逆置后的链表。*/

class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        if(A==NULL)
            return false;
        if(A->next==NULL)
            return true;
        ListNode *slow=A;
        ListNode *quick=A;
        
        //1.找中间节点
        while(quick && quick->next)
        {
            slow=slow->next;
            quick=quick->next->next;
        }
        
        ListNode *next=slow->next;
        ListNode *prev=NULL;
        //2.逆置后半部分
        while(slow)
        {
            slow->next=prev;
            prev=slow;
            slow=next;
            if(next!=NULL)
                next=next->next;
        }
        
        //3.遍历比较两链表
        ListNode* list=A;
        ListNode* newlist=prev;
        while(newlist && list)
        {
            if(newlist->val == list->val)
            {
                newlist=newlist->next;
                list=list->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};