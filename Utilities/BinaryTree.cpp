#include<iostream>
#include <cstdio>
#include"BinaryTree.h"

//�����������ڵ�
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

//���Ӷ������ڵ�
void ConnectBinaryTreeNode(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pRoot != nullptr)
	{
		pRoot->m_pLeft = pLeft;
		pRoot->m_pRight = pRight;
	}
}

//��ӡ�������ڵ�
//����𰸣�˼�������Ƕ�����ѽ����Ҫ��ӡ�����ӽڵ�ѽ����������ֻ�и��ڵ�
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

//��ӡ������
//�ݹ�ķ�����ӡò�Ʊ������ȱ�������ӡ��ʮ����Ӧ���ǹ�ȱ���������whileѭ��
//���ϳ���Ϊ���ӡ���������εĶ����������޽ڵ��Ϊ0������ʧ��
//����𰸣�˼������Ҳ�ǰ��յݹ�ķ���������ڵ��ӡ��û�д�ӡ������������״���Ժ�ѧϰ��ȱ����ķ���
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
//���ٶ�����

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