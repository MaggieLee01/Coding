/*	�������� �ǿ� ���������������Ǹ��������������λλ������ʼλ�á����ǵ�ÿ���ڵ�ֻ�洢һλ���֡�����������ӻ᷵��һ���µ�����
	����Լ���������� 0 ֮�⣬���������ֶ��������㿪ͷ��
	
	���룺(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
	�����7 -> 8 -> 0 -> 7
	���ף���������������޸ĸ���δ������仰˵���㲻�ܶ��б��еĽڵ���з�ת��
	https://leetcode-cn.com/problems/add-two-numbers-ii */

//����һ��Ļ����������˵���
//�������ƺ�һ�㶼���õ�ջ��ѹ��ջ���ܵ�������
//���߲�������Ȼ��ݹ����ӷ������˺���ջ
//�ݹ�˼·������ǲ���о��Ƚ��˷ѿռ䣬�����ǵ�һ���ܳ�������һ���̵ܶ������ʱ�� �����ڵݹ����ж��Ƿ�����ˡ�
//https://leetcode-cn.com/problems/add-two-numbers-ii/solution/c-dui-qi-lian-biao-zhan-2chong-jie-fa-by-chuang-bi/
//����ѹ�����飬��ĩβ��ʼ

#include<stack>
using namespace std;
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
//ѹ��ջ�ķ���
ListNode* addTwoNumbers01(ListNode* l1, ListNode* l2)
{
	if (l1 == nullptr) return l2;
	if (l2 == nullptr) return l1;
	stack<int> num1;
	stack<int> num2;
	ListNode ans = ListNode(0);
	while (l1 != nullptr)
	{
		num1.push(l1->val);
		l1 = l1->next;
	}
	while (l2 != nullptr)
	{
		num2.push(l2->val);
		l2 = l2->next;
	}
	int carry = 0, n1 = 0, n2 = 0, sum = 0;
	while (num1.size() || num2.size() || carry)
	{
		if (num1.empty())
			n1 = 0;
		else
		{
			n1 = num1.top();
			num1.pop();
		}
		if (num2.empty()) 
			n2 = 0;
		else
		{
			n2 = num2.top();
			num2.pop();
		}
		sum = n1 + n2 + carry;
		ListNode* node = new ListNode(sum % 10);
		carry = sum / 10;
		node->next = ans.next;
		ans.next = node;
	}
	return ans.next;
}





int carry = 0;
//�ݹ���ͣ�զ��̫������
void _addTwoNumbers(ListNode* l1, ListNode* l2, ListNode *&ans)//ע�����һ��������ָ�������
{
	if (l1 == nullptr && l2 == nullptr) return;
	_addTwoNumbers(l1->next, l2->next, ans);
	int sum = l1->val + l2->val + carry;
	ListNode* node = new ListNode(sum % 10);
	carry = sum / 10;
	node->next = ans;
	ans = node;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	int num1 = 0, num2 = 0;
	ListNode* t1 = l1, *t2 = l2;
	while (t1 != nullptr)
	{
		num1++;
		t1 = t1->next;
	}
	while (t2 != nullptr)
	{
		num2++;
		t2 = t2->next;
	}
	int sencondary = abs(num1 - num2);
	ListNode* newHead = new ListNode(0);
	ListNode* temp = newHead;
	while (sencondary > 0)
	{
		temp->next = new ListNode(0);
		temp = temp->next;
		sencondary--;
	}
	ListNode* head1 = l1;
	ListNode* head2 = l2;
	if (num1 < num2)
	{
		temp->next = l1;
		head1 = newHead->next;
	}
	else if (num1 > num2)
	{
		temp->next = l2;
		head2 = newHead->next;
	}
	delete newHead;
	ListNode* ans = nullptr;
	_addTwoNumbers(head1, head2, ans);
	if (carry)
	{
		ListNode* node = new ListNode(1);
		node->next = ans;
		ans = node;
	}
	return ans;
}