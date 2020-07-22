//�Ѷ�����508����һ���ǿն����������������·���͡�
//�����У�·��������Ϊһ������������ڵ�������ﵽ����ڵ�����С���·�����ٰ���һ���ڵ㣬�Ҳ�һ���������ڵ㡣
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


//�ο���⣺https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-30/
int res = INT_MIN; //����ֻ�и��ڵ� Ϊ��
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