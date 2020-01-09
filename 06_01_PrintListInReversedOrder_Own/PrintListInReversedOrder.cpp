// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
#include<iostream>
#include"List.h"

//该思路无法在牛客网测试，函数结构不一样，自己的测试样例已全部通过。
//返回值处理需要完善

//此方法相当于完成了链表反转
ListNode* ReverseList(ListNode* pHead)
{
   	ListNode* pNewList = pHead;

	if (pNewList != nullptr && pNewList->m_pNext != nullptr)
	{
		ListNode* pCurrent = pHead;
		ListNode* pNextNode = nullptr;
		ListNode* pLastNode = nullptr;

		//while (pCurrent->m_pNext != nullptr) //这样子最后一个节点没连上，返回pCurrent相当于返回最后一个指针
		while (pCurrent != nullptr)
		{
			pNextNode = pCurrent->m_pNext;
			pCurrent->m_pNext = pLastNode;
			pLastNode = pCurrent;
			pCurrent = pNextNode;
		}
		//pNewList = pCurrent;
		//此时应该返回pLastNode节点
		pNewList = pLastNode;
	}
	return pNewList;
}

//最笨的方法：暴力遍历，时间复杂度，O(n*n)，此方法没有改变输入
//链表翻转的话，改变了链表，可以打印完之后再翻转回去
ListNode* ReverseList(ListNode* pHead);
void PrintListReversingly_Iteratively(ListNode* pHead)
{
	if (pHead == nullptr)
		return;
	if (pHead->m_pNext == nullptr)
		std::cout << pHead->m_nValue << std::endl;
	else
	{
		ListNode* pReverseList = ReverseList(pHead);
		PrintList(pReverseList);

		//没想好，此处如何解决

		//此处依然不可以通过改变指针的指向改变原本pHead的内容，虽然函数返回后pHead不受影响
		//pHead = ReverseList(pReverseList);
	}
}

int main(void) 
{
	ListNode* p1 = CreateListNode(1);
	PrintList(p1);
	PrintListReversingly_Iteratively(p1);
	PrintList(p1);

	p1 = AddTail(p1, 2);
	p1 = AddTail(p1, 3);
	p1 = AddTail(p1, 4);
	p1 = AddTail(p1, 5);
	PrintList(p1);
	PrintListReversingly_Iteratively(p1);
	PrintList(p1);

	return 0;
}