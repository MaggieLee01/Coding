//请实现两个函数，分别用来序列化和反序列化二叉树。
//参考题解：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/solution/c-dui-lie-guan-fang-xu-lie-hua-fang-shi-mian-shi-t/
#include<string>
#include<queue>
#include<sstream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

string serialize(TreeNode* root)
{
	if (root == nullptr) return "";
	ostringstream ostr;
	queue<TreeNode*> q;
	q.push(root);

	while (q.size())
	{
		TreeNode* temp = q.front();
		q.pop();
		if (temp == nullptr)
			ostr << "null ";
		else
		{
			ostr << temp->val << ' ';
			q.push(temp->left);
			q.push(temp->right);
		}
	}
	return ostr.str();
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data)
{
	if (data.size() == 0) return nullptr;
	istringstream input(data);			//流默认以空格分隔
	string val;
	vector<TreeNode *>vec;
	while (input >> val)
	{
		if (val == "null")
			vec.push_back(nullptr);
		else
			vec.push_back(new TreeNode(stoi(val)));
	}
	//注意此处建树的过程值得学习
	int j = 1;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == nullptr) continue;
		if (j < vec.size()) vec[i]->left = vec[j++];
		if (j < vec.size()) vec[i]->right = vec[j++];
	}
	return vec[0];
}

int main(void)
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	//root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	/*root->left->left->left = new TreeNode(8);
	root->left->left->right = new TreeNode(9);*/
	root->left->right->left = new TreeNode(10);
	root->left->right->right = new TreeNode(11);
	root->right->left->left = new TreeNode(12);
	root->right->left->right = new TreeNode(13);
	root->right->right->left = new TreeNode(14);
	root->right->right->right = new TreeNode(15);

	string ans = serialize(root);
	return 0;
}