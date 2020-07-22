/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6
解释: 节点 2 和节点 8 的最近公共祖先是 6。

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。

https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof */

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//递归的写法还是不太熟悉
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == nullptr) return nullptr;
	if (root->val > p->val && root->val > q->val)
		//lowestCommonAncestor(root->left, p, q);		//不知道写返回
		return lowestCommonAncestor(root->left, p, q);
	//else if (root->val < p->val && root->val < q->val)
	if (root->val < p->val && root->val < q->val)
		//lowestCommonAncestor(root->right, p, q);
		return lowestCommonAncestor(root->right, p, q);
	//else
	return root;
}

//迭代法
TreeNode* lowestCommonAncestor01(TreeNode* root, TreeNode* p, TreeNode* q)
{
	//保证p->val > q->val，减少判断
	if (p->val < q->val)
	{
		TreeNode* temp = p;
		p = q;
		q = temp;
	}
	while (root != nullptr)
	{
		if (root->val > p->val)
			root = root->left;
		else if (root->val < q->val)
			root = root->right;
		else break;
	}
	return root;
}