/*******************************************************************************	
问题描述：二叉树的先序遍历

思路分析：法一：使用递归思想进行遍历。
		  法二：非递归思想遍历，借助栈实现
*******************************************************************************/	

//法一实现如下：

vector<int> v;
vector<int> preorderTraversal(TreeNode *root)
{
    if(root==NULL)
    {
        return vector<int>();
    }
    v.push_back(root->val);
    if(root->left)
    {
        preorderTraversal(root->left);
    }
    if(root->right)
    {
        preorderTraversal(root->right);
	}
    return v;
}
	
//法二实现：

vector<int> preorderTraversal(TreeNode *root)
{
	if(root==NULL)
	{
		return vector<int>();
	}
	
	stack<TreeNode *> s;
	vector<int> v;
	s.push(root);
	while(!s.empty())
	{
		TreeNode* top=s.top();
		v.push_back(top->val);
		s.pop();
		
		if(top->right!=NULL)                                 //由于栈是先进后出，故先入右子树根节点
		{
			s.push(top->right);
		}
		
		if(top->left!=NULL)
		{
			s.push(top->left);
		}
	}
	return v;
}	

	