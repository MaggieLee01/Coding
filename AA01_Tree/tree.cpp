//���ı������ݹ�ǵݹ飬 �Ѿ�ͨ��LeetCode����
#include<iostream>
#include<stack>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int m) : val(m), right(nullptr), left(nullptr) {}
};

//void PrintPreOrder(TreeNode* root)
//{
//	stack<TreeNode*> stk;
//	if (root == nullptr) return;
//	stk.push(root);
//	while (stk.size())
//	{
//		TreeNode* top = stk.top();
//		std::cout << top->val << " ";
//
//		if (top->left != nullptr)
//			stk.push(top->left);
//		else
//		{
//			//��ӡ֮�����������������Ȼ�ڶ��α���
//			//stk.pop();
//			if (top->right != nullptr)
//				stk.push(top->right);
//		}
//	}
//}

//����Ҷ��Ĵ����
vector<int> preorderTraversal(TreeNode* root)
{
	if (root == nullptr)
		return {};
	stack<TreeNode*> stk;
	vector<int> vec;
	stk.push(root);
	while (stk.size())
	{
		TreeNode* top = stk.top();
		//��ӡ֮�����������������Ȼ�ڶ��α���
		stk.pop();
		vec.push_back(top->val);
		//Ӧ������������ջ��Ȼ������������ȳ�ջ
		if (top->right != nullptr)
			stk.push(top->right);
		if (top->left != nullptr)
			stk.push(top->left);
	}
	return vec;
}

//vector<int> inorderTraversal(TreeNode* root)
//{
//	if (root == nullptr) return {};
//	vector<int> vec;
//	stack<TreeNode*> stk;
//	stk.push(root);
//	while (stk.size())
//	{	
//		if (root->left != nullptr)
//		{
//			stk.push(root->left);
//			root = root->left;
//		}		
//		else
//		{
//			TreeNode *top = stk.top();
//			vec.push_back(top->val);
//			stk.pop();
//			if (top->right != nullptr)
//				stk.push(top->right);
//			root = stk.top();
//		}
//	}
//	return vec;
//}

//����  �޸�
vector<int> inorderTraversal(TreeNode* root)
{
	if (root == nullptr) return {};
	vector<int> vec;
	stack<TreeNode*> stk;
	while (stk.size() || root != nullptr)
	{
		if (root != nullptr)
		{
			stk.push(root);
			root = root->left;
		}
		else
		{
			TreeNode *top = stk.top();
			vec.push_back(top->val);
			stk.pop();
			root = top->right;
		}
	}
	return vec;
}
//�������
//����ǵݹ������ѹ�Һ�ѹ����ջ�õ������ҵģ���ѹջ˳�����Ϊ��ѹ���ѹ�ҿɱ�Ϊ�������ٰѽ������һ��ջ�У���󵯳��͵õ������еĺ��������
vector<int> postorderTraversal(TreeNode* root)
{
	if (root == nullptr)
		return {};
	vector<int> vec;
	stack<TreeNode*> stk1;
	stack<TreeNode*> stk2;
	stk1.push(root);
	while (stk1.size())
	{
		root = stk1.top();
		stk2.push(root);
		stk1.pop();
		if (root->left != nullptr)
			stk1.push(root->left);
		if (root->right != nullptr)
			stk1.push(root->right);
	}
	while (stk2.size())
	{
		root = stk2.top();
		vec.push_back(root->val);
		stk2.pop();
	}
	return vec;
}

//����һ���߼��ģ����ֱ���ͨ�õķ����������Ҽ���������Ľⷨ��̫�����ˡ�
// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/mo-fang-di-gui-zhi-bian-yi-xing-by-sonp/
vector<int> preorderTraversal_1(TreeNode* root)
{
	if (root == nullptr) return {};
	stack<TreeNode*> stk;
	vector<int> vec;
	stk.push(root);
	while (stk.size())
	{
		TreeNode* top = stk.top();
		stk.pop();		//����֮����������
		if (top != nullptr)
		{
			if (top->right != nullptr)
				stk.push(top->right);
			if (top->left != nullptr)
				stk.push(top->left);
			//��Ϊÿ���ڵ㱻�������Σ��ڶ���ѹ��
			stk.push(top);
			stk.push(nullptr);
		}
		else
		{
			//�ѵ�����Ϊ��ָ�룬֤������ջ���Ľڵ�Ϊ�ѱ����ʹ�
			vec.push_back(stk.top()->val);
			stk.pop();
		}
	}
	return vec;
}
vector<int> postorderTraversal_1(TreeNode* root)
{
	if (root == nullptr) return {};
	vector<int> vec;
	stack<TreeNode*> stk;
	stk.push(root);
	while (stk.size())
	{
		TreeNode* top = stk.top();
		stk.pop();
		if (top != nullptr)
		{
			//ֻ��ı���ڵ��ѹ��˳�򼴿�
			stk.push(top);
			stk.push(nullptr);
			if (top->right != nullptr) stk.push(top->right);
			if (top->left != nullptr) stk.push(top->left);
		}
		else
		{
			vec.push_back(stk.top()->val);
			stk.pop();
		}
	}
	return vec;
}

