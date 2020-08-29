#include<vector>
using namespace std;
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}	
};

//����һ�ö�������һ����������ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·����
//�����ĸ��ڵ㿪ʼ����һֱ��Ҷ�ڵ��������Ľڵ��γ�һ��·����
//https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/

vector<vector<int>> ans;
void backtrace(TreeNode* root, int sum, vector<int> vec, int cur_sum)
{
	if (root == nullptr) return;
	vec.push_back(root->val);
	cur_sum += root->val;
	if (root->left == nullptr &&root->right == nullptr)
	{
		if (cur_sum == sum)
			ans.push_back(vec);
	}
	backtrace(root->left, sum, vec, cur_sum);
	backtrace(root->right, sum, vec, cur_sum);
}
vector<vector<int>> pathSum(TreeNode* root, int sum) 
{
	if (root == nullptr) return {};
	vector<int> vec;
	int cur_sum = 0;
	backtrace(root, sum, vec, cur_sum);
	return ans;
}