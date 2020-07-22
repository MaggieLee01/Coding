//����һ�ö������ĸ��ڵ㣬�жϸ����ǲ���ƽ������������ĳ������������ڵ���������������������1����ô������һ��ƽ���������
//ע�����ƽ�����ĸ����Ȳ����1
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
//������� + ��֦�����Ӷ� On
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

//������� + �ж���� ���Ӷ����ף������Ӷ� O(NlogN)
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