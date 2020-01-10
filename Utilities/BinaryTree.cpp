#include<iostream>
#include <cstdio>
#include"BinaryTree.h"

//创建二叉树节点
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode* pRoot = new BinaryTreeNode();
	if (pRoot != nullptr)
	{
		pRoot->m_nValue = value;
		pRoot->m_pLeft = nullptr;
		pRoot->m_pRight = nullptr;
	}
	return pRoot;
}

//连接二叉树节点
void ConnectBinaryTreeNode(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pRoot != nullptr)
	{
		pRoot->m_pLeft = pLeft;
		pRoot->m_pRight = pRight;
	}
}

//打印二叉树节点
//看完答案，思考，这是二叉树呀，还要打印左右子节点呀，不是链表，只有根节点
void PrintTreeNode(const BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		std::cout << "The root is  " <<pRoot->m_nValue << std::endl;
		if (pRoot->m_pLeft != nullptr)
			std::cout << "The left child is " << pRoot->m_pLeft->m_nValue << std::endl;
		else
			std::cout << "The left child is nullptr" << std::endl;

		if (pRoot->m_pRight != nullptr)
			std::cout << "The Right child is " << pRoot->m_pRight->m_nValue << std::endl;
		else
			std::cout << "The Right child is nullptr" << std::endl;
	}
	else
		std::cout << "The root is nullptr" << std::endl;
	std::cout << std::endl;
}

/*void printbinarytree(binarytreenode* proot)
{
	/*binarytreenode* pleft = proot;
	binarytreenode* pright = proot;
	while (pleft != nullptr || pright != nullptr)
	{
		std::cout << proot->m_nvalue;
		pleft = pleft->m_pleft;
		pright = pright->m_pright;
	}*/

	/*
	if (proot != nullptr)
	{
		std::cout << proot->m_nvalue;
		std::cout << proot->m_pleft << " ";
		std::cout << proot->m_pright << " ";		
		printbinarytree(proot->m_pleft);		
		printbinarytree(proot->m_pright);
	}	
}*/

//打印二叉树
//递归的方法打印貌似变成了深度遍历；打印成十字塔应该是广度遍历，尝试while循环
//以上尝试为想打印出金字塔形的二叉树，且无节点出为0，尝试失败
//看完答案，思考，答案也是按照递归的方法，逐个节点打印，没有打印出金字塔的形状，以后学习广度遍历的方法
void PrintTree(const BinaryTreeNode* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->m_pLeft != nullptr)
			PrintTree(pRoot->m_pLeft);

		if (pRoot->m_pRight != nullptr)
			PrintTree(pRoot->m_pRight);
	}
}
//销毁二叉树

int main(void)
{
	BinaryTreeNode*p = nullptr;
	BinaryTreeNode*p1 = CreateBinaryTreeNode(1);
	BinaryTreeNode*p2 = CreateBinaryTreeNode(2);
	BinaryTreeNode*p3 = CreateBinaryTreeNode(3);
	ConnectBinaryTreeNode(p1, p2, p3);
	BinaryTreeNode*p4 = CreateBinaryTreeNode(4);
	BinaryTreeNode*p5 = CreateBinaryTreeNode(5);
	ConnectBinaryTreeNode(p2, p4, p);
	ConnectBinaryTreeNode(p3, p, p5);
	PrintTree(p1);
	return 0;
}