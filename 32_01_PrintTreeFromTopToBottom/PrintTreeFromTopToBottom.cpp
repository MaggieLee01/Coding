#include<vector>
#include<queue>
using std::queue;
using std::vector;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int m):val(m),left(nullptr),right(nullptr){}
};

//在寻找腐烂桔子一题，已经学会了队列完成BFS的方法，同时知道了分层的方法，打印树的前两道题目就显得很简单了
//做完题多看题解，看别人的方法，好的方法学下来

/*从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。*/
vector<int> levelOrder_01(TreeNode* root)
{
	if (root == nullptr) return {};
	vector<int> ans;
	queue<TreeNode *> node;
	node.push(root);
	while (node.size())
	{
		TreeNode *top = node.front();
		node.pop();
		ans.push_back(top->val);
		if (top->left != nullptr)
			node.push(top->left);
		if (top->right != nullptr)
			node.push(top->right);
	}
	return ans;
}

//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
//和上一题相比较，关键点在分层，先提前统计出queue的数量即可
vector<vector<int>> levelOrder_02(TreeNode* root) {
	if (root == nullptr) return {};
	vector<vector<int>> ans;
	queue<TreeNode *> node;
	node.push(root);
	while (node.size())
	{
		vector<int> sub;
		int length = node.size();
		for (int i = 0; i < length; i++)
		{
			TreeNode *top = node.front();
			node.pop();
			sub.push_back(top->val);
			if (top->left != nullptr)
				node.push(top->left);
			if (top->right != nullptr)
				node.push(top->right);
		}
		ans.push_back(sub);
	}
	return ans;
}

//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
//第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。