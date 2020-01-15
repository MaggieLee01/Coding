// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。

//回忆之前的思路，传递索引的方法，自己coding，
//找到中序遍历的根节点后，以根节点的索引为分界线，分别左右递归；注意，前序遍历与中序遍历的长度相等
//已通过牛客网测试

//参考别人的代码，细节优化：

#include<iostream>
#include<vector>
#include"../Utilities/BinaryTree.h"
BinaryTreeNode* reConstructBianryTree(std::vector<int>pre, int preStart, int preEnd, std::vector<int> vin, int vinStart, int vinEnd)
{
	//此时若不进if判断的话，会输出一堆0，所以if外应该为nullptr，在if内分配内存
	//BinaryTreeNode* pRoot = new BinaryTreeNode();
	BinaryTreeNode* pRoot = nullptr;
	if (preStart <= preEnd && vinStart <= vinEnd)
	{
		int nRootValue = pre[preStart];
		pRoot = new BinaryTreeNode();
		pRoot->m_nValue = nRootValue;//不能在pRoot为空的情况下，给m_nValue赋值；可以在pRoot为空的情况下指针指向其他内存；基础问题，
		int i = 0;
		for (i = vinStart; i <= vinEnd; i++)
		{
			if (nRootValue == vin[i])
				break;//在中序遍历中找到了根节点
		}
		pRoot->m_pLeft = reConstructBianryTree(pre, preStart + 1, i - vinStart + preStart, vin, vinStart, i - 1);
		pRoot->m_pRight = reConstructBianryTree(pre, i - vinStart + preStart + 1, preEnd, vin, i + 1, preEnd);
	}
	return pRoot;
}

BinaryTreeNode* reConstructBianryTree(std::vector<int>pre, std::vector<int> vin)
{
	BinaryTreeNode* pRoot = new BinaryTreeNode();
	int preLength = pre.size();
	int vinLength = vin.size();
	if (preLength == 0 || vinLength == 0 || preLength != vinLength)
		return pRoot;
	pRoot = reConstructBianryTree(pre, 0, preLength - 1, vin, 0, vinLength - 1);
	return pRoot;
}

int main(void)
{
	//正常
	BinaryTreeNode* pRoot = nullptr;
	std::vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	std::vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	pRoot = reConstructBianryTree(pre, vin);
	TraversalTree_Preorder(pRoot);
	std::cout << std::endl;
	TraversalTree_Inorder(pRoot);
	std::cout << std::endl;

	BinaryTreeNode* pRoot1 = nullptr;
	std::vector<int> pre1 = { 1, 2, 4, 5, 3, 6, 7 };
	std::vector<int> vin1 = { 4, 2, 5, 1, 6, 3, 7 };
	pRoot1 = reConstructBianryTree(pre1, vin1);
	TraversalTree_Preorder(pRoot1);
	std::cout << std::endl;
	TraversalTree_Inorder(pRoot1);
	std::cout << std::endl;

	BinaryTreeNode* pRoot2 = nullptr;
	std::vector<int> pre2 = { 1, 2, 4 };
	std::vector<int> vin2 = { 4, 2, 1, 3 };
	pRoot2 = reConstructBianryTree(pre2, vin2);
	TraversalTree_Preorder(pRoot2);
	std::cout << std::endl;
	TraversalTree_Inorder(pRoot2);
	std::cout << std::endl;
}
