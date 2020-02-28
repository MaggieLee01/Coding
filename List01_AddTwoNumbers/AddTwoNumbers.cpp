//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
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
//		//难点 没有进位且temp2后面没有元素的话无需有0
//		if (temp1->next == nullptr)
//			temp1->next = new ListNode(0);//无论是否有进位都先保证后面有节点
//		if (temp1->val >= 10)//进位
//		{
//			temp1->val = temp1->val - 10;
//			temp1->next->val++;
//		}
//		temp2 = temp2->next;
//		left = temp1;
//		temp1 = temp1->next;		
//	}
//	if (temp1->val == 0)//因为不会以0开头，所以这个0一定是new出来没有用上的0 
//	{
//		delete temp1;
//		temp1 = nullptr;
//		left->next = nullptr;
//	}
//	if (temp1->val >= 10)//进位
//	{
//		temp1->val = temp1->val - 10;
//		if (temp1->next == nullptr)
//			temp1->next = new ListNode(0);//无论是否有进位都先保证后面有节点
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
//		temp3->next = new ListNode(0);//无论是否有进位都先保证后面有节点			
//		if (temp3->val >= 10)//进位
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

//上面尝试了这种方法都没成功，看着题解后写
ListNode* addTwoNumbers_answer1(ListNode* l1, ListNode* l2)
{
	ListNode *ans = new ListNode(0);
	ListNode *temp1 = new ListNode(0);	
	ListNode *temp2 = new ListNode(0); // 看了题解，因为后面已经考虑到l1 为空的情况，此处无需加头节点
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
		else  //看了题解，完全可以合并一起，用除法表示
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
	temp3 = ans->next;//ans自己有一个0，temp11起头也有一个0
	return temp3;
}

//看完题解后精简
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