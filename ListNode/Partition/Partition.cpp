
/******************************************************************************************
问题描述：Partitioning a linked list around a given value and keeping the original order
          有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
Example：
          Input : 1->4->3->2->5->2->3, x = 3
          Output: 1->2->2->4->3->5->3

思路分析：1.首先定义两个链表，分别存储大于或等于value值，和小于value值的节点
          2.遍历链表进行分离
          3.将两个链表进行组合
******************************************************************************************/
#include<iostream>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) 
        : val(x)
        , next(NULL) 
    {}
};

//版本二：以空间换时间，提高效率。将两条链表设定为带头节点的单链表，省去了再度判断两链表的条件。
ListNode *partition(ListNode *head, int x) 
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *less = new ListNode(0);
    ListNode *less_tail = less;
    ListNode *more_or_equal = new ListNode(0);
    ListNode *more_or_equal_tail = more_or_equal;

    while (head != NULL)
    {
        if (head->val < x)
        {
            less_tail->next = head;
            less_tail = less_tail->next;
        }

        else
        {
            more_or_equal_tail->next = head;
            more_or_equal_tail = more_or_equal_tail->next;
        }

        head = head->next;
    }
    more_or_equal_tail->next = NULL;                                 //此句切记加上
    less_tail->next = more_or_equal->next;
    head = less->next;
    return head;
}

//版本一：判断条件过多，可优化。
//ListNode *partition(ListNode *head, int x)
//{
//    ListNode *less = NULL;
//    ListNode *less_tail = NULL;
//    ListNode *more = NULL;
//    ListNode *more_tail = NULL;
//
//    ListNode *cur = head;
//    while (cur != NULL)
//    {
//        ListNode *insert = cur;
//        cur = cur->next;
//        insert->next = NULL;
//
//        if (insert->val < x)
//        {
//            if (less == NULL)
//            {
//                less = less_tail = insert;
//                continue;
//            }
//            less_tail->next = insert;
//            less_tail = insert;
//        }
//
//        else
//        {
//            if (more == NULL)
//            {
//                more = more_tail = insert;
//                continue;
//            }
//            more_tail->next = insert;
//            more_tail = insert;
//        }
//    }
//
//    if (less_tail == NULL)
//    {
//
//        return more;
//    }
//
//    else
//    {
//        less_tail->next = more;
//        return less;
//    }
//}
//        cur = cur->next;
//        insert->next = NULL;
//
//        if (insert->val < x)
//        {
//            if (less == NULL)
//            {
//                less = less_tail = insert;
//                continue;
//            }
//            less_tail->next = insert;
//            less_tail = insert;
//        }
//
//        else
//        {
//            if (more == NULL)
//            {
//                more = more_tail = insert;
//                continue;
//            }
//            more_tail->next = insert;
//            more_tail = insert;
//        }
//    }
//
//    if (less_tail == NULL)
//    {
//
//        return more;
//    }
//
//    else
//    {
//        less_tail->next = more;
//        return less;
//    }
//}

///////////////////////////////以下为简单测试//////////////////////////////////

void Test()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(2);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(2);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    ListNode *head = partition(node1, 3);

}
int main()
{
    Test();
	
	system("pause");
	return 0;
}


///////////////////////////////////////牛客OJ////////////////////////////////////////////

ListNode* partition(ListNode* pHead, int x) {
        // write code here
        if(pHead==NULL)
        {
            return NULL;
        }
        //1. 用两个链表分别存储大于x的节点和小于x的节点。（带头节点链表：不用考虑空链表尾插需要更新头节点的情况；尾指针：有利于尾插操作）
        ListNode *lesshead=(ListNode *)malloc(sizeof(ListNode));
        ListNode *lesstail=lesshead;
        ListNode *greaterhead=(ListNode *)malloc(sizeof(ListNode));
        ListNode *greatertail=greaterhead;
        ListNode *cur=pHead;
        //2.遍历链表进行尾插操作
        while(cur)
        {
            if(cur->val < x)
            {
                lesstail->next=cur;
                lesstail=lesstail->next;
            }
            else
            {
                greatertail->next=cur;
                greatertail=greatertail->next;
            }
            cur=cur->next;
        }
        //此时需要给尾结点的下一个节点置空，否则他将可能会造成无法避免的错误
        greatertail->next=NULL;
        lesstail->next=NULL;
        
        //3.拼接两个链表
		
        //3.3可以处理3.1和3.2情况，故可以屏蔽
        //3.1链表的值均大于x。即：小于x的链表为空
        /*if(lesstail==lesshead)            
        {
            ListNode *head=greaterhead->next;
            free(greaterhead);
            return head;
        }
        //3.2链表的值均小于x。即：大于x的链表为空
        if(greatertail==greaterhead)      
        {
            ListNode *head=lesshead->next;
            free(lesshead);
            return head;
        }*/
		
        //3.3两个链表均不为空。拼接大小链表
        lesstail->next=greaterhead->next;
        free(greaterhead);
        ListNode *head=lesshead->next;
        free(lesshead);
        return head;
    }
