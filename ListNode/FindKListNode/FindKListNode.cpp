//问题描述：寻找链表中倒数第k个节点

//思路如下：主要使用了快慢指针的思想
//1.首先对参数参数进行合法性检查；
//2.定义一个快指针指向链表头部，让其先行k步之后。再定义一个慢指针指向链表头部，此时，快慢指针相差的步数为k。最后，让快慢指针同时向前进行；当快指针指向链表尾部时，即：慢指针指向倒数第k个节点。

#include<iostream>
#include<vector>

using namespace std;

struct ListNode 
{
    int val;
    struct ListNode *next;
    ListNode(int x) 
        :val(x)
        ,next(NULL) 
    {}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if (pListHead == nullptr)
    {
        return nullptr;
    }

    ListNode *quick = pListHead;
    while ((quick != nullptr) && k)
    {
        quick = quick->next;
        k--;
    }

    if (k == 0)
    {
        ListNode *slow = pListHead;
        while (quick != nullptr)
        {
            quick = quick->next;
            slow = slow->next;
        }
        return slow;
    }
    return nullptr;
}

/**********************************************************************************
                        以下为测试代码
**********************************************************************************/

void TestFindKListNode()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    ListNode *ret = FindKthToTail(&node1, 1);
    cout << (ret->val) << endl;
}

int main()
{
    TestFindKListNode();
	
	system("pause");
	return 0;
}
