#include<iostream>
#include"List.h"

//生成链表节点
ListNode* CreateListNode(int value) 
{
	ListNode* pNode = new ListNode();//此处最好加()初始化一下，已通过内存查看
	if (pNode == nullptr)
		return nullptr;
	pNode->m_nValue = value;
	pNode->m_pNext = nullptr;
	return pNode;
}

//之前疑惑，为什么传入一级指针形参，而不是二级指针形参或者返回指针，依然可以正常连接节点。
//今日得到答案：ListNode节点存储的是一个int型数字和指向下一个节点的地址值。【指针在内存中的表现即为地址值】
//因此，虽然是改变指针m_pNext的指向，但指针m_pNext是pCurrent指向的内容，属于指针的内容。
//此处不同于 重新给pCurrent分配新的内存。

//连接链表节点
void ConnectListNode(ListNode* pCurrent, ListNode* pNext)
{
	if (pCurrent == nullptr)
		return;
	pCurrent->m_pNext = pNext;//说明可以将指向为空的指针指向其他内存
}

//打印链表节点
void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
		return;
	std::cout << "ListNode: " << pNode->m_nValue << std::endl;
}

//打印链表
void PrintList(ListNode* pHead)
{
	if (pHead == nullptr)
		return;
	ListNode* pNode = pHead;
	std::cout << "PrintList start:" << std::endl;
	while (pNode != nullptr)
	{
		std::cout << pNode->m_nValue << ' ';
		//++ pNode;//链表，不是数组，不能指针++呀
		pNode = pNode->m_pNext;
	}
	std::cout << "PrintList end:" << std::endl;
}

//销毁链表
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

//链表后面增加节点
void AddTail(ListNode* pHead, int value)
{

}

//移除节点
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