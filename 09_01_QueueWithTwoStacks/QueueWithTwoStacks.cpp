// ������9��������ջʵ�ֶ���
// ��Ŀ��������ջʵ��һ�����С����е��������£���ʵ��������������appendTail
// ��deleteHead���ֱ�����ڶ���β����������ڶ���ͷ��ɾ�����Ĺ��ܡ� 

//ע��ģ���д��������const �������÷�����һ��д���������߿��𰸱�д
//throw�׳��쳣����֮��ĳ���

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
template <typename T> void CQueue<T>::addpendTail(const T & node)//�˴������ǹؼ�
{
	stack1.push(node);
}
template <typename T> T CQueue<T>::deleteHead(void)
{
	//if (stack1.size() > 0 && stack2.size() <= 0)
	if (stack2.size() <= 0)//�˴������ж�stack1�Ĵ�С��whileѭ��������
	{
		while (stack1.size() > 0)
		{
			T & temp = stack1.top();//�˴����������ã���Ȼwhileѭ���������ʧ��������Ȼ�ڶ�����
			//T temp = stack1.top();
			stack1.pop();
			stack2.push(temp);
		}
	}
	//�˴�����쳣���
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