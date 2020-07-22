//腾讯笔试 已AC
#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main(void)
{
	vector<long long int> ans;
	int testCnt = 0;
	cin >> testCnt;//测试次数
	for (int i = 0; i < testCnt; i++)
	{
		stack<long long int> s;
		long long int node = 0;
		int depth = 0;
		cin >> node >> depth;
		node = node / 2;
		while (node != 0)
		{
			s.push(node);
			node = node / 2;
		}
		int j = 1;
		while (s.size() && j < depth)
		{
			s.pop();
			j++;
		}
		if (j == depth && s.size()) ans.push_back(s.top());
		else ans.push_back(-1);
	}
	for (long long int i : ans)
	{
		cout << i << endl;
	}
	return 0;
}