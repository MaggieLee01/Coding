/* 请完成一个函数，输入一个二叉树，该函数输出它的镜像。*/
//https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
struct TreeNode
{ 
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int m):val(m),left(nullptr),right(nullptr){}
};
//网页编辑一遍成，终于渐渐会写递归
TreeNode* mirrorTree(TreeNode* root)
{
	if (root == nullptr) return nullptr;
	TreeNode *mirror = new TreeNode(root->val);
	mirror->left = mirrorTree(root->right);
	mirror->right = mirrorTree(root->left);
	return mirror;
}
//看了题解，非递归版本的，用栈或者队列；递归版本的大多都是在原树上操作，没有新建节点