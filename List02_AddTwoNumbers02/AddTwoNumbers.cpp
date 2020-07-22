/*	给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
	你可以假设除了数字 0 之外，这两个数字都不会以零开头。
	
	输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
	输出：7 -> 8 -> 0 -> 7
	进阶：如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
	https://leetcode-cn.com/problems/add-two-numbers-ii */

//在上一题的基础上增加了倒序
//逆序处理，似乎一般都会用到栈，压入栈就能倒序处理了
//或者补齐链表，然后递归做加法，用了函数栈
//递归思路很妙，但是补零感觉比较浪费空间，尤其是当一个很长的数和一个很短的数相加时。 可以在递归内判断是否对齐了。
//https://leetcode-cn.com/problems/add-two-numbers-ii/solution/c-dui-qi-lian-biao-zhan-2chong-jie-fa-by-chuang-bi/
//或者压入数组，从末尾开始

#include<stack>
using namespace std;
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
//压入栈的方法
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
//递归求和，咋不太熟练啊
void _addTwoNumbers(ListNode* l1, ListNode* l2, ListNode *&ans)//注意最后一个参数，指针的引用
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