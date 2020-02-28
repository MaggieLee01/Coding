//����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣
//ʾ��������һ������ : 1->2->3->4->5, �� n = 2	��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int number) :val(number), next(nullptr) {}
};
//Ŀǰ�ؼ��㣺����ɾ��������n���ڵ�
//Ŀǰ�ѵ㣺��������Ĵ����ã�һ��Ԫ�� nΪ1����� nΪ���ȵ����
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (head == nullptr) return head;
	ListNode *fast = head, *low = head;

	while (fast != nullptr && n-- >= 0)//������k+1��
		fast = fast->next;
	if (n > 0)	return head;		//n����ֵ̫����
	if (n == 0)	return head->next;	//�պ�Ϊ��һ��
	while (fast != nullptr)
	{
		low = low->next;
		fast = fast->next;
	}
	//if (low->next != nullptr)//��n=1��lowָ�����ڶ��������������ж�low->next
		low->next = low->next->next;
	return head;
}

//���ѵ����ڴ���һ��Ԫ�� ����Ҫɾ����Ϊ��һ��Ԫ�أ������������ͨ���жϼ�������n���жϵģ�
//���˺ܶ���⣬�����������ͷ�ڵ㴦��
ListNode* removeKthFromEnd(ListNode* head, int n)
{
	ListNode *node = new ListNode(0);
	node->next = head;
	ListNode *fast = node;
	ListNode *low = node;
	while (fast != nullptr && n-- >= 0)
		fast = fast->next;
	while (fast != nullptr)
	{
		low = low->next;
		fast = fast->next;
	}
	ListNode *ToBeDeleted = low->next;
	low->next = ToBeDeleted->next;//��n=1��lowָ�����ڶ��������������ж�low->next

	//�ͷ��ڴ�
	delete ToBeDeleted;
	ToBeDeleted = nullptr;

	ToBeDeleted = node;
	delete ToBeDeleted;
	ToBeDeleted = nullptr;

	return head;
}

int main(void)
{
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	p1->next = p2;

	ListNode* p3 = removeNthFromEnd(p1, 2);
}