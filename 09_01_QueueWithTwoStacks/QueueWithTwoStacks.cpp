// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。 

//注意模板的写法，还有const 参数的用法，第一次写不熟练。边看答案边写
//throw抛出异常处理之后的程序

#include<stack>
#include<iostream>
#include<exception>
using namespace std;

template<typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);
	void addpendTail(const T & node);
	T deleteHead(void);
private:
	stack<T> stack1;
	stack<T> stack2;
};
template <typename T> CQueue<T>::CQueue(void)
{}
template <typename T> CQueue<T>::~CQueue(void)
{}
template <typename T> void CQueue<T>::addpendTail(const T & node)//此处引用是关键
{
	stack1.push(node);
}
template <typename T> T CQueue<T>::deleteHead(void)
{
	//if (stack1.size() > 0 && stack2.size() <= 0)
	if (stack2.size() <= 0)//此处不用判断stack1的大小，while循环中已有
	{
		while (stack1.size() > 0)
		{
			T & temp = stack1.top();//此处必须是引用，不然while循环外变量消失，变量依然在队列中
			//T temp = stack1.top();
			stack1.pop();
			stack2.push(temp);
		}
	}
	//此处添加异常检测
	/*if (stack2.size() > 0)
	{
		T temp = stack2.top();
		stack2.pop();
	}*/
	if (stack2.size() == 0)
		throw new exception("queue is empty");
	T head = stack2.top();
	stack2.pop();

	return head;
}

void Test(char actual, char expected)
{
	if (actual == expected)
		std::cout << "Passed" << std::endl;
	else
		std::cout << "Failed" << std::endl;
}
int main(void)
{
	CQueue<char> test1;
	test1.addpendTail('a');
	test1.addpendTail('b');
	test1.addpendTail('c');
	test1.addpendTail('d');
	char a = test1.deleteHead();
	Test(a, 'a');
	char b = test1.deleteHead();
	Test(b, 'b');

	CQueue<char> test2;
	char e = test2.deleteHead();
	Test(e, 'a');

	CQueue<char> test3;
	test3.addpendTail('d');
	char f = test3.deleteHead();
	Test(e, 'a');

	return 0;
}