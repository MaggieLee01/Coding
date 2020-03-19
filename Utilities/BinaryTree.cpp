//���� ���� ��ӡ  ���� �ο�book˼·
//������7�ַ����������ϴ���˼·��д��ӡ��ʼ����ӡ���δ�������ϸ���������
#include<iostream>
#include <cstdio>
#include"BinaryTree.h"
#include<queue>
#include<stack>
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
//��Ȼͬ��������һ�������������ʱ������ΪӦ���Ƕ���ָ�룬һ��ָ������Ļ���pRoot���˺����ͱ����Ұָ��
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
//����������
//��ȣ�ǰ�к󡢵ݹ�ǵݹ飩����ȱ���
//�ݹ����ʱ�����轫�ڵ�ֵ�洢�������β�ʱ����vectorӦ��
//void TraversalTree_Preorder_recursively(BinaryTreeNode* pRoot��vector<int> &path),��valueѹ��vector
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
//�ǵݹ��������д����ȱ�������д�������˼·���Լ�coding
//ִ�������˼·������ǰ��������ȰѸ��ڵ�ѹ���ջ�����������ڵ㣬����ڵ�Ϊ�յ�ʱ�򣬲ŵ�����ջ�еĻ��˽ڵ㣨�����Ǹ��ڵ㣬Ҳ�����Ǹ��ڵ�ĸ��ڵ㣩���������˽ڵ���ҽڵ㣬
void TraversalTree_Preorder(BinaryTreeNode* pRoot)
{
	std::stack<BinaryTreeNode*> tree;
	//tree.push(pRoot);
	while (pRoot != nullptr || !tree.empty())
	{
		if (pRoot != nullptr)
		{
			std::cout << pRoot->m_nValue << ' ';
			tree.push(pRoot);//֮ǰֻ����ѹ��ֵ��������û�����壬ѹ��ڵ���ܻ���
			//tree.push(pRoot->m_pLeft);//֮ǰѹ�����ӽڵ㣬�����Ӹտ�ʼ��ȷ������ײ�ʱ��ʱ�������߼�����
			//ջ����ֻ�洢���ܻ���˵ĸ��ڵ㣨ÿһС��֧)�������ȫ����������򵯳��ҽڵ�
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

//�ο�ǰ��˼·���Լ�д���������������ͬ����ͬ�ı���˳��ֻ�Ǵ�ӡ��ʱ����ͬ������ڵ�Ϊ�յ�ʱ���Ӧ�ô�ӡ
void TraversalTree_Inorder(BinaryTreeNode* pRoot)
{
	std::stack<BinaryTreeNode*> tree;
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
//���격��˼·���Լ�coding
//�½���һ���ṹ�壬����bool��������¼���Ƿ��Ƿ񱻷��ʹ���ѹ��ջʱ���Ϊfalse��
//����������ڵ���ʸ��ڵ�ʱ����һ�η��ʱ��Ϊtrue�����������ҽڵ��ٴη��ʵ�ջ��Ԫ��ʱ������ʽ����ø��ڵ㣬������ջ��Ԫ��
void TraversalTree_Postorder(BinaryTreeNode* pRoot)
{
	struct TempNode
	{
		BinaryTreeNode* m_pNode;
		bool m_bVisited;
	};
	std::stack<TempNode*> StackTree;	
	BinaryTreeNode* pTreeNode = pRoot;
	while (pTreeNode != nullptr || StackTree.empty() != 1)
	{
		//һֱ������ڵ㵽Ϊ��Ϊֹ
		while (pTreeNode != nullptr)
		{
			TempNode* ptemp = new TempNode();//��Ϊ����Ҫ��stack����Ľṹ���жϣ����Դ˴�Ӧ����new�����ڴ�
			ptemp->m_pNode = pTreeNode;
			ptemp->m_bVisited = false;
			StackTree.push(ptemp);
			pTreeNode = pTreeNode->m_pLeft;
		}
		//������top�󵯳������ж�m_bVisited��if����ѹ�룬˼���Ƿ��б�Ҫ���ҵ�д���Ƿ���������أ�
		if (StackTree.empty() != 1)
		{
			TempNode* ptemp = StackTree.top();
			
			if (ptemp->m_bVisited == false)
			{
				pTreeNode = ptemp->m_pNode->m_pRight;
				ptemp->m_bVisited = true;
			}
			else
			{
				std::cout << ptemp->m_pNode->m_nValue << ' ';
				StackTree.pop();
				delete ptemp;//�˺�temp�ڵ㲻��Ҫ�ˣ��ͷ��ڴ�
				ptemp = nullptr;
			}
		}
	}
}
//����˼·���Լ�coding
//������ȱ���
//��ΪΪһ���βΣ����Ժ�������֮��Ӱ��ָ���ָ��������¶���һ����ָ�벻���β�ָ��
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

//˼·��Դ��LeetCode���

int test(void)
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
	ConnectBinaryTreeNode(p2, p4, p);
	ConnectBinaryTreeNode(p3, p, p7);

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

	TraversalTree_Postorder(p1);
	std::cout << std::endl;

	TraversalTree_BreadthFirst(p1);
	std::cout << std::endl;

	TraversalTree_Preorder(p);
	std::cout << std::endl;

	DestroyTree(&p1);
	PrintTree(p1);
	return 0;
}
