//Ã⁄—∂±  ‘ “—AC
#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class MyQueue
{
private:
	stack<int> first;
	stack<int> second;
public:
	void push(int i)
	{
		first.push(i);
	}
	void pop()
	{
		if (second.size()) second.pop();
		else if (first.size())
		{
			while (first.size())
			{
				second.push(first.top());
				first.pop();
			}
			second.pop();
		}
	}
	int front()
	{
		if (second.size()) return second.top();
		else if (first.size())
		{
			while (first.size())
			{
				second.push(first.top());
				first.pop();
			}
			return second.top();
		}
	}
};
int main(void)
{
	MyQueue q;
	vector<int> ans;
	
	int opCnt = 0;
	cin >> opCnt;
	for (int j = 0; j < opCnt; j++)
	{
		string operaType;
		int num = 0;
		cin >> operaType;
		if (operaType == "add")
		{
			cin >> num;
			q.push(num);
		}
		else if (operaType == "peek")
		{
			ans.push_back(q.front());
		}
		else if (operaType == "poll")
		{
			q.pop();
		}
	}
	
	for (int i : ans)
	{
		cout << i << endl;
	}
	return 0;
}