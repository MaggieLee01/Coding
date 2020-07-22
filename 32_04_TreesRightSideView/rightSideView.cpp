/*����һ�ö������������Լ�վ�������Ҳ࣬���մӶ������ײ���˳�򣬷��ش��Ҳ����ܿ����Ľڵ�ֵ��

ʾ��:
����: [1,2,3,null,5,null,4]
���: [1, 3, 4]
����:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

https://leetcode-cn.com/problems/binary-tree-right-side-view */

#include<queue>
#include<vector>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//ֻ���α�����
vector<int> rightSideView(TreeNode* root)
{
	queue<TreeNode* >s;
	if (root == nullptr) return {};
	s.push(root);

	vector<int> ans;
	while (s.size())
	{
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			TreeNode* top = s.front();
			s.pop();
			if (i == n - 1) ans.push_back(top->val);
			if (top->left != nullptr)  s.push(top->left);
			if (top->right != nullptr) s.push(top->right);
		}
	}
	return ans;
}
//���𰸣��еݹ鷨����¼���
void rightSideCore(vector<int>& ans, TreeNode* root, int depth)
{
	if (root == nullptr) return;
	if (depth == ans.size()) ans.push_back(root->val);
	depth++;
	rightSideCore(ans, root->right, depth);
	rightSideCore(ans, root->left, depth);
}
vector<int> rightSideView(TreeNode* root)
{
	if (root == nullptr) return {};
	vector<int> ans;
	rightSideCore(ans, root, 0);
	return ans;
}
