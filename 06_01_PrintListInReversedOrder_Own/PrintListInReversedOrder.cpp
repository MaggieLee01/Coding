// ������6����β��ͷ��ӡ����
// ��Ŀ������һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ��
#include<iostream>
#include"List.h"

//��˼·�޷���ţ�������ԣ������ṹ��һ�����Լ��Ĳ���������ȫ��ͨ����
//����ֵ������Ҫ����

//�˷����൱�����������ת
ListNode* ReverseList(ListNode* pHead)
{
   	ListNode* pNewList = pHead;

	if (pNewList != nullptr && pNewList->m_pNext != nullptr)
	{
		ListNode* pCurrent = pHead;
		ListNode* pNextNode = nullptr;
		ListNode* pLastNode = nullptr;

		//while (pCurrent->m_pNext != nullptr) //���������һ���ڵ�û���ϣ�����pCurrent�൱�ڷ������һ��ָ��
		while (pCurrent != nullptr)
		{
			pNextNode = pCurrent->m_pNext;
			pCurrent->m_pNext = pLastNode;
			pLastNode = pCurrent;
			pCurrent = pNextNode;
		}
		//pNewList = pCurrent;
		//��ʱӦ�÷���pLastNode�ڵ�
		pNewList = pLastNode;
	}
	return pNewList;
}

//��ķ���������������ʱ�临�Ӷȣ�O(n*n)���˷���û�иı�����
//����ת�Ļ����ı����������Դ�ӡ��֮���ٷ�ת��ȥ
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

		//û��ã��˴���ν��

		//�˴���Ȼ������ͨ���ı�ָ���ָ��ı�ԭ��pHead�����ݣ���Ȼ�������غ�pHead����Ӱ��
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