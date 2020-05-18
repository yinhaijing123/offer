/*******************************************************************************************
问题描述：求树的深度

算法思路：递归实现（即：求一个树的深度，就是求他的左子树与右子树中较大的一个子树的深度后+1）
		
*******************************************************************************************/

	int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL)
        {
            return 0;
        }
        
        int LchildDep=TreeDepth(pRoot->left);
        int RchildDep=TreeDepth(pRoot->right);
        return 1+(LchildDep>RchildDep?LchildDep:RchildDep);
    }