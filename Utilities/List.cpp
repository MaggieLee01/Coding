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
	pCurrent->m_pNext = pNext;//˵�����Խ�ָ��Ϊ�յ�ָ��ָ�������ڴ�
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
		delete pNode;
		pHead = pHead->m_pNext;
	}
}

//����������ӽڵ�
void AddTail(ListNode* pHead, int value)
{

}

//�Ƴ��ڵ�
void RemoveListNode(ListNode* pHead, int value)
{

}

int main(void)
{
	ListNode* p1 = CreateListNode(1);
	PrintListNode(p1);
	ListNode* p2 = CreateListNode(2);
	PrintListNode(p2);
	ConnectListNode(p1, p2);
	PrintList(p1);
	return 0;
}