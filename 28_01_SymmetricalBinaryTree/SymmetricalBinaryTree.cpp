//请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
//https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int m) :val(m), left(nullptr), right(nullptr) {}
};

//网页编辑一遍成，终于渐渐会写递归
bool isSymmetricCore(TreeNode* left, TreeNode* right)
{
	if (left == nullptr && right == nullptr) return true;
	if (left == nullptr || right == nullptr) return false;
	return (left->val == right->val) && isSymmetricCore(left->left, right->right) && isSymmetricCore(left->right, right->left);
}
bool isSymmetric(TreeNode* root)
{
	return (root == nullptr) || isSymmetricCore(root->left, root->right);
}

//看了题解，非递归版本的，用栈或者队列