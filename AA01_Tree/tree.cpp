//树的遍历，递归非递归， 已经通过LeetCode测试
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
//			//打印之后必须立即弹出，不然第二次遍历
//			//stk.pop();
//			if (top->right != nullptr)
//				stk.push(top->right);
//		}
//	}
//}

//看着叶神的代码改
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
		//打印之后必须立即弹出，不然第二次遍历
		stk.pop();
		vec.push_back(top->val);
		//应该右子树先入栈，然后才能左子树先出栈
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

//看答案  修改
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
//后序遍历
//先序非递归版是先压右后压左入栈得到中左右的，把压栈顺序调整为先压左后压右可变为中右左，再把结果放入一个栈中，最后弹出就得到左右中的后序遍历。
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

//看到一个高级的，三种遍历通用的方法，这是我见过的最秀的解法，太厉害了。
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
		stk.pop();		//访问之后立即弹出
		if (top != nullptr)
		{
			if (top->right != nullptr)
				stk.push(top->right);
			if (top->left != nullptr)
				stk.push(top->left);
			//因为每个节点被遍历两次，第二次压入
			stk.push(top);
			stk.push(nullptr);
		}
		else
		{
			//已弹出的为空指针，证明现在栈顶的节点为已被访问过
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
			//只需改变根节点的压入顺序即可
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

//求树的最大高度
int maxDepth(TreeNode* root)
{
	if (root == nullptr) return 0;
	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

//验证二叉搜索树，递归前序遍历的方法，记录max，min
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

//验证二叉搜索树，中序遍历的方法，使保持升序
bool isValidBST01(TreeNode* root)
{
	if (root == nullptr) return true;
	stack<TreeNode*> stk;
	int last = INT_MIN;
	stk.push(root);
	while (stk.size())
	{
		TreeNode* top = stk.top();
		stk.pop();		//访问之后立即弹出
		if (top != nullptr)
		{
			if (top->right != nullptr) stk.push(top->right);
			//因为每个节点被遍历两次，第二次压入
			stk.push(top);
			stk.push(nullptr);
			if (top->left != nullptr)  stk.push(top->left);
		}
		else
		{
			//已弹出的为空指针，证明现在栈顶的节点为已被访问过
			if (last >= stk.top()->val) return false;
			last = stk.top()->val;
			stk.pop();
		}
	}
	return true;
}


//判断平衡性
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


//翻转链表
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

//验证二叉搜索树 没写对
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