/*����һ������ÿ k ���ڵ�һ����з�ת�����㷵�ط�ת�������
k ��һ��������������ֵС�ڻ��������ĳ��ȡ�
����ڵ��������� k ������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��

�����������1->2->3->4->5
�� k = 2 ʱ��Ӧ������: 2->1->4->3->5
�� k = 3 ʱ��Ӧ������: 3->2->1->4->5

����㷨ֻ��ʹ�ó����Ķ���ռ䡣
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʽ��нڵ㽻����

https://leetcode-cn.com/problems/reverse-nodes-in-k-group */

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

//��Ŭ�����õݹ飬������е��鷳
ListNode* reverseKGroup(ListNode* head, int k) 
{
	if (head == nullptr || head->next == nullptr) return head;
	ListNode* newHead = nullptr;	//�µ�ͷ��
	ListNode* pTemp = head;			//ÿ�ַ�תǰ����ʼ�ڵ�
	ListNode* pLast = head;			//ÿ�η�ת���β���ڵ�
	int cnt = 0;

	while (pTemp != nullptr)
	{
		ListNode* ptail = pTemp;	//����ÿ�ַ�ת��β��
		ListNode* curr = pTemp;		//������ת����������ָ��
		ListNode* pre = nullptr;
		ListNode* next = nullptr;

		//ûע�⵽��ʣ��ڵ㱣��ԭ��˳������鷳ѽ
		int i = 0;
		for (i = 0; i < k && curr != nullptr; i++)
		{
			next = curr->next;
			curr->next = pre;
			pre = curr;
			curr = next;
		}

		//�������ٴη�ת����
		if (i < k)
		{
			ptail = pre;
			ListNode* pC = pre;			//��ǰ�ڵ�
			ListNode* pN = nullptr;		//��һ���ڵ�
			ListNode* pPre = nullptr;	//�µ�ͷ��
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
		else pLast->next = pre;			//����ֻ��һ�ֵ���ѭ������һ�ֲ���pLast->next ��ֵ����Ϊ�˿�pLast ���� head
		pLast = ptail;
		pTemp = curr;
		cnt++;
	}
	return newHead;
}

//Ⱥ�￴���ܼ���д�����ܰ���д��
ListNode* reverseKGroup01(ListNode* head, int k)
{
	if (head == nullptr) return head;
	ListNode* slow = head;
	ListNode* fast = head;
	//����K���Ļ����������
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

//��⿴���ģ�����һ�����ƣ�
ListNode* reverseKGroup02(ListNode* head, int k)
{
	ListNode *pre = head;
	for (int i = 0; i < k; i++)
	{
		if (pre) pre = pre->next;
		else return head;			//ԭ˳�򷵻�
	}
	pre = reverseKGroup02(pre, k);	//֮ǰ��preΪnullptr���˴��൱�� pre Ϊʣ��Ľڵ�
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