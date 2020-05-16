/********************************************************************************
问题描述：给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
        （注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针）

思路分析：分两种情况：
           1.有右子树；下一个节点为右子树的最左子节点。
           2.无右子树。
               （1）该节点为其父节点的左节点；下一个节点为该节点的父节点
               （2）该节点为其父节点的右节点。（沿着指向父节点的指针向上遍历，直到找到一个是它父节点的左节点的节点。）
                   如果这样的节点存在，则，该节点的父节点即为他的下一个节点；
                   若不存在，则，该节点为树的最后一个节点，即下一个节点为空。
********************************************************************************/
TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    if(pNode==NULL)
        return NULL;
    //1.有右子树
    if(pNode->right!=NULL)
    {
        TreeLinkNode* cur=pNode->right;
        while(cur->left!=NULL)
        {
            cur=cur->left;
        }
        return cur;
    }
    //2.无右子树
    else
    {
        TreeLinkNode *father=pNode->next;
        if(father==NULL)
        {
            return NULL;
        }
        //（1）该节点为其父节点的左孩子
        if(father->left==pNode)
        {
            return father;
        }
        //（2）该节点为其父节点的右孩子
        if(father->right==pNode)
        {
            TreeLinkNode *grandfather=father->next;
            while(grandfather!=NULL)
            {
                if(grandfather->left==father)     //存在该祖父节点
                    return grandfather;
                else
                {
                    father=grandfather;
                    grandfather=grandfather->next;
                }
            }
            return NULL;                          //不存在该祖父节点
        }
    }
}