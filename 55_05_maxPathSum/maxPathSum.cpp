//难度困难508给定一个非空二叉树，返回其最大路径和。
//本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
//https://leetcode-cn.com/problems/binary-tree-maximum-path-sum

#include<algorithm>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//参考题解：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-30/
int res = INT_MIN; //可能只有根节点 为负
int helper(TreeNode* root)
{
	if (root == nullptr) return 0;
	int left = max(helper(root->left), 0);
	int right = max(helper(root->right), 0);

	res = max(res, root->val + left + right);
	return root->val + max(left, right);
}
int maxPathSum(TreeNode* root)
{
	helper(root);
	return res;
}