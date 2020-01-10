#include<vector>
#include<stack>
#include"../Utilities/List.h"
//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
//vector最可怕的就是在头部插入，可能需要多次重新分配空间，复制很多次数组。
//v.insert(v.begin(), head->val); 等价于 v.push_front(head->val);
//每次插入相当于把当前数组元素全部向后移动一个位置，再插入当前元素，这一块的时间复杂度就是O(n ^ 2)，效率低。

//该代码已通过牛客网系统

//牛客网评论的其他思路：
//可以将反转后的链表压入vector
//链表值存入vector后，利用vector自带的反转函数

std::vector<int> printListFromTailToHead(ListNode* pHead) 
{
	std::vector<int> ReservedList;//不知道如何初始化vector
	/*
	//先判断是否为空,不判断也行
	if (pHead == nullptr)
		return ReservedList;
	*/
	std::stack<int> StackOfList;
	//一级指针，此处的遍历不影响函数外pHead的指向
	while (pHead != nullptr)
	{
		StackOfList.push(pHead->m_nValue);
		pHead = pHead->m_pNext;
	}

	//看完牛客网其他代码，此处可以用 while(!StackOfList.empty() )来循环，不用for循环
	int size = StackOfList.size();
	int item = 0;
	for (int i = 0; i < size; i++)
	{
		item = StackOfList.top();
		StackOfList.pop();
		ReservedList.push_back(item);
	}	
	return ReservedList;
}
int main(void)
{
	std::vector<int> ReservedList;

	ListNode* p1 = CreateListNode(1);
	ReservedList = printListFromTailToHead(p1);

	p1 = AddTail(p1, 2);
	p1 = AddTail(p1, 3);
	p1 = AddTail(p1, 4);
	p1 = AddTail(p1, 5);
	ReservedList = printListFromTailToHead(p1);

	//空指针测试
	ListNode* p2 = nullptr;
	ReservedList = printListFromTailToHead(p2);	

	return 0;
}