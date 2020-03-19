//��ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ����һ�ö����������ľ���һ������ô���ǶԳƵġ�
//https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int m) :val(m), left(nullptr), right(nullptr) {}
};

//��ҳ�༭һ��ɣ����ڽ�����д�ݹ�
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

//������⣬�ǵݹ�汾�ģ���ջ���߶���