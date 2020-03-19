/*使用队列实现栈的下列操作：
	push(x) --元素 x 入栈
	pop() --移除栈顶元素
	top() --获取栈顶元素
	empty() --返回栈是否为空
	https://leetcode-cn.com/problems/implement-stack-using-queues */

//也可以一个队列实现，逐个弹出队首元素压入队尾
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
		//可以定义一个队列，逐个弹出压入；两个队列的话下面可以直接交换队列1 与 队列2
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