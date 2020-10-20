/*************************************************************************************************************************
问题描述：输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

思路分析：顺序遍历链表，头插到vector中

**************************************************************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if(head==NULL)
            return vector<int>();
        ListNode* cur=head;
        vector<int> ret;
        while(cur!=NULL)
        {
            ret.insert(ret.begin(),cur->val);
            cur=cur->next;
        }
        return ret;
    }
};
