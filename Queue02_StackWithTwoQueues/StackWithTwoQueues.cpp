/*ʹ�ö���ʵ��ջ�����в�����
	push(x) --Ԫ�� x ��ջ
	pop() --�Ƴ�ջ��Ԫ��
	top() --��ȡջ��Ԫ��
	empty() --����ջ�Ƿ�Ϊ��
	https://leetcode-cn.com/problems/implement-stack-using-queues */

//Ҳ����һ������ʵ�֣������������Ԫ��ѹ���β
#include<queue>
using std::queue;
class MyStack {
private:
	queue<int> first;
	queue<int> second;
public:
	/** Initialize your data structure here. */
	MyStack() {	}

	/** Push element x onto stack. */
	void push(int x) 
	{
		while (first.size())
		{
			second.push( first.front() );
			first.pop();
		}
		first.push(x);
		//���Զ���һ�����У��������ѹ�룻�������еĻ��������ֱ�ӽ�������1 �� ����2
		while (second.size())
		{
			first.push(second.front());
			second.pop();
		}		
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() 
	{
		int temp = first.front();
		first.pop();
		return temp;
	}

	/** Get the top element. */
	int top() 
	{
		 return first.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() 
	{
		return (first.empty() && second.empty());
	}
};

int main(void)
{
	MyStack my;
	my.push(1);
	my.push(2);
	int a = my.top();
	a = my.pop();
	a = my.pop();
	bool n = my.empty();
}