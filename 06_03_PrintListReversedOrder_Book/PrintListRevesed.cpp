#include<vector>
#include<iostream>
#include"../Utilities/List.h"

//������۴𰸣��ݹ� �ǵݹ� ���ַ��������붼�ܼ�飬δ��ϸ�������롣
//�ǵݹ鷽���漰����ջ�������ջ�Ļ�������֮������ɴ˷���
//����ʾ��˼�����Եݹ鷽����ʱ�临�Ӷȷ�����O(n)�ɣ�ֻ����������
//�ѵ㣺��������ݹ�ѭ������ӡ�͵��õݹ麯�����Ⱥ�˳�򡣵ݹ���÷��غ�����ִ�к���Ĵ��롣
//Ŀǰ�汾�׶ˣ������ں����ڻ��У������ӡ ���������־������ʼ��־�С�

//����𰸣�˼�������������ӡ�ı׶ˣ�ò��ֻ���ں�����ִ���ˣ��������޷����
//����ڲ��Գ���֮��delete�ڴ�
//�Լ�д��Ӧ��ûʲô���⣬��book�ϻ�����࣬ͨ��������������ԣ��޷�ͨ��ţ�����������ṹ��ͬ��
//����book�ϵ�д�����������
void printListFromTailToHead_Recursively(ListNode* pHead) 
{
	
	if (pHead == nullptr)
	{
		//std::cout << std::endl;//�˴��Ǵ�ӡ�������㣬�����յ�
		std::cout << "Reversed List Begins:" << std::endl;
		return;
	}
	//����𰸣�˼�����˴����õĵݹ麯�����Է���pHead->m_pNext != nullptr�������£����Լ���һ�α���	
	printListFromTailToHead_Recursively(pHead->m_pNext);
	std::cout << pHead->m_nValue << ' ';
}
int main(void)
{
	
	ListNode* p1 = CreateListNode(1);
	
	//һ���ڵ����
	printListFromTailToHead_Recursively(p1);
	std::cout << std::endl << "Reversed List Ends" << std::endl;

	p1 = AddTail(p1, 2);
	p1 = AddTail(p1, 3);
	p1 = AddTail(p1, 4);
	p1 = AddTail(p1, 5);

	//������ڵ����	
	printListFromTailToHead_Recursively(p1);
	std::cout << std::endl << "Reversed List Ends" << std::endl;

	//��ָ�����
	ListNode* p2 = nullptr;	
	printListFromTailToHead_Recursively(p2);
	std::cout << "Reversed List Ends" << std::endl;

	return 0;
}
