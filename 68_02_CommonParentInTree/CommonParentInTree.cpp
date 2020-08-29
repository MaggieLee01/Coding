/*����һ��������, �ҵ�����������ָ���ڵ������������ȡ�
�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����
���ӣ�https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree */

//�����������Ļ����鷳һ�㣬�к��������������ͨ�����ݷ�Ѱ��·����Ȼ��Ѱ�ҹ�����Զ·������û���ü���
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* ans;
//������������ж�����������Ȼ���жϸ��ڵ�
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

//���Ƶ�д����������ɣ���һЩ
//https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/mian-shi-ti-68-ii-er-cha-shu-de-zui-jin-gong-gon-7/
TreeNode* lowestCommonAncestor01(TreeNode* root, TreeNode* p, TreeNode* q)
{
	//�����ֹ��������Ҫ���ж�root �ǲ��� q ���� p������
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
