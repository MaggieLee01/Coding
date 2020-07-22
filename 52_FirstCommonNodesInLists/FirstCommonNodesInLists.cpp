//输入两个链表，找出它们的第一个公共节点。
//https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/

//看题解，一直走，遍历a链表的节点走到尽头后遍历b链表，a + common + b =  b + common + a
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
		//这样子写不对，如果没有交点则死循环
		/*pa = pa->next == nullptr ? headB : pa->next;
		pb = pb->next == nullptr ? headA : pb->next;*/

		//这样子，遍历完链表a b 或者 链表b a 之后，同时到达了nullptr，两者相等，结束循环
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