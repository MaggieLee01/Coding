/*给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree */

//不是搜索树的话，麻烦一点，有后序遍历方法，有通过回溯法寻找路径，然后寻找公共最远路径，还没来得及看
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* ans;
//后序遍历，先判断左右子树，然后判断根节点
bool dfs(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == nullptr) return false;
	bool lson = dfs(root->left, p, q);
	bool rson = dfs(root->right, p, q);
	if (lson && rson || ((p->val == root->val || q->val == root->val) && (lson || rson)))
		ans = root;
	return (lson || rson || (root->val == p->val || root->val == q->val));
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	dfs(root, p, q);
	return ans;
}

//类似的写法，背这个吧，简单一些
//https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/mian-shi-ti-68-ii-er-cha-shu-de-zui-jin-gong-gon-7/
TreeNode* lowestCommonAncestor01(TreeNode* root, TreeNode* p, TreeNode* q)
{
	//这个截止条件很重要，判断root 是不是 q 或者 p的祖先
	if (root == nullptr || root == q || root == p) return root;
	TreeNode* left = lowestCommonAncestor01(root->left, p, q);
	TreeNode* right = lowestCommonAncestor01(root->right, p, q);
	if (left == nullptr) return right;
	if (right == nullptr) return left;
	return root;
}

int main(void)
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	root->left->left->left = new TreeNode(8);
	root->left->left->right = new TreeNode(9);
	root->left->right->left = new TreeNode(10);
	root->left->right->right = new TreeNode(11);
	root->right->left->left = new TreeNode(12);
	root->right->left->right = new TreeNode(13);
	root->right->right->left = new TreeNode(14);
	root->right->right->right = new TreeNode(15);
	lowestCommonAncestor01(root, root->left->left->right, root->left->right->right);
	return 0;
}
