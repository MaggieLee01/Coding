#pragma once
struct BinaryTreeNode
{
	int				m_nValue;//成员命名加m_前缀
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
//创建二叉树节点
BinaryTreeNode* CreateBinaryTreeNode(int value);

//连接二叉树节点
void ConnectBinaryTreeNode(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);

void PrintTreeNode(const BinaryTreeNode* pRoot);
void PrintTree(const BinaryTreeNode* pRoot);

void DestroyTree(BinaryTreeNode** pRoot);

void TraversalTree_Preorder_recursively(BinaryTreeNode* pRoot);
void TraversalTree_Inorder_recursively(BinaryTreeNode* pRoot);
void TraversalTree_Postorder_recursively(BinaryTreeNode* pRoot);
void TraversalTree_Preorder(BinaryTreeNode* pRoot);
void TraversalTree_Inorder(BinaryTreeNode* pRoot);
void TraversalTree_Postorder(BinaryTreeNode* pRoot);
void TraversalTree_BreadthFirst(BinaryTreeNode* pRoot);