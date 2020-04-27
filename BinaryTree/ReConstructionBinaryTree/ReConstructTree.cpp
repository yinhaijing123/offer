
/*******************************************************************************	
问题描述：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
          例如：输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

思路分析：1.构造根节点，即为前序遍历第一个节点
		  2.找左子树（即左子树前序遍历和中序遍历）
		  3.找右子树（即右子树前序遍历和中序遍历）
		  4.递归调用，直到size==NULL
*******************************************************************************/	

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
   if((pre.size()==0)||(vin.size()==0))
   {
       return NULL;
   }
   //1.构造根节点，即为前序遍历第一个节点
   TreeNode *root=new TreeNode(pre[0]);
   vector<int> left_pre,left_vin,right_pre,right_vin;
   int border=0;
   for(int i =0;i<vin.size();i++)
   {
      if(vin[i]==pre[0])
      {
         border=i;
         break;
      }
   }
   //2.找左子树（即左子树前序遍历和中序遍历）,例：pre={1,2,4,7,3,5,6,8}和vin={4,7,2,1,5,3,8,6}；则left_pre={2,4,7},left_vin={4,7,2},right_pre={3,5,6,8},right_vin={5,3,8,6}
   for(int i=0;i<border;i++)
   {
      left_pre.push_back(pre[i+1]);
      left_vin.push_back(vin[i]);
   }
   //3.找右子树（即右子树前序遍历和中序遍历）
   for(int i=border+1;i<vin.size();i++)
   {
      right_pre.push_back(pre[i]);
      right_vin.push_back(vin[i]);
   }
   //4.递归调用，直到size==NULL
   root->left=reConstructBinaryTree(left_pre,left_vin);
   root->right=reConstructBinaryTree(right_pre,right_vin);
   return root;
}
