#include<vector>
#include<stack>
#include"../Utilities/List.h"
//����һ�������������β��ͷ��˳�򷵻�һ��ArrayList��
//vector����µľ�����ͷ�����룬������Ҫ������·���ռ䣬���ƺܶ�����顣
//v.insert(v.begin(), head->val); �ȼ��� v.push_front(head->val);
//ÿ�β����൱�ڰѵ�ǰ����Ԫ��ȫ������ƶ�һ��λ�ã��ٲ��뵱ǰԪ�أ���һ���ʱ�临�ӶȾ���O(n ^ 2)��Ч�ʵ͡�

//�ô�����ͨ��ţ����ϵͳ

//ţ�������۵�����˼·��
//���Խ���ת�������ѹ��vector
//����ֵ����vector������vector�Դ��ķ�ת����

std::vector<int> printListFromTailToHead(ListNode* pHead) 
{
	std::vector<int> ReservedList;//��֪����γ�ʼ��vector
	/*
	//���ж��Ƿ�Ϊ��,���ж�Ҳ��
	if (pHead == nullptr)
		return ReservedList;
	*/
	std::stack<int> StackOfList;
	//һ��ָ�룬�˴��ı�����Ӱ�캯����pHead��ָ��
	while (pHead != nullptr)
	{
		StackOfList.push(pHead->m_nValue);
		pHead = pHead->m_pNext;
	}

	//����ţ�����������룬�˴������� while(!StackOfList.empty() )��ѭ��������forѭ��
	int size = StackOfList.size();
	int item = 0;
	for (int i = 0; i < size; i++)
	{
		item = StackOfList.top();
		StackOfList.pop();
		ReservedList.push_back(item);
	}	
	return ReservedList;
}
int main(void)
{
	std::vector<int> ReservedList;

	ListNode* p1 = CreateListNode(1);
	ReservedList = printListFromTailToHead(p1);

	p1 = AddTail(p1, 2);
	p1 = AddTail(p1, 3);
	p1 = AddTail(p1, 4);
	p1 = AddTail(p1, 5);
	ReservedList = printListFromTailToHead(p1);

	//��ָ�����
	ListNode* p2 = nullptr;
	ReservedList = printListFromTailToHead(p2);	

	return 0;
}