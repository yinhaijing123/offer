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
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int size=getSize(root);
    int *arr=(int *)malloc(sizeof(int)*sz);

    stack st;
    stackInit(&st);
    int idx=0;

    //prev:上一次访问的节点
    struct TreeNode *prev=NULL;
    while(root || !stackEmpty(&st))
    {
        //1.左路径入栈
        while(root)
        {
            stackPush(&st,root);
            root=root->left;
        }
        //2.取栈顶元素，右节点为空/右节点已访问，访问该节点，出栈。
        struct TreeNode *top=stackTop(&st);
        if(top->right==NULL ||top->right==prev)
        {
            arr[idx++]=top->val;
            stackPop(&st);
            //更新prev
            prev=top;
        }
        //3.若右路径不为空且右节点未被访问，入栈
        else
        {
            root=top->right;
        }

    }
}