//在牛客看到之前用压入vector的方法，比索引的方法简单，自己按照回忆的思路重新写了一版
//不同的方法运用的数据结构不同，但该题解法的核心只有一个，前序遍历的第一个为根节点
//通过了牛客测试，还未细细地考虑各个细节
//额外地发现自己binary打错了，惭愧
#include<iostream>
#include<vector>
#include"../Utilities/BinaryTree.h"

BinaryTreeNode* reConstructBinaryTree(std::vector<int>pre, std::vector<int>vin)
{
	BinaryTreeNode* pRoot = nullptr;
	if (pre.size() != 0 && vin.size() != 0 && pre.size() == vin.size() )
	{
		std::vector<int> pre_front, pre_behind, vin_front, vin_behind;
		int i = 0;
		for (i = 0; i < pre.size(); i++)
		{
			if (pre[0] == vin[i])
				break;
		}
		for (int j = 0; j < i; j++)
		{
			pre_front.push_back(pre[j + 1]);
			vin_front.push_back(vin[j]);
		}
		for (int j = i + 1; j < pre.size(); j++)
		{
			pre_behind.push_back(pre[j]);
			vin_behind.push_back(vin[j]);
		}
		pRoot = new BinaryTreeNode();
		pRoot->m_nValue = pre[0];
		pRoot->m_pLeft = reConstructBinaryTree(pre_front, vin_front);
		pRoot->m_pRight = reConstructBinaryTree(pre_behind, vin_behind);
	}
	return pRoot;
}

int main(void)
{
	//正常
	BinaryTreeNode* pRoot = nullptr;
	std::vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	std::vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	pRoot = reConstructBinaryTree(pre, vin);
	TraversalTree_Preorder(pRoot);
	std::cout << std::endl;
	TraversalTree_Inorder(pRoot);
	std::cout << std::endl;

	BinaryTreeNode* pRoot1 = nullptr;
	std::vector<int> pre1 = { 1, 2, 4, 5, 3, 6, 7 };
	std::vector<int> vin1 = { 4, 2, 5, 1, 6, 3, 7 };
	pRoot1 = reConstructBinaryTree(pre1, vin1);
	TraversalTree_Preorder(pRoot1);
	std::cout << std::endl;
	TraversalTree_Inorder(pRoot1);
	std::cout << std::endl;

	BinaryTreeNode* pRoot2 = nullptr;
	std::vector<int> pre2 = { 1, 2, 4 };
	std::vector<int> vin2 = { 4, 2, 1, 3 };
	pRoot2 = reConstructBinaryTree(pre2, vin2);
	TraversalTree_Preorder(pRoot2);
	std::cout << std::endl;
	TraversalTree_Inorder(pRoot2);
	std::cout << std::endl;
}
