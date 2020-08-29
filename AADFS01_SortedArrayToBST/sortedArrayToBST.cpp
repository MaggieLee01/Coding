/*
	��һ�������������е��������飬ת��Ϊһ�ø߶�ƽ�������������
	�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1��
*/
//https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
//���ж��ֽ��
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
//�����̵���⣬���
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

//��������תΪBST
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
	ListNode* pre = nullptr;	//�������Ҫ���ݹ�ʱҪ�ض�����
	while (hi != nullptr && hi->next != nullptr)
	{
		pre = lo;
		lo = lo->next;
		hi = hi->next->next;
	}
	pre->next = nullptr;		//ȡ�������ǰһ�룬loΪ���εĿ�ͷ

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