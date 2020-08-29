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
/*����һ����������һ��Ŀ��ͣ��жϸ������Ƿ���ڸ��ڵ㵽Ҷ�ӽڵ��·��������·�������нڵ�ֵ��ӵ���Ŀ��͡�
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣*/

//Ϊʲô���ǲ����Լ�д��
//�ݹ��ж�������Ŀ����Ƿ�Ϊsum - root->vals
bool hasPathSum(TreeNode* root, int sum)
{
	if (root == nullptr) return false;
	if (root->left == nullptr && root->right == nullptr) 
		return sum == root->val;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

//bfs�ķ��� ���ϱ���ڵ��ֵ
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


//����һ�����������������дӸ��ڵ㵽Ҷ�ӽڵ��·��
//https://leetcode-cn.com/problems/binary-tree-paths/
//����������ŵĻ��ݷ�������һ���Ѿ���֤�˵ݹ����Ԫ�طǿգ������´εݹ�֮ǰ�жϼ���
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

//�ȵݹ����жϣ�ע������������ã����ҽڵ�ݹ��ʱ���ܻ���Ӱ�죬���Բ�������
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

/*����һ����������һ��Ŀ��ͣ��ҵ����дӸ��ڵ㵽Ҷ�ӽڵ�·���ܺ͵��ڸ���Ŀ��͵�·����*/
//https://leetcode-cn.com/problems/path-sum-ii/
//�������鷳һЩ��������ѹ������������ݹ�֮ǰҪ����
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

//ò�Ƶݹ�֮���жϱȽϷ���
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

/*����һ��������������ÿ����㶼�����һ������ֵ���ҳ�·���͵��ڸ�����ֵ��·��������
·������Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����������·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩��
https://leetcode-cn.com/problems/path-sum-iii */
//https://leetcode-cn.com/problems/path-sum-iii/solution/c-xian-xu-bian-li-di-gui-fang-fa-yu-fei-di-gui-fan/

//�򵥵ķ�����ʱ�临�ӶȽϸ�
int helper(TreeNode*root, int sum)
{
	if (root == nullptr) return 0;
	sum -= root->val;
	return (sum == 0 ? 1 : 0) + helper(root->left, sum) + helper(root->right, sum);
}
//��ÿ���ڵ�Ϊ���ڵ㣬����һ��·����Ϊsum���м�����Ȼ�������
int pathSum_noroot(TreeNode* root, int sum) 
{
	if (root == nullptr) return 0;
	return helper(root, sum) + pathSum_noroot(root->left, sum) + pathSum_noroot(root->right, sum);
}

//����ڵ�͵ķ���,ע����ݷ����Ļ���
void helper01(TreeNode* root, unordered_map<int, int>&prefix, int &res, int sum,int cur_sum)
{
	if (root == nullptr) return;
	cur_sum += root->val;
	//ע������ط���Ӧ����cur_sum - sum��ֻ�������ӣ������ҵ��м��Ϊsum��һ��
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
