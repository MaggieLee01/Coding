// ������7���ؽ�������
// ��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö�������������
// ���ǰ���������������Ľ���ж������ظ������֡���������ǰ���������{1,
// 2, 4, 7, 3, 5, 6, 8}�������������{4, 7, 2, 1, 5, 3, 8, 6}�����ؽ���
// ͼ2.6��ʾ�Ķ��������������ͷ��㡣

//����֮ǰ��˼·�����������ķ������Լ�coding��
//�ҵ���������ĸ��ڵ���Ը��ڵ������Ϊ�ֽ��ߣ��ֱ����ҵݹ飻ע�⣬ǰ���������������ĳ������
//��ͨ��ţ��������

//�ο����˵Ĵ��룬ϸ���Ż���

#include<iostream>
#include<vector>
#include"../Utilities/BinaryTree.h"
BinaryTreeNode* reConstructBianryTree(std::vector<int>pre, int preStart, int preEnd, std::vector<int> vin, int vinStart, int vinEnd)
{
	//��ʱ������if�жϵĻ��������һ��0������if��Ӧ��Ϊnullptr����if�ڷ����ڴ�
	//BinaryTreeNode* pRoot = new BinaryTreeNode();
	BinaryTreeNode* pRoot = nullptr;
	if (preStart <= preEnd && vinStart <= vinEnd)
	{
		int nRootValue = pre[preStart];
		pRoot = new BinaryTreeNode();
		pRoot->m_nValue = nRootValue;//������pRootΪ�յ�����£���m_nValue��ֵ��������pRootΪ�յ������ָ��ָ�������ڴ棻�������⣬
		int i = 0;
		for (i = vinStart; i <= vinEnd; i++)
		{
			if (nRootValue == vin[i])
				break;//������������ҵ��˸��ڵ�
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
	//����
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
