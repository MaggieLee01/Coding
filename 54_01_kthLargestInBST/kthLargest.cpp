//https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
/*给定一棵二叉搜索树，请找出其中第k大的节点。
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

//看答案递归倒序方法，右中左遍历的顺序，减少了遍历的时间
//这种情况是遍历一次少一个数，所以应该是全局变量或者引用，和回溯法的区别
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