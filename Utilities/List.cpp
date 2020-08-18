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
	//看完答案，思考，return和exit的区别

	//说明可以将指向为空的指针指向其他内存，//此处理解有误，是因为指针m_pNext是pCurrent指向的内容
	pCurrent->m_pNext = pNext;
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
	//看完答案，思考，不检查为也可以，不进入while循环了
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
	std::cout << std::endl;
	std::cout << "PrintList end:" << std::endl;
}

//销毁链表
//此处修改了指针的指向，所以需要二级指针
//如果仅仅形参为一级指针，函数修改了指向内存的内容，却不能改变指针的指向，执行完函数后；因此p1仍然指向此前的内存，但由于函数内delete了内存，使用p1成为了野指针
//看完答案，思考，答案仅仅用了一级形参，个人不赞同，依然坚持以上思考。
void DestroyList(ListNode** pHead)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;
	while (*pHead != nullptr)
	{
		//看完答案，思考，此处新建的ListNode* pNode是放在while内，还是放在while外面会快一点，毕竟此处要不停赋值。
		ListNode* pNode = (*pHead)->m_pNext;
		delete *pHead;
		*pHead = nullptr;
		*pHead = pNode;
	}
}

//链表后面增加节点
ListNode* AddTail(ListNode* pHead, int value)
{
	ListNode* pNode = new ListNode();
	if (pNode == nullptr)
		return nullptr;
	else
	{
		pNode->m_nValue = value;
		pNode->m_pNext = nullptr;
	}

	//考虑没有头结点的话，增加的节点即为头节点
	if (pHead == nullptr)
		pHead = pNode;
	else
	{
		//看完答案，思考，此处命名可读性较差
		ListNode* p = pHead;
		while (p->m_pNext != nullptr)
			p = p->m_pNext;
		//p = pNode;	//不应该改变指针的指向，应该改变指针的内容
		p->m_pNext = pNode;
	}
	return pHead;
}

//移除节点
ListNode* RemoveListNode(ListNode* pHead, int value)
{
	if (pHead == nullptr)
		return nullptr;
	ListNode* pNode = pHead;
	//判断是否为第一个节点
	if (pHead->m_nValue == value)
	{
		pHead = pHead->m_pNext;//此处改变了指针的指向，所以形参二级或者返回指针
		delete pNode;
		pNode = nullptr;
		//找到并删除之后应该立即返回，不然还会继续往下执行，浪费时间，且pNode指向空指针后，后面的判断逻辑有误
		//看完答案，思考，或者此处不返回的话，后面的内容则全部在else条件下
		return pHead;
	}
	//从第二个开始遍历
	while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
		pNode = pNode->m_pNext;
	//下一个节点为要删除的节点
	if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
	{
		ListNode* ToBedelete = pNode->m_pNext;//ToBedelete命名不好
		pNode->m_pNext = pNode->m_pNext->m_pNext;
		delete ToBedelete;
		ToBedelete = nullptr;
	}
	//遍历到最后没找到	
	else
	{
		std::cout << "No point:	" << value << std::endl;
		//return nullptr; 此处即使没找到也不应该返回nullptr
	}
	return pHead;
}
//看完答案，思考，RemoveListNode函数可以按照答案优化代码，思路基本OK，特殊情况都考虑较全，但是代码编写需要优化
//例如，为了提高代码的可读性，除了遍历变量外，其他变量最好赋予有意义的命名，执行什么功能即命什么名；同时严格按照命名规则，指针前缀，成员前缀，RemoveListNode
//还有，可以一开始定义pToBedelete节点，在首节点或者不在首节点，两种情况中，找到后赋值给pToBedelete节点，最后统一处理：判断pToBedelete节点是否为空然后删除

/*
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
	p1 = AddTail(p1, 6);
	PrintList(p1);
	p1 = RemoveListNode(p1, 3);
	PrintList(p1);
	DestroyList(&p1);

	p1 = AddTail(p1, 8);
	PrintList(p1);
	p1 = AddTail(p1, 9);
	PrintList(p1);
	p1 = AddTail(p1, 10);
	PrintList(p1);
	p1 = RemoveListNode(p1, 8);
	PrintList(p1);

	return 0;
}
*/
//看完答案的总结：
//学习return和exit的区别
//注意if判断为真情况内没有返回的话，后面的内容尽可能在else条件下
//AddTail函数命名需要改进， DestroyList函数和答案有设计出入，我目前坚持自己的观点； RemoveListNode函数需要学习的coding细节汗多，已记录在函数后面
//其他函数整体基本OK

//凡是带有“看完答案，思考，”的注释，才是为看完答案之后的想法，其他注释为自己coding时边写边调试边思考解决问题的记录