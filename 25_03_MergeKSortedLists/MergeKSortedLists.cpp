//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//https://leetcode-cn.com/problems/merge-k-sorted-lists/

#include<vector>
#include<queue>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
//小根堆的方法
ListNode* mergeKLists(vector<ListNode*>& lists)
{
	auto cmp = [](const ListNode* l1, const ListNode*l2) {return l1->val > l2->val; };
	priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>pq(cmp);
	for (auto list : lists)
	{
		if (list != nullptr)
			pq.push(list);
	}
	ListNode* ans = new ListNode(0);
	ListNode* Head = ans;
	while (pq.size())
	{
		ListNode* node = pq.top();
		pq.pop();
		ans->next = node;
		ans = ans->next;
		if (node->next != nullptr) pq.push(node->next);
	}
	return Head->next;
}

//分治方法比较 合并链表
ListNode* mergeList(ListNode* left, ListNode* right)
{
	if (left == nullptr) return right;
	if (right == nullptr) return left;
	ListNode *pHead = new ListNode(0);
	ListNode *pTemp = pHead;
	while (left != nullptr && right != nullptr)
	{
		if (left->val < right->val)
		{
			pTemp->next = left;
			left = left->next;
		}
		else
		{
			pTemp->next = right;
			right = right->next;
		}
		pTemp = pTemp->next;
	}
	if (left != nullptr) pTemp->next = left;
	if (right != nullptr) pTemp->next = right;
	return pHead->next;
}
ListNode* merge(vector<ListNode*>& lists, int start, int end)
{
	if (start == end)  return lists[end];
	int mid = ((end - start) >> 1) + start;
	ListNode* left = merge(lists, start, mid);
	ListNode* right = merge(lists, mid + 1, end);
	return mergeList(left, right);
}
ListNode* mergeKLists02(vector<ListNode*>& lists)
{
	if (lists.size() == 0) return nullptr;
	return merge(lists, 0, lists.size() - 1);
}


int main(void)
{
	ListNode* top = new ListNode(1);
	top->next = new ListNode(4);
	top->next->next = new ListNode(5);

	ListNode* top1 = new ListNode(1);
	top1->next = new ListNode(3);
	top1->next->next = new ListNode(6);

	ListNode* top2 = new ListNode(2);
	top2->next = new ListNode(6);

	vector<ListNode*> lists{ top, top1, top2 };
	ListNode* ans = mergeKLists02(lists);
	return 0;
}