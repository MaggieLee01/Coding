//反转一个单链表。输入: 1->2->3->4->5->NULL;	输出 : 5->4->3->2->1->NULL
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int n) :val(n), next(nullptr) {}
};
//迭代法
ListNode *ReverceList(ListNode *head)
{
	ListNode *pre = nullptr;
	ListNode *curr = head;
	while (curr != nullptr)
	{
		ListNode *temp = curr->next;
		curr->next = pre;
		pre = curr;
		curr = temp;
	}
	return pre;
}
//递归法
ListNode *Tail = nullptr;
ListNode *ReverceList_ReCore(ListNode *head)
{
	if (head == nullptr) 
		return nullptr;
	if (head->next == nullptr)
	{
		Tail = head;//尾结点成为新的头节点
		return head;
	}		
	ListNode *temp = ReverceList_ReCore(head->next);
	head->next = nullptr;//清除原来的指向，使其成为反转链表的尾结点
	temp->next = head;//指针反转
	return head;
}
ListNode *ReverceList_Re01(ListNode *head)
{
	ReverceList_ReCore(head);
	return Tail;
}
//答案上的递归方法
ListNode *ReverceList_Re02(ListNode *head)
{
	if (head == nullptr || head->next == nullptr) return head;
	ListNode *ans = ReverceList_Re02(head->next);
	head->next->next = head;
	head->next = nullptr;
	return ans;
}
int main(void)
{
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	ReverceList(p1);
	return 0;
}
