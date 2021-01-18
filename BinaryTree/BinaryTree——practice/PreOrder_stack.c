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

//  void preOder(struct TreeNode *root,int *arr,int *idx)
//  {
//      if(root)
//      {
//          arr[*idx]=root->val;
//          (*idx)++;
//          preOder(root->left,arr,idx);
//          preOder(root->right,arr,idx);
//      }
//  }
// int* preorderTraversal(struct TreeNode* root, int* returnSize){
//     int sz=getSize(root);
//     int *arr=(int *)malloc(sizeof(int)*sz);
//     int idx=0;
//     preOder(root,arr,&idx);

//     *returnSize=sz;
//     return arr;
// }

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int sz=getSize(root);
    int *arr=(int *)malloc(sizeof(int)*sz);
    stack st;
    stackInit(&st);
    int idx=0;
    //当前遍历的节点不为空，或者栈不为空
    while(root|| !stackEmpty(&st))
    {
        //1.访问最左路径
        while(root)
        {
            arr[idx++]=root->val;
            //当前节点入栈
            stackPush(&st,root);
            root=root->left;
        }

        //2.获取栈顶元素，访问右子树
        root=stackTop(&st);
        stackPop(&st);
        root=root->right;
    }
    *returnSize=sz;
    return arr;
}