//���������߶�
int maxDepth(TreeNode* root)
{
	if (root == nullptr) return 0;
	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

//��֤�������������ݹ�ǰ������ķ�������¼max��min
//https://leetcode-cn.com/problems/validate-binary-search-tree/
bool helper(TreeNode* root, int lower, int upper)
{
	if (root == nullptr) return true;
	if (root->val <= lower || root->val >= upper) return false;
	return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
}
bool isValidBST(TreeNode* root)
{
	return helper(root, LONG_MIN, LONG_MAX);
}

//��֤��������������������ķ�����ʹ��������
bool isValidBST01(TreeNode* root)
{
	if (root == nullptr) return true;
	stack<TreeNode*> stk;
	int last = INT_MIN;
	stk.push(root);
	while (stk.size())
	{
		TreeNode* top = stk.top();
		stk.pop();		//����֮����������
		if (top != nullptr)
		{
			if (top->right != nullptr) stk.push(top->right);
			//��Ϊÿ���ڵ㱻�������Σ��ڶ���ѹ��
			stk.push(top);
			stk.push(nullptr);
			if (top->left != nullptr)  stk.push(top->left);
		}
		else
		{
			//�ѵ�����Ϊ��ָ�룬֤������ջ���Ľڵ�Ϊ�ѱ����ʹ�
			if (last >= stk.top()->val) return false;
			last = stk.top()->val;
			stk.pop();
		}
	}
	return true;
}


//�ж�ƽ����
int helphigh(TreeNode* root)
{
	if (root == nullptr) return 0;
	int left = helphigh(root->left);
	if (left == -1) return -1;
	int right = helphigh(root->right);
	if (right == -1) return -1;
	if (abs(left - right) <= 1)
		return max(left, right) + 1;
	else
		return -1;
}
bool isBalanced(TreeNode* root)
{
	return helphigh(root) != -1;
}


//��ת����
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int m) :val(m), next(nullptr) {}
};
ListNode*  rev(ListNode* node)
{
	if (node == nullptr)
		return nullptr;
	ListNode* pre = nullptr;
	ListNode* cur = node;
	while (cur != nullptr)
	{
		ListNode* temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	return pre;
}

//��֤���������� ûд��
//bool Search(TreeNode *root)
//{
//	pair ans;
//	if (root == nullptr) return true;
//	auto pair_left = Search(root->left);
//	auto pair_right = Search(root->right);
//	
//	if (pair_left.isSearch && pair_right.isSearch)
//	{
//		ans.isSearch = pair_left.max < root->val < pair_right.min;
//		ans.max = pair_right.max;
//		ans.min = pair_left.min;
//	}
//	else
//		ans.isSearch = false;
//	return ans;
//}
//
//int Getmax(TreeNode* root)
//{
//	if (root != nullptr) return 0;
//	int left = INT_MIN;
//	left = max(left, Getmax(root->left));
//	right = min(right, )
//}
//struct bst
//{
//	bool isvaild;
//	int maxval;
//	int minval;
//};
//bst isValidBST1(TreeNode* root)
//{
//	bst ans;
//	if (root->left == nullptr && root->right == nullptr)
//	{
//		ans.isvaild = true;
//		ans.minval = root->val;
//		ans.maxval = root->val;
//		return ans;
//	}
//	auto left = isValidBST1(root->left);
//	auto right = isValidBST1(root->right);
//
//	if (left.isvaild && right.isvaild)
//	{
//		ans.isvaild = left.maxval < root->val && root->val < right.minval;
//		ans.maxval = right.maxval;
//		ans.minval = left.minval;
//	}
//	else
//		ans.isvaild = false;
//	return ans;
//}
//bool isValidBST(TreeNode* root)
//{
//	if (root == nullptr) return true;
//	return isValidBST1(root).isvaild;
//}




int main(void)
{
	ListNode* p1 = new ListNode(1);
	p1->next = new ListNode(2);
	p1->next->next = new ListNode(3);
	ListNode *p4 = rev(p1);
	return 0;
}