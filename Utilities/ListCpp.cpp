// https://leetcode-cn.com/problems/add-two-numbers/solution/cjie-ti-de-wan-zheng-dai-ma-bao-gua-sheng-cheng-ce/
#include<vector>
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int number):val(number),next(nullptr){}
};


ListNode* generateListNode(std::vector<int> vals)
{
	ListNode *ans = new ListNode(0);
	ListNode *head = ans;
	for (auto temp : vals)
	{
		ans->next = new ListNode(temp);
		ans = ans->next;
	}
	ans = head->next;
	delete head;
	head = nullptr;
	return ans;
}
void freeListNode(ListNode* head)
{
	ListNode *ans = new ListNode(0);
	ListNode *temp = ans;
	temp->next = head;
	while (temp != nullptr)
	{

	}

}
void printListNode(ListNode* head)
{

}

