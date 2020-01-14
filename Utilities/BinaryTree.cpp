#include<iostream>
#include <cstdio>
#include"BinaryTree.h"
#include<queue>
#include<stack>
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

/*void PrintTree(binarytreenode* proot)
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
		PrintTree(proot->m_pleft);		
		PrintTree(proot->m_pright);
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
//依然同链表销毁一样的情况，销毁时个人认为应该是二级指针，一级指针参数的话，pRoot出了函数就变成了野指针
void DestroyTree(BinaryTreeNode** pRoot)
{
	if (pRoot != nullptr && *pRoot != nullptr)
	{
		BinaryTreeNode* pRight = (*pRoot)->m_pRight;
		BinaryTreeNode* pLeft = (*pRoot)->m_pLeft;
		delete *pRoot;
		*pRoot = nullptr;
		DestroyTree( &pRight );
		DestroyTree( &pLeft );
	}
}
//二叉树遍历
//深度（前中后、递归非递归）、广度遍历
void TraversalTree_Preorder_recursively(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		std::cout << pRoot->m_nValue<<' ';
		TraversalTree_Preorder_recursively(pRoot->m_pLeft);
		TraversalTree_Preorder_recursively(pRoot->m_pRight);
	}
}
void TraversalTree_Inorder_recursively(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		TraversalTree_Inorder_recursively(pRoot->m_pLeft);
		std::cout << pRoot->m_nValue << ' ';
		TraversalTree_Inorder_recursively(pRoot->m_pRight);
	}
}
void TraversalTree_Postorder_recursively(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		TraversalTree_Postorder_recursively(pRoot->m_pLeft);		
		TraversalTree_Postorder_recursively(pRoot->m_pRight);
		std::cout << pRoot->m_nValue << ' ';
	}
}
//非递归遍历不会写，广度遍历不会写，看答案
//执行完程序，思路，由于前序遍历，先把根节点压入堆栈，逐个遍历左节点，当左节点为空的时候，才弹出堆栈中的回退节点（可能是父节点，也可能是父节点的父节点），遍历回退节点的右节点，
void TraversalTree_Preorder(BinaryTreeNode* pRoot)
{
	std::stack<BinaryTreeNode*> tree;
	//tree.push(pRoot);
	while (pRoot != nullptr || !tree.empty())
	{
		if (pRoot != nullptr)
		{
			std::cout << pRoot->m_nValue << ' ';
			tree.push(pRoot);//之前只考虑压入值，这样子没有意义，压入节点才能回退
			//tree.push(pRoot->m_pLeft);//之前压入了子节点，这样子刚开始正确，到最底层时的时候会出现逻辑错误，
			//栈里面只存储可能会回退的根节点（每一小分支)，若左边全部遍历完后，则弹出右节点
			pRoot = pRoot->m_pLeft;
		}
		else
		{			
			pRoot = tree.top();	
			tree.pop();
			//tree.push(pRoot->m_pRight);
			pRoot = pRoot->m_pRight;
		}
	}	
}

//参考前序思路，自己写中序遍历；依旧是同上相同的遍历顺序，只是打印的时机不同，当左节点为空的时候才应该打印
void TraversalTree_Inorder(BinaryTreeNode* pRoot)
{
	std::stack<BinaryTreeNode*> tree;
	//tree.push(pRoot);
	while (pRoot != nullptr || !tree.empty())
	{
		if (pRoot != nullptr)
		{			
			tree.push(pRoot);
			pRoot = pRoot->m_pLeft;
		}
		else
		{
			pRoot = tree.top();
			tree.pop();
			std::cout << pRoot->m_nValue << ' ';
			pRoot = pRoot->m_pRight;
		}
	}
}
void TraversalTree_Postorder(BinaryTreeNode* pRoot)
{

}
//广度优先遍历
//因为为一级形参，所以函数结束之后不影响指针的指向，最后重新定义一个新指针不用形参指针
void TraversalTree_BreadthFirst(BinaryTreeNode* pRoot)
{
	std::queue<BinaryTreeNode*> tree;
	tree.push(pRoot);
	while (pRoot != nullptr && tree.empty() != 1)
	{	
		pRoot = tree.front();
		std::cout << pRoot->m_nValue << ' ';
		tree.pop();
		if (pRoot->m_pLeft != nullptr)
			tree.push(pRoot->m_pLeft);
		if (pRoot->m_pRight != nullptr)
			tree.push(pRoot->m_pRight);		
	}
}
int main(void)
{
	BinaryTreeNode*p = nullptr;
	BinaryTreeNode*p1 = CreateBinaryTreeNode(1);
	BinaryTreeNode*p2 = CreateBinaryTreeNode(2);
	BinaryTreeNode*p3 = CreateBinaryTreeNode(3);	
	BinaryTreeNode*p4 = CreateBinaryTreeNode(4);
	BinaryTreeNode*p5 = CreateBinaryTreeNode(5);
	BinaryTreeNode*p6 = CreateBinaryTreeNode(6);
	BinaryTreeNode*p7 = CreateBinaryTreeNode(7);

	ConnectBinaryTreeNode(p1, p2, p3);
	ConnectBinaryTreeNode(p2, p4, p5);
	ConnectBinaryTreeNode(p3, p6, p7);

	PrintTree(p1);

	TraversalTree_Preorder_recursively(p1);
	std::cout << std::endl;

	TraversalTree_Inorder_recursively(p1);
	std::cout << std::endl;

	TraversalTree_Postorder_recursively(p1);
	std::cout << std::endl;

	TraversalTree_Preorder(p1);
	std::cout << std::endl;

	TraversalTree_Inorder(p1);
	std::cout << std::endl;

	TraversalTree_BreadthFirst(p1);
	std::cout << std::endl;

	TraversalTree_Preorder(p);
	std::cout << std::endl;

	DestroyTree(&p1);
	PrintTree(p1);
	return 0;
}
