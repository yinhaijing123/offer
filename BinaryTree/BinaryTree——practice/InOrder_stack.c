/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getSize(struct TreeNode *root)
{
    if(root)
    {
        return 1+ getSize(root->left)+getSize(root->right);
    }
    return 0;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int sz=getSize(root);
    int *arr=(int *)malloc(sizeof(int)*sz);
    int idx=0;

    stack st;
    stackInit(&st);
    while(root || !stackEmpty(&st))
    {
        //1.访问左子树
        while(root)
        {
            stackPush(&st,root);
            root=root->left;
        }

        //2.取栈顶元素。访问
        root = stackTop(&sz);
        arr[idx++]=root->val;
        stackPop(&sz);
        root=root->right;
    }
}