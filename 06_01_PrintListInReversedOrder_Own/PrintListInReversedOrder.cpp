// ������6����β��ͷ��ӡ����
// ��Ŀ������һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ��
#include<iostream>
#include"../Utilities/list.h"

//��ķ���������������ʱ�临�Ӷȣ�O(n*n)���˷���û�иı�����
//����ת�Ļ����ı����������Դ�ӡ��֮���ٷ�ת��ȥ

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