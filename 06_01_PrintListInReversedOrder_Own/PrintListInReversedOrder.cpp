// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
#include<iostream>
#include"../Utilities/list.h"

//最笨的方法：暴力遍历，时间复杂度，O(n*n)，此方法没有改变输入
//链表翻转的话，改变了链表，可以打印完之后再翻转回去

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
		pHead = ReverseList(pReverseList);
	}
}
ListNode* ReverseList(ListNode* pHead)
{
	if (pHead != nullptr && pHead->m_pNext != nullptr)
	{
		ListNode* pCurrent = pHead;
		ListNode* pNextNode = nullptr;		
		ListNode* pLastNode = nullptr;
		ListNode* pNewList = nullptr;
		while (pCurrent->m_pNext != nullptr)
		{
			pNextNode = pCurrent->m_pNext;
			pCurrent->m_pNext = pLastNode;
			pLastNode = pCurrent;
			pCurrent = pNextNode;
		}
		pNewList = pCurrent;
	}
	return pHead;
}