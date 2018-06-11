/******************************************************************************************************
问题描述：将已经排序的单链表，转换为平衡二叉搜索树

思路分析：1.确定二叉树的根节点，即找单链表的中间节点-----快慢指针    （根据单链表和平衡二叉树的性质得：
            单链表的中间节点即为平衡二叉树的根节点，单链表中间节点左侧为根节点的左子树，右侧为根节点的右子树）
          2.从中间节点处，将单链表分割为两个子链表，分别为根节点的左子树和右子树。
          3.再递归分别确定左子树的根节点及右子树的根节点
******************************************************************************************************/

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) 
        : val(x), next(NULL) 
    {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) 
        : val(x), left(NULL), right(NULL) 
    {}
};

TreeNode* sortedListToBST(ListNode *head) 
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    { 
        TreeNode *root = new TreeNode(head->val);
        return root;
    }
    ListNode *flase_head = new ListNode(-1);               //慢指针指向头节点前一个节点
    flase_head->next = head;

    ListNode *quick = head;
    ListNode *slow = flase_head;
    while (quick->next != NULL && quick!= NULL)
    {
        quick = quick->next->next;
        slow = slow->next;
    }
    TreeNode *root = new TreeNode(slow->next->val);
    
    ListNode *left = head;
    ListNode *right = slow->next->next;
    slow->next = NULL;

    root->left = sortedListToBST(left);
    root->right = sortedListToBST(right);
    return root;
}
