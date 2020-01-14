#pragma once
struct BinaryTreeNode
{
	int				m_nValue;//��Ա������m_ǰ׺
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
//�����������ڵ�
BinaryTreeNode* CreateBinaryTreeNode(int value);

//���Ӷ������ڵ�
void ConnectBinaryTreeNode(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);

void PrintTreeNode(const BinaryTreeNode* pRoot);
void PrintTree(const BinaryTreeNode* pRoot);

void DestroyTree(BinaryTreeNode** pRoot);
