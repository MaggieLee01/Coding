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
	//����𰸣�˼����return��exit������

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
	//����𰸣�˼���������ΪҲ���ԣ�������whileѭ����
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
//�˴��޸���ָ���ָ��������Ҫ����ָ��
//��������β�Ϊһ��ָ�룬�����޸���ָ���ڴ�����ݣ�ȴ���ܸı�ָ���ָ��ִ���꺯�������p1��Ȼָ���ǰ���ڴ棬�����ں�����delete���ڴ棬ʹ��p1��Ϊ��Ұָ��
//����𰸣�˼�����𰸽�������һ���βΣ����˲���ͬ����Ȼ�������˼����
void DestroyList(ListNode** pHead)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;
	while (*pHead != nullptr)
	{
		//����𰸣�˼�����˴��½���ListNode* pNode�Ƿ���while�ڣ����Ƿ���while������һ�㣬�Ͼ��˴�Ҫ��ͣ��ֵ��
		ListNode* pNode = (*pHead)->m_pNext;
		delete *pHead;
		*pHead = nullptr;
		*pHead = pNode;
	}
}

//����������ӽڵ�
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

	//����û��ͷ���Ļ������ӵĽڵ㼴Ϊͷ�ڵ�
	if (pHead == nullptr)
		pHead = pNode;
	else
	{
		//����𰸣�˼�����˴������ɶ��Խϲ�
		ListNode* p = pHead;
		while (p->m_pNext != nullptr)
			p = p->m_pNext;
		//p = pNode;	//��Ӧ�øı�ָ���ָ��Ӧ�øı�ָ�������
		p->m_pNext = pNode;
	}
	return pHead;
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
		//�ҵ���ɾ��֮��Ӧ���������أ���Ȼ�����������ִ�У��˷�ʱ�䣬��pNodeָ���ָ��󣬺�����ж��߼�����
		//����𰸣�˼�������ߴ˴������صĻ��������������ȫ����else������
		return pHead;
	}
	//�ӵڶ�����ʼ����
	while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
		pNode = pNode->m_pNext;
	//��һ���ڵ�ΪҪɾ���Ľڵ�
	if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
	{
		ListNode* ToBedelete = pNode->m_pNext;//ToBedelete��������
		pNode->m_pNext = pNode->m_pNext->m_pNext;
		delete ToBedelete;
		ToBedelete = nullptr;
	}
	//���������û�ҵ�	
	else
	{
		std::cout << "No point:	" << value << std::endl;
		//return nullptr; �˴���ʹû�ҵ�Ҳ��Ӧ�÷���nullptr
	}
	return pHead;
}
//����𰸣�˼����RemoveListNode�������԰��մ��Ż����룬˼·����OK��������������ǽ�ȫ�����Ǵ����д��Ҫ�Ż�
//���磬Ϊ����ߴ���Ŀɶ��ԣ����˱��������⣬����������ø����������������ִ��ʲô���ܼ���ʲô����ͬʱ�ϸ�����������ָ��ǰ׺����Աǰ׺��RemoveListNode
//���У�����һ��ʼ����pToBedelete�ڵ㣬���׽ڵ���߲����׽ڵ㣬��������У��ҵ���ֵ��pToBedelete�ڵ㣬���ͳһ�����ж�pToBedelete�ڵ��Ƿ�Ϊ��Ȼ��ɾ��

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
//����𰸵��ܽ᣺
//ѧϰreturn��exit������
//ע��if�ж�Ϊ�������û�з��صĻ�����������ݾ�������else������
//AddTail����������Ҫ�Ľ��� DestroyList�����ʹ�����Ƴ��룬��Ŀǰ����Լ��Ĺ۵㣻 RemoveListNode������Ҫѧϰ��codingϸ�ں��࣬�Ѽ�¼�ں�������
//���������������OK

//���Ǵ��С�����𰸣�˼��������ע�ͣ�����Ϊ�����֮����뷨������ע��Ϊ�Լ�codingʱ��д�ߵ��Ա�˼���������ļ�¼