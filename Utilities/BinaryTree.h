#pragma once
struct BinaryTreeNode
{
	int				m_nValue;//��Ա������m_ǰ׺
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
//�����������ڵ�
BinaryTreeNode* CreateBinaryTreeNode(int value);
