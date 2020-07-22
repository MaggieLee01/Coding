//输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
//注意理解平衡树的概念，深度不相差1
//https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/

#include<cmath>
#include<algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//后序遍历 + 减枝，复杂度 On
int isBalancedCore(TreeNode *root)
{
	if (root == nullptr)
		return 0;
	int depth1 = isBalancedCore(root->left);
	if (depth1 == -1) return -1;
	int depth2 = isBalancedCore(root->right);
	if (depth2 == -1) return -1;
	if (abs(depth1 - depth2) > 1) return -1;
	return max(depth1, depth2) + 1;
}
bool isBalanced(TreeNode* root)
{
	return isBalancedCore(root) != -1;
}

//先序遍历 + 判断深度 （从顶至底），复杂度 O(NlogN)
int depth(TreeNode* root)
{
	if (root == nullptr) return 0;
	return max(depth(root->left), depth(root->right)) + 1;
}
bool isBalance01(TreeNode* root)
{
	if (root == nullptr) return true;
	return isBalancedCore(root->left) && isBalance01(root->right) && abs(depth(root->left)-depth(root->right));
}