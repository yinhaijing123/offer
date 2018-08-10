/********************************************************************************
问题描述：把二叉树打印成多行
        （要求：从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。）

思路分析：此问题是对层序遍历的变型(由于要按行打印,故需要记录二叉树每一层的节点个数)
		  首先，对第一层进行入队列，即，只有一个节点pRoot节点，
		  然后，进入循环处理事件。
		        记录该队列此时的元素个数（用于判定一维数组的个数），每出一次队列，
				将该节点的值插入要打印的一维数组中，并判断其左右子树是否为空，
				若不为空，则执行入队列操作。直至将该层的所有节点的值都插入到了一维数组中
				则可以将该一维数组插入到二维数组中，此时说明已经将一行已经保存了
		  直至队列为空，则标志着所有的节点已经被遍历了。  
********************************************************************************/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

vector<vector<int> > Print(TreeNode* pRoot)
 {
	vector<vector<int>> vv;
	if(pRoot==NULL)
	{
		return vv;
	}
	queue<TreeNode *> q;
	q.push(pRoot);

	while(!q.empty())
	{
		int size_i=q.size();
		int i=0;
		vector<int> v;
		
		while(i++ < size_i)
		{
			TreeNode *tmp=q.front();
			q.pop();
			v.push_back(tmp->val);
			if(tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);
		}
		vv.push_back(v);
	}
	return vv;
}

