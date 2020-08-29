//难度困难508给定一个非空二叉树，返回其最大路径和。
//本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
//https://leetcode-cn.com/problems/binary-tree-maximum-path-sum


#include<algorithm>
#include<iostream>
#include<unordered_set>
#include<queue>
#include<vector>
#include<string>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//参考题解：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-30/
int res = INT_MIN; //可能只有根节点 为负
int helper(TreeNode* root)
{
	if (root == nullptr) return 0;
	int left = max(helper(root->left), 0);
	int right = max(helper(root->right), 0);

	res = max(res, root->val + left + right);
	return root->val + max(left, right);
}
int maxPathSum(TreeNode* root)
{
	helper(root);
	return res;
}

//
////{1,2,3,4,5,6,8,9,10,12,15,16,18,20,}
//int get_ugly(int n)
//{
//	unordered_set<int> uset;
//	priority_queue<int> pq;
//	pq.push(1);
//	uset.insert(1);
//	while (uset.size() < n)
//	{
//		int minval = pq.top();
//		pq.push(minval * 2);
//		pq.push(minval * 3);
//		pq.push(minval * 5);
//
//		uset.insert(minval * 2);
//		if (uset.size() == n) break;
//		uset.insert(minval * 3);
//		if (uset.size() == n) break;
//		uset.insert(minval * 5);
//	}
//}

//bool cmp(vector<int> vec1, vector<int> vec2)
//{
//	return vec1[0] < vec2[0];
//}
//int main(void)
//{
//	int num = 0;
//	cin >> num;
//	vector<vector<int>> ans;
//	if (num % 2 == 0)
//	{
//		//个位可能借位 也可能不借位
//		int c1 = (num % 10) / 2;
//		int c2 = (num % 10 + 10) / 2;
//
//		//十位不借位
//		int b1 = (num / 10 % 10) - c1;
//		int b2 = (num / 10 % 10) - c2 - 1;
//		int a0 = 0;		
//		if ((num / 100) % 2 == 0)	
//			a0 = num / 100 / 2;
//
//		//十位借位 
//		int a1 = 0;
//		int b11 = (num / 10 % 10) + 10 - c1;
//		int b21 = (num / 10 % 10) + 10 - c2 - 1;
//		if ((num / 100-1) % 2 == 0)
//		{
//			a1 = (num / 100 - 1) / 2;		
//		}
//
//		if (0 < a0 && a0 <= 9 && 0 <= b2 && b2 <= 9 && 0 <= c2 && c2 <= 9 && a0 != b2 && a0 != c2 && b2 != c2)
//			ans.push_back({ a0 * 100 + b2 * 10 + c2,  a0 * 100 + c2 * 10 + c2 });
//
//		if (0 < a0 && a0 <= 9 && 0 <= b1 && b1 <= 9 && 0 <= c1 && c1 <= 9 && a0 != b1 && a0 != c1 && b1 != c1)
//			ans.push_back({ a0 * 100 + b1 * 10 + c1,  a0 * 100 + c1 * 10 + c1 });
//
//		if (0 < a1 && a1 <= 9 && 0 <= b21 && b21 <= 9 && 0 <= c2 && c2 <= 9 && a1 != b21 && a1 != c2 && b21 != c2)
//			ans.push_back({ a1 * 100 + b21 * 10 + c2,  a0 * 100 + c2 * 10 + c2 });
//
//		if (0 < a1 && a1 <= 9 && 0 <= b11 && b11 <= 9 && 0 <= c1 && c1 <= 9 && a1 != b11 && a1 != c1 && b11 != c1)
//			ans.push_back({ a1 * 100 + b11 * 10 + c1,  a0 * 100 + c1 * 10 + c1 });
//
//	}
//	if (ans.size() == 0) cout << '0' << endl;
//	else 
//	{
//		cout << ans.size() << endl;
//		sort(ans.begin(), ans.end(), cmp);
//		for (int i = 0; i < ans.size(); i++)
//			cout << ans[i][0] << " " << ans[i][1] << endl;
//	}
//	return 0;	
//}

//int main(void)
//{
//	int num = 0;
//	cin >> num;
//	vector<long> vec(num*num);
//	vec[0] = 1;
//	vec[1] = 1;
//	for (int i = 2; i < vec.size(); i++)
//	{
//		vec[i] = vec[i - 1] + vec[i - 2];
//	}
//	int k = vec.size() - 1;
//	vector<vector<int>> ans(num, vector<int>(num));
//
//	for (int i = 0; i < num / 2; i++)
//	{
//		for (int j = i; j < num - i; j++)
//		{
//			if (ans[i][j] == 0)
//				ans[i][j] = vec[k--];
//		}
//		for (int j = i+1; j < num - i; j++)
//		{
//			if (ans[j][num - 1 - i] == 0)
//				ans[j][num - 1 - i] = vec[k--];
//		}
//		for (int j = num - 1 - i; j > i; j--)
//		{
//			if (ans[num - 1 - i][j] == 0)
//				ans[num - 1 - i][j] = vec[k--];
//		}
//		for (int j = num - 1 - i; j > i; j--)
//		{
//			if (ans[j][i] == 0)
//				ans[j][i] = vec[k--];
//		}
//	}
//	if(num%2==1) 
//		ans[num / 2][num / 2] = vec[k--];
//	for (int i = 0; i < num; i++)
//	{
//		cout << ans[i][0] ;
//		for (int j = 0; j < num; j++)
//			cout <<  ' '<<ans[i][j] ;
//		cout << endl;
//	}
//	cout << endl;
//	return 0;
//}

//int main(void)
//{
//	int M = 0, N = 0;
//	cin >> M >> N;
//	vector<vector<int>> vec(M, vector<int>(N));
//	for (int i = 0; i < M; i++)
//		for (int j = 0; j < N; j++)
//			cin >> vec[i][j];
//	cout << "NO" << endl;
//	return 0;
//}


//米哈游 分数运算 已AC
//int gcd(int a, int b)
//{
//	if (a == 0) return b;
//	else
//		return gcd(b%a, a);
//}
//int main(void)
//{
//	string str;
//	cin >> str;
//	int up1 = str[0]-'0';
//	int down1 = str[2] - '0';
//	cin >> str;
//	char s = str[0];
//	cin >> str;
//	int up2 = str[0] - '0';
//	int down2 = str[2] - '0';
//	int down = 0;
//	int up = 0;
//		
//	if (s == '+' || s == '-')
//	{
//		if (down1 < down2) swap(down1, down2);
//		int comm = gcd(down1, down2);
//		down = down1 * down2 / comm;
//		if (s == '+')
//			up = (up1 * down2 + up2 * down1 ) /comm;
//		if (s == '-')
//			up = (up1 * down2 - up2 * down1) / comm;
//	}
//	if (s == '*')
//	{
//		down = down1 * down2;
//		up = up1 * up2;
//	}
//	if (s == '/')
//	{
//		down = down1 * up2;
//		up = up1 * down2;
//	}
//
//	int result_comm = 0;
//	if (down > up)	
//		result_comm = gcd(down, up);
//	else
//		result_comm = gcd(up, down);
//	if (result_comm < 0) 
//		result_comm = -result_comm;
//	if (result_comm != 1)
//	{
//		down = down / result_comm;
//		up = up / result_comm;
//	}
//	
//	string ans;	
//	ans += to_string(up);
//	if (down != 1)
//	{
//		ans += '/';
//		ans += to_string(down);
//	}
//	cout << ans << endl;
//	return 0;
//}