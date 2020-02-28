//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//输入：1->2->4, 1->3->4；输出：1->1->2->3->4->4
// https://leetcode-cn.com/problems/merge-two-sorted-lists

//已通过LeetCode 还没来得及看课本答案
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int m):val(m),next(nullptr){}
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
	ListNode *ans = new ListNode(0);
	ListNode *n1 = ans;
	while (l1 != nullptr && l2 != nullptr)
	{
		if (l1->val > l2->val)
		{
			n1->next = l2;
			l2 = l2->next;
		}
		else
		{
			n1->next = l1;
			l1 = l1->next;
		}
		n1 = n1->next;
	}
	if (l1 == nullptr) n1->next = l2;
	if (l2 == nullptr) n1->next = l1;
	return ans->next;
}