// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

//回忆思路，可以分为3种情况，
//该节点为左子树，右子树，父节点

#include<iostream>
struct BinaryTreeNode 
{
	int				m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};
BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	BinaryTreeNode* pNext = nullptr;
	if (pNode != nullptr)
	{

	}
	return pNext;
}