//�������������ҳ����ǵĵ�һ�������ڵ㡣
//https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/

//����⣬һֱ�ߣ�����a����Ľڵ��ߵ���ͷ�����b����a + common + b =  b + common + a
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int m) :val(m), next(nullptr) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
	ListNode*pa = headA;
	ListNode*pb = headB;
	while (pa != pb)
	{
		//������д���ԣ����û�н�������ѭ��
		/*pa = pa->next == nullptr ? headB : pa->next;
		pb = pb->next == nullptr ? headA : pb->next;*/

		//�����ӣ�����������a b ���� ����b a ֮��ͬʱ������nullptr��������ȣ�����ѭ��
		pa = pa == nullptr ? headB : pa->next;
		pb = pb == nullptr ? headA : pa->next;
	}
	return pa;
}
int main(void)
{
	ListNode pHead(1);
	pHead.next = &ListNode(5);

	ListNode pHead2(2);
	pHead2.next = &ListNode(6);
	pHead2.next->next = &ListNode(4);

	ListNode* ans = getIntersectionNode(&pHead, &pHead2);
	return 0;

}