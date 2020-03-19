/*	给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。
	给定二叉树

		  1
		 / \
		2   3
	   / \
	  4   5
	返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。注意：两结点之间的路径长度是以它们之间边的数目表示。
	https://leetcode-cn.com/problems/diameter-of-binary-tree */

//网页编辑问题不大，树的简单操作基本掌握
#include<algorithm>
using std::max;
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int ans = 0;
int diameterOfBinaryTreeCore(TreeNode* root)
{
	if (root == nullptr) return -1;
	int left = diameterOfBinaryTreeCore(root->left) + 1;
	int right = diameterOfBinaryTreeCore(root->right) + 1;
	ans = max(ans, left + right);
	return max(left, right);
}
int diameterOfBinaryTree(TreeNode* root)
{
	if (root == nullptr) return 0;
	diameterOfBinaryTreeCore(root);
	return ans;
}
//第一次写也犯了错误，树的直径可以不经过根节点，树的深度要经过根节点
//https://leetcode-cn.com/problems/diameter-of-binary-tree/solution/hot-100-9er-cha-shu-de-zhi-jing-python3-di-gui-ye-/
//看了题解，基本都是这个递归的方法
//细节处理之处，+1的时间问题
int diameterOfBinaryTreeCore_others(TreeNode* root)
{
	if (root == nullptr) return 0;
	int left = diameterOfBinaryTreeCore(root->left) ;
	int right = diameterOfBinaryTreeCore(root->right) ;
	ans = max(ans, left + right);
	return max(left, right) + 1;//在此处加一，则不会出现上面那种多加的情况，此处root一定不为空，所以一定可以加一。
	//上面我写的，root->left在为空的情况下也加1，导致多加了
}

//https://leetcode-cn.com/problems/diameter-of-binary-tree/comments/277575
//很多类似思路的题目