//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
//示例：给定一个链表 : 1->2->3->4->5, 和 n = 2	当删除了倒数第二个节点后，链表变为 1->2->3->5.
// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int number) :val(number), next(nullptr) {}
};
//目前关键点：仅仅删除倒数第n个节点
//目前难点：特殊情况的处理不好，一个元素 n为1的情况 n为长度的情况
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (head == nullptr) return head;
	ListNode *fast = head, *low = head;

	while (fast != nullptr && n-- >= 0)//倒数第k+1个
		fast = fast->next;
	if (n > 0)	return head;		//n的数值太大了
	if (n == 0)	return head->next;	//刚好为第一个
	while (fast != nullptr)
	{
		low = low->next;
		fast = fast->next;
	}
	//if (low->next != nullptr)//若n=1，low指向倒数第二个，所以无需判断low->next
		low->next = low->next->next;
	return head;
}

//困难点在于处理一个元素 或者要删除的为第一个元素，上面代码我是通过判断计数长度n来判断的，
//看了很多题解，很巧妙，增加了头节点处理，
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
	low->next = ToBeDeleted->next;//若n=1，low指向倒数第二个，所以无需判断low->next

	//释放内存
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