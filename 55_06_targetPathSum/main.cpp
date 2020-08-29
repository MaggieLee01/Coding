#include<queue>
#include<string>
#include<unordered_map>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//https://leetcode-cn.com/problems/path-sum/
/*给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
说明: 叶子节点是指没有子节点的节点。*/

//为什么就是不会自己写呢
//递归判断子树的目标和是否为sum - root->vals
bool hasPathSum(TreeNode* root, int sum)
{
	if (root == nullptr) return false;
	if (root->left == nullptr && root->right == nullptr) 
		return sum == root->val;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

//bfs的方法 不断保存节点和值
bool hasPathSum_01(TreeNode* root, int sum)
{
	if (root == nullptr) return false;
	if (root->left == nullptr && root->right == nullptr)
		return sum == root->val;
	queue<TreeNode*> que_node;
	queue<int> que_val;
	que_node.push(root);
	que_val.push(root->val);
	while (que_node.size())
	{
		int temp = que_val.front();
		TreeNode* tempnode = que_node.front();
		que_node.pop();
		que_val.pop();
		if (tempnode->left == nullptr && tempnode->right == nullptr)
		{
			if (temp == sum) return true;
			continue;
		}
		if (tempnode->left != nullptr)
		{
			que_node.push(tempnode->left);
			que_val.push(temp + tempnode->left->val);
		}
		if (tempnode->right != nullptr)
		{
			que_node.push(tempnode->right);
			que_val.push(temp + tempnode->right->val);
		}
	}
	return false;
}


//给定一个二叉树，返回所有从根节点到叶子节点的路径
//https://leetcode-cn.com/problems/binary-tree-paths/
//借鉴生成括号的回溯方法，第一次已经保证了递归参数元素非空，所以下次递归之前判断即可
vector<string> ans;
void dfs(TreeNode* root, const string& str)
{
	if (root->left == nullptr && root->right == nullptr)
	{
		ans.push_back(str);
		return;
	}
	if (root->left != nullptr)
		dfs(root->left, str + "->" + to_string(root->left->val));
	if (root->right != nullptr)
		dfs(root->right, str + "->" + to_string(root->right->val));
}
vector<string> binaryTreePaths(TreeNode* root)
{
	if (root == nullptr) return {};
	dfs(root, to_string(root->val));
	return ans;
}

//先递归再判断，注意参数不是引用，左右节点递归的时候不能互相影响，所以不能引用
vector<string> ans01;
void dfs01(TreeNode* root,  string str)
{
	if (root == nullptr) return;
	str += to_string(root->val);
	if (root->left == nullptr && root->right == nullptr)
	{
		ans01.push_back(str);
		return;
	}
	str += "->";
	dfs01(root->left, str );
	dfs01(root->right, str );
}
vector<string> binaryTreePaths01(TreeNode* root)
{
	string str;
	dfs01(root, str);
	return ans01;
}

/*给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。*/
//https://leetcode-cn.com/problems/path-sum-ii/
//这种略麻烦一些，左子树压入后在右子树递归之前要弹出
vector<vector<int>> ans02;
void dfs_02(TreeNode* root, vector<int> vec, int sum)
{
	if (root->left == nullptr && root->right == nullptr)
		if (sum == 0)
			ans02.push_back(vec);
	if (root->left != nullptr)
	{
		vec.push_back(root->left->val);
		dfs_02(root->left, vec, sum - root->left->val);
		vec.pop_back();
	}
	if (root->right != nullptr)
	{
		vec.push_back(root->right->val);
		dfs_02(root->right, vec, sum - root->right->val);
		vec.pop_back();
	}
}
vector<vector<int>> pathSum_fromroot(TreeNode* root, int sum) 
{
	if (root == nullptr) return {};
	vector<int> vec;
	vec.push_back(root->val);
	dfs_02(root, vec, sum - root->val);
	return ans02;
}

//貌似递归之后判断比较方便
vector<vector<int>> ans03;
void dfs_03(TreeNode* root, vector<int> vec, int sum)
{
	if (root == nullptr) return;
	vec.push_back(root->val);
	sum -= root->val;
	if (root->left == nullptr && root->right == nullptr)
		if (sum == 0)
			ans03.push_back(vec);	
	dfs_03(root->left, vec, sum);
	dfs_03(root->right, vec, sum);
}
vector<vector<int>> pathSum_fromroot01(TreeNode* root, int sum)
{
	vector<int> vec;
	dfs_03(root, vec, sum);
	return ans03;
}

/*给定一个二叉树，它的每个结点都存放着一个整数值。找出路径和等于给定数值的路径总数。
路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
https://leetcode-cn.com/problems/path-sum-iii */
//https://leetcode-cn.com/problems/path-sum-iii/solution/c-xian-xu-bian-li-di-gui-fang-fa-yu-fei-di-gui-fan/

//简单的方法，时间复杂度较高
int helper(TreeNode*root, int sum)
{
	if (root == nullptr) return 0;
	sum -= root->val;
	return (sum == 0 ? 1 : 0) + helper(root->left, sum) + helper(root->right, sum);
}
//以每个节点为根节点，都算一遍路径和为sum的有几条，然后加起来
int pathSum_noroot(TreeNode* root, int sum) 
{
	if (root == nullptr) return 0;
	return helper(root, sum) + pathSum_noroot(root->left, sum) + pathSum_noroot(root->right, sum);
}

//保存节点和的方法,注意回溯方法的回退
void helper01(TreeNode* root, unordered_map<int, int>&prefix, int &res, int sum,int cur_sum)
{
	if (root == nullptr) return;
	cur_sum += root->val;
	//注意这个地方，应该是cur_sum - sum，只有这样子，才能找到中间和为sum的一段
	//int find_sum = sum - cur_sum;
	int find_sum = cur_sum - sum;
	if (prefix.find(find_sum) != prefix.end()) 
	{
		res += prefix[find_sum];
	}
	prefix[cur_sum]++;
	helper01(root->left, prefix, res, sum, cur_sum);
	helper01(root->right, prefix, res, sum, cur_sum);
	prefix[cur_sum]--;	
}
int pathSum_noroot01(TreeNode* root, int sum)
{
	if (root == nullptr) return 0;
	unordered_map<int, int>prefix;
	prefix[0] = 1;
	int res = 0;
	helper01(root, prefix, res, sum, 0);
	return res;
}
int main(void)
{
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(-2);
	root->left->right = new TreeNode(2);
	root->left->right->right = new TreeNode(1);
	root->right = new TreeNode(-3);
	root->right->right = new TreeNode(11);
	int ans = pathSum_noroot01(root,8);
	return 0;
}
