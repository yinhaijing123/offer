BTree.h
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
﻿// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
// 前序遍历创建节点。
BTNode* BinaryTreeCreate(BTDataType a[],int* pi)
{
    if (a[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }


    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    root->_data = a[*pi];
    (*pi)++;


    root->_left = BinaryTreeCreate(a, pi);
    root->_right = BinaryTreeCreate(a, pi);
    return root;
}
// 二叉树销毁
//后序遍历从叶子节点~根节点逐步释放空间
void BinaryTreeDestory(BTNode** root)
{
    if (*root)
    {
        BinaryTreeDestory(&((*root)->_left));
        BinaryTreeDestory(&((*root)->_right));
        free(*root);
        *root = NULL;
    } 
}
// 二叉树节点个数
//=1 + 左子树节点个数+右子树节点个数
int BinaryTreeSize(BTNode* root)
{
    if (root == NULL)
        return 0;
    return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
// 二叉树叶子节点个数
//=左子树叶子节点个数+右子树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
    if (root == NULL)
        return 0;
    if (root->_left == NULL && root->_right == NULL)
        return 1;
    return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// 二叉树第k层节点个数
//=左子树第k-1层节点个数+右子树第k-1层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
    if (root == NULL)
        return 0;
    if (k == 1)
        return 1;
    return BinaryTreeLevelKSize(root->_left, k - 1)+BinaryTreeLevelKSize(root->_right,k-1);
}
// 二叉树查找值为x的节点
//前序遍历比较节点值是否为x
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
    if (root)
    {
        if (root->_data == x)
            return root;
        BTNode *ret = BinaryTreeFind(root->_left, x);
        if (ret)
            return ret;
        else
            return BinaryTreeFind(root->_right, x);
    }
    return NULL;
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
    if (root == NULL)
        return;
    printf("%c ", root->_data);
    BinaryTreePrevOrder(root->_left);
    BinaryTreePrevOrder(root->_right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
    if (root == NULL)
        return;
    BinaryTreeInOrder(root->_left);
    printf("%c ", root->_data);
    BinaryTreeInOrder(root-> _right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
    if (root == NULL)
        return;
    BinaryTreePostOrder(root->_left);
    BinaryTreePostOrder(root->_right);
    printf("%c ", root->_data);
}
//层序遍历
//借助队列。先入队根节点，访问根节点，入队根节点的左右子节点，根节点出队
void BinaryTreeLevelOrder(BTNode* root)
{
    if (root)
    {
        Queue q;
        QueueInit(&q);
        QueuePush(&q, root);


        while (!QueueEmpty(&q))
        {
            BTNode* head = QueueFront(&q);
            printf("%c ", head->_data);
            QueuePop(&q);
            if (head->_left)
                QueuePush(&q, head->_left);
            if (head->_right)
                QueuePush(&q, head->_right);
        }
    }
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
    if (root)
    {
        Queue q;
        QueueInit(&q);
        QueuePush(&q, root);
        
        //找到第一个为NULL的节点
        while (!QueueEmpty(&q))
        {
            BTNode* head = QueueFront(&q);
            printf("%c ", head->_data);
            QueuePop(&q);


            if (head)
            {
                QueuePush(head->_left);
                QueuePush(head->_right);
            }
            else
                break;
        }
        //完全二叉树中，按层序遍历树，各节点之间不存在NULL节点，即连续。根据此特点，判断其等价于判断叶子节点下一层是否具有非空节点。
        while (!QueueEmpty(&q))
        {
            BTNode* head = QueueFront(&q);
            QueuePop(&q);
            if (head != NULL)
                return 0;
        }
    }
    return 1;
}


Test.c
#include"BTree.h"
int main()
{
    BTDataType a[] = "ABD##E#H##CF##G##";
    int pi = 0;
    BTNode *root = BinaryTreeCreate(a,&pi);
    printf("size is %d\n", BinaryTreeSize(root));
    printf("leaf size is %d\n", BinaryTreeLeafSize(root)); 
    printf("K level is %d\n", BinaryTreeLevelKSize(root,3)); 
    BTNode* ret = BinaryTreeFind(root, 'E');
    printf("node is %p,node val is %c\n", ret,ret->_data);
    ret = BinaryTreeFind(root, 'x');
    printf("node is %p\n", ret);
    BinaryTreePrevOrder(root);
    printf("\n");
    BinaryTreeInOrder(root);
    printf("\n");
    BinaryTreePostOrder(root);
    printf("\n");

    BinaryTreeDestory(&root);
    printf("size is %d\n", BinaryTreeSize(root));
    printf("leaf size is %d\n", BinaryTreeLeafSize(root));

    return 0;
}


