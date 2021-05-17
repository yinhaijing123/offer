/*******************************************************************************************
问题描述：根据一棵树的中序遍历与后序遍历构造二叉树

算法思路：主要是划分左右子区间。(后序遍历的特点：最后一个节点一定是根节点，根节点的上一个节点一定是右子树根节点。中序遍历的特点：若某节点在中序序列中的位置为idx,则有：该节点左子树为中序序列[instart,idx-1]区间,该节点右子树为中序序列[idx+1,inend])区间
		  核心代码主要流程：
			  1. 判断区间是否有效；
			  2. 根据后序序列从后向前遍历，创建根节点；
			  3.划分左右区间——确定左右子树(左：[instart,idx-1]，右：[idx+1,inend])
			  4.创建右子树(若右子树无数据，则将右子树连接nullptr，否则，递归创建右子树节点)
			  5.创建左子树(若左子树无数据，则将左子树连接nullptr，否则，递归创建左子树节点)
*******************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *_buildTree(vector<int> &inorder,vector<int>& postorder,int &postIdx,int startIdx,int endIdx)
    {
        //1 判断区间是否有效
        if(startIdx>endIdx)
            return nullptr;
        //2.创建根节点
        TreeNode *root=new TreeNode(postorder[postIdx]);
        //3.划分左右区间
        int curIdx=startIdx;
        for(;curIdx<endIdx;++curIdx)
        {
            if(inorder[curIdx]==postorder[postIdx])
                break;
        }
        //4.创建右子树:[curIdx+1,endIdx]
        if(curIdx<endIdx)
            root->right=_buildTree(inorder,postorder,--postIdx,curIdx+1,endIdx);
        else
            root->right=nullptr;
        //5.创建左子树:[startIdx,curIdx-1]
        if(startIdx<curIdx)
            root->left=_buildTree(inorder,postorder,--postIdx,startIdx,curIdx-1);
        else
            root->left=nullptr;
        
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx=postorder.size()-1;
        return _buildTree(inorder,postorder,postIdx,0,inorder.size()-1);
    }
};