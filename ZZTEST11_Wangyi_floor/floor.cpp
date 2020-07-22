////网易笔试，已AC
//#include<iostream>
//#include<vector>
//#include<stack>
//using namespace std;
//
//int main(void)
//{
//	int n = 0;
//	cin >> n;
//	vector<int> height(n, 0);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> height[i];
//	}
//	if (n == 0) return 0;
//
//
//	//寻找右边一下个更小元素
//	vector<int> minright(n, n);
//	stack<int> s;
//	s.push(n - 1);		//栈存放索引值
//	for (int i = n - 2; i >= 0; i--)
//	{
//		while (s.size() && height[s.top()] >= height[i])
//			s.pop();
//		if (s.size()) minright[i] = s.top();
//		s.push(i);
//	}
//
//	//寻找左边下一个更小元素
//	vector<int> minleft(n, -1);
//	stack<int> s2;
//	s2.push(0);
//	for (int i = 1; i < n; i++)
//	{
//		while (s2.size() && height[s2.top()] >= height[i])	
//			s2.pop();		
//		if (s2.size()) minleft[i] = s2.top();
//		s2.push(i);
//	}
//
//	long int ans = 0;
//	for (int i = 0; i < n; i++)
//	{
//		long area = height[i] * (minright[i] - minleft[i] - 1);
//		if (area > ans) ans = area;
//	}
//	cout << ans << endl;
//	return 0;
//}


//另一个笔试题
#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include <cctype>
using namespace std;


void sort(vector<int> &arr, int n)
{
	int m = arr.size();
	if (m <= 0)
		return;
	for (int i = 0; i < n; i++)
	{
		for (int j = m - 1; j > i; j--)
		{
			if (arr[j - 1] < arr[j])
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int M = 0, N = 0; //总共M只动物
	cin >> M >> N;
	vector<int> arr;
	for (int i = 0; i < M; i++)
	{
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr, N);
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i];
	}
	system("pause");
	return 0;
}