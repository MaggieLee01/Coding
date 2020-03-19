//��תһ������������: 1->2->3->4->5->NULL;	��� : 5->4->3->2->1->NULL
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int n) :val(n), next(nullptr) {}
};
//������
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
//�ݹ鷨
ListNode *Tail = nullptr;
ListNode *ReverceList_ReCore(ListNode *head)
{
	if (head == nullptr) 
		return nullptr;
	if (head->next == nullptr)
	{
		Tail = head;//β����Ϊ�µ�ͷ�ڵ�
		return head;
	}		
	ListNode *temp = ReverceList_ReCore(head->next);
	head->next = nullptr;//���ԭ����ָ��ʹ���Ϊ��ת�����β���
	temp->next = head;//ָ�뷴ת
	return head;
}
ListNode *ReverceList_Re01(ListNode *head)
{
	ReverceList_ReCore(head);
	return Tail;
}
//���ϵĵݹ鷽��
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
