//打家劫舍系列问题03：所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
//之前的思维误区，并不一定是隔行相互交错，只要父节点不与子节点同时被抢劫即可

#include<iostream>
#include<algorithm>
#include<unordered_map>
using std::cout;
using std::unordered_map;
using std::endl;
using std::max;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {  }
};

//超时，简单测试用例通过
int rob_recursively(TreeNode* root)
{
	//递归寻找截止条件
	if (root == nullptr) return 0;
	int doNot = 0, doIt = root->val, ans = 0;
	//不抢劫根节点
	doNot =  rob_recursively(root->left) + rob_recursively(root->right);
	//抢劫根节点，然后过渡到第三层
	if (root->left != nullptr)
		doIt = doIt + rob_recursively(root->left->left) + rob_recursively(root->left->right);
	if (root->right != nullptr)
		doIt = doIt + rob_recursively(root->right->left)+rob_recursively(root->right->right);
	ans=max(doNot, doIt);
	return ans;
}

//备忘录方法，减少循环次数
//在思考无法用数组记录时，看了答案，使用了map容器
//开始尝试接触map容器数据结构，已经通过LeetCode中文网测试
unordered_map<TreeNode*, int> Dict;
int rob_Dict(TreeNode* root)
{
	if (root == nullptr) return 0;
	auto isExist = Dict.find(root);
	if (isExist != Dict.end()) return isExist->second;

	int doNot = 0, doIt = root->val, ans = 0;
	//不抢劫根节点
	doNot = rob_Dict(root->left) + rob_Dict(root->right);
	//抢劫根节点，然后过渡到第三层
	if (root->left != nullptr)
		doIt = doIt + rob_Dict(root->left->left) + rob_Dict(root->left->right);
	if (root->right != nullptr)
		doIt = doIt + rob_Dict(root->right->left) + rob_Dict(root->right->right);
	ans = max(doNot, doIt);
	Dict.emplace(root, ans);
	return ans;	
}

//作者推荐的巧妙思路，返回数组
//设定，形参dp存储抢劫root 与 不抢劫 root 的两个数值，然后返回该形参
//dp[0]表示不抢劫该房间，dp[1]表示抢劫这一家

//这样子写不对，依然有很多重复子问题
//这样子没有充分发挥堆内存的作用，堆内存应该起到记忆作用，不应该递归重复子问题
//int *rob_Opt(TreeNode *root, int *dp)
//{
//	
//	if (root == nullptr)
//		dp[0] = 0, dp[1] = 0;
//	else
//	{
//		int *leftNew = new int[2];
//		int *left = rob_Opt(root->left, leftNew);
//		int *rightNew = new int[2];
//		int *right = rob_Opt(root->right, rightNew);
//		dp[0] = max(left[0], left[1]) + max(right[0], right[1]);
//
//		dp[1] = root->val;
//		if (root->left != nullptr)
//		{
//			int *leftleftNew = new int[2];
//			int *leftleft = rob_Opt(root->left->left, leftleftNew);
//			int *leftrightNew = new int[2];
//			int *leftright = rob_Opt(root->right, leftrightNew);
//			dp[1] += max(leftleft[0], leftleft[1]) + max(leftright[0], leftright[1]);
//		}
//	}
//}

//已通过LeetCode测试
//再看答案写代码，上面自己的误区，没有充分发挥返回数组的功能，数组中已经包含抢劫 与 不抢劫 的全部数据
int* rob_Opt(TreeNode* root)
{
	//int *ans = new int[2]();  可以 默认为0 
	int *ans = new int[2]{ 0,0 }; //可以这样子初始化
	//int *ans = new int[2](0); 编译不通过 ！！！！
	
	if (root != nullptr)
	{
		int *left = rob_Opt(root->left);
		int *right = rob_Opt(root->right);
		//[0]表示抢劫该房间，[1]表示不抢劫该房间
		//抢劫该房间时，下个房间不能抢了，即left right 不能再抢劫了
		ans[0] = root->val + left[1] + right[1];
		//不抢劫该房间时，下个房间可以抢也可以不抢，求取最大值
		//之前的思维误区，并不一定是隔行相互交错，只要父节点不与子节点同时被抢劫即可
		//doNot = left[1] + right[1];
		ans[1] = max(left[0], left[1]) + max(right[0], right[1]);
	}
	//应该delete left right 吧
	return ans;	
}
int rob(TreeNode *root)
{
	if (root == nullptr) return 0;
	int * temp = rob_Opt(root);
	int ans = max(temp[0], temp[1]);
	return ans;
}

int main(void)
{
	TreeNode *root1= new TreeNode(3);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(3);
	TreeNode *node5 = new TreeNode(1);
	root1->left = node1;
	root1->right = node2;
	node1->right = node4;
	node2->right = node5;
	int ans = rob(root1);
	return ans;
}