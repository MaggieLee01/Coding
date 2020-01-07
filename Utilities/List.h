#pragma once
struct ListNode
{
	int			m_nValue;//注意命名规则
	ListNode*	m_pNext;
};

//生成链表节点
ListNode* CreateListNode(int value);

//连接链表节点
void ConnectListNode(ListNode* pCurrent, ListNode* pNext);

//打印链表节点
void PrintListNode(ListNode* pNode);

//打印链表
void PrintList(ListNode* pHead);

//销毁链表
void DestroyList(ListNode* pHead);

//链表后面增加节点
void AddTail(ListNode* pHead, int value);

//移除节点
void RemoveListNode(ListNode* pHead, int value);


