#include<iostream>
#include"List.h"

//��������ڵ�
ListNode* CreateListNode(int value) 
{
	ListNode* pNode = new ListNode();//�˴���ü�()��ʼ��һ�£���ͨ���ڴ�鿴
	if (pNode == nullptr)
		return nullptr;
	pNode->m_nValue = value;
	pNode->m_pNext = nullptr;
	return pNode;
}

//֮ǰ�ɻ�Ϊʲô����һ��ָ���βΣ������Ƕ���ָ���βλ��߷���ָ�룬��Ȼ�����������ӽڵ㡣
//���յõ��𰸣�ListNode�ڵ�洢����һ��int�����ֺ�ָ����һ���ڵ�ĵ�ֵַ����ָ�����ڴ��еı��ּ�Ϊ��ֵַ��
//��ˣ���Ȼ�Ǹı�ָ��m_pNext��ָ�򣬵�ָ��m_pNext��pCurrentָ������ݣ�����ָ������ݡ�
//�˴���ͬ�� ���¸�pCurrent�����µ��ڴ档

//��������ڵ�
void ConnectListNode(ListNode* pCurrent, ListNode* pNext)
{
	if (pCurrent == nullptr)
		return;
	//˵�����Խ�ָ��Ϊ�յ�ָ��ָ�������ڴ棬//�˴������������Ϊָ��m_pNext��pCurrentָ�������
	pCurrent->m_pNext = pNext;
}

//��ӡ����ڵ�
void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
		return;
	std::cout << "ListNode: " << pNode->m_nValue << std::endl;
}

//��ӡ����
void PrintList(ListNode* pHead)
{
	if (pHead == nullptr)
		return;
	ListNode* pNode = pHead;
	std::cout << "PrintList start:" << std::endl;
	while (pNode != nullptr)
	{
		std::cout << pNode->m_nValue << ' ';
		//++ pNode;//�����������飬����ָ��++ѽ
		pNode = pNode->m_pNext;
	}
	std::cout << std::endl;
	std::cout << "PrintList end:" << std::endl;
}

//��������
void DestroyList(ListNode* pHead)
{
	if (pHead == nullptr)
		return;
	while (pHead != nullptr)
	{
		ListNode* pNode = pHead->m_pNext;
		delete pHead;
		pHead = nullptr;
		pHead = pNode;
	}
}

//����������ӽڵ�
void AddTail(ListNode* pHead, int value)
{
	ListNode* pNode = new ListNode();
	if (pNode == nullptr || pHead == nullptr)
		return;
	pNode->m_nValue = value;
	pNode->m_pNext = nullptr;

	ListNode* p = pHead;
	while (p->m_pNext != nullptr)
		p = p->m_pNext;
	//p = pNode;	//��Ӧ�øı�ָ���ָ��Ӧ�øı�ָ�������
	p->m_pNext = pNode;
}

//�Ƴ��ڵ�
ListNode* RemoveListNode(ListNode* pHead, int value)
{
	if (pHead == nullptr)
		return nullptr;
	ListNode* pNode = pHead;
	//�ж��Ƿ�Ϊ��һ���ڵ�
	if (pHead->m_nValue == value)
	{
		pHead = pHead->m_pNext;//�˴��ı���ָ���ָ�������βζ������߷���ָ��
		delete pNode;
		pNode = nullptr;
	}
	//�ӵڶ�����ʼ����
	while ( pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value )
		pNode = pNode->m_pNext;
	//��һ���ڵ�ΪҪɾ���Ľڵ�
	if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
	{
		ListNode* ToBedelete = pNode->m_pNext;
		pNode->m_pNext = pNode->m_pNext->m_pNext;
		delete ToBedelete;
		ToBedelete = nullptr;
	}
	//���������û�ҵ�	
	else 
	{
		std::cout << "No point:	" << value << std::endl;
		return nullptr;
	}
	return pHead;
}

int main(void)
{
	ListNode* p1 = CreateListNode(1);
	PrintListNode(p1);
	ListNode* p2 = CreateListNode(2);
	PrintListNode(p2);
	ConnectListNode(p1, p2);
	PrintList(p1);
	AddTail(p1, 3);
	PrintList(p1);
	AddTail(p1, 4);
	PrintList(p1);
	AddTail(p1, 5);
	PrintList(p1);
	AddTail(p1, 6);
	PrintList(p1);
	p1 = RemoveListNode(p1, 3);
	PrintList(p1);
	DestroyList(p1);
	return 0;
}