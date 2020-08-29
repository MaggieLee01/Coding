//https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
/*����һ�ö��������������ҳ����е�k��Ľڵ㡣
*/

#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int kthLargest(TreeNode* root, int k) 
{
	if (root == nullptr) return -1;
	stack<TreeNode*> stk;
	vector<int> vec;
	stk.push(root);

	while (stk.size())
	{
		TreeNode* temp = stk.top();
		stk.pop();
		if (temp != nullptr)
		{
			if (temp->right != nullptr)
				stk.push(temp->right);
			stk.push(temp);
			stk.push(nullptr);
			if (temp->left != nullptr)
				stk.push(temp->left);
		}
		else
		{
			int ans = stk.top()->val;
			vec.push_back(ans);
			stk.pop();
		}
	}
	if (vec.size() >= k)
		return vec[vec.size() - k];
	return -1;
}

//���𰸵ݹ鵹�򷽷��������������˳�򣬼����˱�����ʱ��
//��������Ǳ���һ����һ����������Ӧ����ȫ�ֱ����������ã��ͻ��ݷ�������
int res = 0, n = 0;
void dfs(TreeNode* root)
{
	if (root == nullptr || n == 0) return;
	dfs(root->right);
	if (--n == 0)
	{
		res = root->val;
		return;
	}
	dfs(root->left);
}
int kthLargest(TreeNode* root, int k)
{
	n = k;
	dfs(root);
	return res;
}