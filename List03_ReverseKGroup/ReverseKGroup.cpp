/*给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

给你这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

https://leetcode-cn.com/problems/reverse-nodes-in-k-group */

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

//在努力不用递归，处理的有点麻烦
ListNode* reverseKGroup(ListNode* head, int k) 
{
	if (head == nullptr || head->next == nullptr) return head;
	ListNode* newHead = nullptr;	//新的头部
	ListNode* pTemp = head;			//每轮翻转前的起始节点
	ListNode* pLast = head;			//每次翻转后的尾部节点
	int cnt = 0;

	while (pTemp != nullptr)
	{
		ListNode* ptail = pTemp;	//保存每轮翻转的尾部
		ListNode* curr = pTemp;		//正常翻转迭代的三个指针
		ListNode* pre = nullptr;
		ListNode* next = nullptr;

		//没注意到，剩余节点保持原有顺序，这个麻烦呀
		int i = 0;
		for (i = 0; i < k && curr != nullptr; i++)
		{
			next = curr->next;
			curr->next = pre;
			pre = curr;
			curr = next;
		}

		//将最后的再次翻转回来
		if (i < k)
		{
			ptail = pre;
			ListNode* pC = pre;			//当前节点
			ListNode* pN = nullptr;		//下一个节点
			ListNode* pPre = nullptr;	//新的头部
			while (pC != nullptr)
			{
				pN = pC->next;
				pC->next = pPre;
				pPre = pC;
				pC = pN;
			}
			pre = pPre;	
		}

		if (cnt == 0) newHead = pre;
		else pLast->next = pre;			//避免只有一轮的死循环，第一轮不给pLast->next 赋值，因为此刻pLast 等于 head
		pLast = ptail;
		pTemp = curr;
		cnt++;
	}
	return newHead;
}

//群里看到很简洁的写法，很棒的写法
ListNode* reverseKGroup01(ListNode* head, int k)
{
	if (head == nullptr) return head;
	ListNode* slow = head;
	ListNode* fast = head;
	//不够K个的话，正常输出
	for (int i = 0; i < k; i++)
	{
		if (fast) fast = fast->next;
		else return head;
	}
	ListNode *nHead = slow;
	ListNode *pre = nullptr;
	for (int i = 0; i < k; i++)
	{
		ListNode* nx = slow->next;
		slow->next = pre;
		pre = slow;
		slow = nx;
	}
	nHead->next = reverseKGroup01(slow, k);
	return pre;
}

//题解看到的，和上一个类似，
ListNode* reverseKGroup02(ListNode* head, int k)
{
	ListNode *pre = head;
	for (int i = 0; i < k; i++)
	{
		if (pre) pre = pre->next;
		else return head;			//原顺序返回
	}
	pre = reverseKGroup02(pre, k);	//之前的pre为nullptr，此处相当于 pre 为剩余的节点
	for (int i = 0; i < k; i++)
	{
		ListNode *temp = head->next;
		head->next = pre;
		pre = head;
		head = temp;
	}
	return pre;
}

int main(void)
{
	ListNode *pNode1 = new ListNode(1);
	ListNode *pNode2 = new ListNode(1);

	pNode1->next = new ListNode(2);
	pNode1->next->next = new ListNode(3);
	pNode1->next->next->next = new ListNode(4);
	pNode1->next->next->next->next = new ListNode(5);

	//ListNode *ans = reverseKGroup(pNode2, 1);
	ListNode *ans1 = reverseKGroup02(pNode1, 3);
	ListNode *ans2 = reverseKGroup(pNode1, 3);
	return 0;
}