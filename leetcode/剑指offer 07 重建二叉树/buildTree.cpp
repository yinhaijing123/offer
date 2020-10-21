/*************************************************************************************************************************
问题描述：输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
		  例如，给出：
		  前序遍历 preorder = [3,9,20,15,7]
		  中序遍历 inorder = [9,3,15,20,7]
		  返回如下的二叉树：

			  3
		     / \
		    9  20
			  /  \
		     15   7
思路分析：遍历前序序列：第一个元素即为树的根节点。在中序序列中找第一个节点所在位置下标，则：可得左子树的前序遍历和中序遍历序列，之后递归实现即可。

**************************************************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
            return NULL;
        return buildTreeCore(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
    TreeNode * buildTreeCore(vector<int>::iterator prestart,vector<int>::iterator preend,vector<int>::iterator instart,vector<int>::iterator inend)
    {
        if(prestart==preend)
            return NULL;
        TreeNode * root=new TreeNode(*prestart);
        vector<int>::iterator mid=find(instart,inend,root->val);

        root->left=buildTreeCore(prestart+1,prestart+1+(mid-instart),instart,mid-1);
        root->right=buildTreeCore(prestart+1+(mid-instart),preend,mid+1,inend);
        return root;
    }
};
