/*给定一个二叉树，判断其是否是一个有效的二叉搜索树。
假设一个二叉搜索树具有如下特征：
	节点的左子树只包含小于当前节点的数。
	节点的右子树只包含大于当前节点的数。
	所有左子树和右子树自身必须也是二叉搜索树。

输入:
    2
   / \
  1   3
输出: true

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
https://leetcode-cn.com/problems/validate-binary-search-tree */

//注意BST的概念，左子树所有的节点都小于根节点
#include<limits>
using namespace std;
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}	
};
//bool isValidBST(TreeNode* root)
//{
//	 //要记录 子树的最值，不能直接这样子比较
//	 if (root == nullptr || root->left == nullptr && root->right == nullptr)
//		 return true;
//	 bool isLeftNode = false, isRightNode = false;
//	 if (root->left != nullptr)
//	 {
//		 isLeftNode = root->val > root->left->val && isValidBST(root->left);
//		 if (isLeftNode == false) return false;
//	 }
//	 if (root->right != nullptr)
//	 {
//		 isRightNode = root->val < root->right->val && isValidBST(root->right);
//		 if (isRightNode == false) return isRightNode;
//	 }
//	 return true;
//}

//方法不对，看甜姨的题解，竟然几句代码就搞定了，好神奇的思路
//中序遍历，维护最大值，将最大值放在引用里传递
//中序遍历，先判断左子树且找到左子树的max，max和根节点值比较并更新，然后判断右子树
bool InOrder(TreeNode* root, long &pre)
{
	if (root == nullptr) return true;
	if (!InOrder(root->left, pre)) return false;
	if (root->val <= pre) return false;
	pre = root->val;
	return InOrder(root->right, pre);
}
bool isVaildBST(TreeNode* root)
{
	long pre = LONG_MIN;
	return InOrder(root, pre);
}
/*
输入:
  5
 / \
 1  6
/ \
0  7
*/
//有点疑惑，怎么不考虑左边的最大值呢，明白了，pre维护的就是最大值
int main()
{
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(1);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(6);
	bool ans = isVaildBST(root);
	return 0;

}







