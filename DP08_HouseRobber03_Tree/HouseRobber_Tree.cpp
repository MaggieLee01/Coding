//��ҽ���ϵ������03�����з��ݵ�����������һ�ö��������� �������ֱ�������ķ�����ͬһ�����ϱ���٣����ݽ��Զ�������
//֮ǰ��˼ά����������һ���Ǹ����໥����ֻҪ���ڵ㲻���ӽڵ�ͬʱ�����ټ���

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

//��ʱ���򵥲�������ͨ��
int rob_recursively(TreeNode* root)
{
	//�ݹ�Ѱ�ҽ�ֹ����
	if (root == nullptr) return 0;
	int doNot = 0, doIt = root->val, ans = 0;
	//�����ٸ��ڵ�
	doNot =  rob_recursively(root->left) + rob_recursively(root->right);
	//���ٸ��ڵ㣬Ȼ����ɵ�������
	if (root->left != nullptr)
		doIt = doIt + rob_recursively(root->left->left) + rob_recursively(root->left->right);
	if (root->right != nullptr)
		doIt = doIt + rob_recursively(root->right->left)+rob_recursively(root->right->right);
	ans=max(doNot, doIt);
	return ans;
}

//����¼����������ѭ������
//��˼���޷��������¼ʱ�����˴𰸣�ʹ����map����
//��ʼ���ԽӴ�map�������ݽṹ���Ѿ�ͨ��LeetCode����������
unordered_map<TreeNode*, int> Dict;
int rob_Dict(TreeNode* root)
{
	if (root == nullptr) return 0;
	auto isExist = Dict.find(root);
	if (isExist != Dict.end()) return isExist->second;

	int doNot = 0, doIt = root->val, ans = 0;
	//�����ٸ��ڵ�
	doNot = rob_Dict(root->left) + rob_Dict(root->right);
	//���ٸ��ڵ㣬Ȼ����ɵ�������
	if (root->left != nullptr)
		doIt = doIt + rob_Dict(root->left->left) + rob_Dict(root->left->right);
	if (root->right != nullptr)
		doIt = doIt + rob_Dict(root->right->left) + rob_Dict(root->right->right);
	ans = max(doNot, doIt);
	Dict.emplace(root, ans);
	return ans;	
}

//�����Ƽ�������˼·����������
//�趨���β�dp�洢����root �� ������ root ��������ֵ��Ȼ�󷵻ظ��β�
//dp[0]��ʾ�����ٸ÷��䣬dp[1]��ʾ������һ��

//������д���ԣ���Ȼ�кܶ��ظ�������
//������û�г�ַ��Ӷ��ڴ�����ã����ڴ�Ӧ���𵽼������ã���Ӧ�õݹ��ظ�������
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

//��ͨ��LeetCode����
//�ٿ���д���룬�����Լ���������û�г�ַ��ӷ�������Ĺ��ܣ��������Ѿ��������� �� ������ ��ȫ������
int* rob_Opt(TreeNode* root)
{
	//int *ans = new int[2]();  ���� Ĭ��Ϊ0 
	int *ans = new int[2]{ 0,0 }; //���������ӳ�ʼ��
	//int *ans = new int[2](0); ���벻ͨ�� ��������
	
	if (root != nullptr)
	{
		int *left = rob_Opt(root->left);
		int *right = rob_Opt(root->right);
		//[0]��ʾ���ٸ÷��䣬[1]��ʾ�����ٸ÷���
		//���ٸ÷���ʱ���¸����䲻�����ˣ���left right ������������
		ans[0] = root->val + left[1] + right[1];
		//�����ٸ÷���ʱ���¸����������Ҳ���Բ�������ȡ���ֵ
		//֮ǰ��˼ά����������һ���Ǹ����໥����ֻҪ���ڵ㲻���ӽڵ�ͬʱ�����ټ���
		//doNot = left[1] + right[1];
		ans[1] = max(left[0], left[1]) + max(right[0], right[1]);
	}
	//Ӧ��delete left right ��
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