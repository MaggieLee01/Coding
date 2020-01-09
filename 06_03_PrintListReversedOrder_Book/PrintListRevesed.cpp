#include<vector>
#include<iostream>
#include"../Utilities/List.h"

//瞟了两眼答案，递归 非递归 两种方法，代码都很简介，未仔细分析代码。
//非递归方法涉及到了栈，等完成栈的基础函数之后再完成此方法
//在提示下思考尝试递归方法，时间复杂度分析：O(n)吧，只遍历了两遍
//难点：处理结束递归循环；打印和调用递归函数的先后顺序。递归调用返回后会继续执行后面的代码。
//目前版本弊端：不能在函数内换行，输出打印 链表结束标志，链表开始标志有。

//看完答案，思考，关于输出打印的弊端，貌似只能在函数外执行了，函数内无法解决
//最好在测试程序之后delete内存
//自己写的应该没什么问题，和book上基本差不多，通过了三种情况测试，无法通过牛客网，函数结构不同；
//可能book上的写法更便于理解
void printListFromTailToHead_Recursively(ListNode* pHead) 
{
	
	if (pHead == nullptr)
	{
		//std::cout << std::endl;//此处是打印链表的起点，不是终点
		std::cout << "Reversed List Begins:" << std::endl;
		return;
	}
	//看完答案，思考，此处调用的递归函数可以放在pHead->m_pNext != nullptr的条件下，可以减少一次遍历	
	printListFromTailToHead_Recursively(pHead->m_pNext);
	std::cout << pHead->m_nValue << ' ';
}
int main(void)
{
	
	ListNode* p1 = CreateListNode(1);
	
	//一个节点测试
	printListFromTailToHead_Recursively(p1);
	std::cout << std::endl << "Reversed List Ends" << std::endl;

	p1 = AddTail(p1, 2);
	p1 = AddTail(p1, 3);
	p1 = AddTail(p1, 4);
	p1 = AddTail(p1, 5);

	//多个个节点测试	
	printListFromTailToHead_Recursively(p1);
	std::cout << std::endl << "Reversed List Ends" << std::endl;

	//空指针测试
	ListNode* p2 = nullptr;	
	printListFromTailToHead_Recursively(p2);
	std::cout << "Reversed List Ends" << std::endl;

	return 0;
}
