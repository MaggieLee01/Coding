#pragma once
struct ListNode
{
	int			m_nValue;//ע����������
	ListNode*	m_pNext;
};

//��������ڵ�
ListNode* CreateListNode(int value);

//��������ڵ�
void ConnectListNode(ListNode* pCurrent, ListNode* pNext);

//��ӡ����ڵ�
void PrintListNode(ListNode* pNode);

//��ӡ����
void PrintList(ListNode* pHead);

//��������
void DestroyList(ListNode* pHead);

//����������ӽڵ�
void AddTail(ListNode* pHead, int value);

//�Ƴ��ڵ�
void RemoveListNode(ListNode* pHead, int value);


