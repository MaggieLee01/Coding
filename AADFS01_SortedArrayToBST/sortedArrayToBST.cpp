/*
	将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
	本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
*/
//https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
//会有多种结果
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode 
 {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//看甜姨的题解，简洁
TreeNode* dfs(vector<int>& nums, int lo, int hi)
{
	if (lo > hi) return nullptr;
	int mid = (hi - lo) / 2 + lo;
	TreeNode* root = new TreeNode(nums[mid]);
	root->left = dfs(nums, lo, mid - 1);
	root->right = dfs(nums, mid + 1, hi);
	return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) 
{
	return dfs(nums, 0, nums.size() - 1);
}

//有序链表转为BST
//https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

TreeNode* sortedListToBST(ListNode* head) 
{
	if (head == nullptr) return nullptr;
	if (head->next == nullptr)	
		return new TreeNode(head->val);
	ListNode* lo = head;
	ListNode* hi = head;
	ListNode* pre = nullptr;	//这个很重要，递归时要截断链表
	while (hi != nullptr && hi->next != nullptr)
	{
		pre = lo;
		lo = lo->next;
		hi = hi->next->next;
	}
	pre->next = nullptr;		//取了链表的前一半，lo为后半段的开头

	TreeNode* root = new TreeNode(lo->val);
	root->left = sortedListToBST(head);
	root->right = sortedListToBST(lo->next);
	return root;
}
int main(void)
{
	vector<int> nums = { -10,-3,0,5,9 };
	sortedArrayToBST(nums);
	return 0;
}