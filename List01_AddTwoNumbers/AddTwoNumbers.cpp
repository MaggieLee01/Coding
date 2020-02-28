//�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
//��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�
//�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
//���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
//�����7 -> 0 -> 8
//ԭ��342 + 465 = 807
// https://leetcode-cn.com/problems/add-two-numbers

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//	ListNode *temp1 = new ListNode(0);
//	ListNode *temp2 = new ListNode(0);
//	ListNode *left = nullptr;
//
//	ListNode *ans = temp1;
//	temp1->next = l1;
//	temp2->next = l2;
//	while (temp2 != nullptr)
//	{
//		temp1->val = temp1->val + temp2->val;
//		//�ѵ� û�н�λ��temp2����û��Ԫ�صĻ�������0
//		if (temp1->next == nullptr)
//			temp1->next = new ListNode(0);//�����Ƿ��н�λ���ȱ�֤�����нڵ�
//		if (temp1->val >= 10)//��λ
//		{
//			temp1->val = temp1->val - 10;
//			temp1->next->val++;
//		}
//		temp2 = temp2->next;
//		left = temp1;
//		temp1 = temp1->next;		
//	}
//	if (temp1->val == 0)//��Ϊ������0��ͷ���������0һ����new����û�����ϵ�0 
//	{
//		delete temp1;
//		temp1 = nullptr;
//		left->next = nullptr;
//	}
//	if (temp1->val >= 10)//��λ
//	{
//		temp1->val = temp1->val - 10;
//		if (temp1->next == nullptr)
//			temp1->next = new ListNode(0);//�����Ƿ��н�λ���ȱ�֤�����нڵ�
//		temp1->next->val++;
//	}
//	
//	return ans->next;
//}
//
//ListNode* addTwoNumbers01(ListNode* l1, ListNode* l2) {
//	ListNode *temp1 = new ListNode(0);
//	ListNode *temp2 = new ListNode(0);
//	ListNode *temp3 = new ListNode(0);
//	ListNode *ans = temp3;
//	temp1->next = l1;
//	temp2->next = l2;
//	while (temp1 != nullptr && temp2 != nullptr)
//	{		
//		temp3->val = temp1->val + temp2->val;
//		temp3->next = new ListNode(0);//�����Ƿ��н�λ���ȱ�֤�����нڵ�			
//		if (temp3->val >= 10)//��λ
//		{
//			temp3->val = temp3->val - 10;
//			temp3->next->val++;
//		}
//		temp1 = temp1->next;
//		temp2 = temp2->next;	
//		if ((temp1 == nullptr || temp2 == nullptr) && temp3->next->val == 0) break;
//		temp3 = temp3->next;
//	}
//	if (temp1 == nullptr)
//		temp3->next = temp2;
//	else 
//		temp3->next = temp1;
//	return ans->next;
//}

//���波�������ַ�����û�ɹ�����������д
ListNode* addTwoNumbers_answer1(ListNode* l1, ListNode* l2)
{
	ListNode *ans = new ListNode(0);
	ListNode *temp1 = new ListNode(0);	
	ListNode *temp2 = new ListNode(0); // ������⣬��Ϊ�����Ѿ����ǵ�l1 Ϊ�յ�������˴������ͷ�ڵ�
	ListNode *temp3 = ans;
	temp1->next = l1;
	temp2->next = l2;
	int count = 0;
	while (temp1 != nullptr || temp2 != nullptr)
	{
		int val1 = (temp1 == nullptr) ? 0: temp1->val;
		int val2 = (temp2 == nullptr) ? 0: temp2->val;
		int sum = val1 + val2 + count;
		if (sum >= 10)
		{
			temp3->next = new ListNode(sum - 10);
			count = 1;
		}
		else  //������⣬��ȫ���Ժϲ�һ���ó�����ʾ
		{
			temp3->next = new ListNode(sum);
			count = 0;
		}
		if (temp1 != nullptr) temp1 = temp1->next;
		if (temp2 != nullptr) temp2 = temp2->next;
		temp3 = temp3->next;			
	}
	if (count == 1)
		temp3->next = new ListNode(1);
	temp3 = ans->next;
	delete ans;
	ans = temp3;
	temp3 = ans->next;//ans�Լ���һ��0��temp11��ͷҲ��һ��0
	return temp3;
}

//�������󾫼�
ListNode* addTwoNumbers_answer2(ListNode* l1, ListNode* l2)
{
	ListNode *ans = new ListNode(0);
	ListNode *temp1 = l1, *temp2 = l2, *temp3 = ans;
	int count = 0;
	while (temp1 != nullptr || temp2 != nullptr)
	{
		int val1 = (temp1 == nullptr) ? 0 : temp1->val;
		int val2 = (temp2 == nullptr) ? 0 : temp2->val;
		int sum = val1 + val2 + count;
		count = sum / 10;
		temp3->next = new ListNode(sum % 10);
		temp3 = temp3->next;		
		if (temp1 != nullptr) temp1 = temp1->next;
		if (temp2 != nullptr) temp2 = temp2->next;
		
	}
	if (count == 1)
		temp3->next = new ListNode(1);
	temp3 = ans->next;
	delete ans;
	ans = nullptr;
	return temp3;
}
int main(void)
{
	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode *l3 = new ListNode(9);
	l3->next = new ListNode(9);
	ListNode *l4 = new ListNode(9);
	ListNode *l5 = addTwoNumbers_answer1(l1, l2);
	return 0;
}