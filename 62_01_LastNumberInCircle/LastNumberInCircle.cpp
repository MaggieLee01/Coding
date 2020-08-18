/*
0,1, ,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。
例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

输入: n = 5, m = 3
输出: 3

输入: n = 10, m = 17
输出: 2

https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof
*/
#include<iostream>
#include<vector>
using namespace std;

//模拟的方法，56795，87778 这种输入超时了，说明erase太费时间吧，不用这个方法有其他办法吗
int lastRemaining(int n, int m)
{
	if (n <= 1) return 0;
	vector<int> num(n, 0);
	for (int i = 0; i < n; i++)
		num[i] = i;

	int index = (m - 1) % n;
	while (num.size() != 1)
	{
		auto it = num.begin();
		it = it + index;
		num.erase(it);//erase参数只能为迭代器
		index = (index + (m - 1)) % (num.size());
	}
	return num[0];
}
//不用erase函数，依旧超时，看题解找其他思路
int lastRemaining01(int n, int m)
{
	if (n <= 1) return 0;
	vector<int> num(n, 0);
	for (int i = 0; i < n; i++)
		num[i] = i;

	int size = n;
	int i = 0;
	while (size > 1)
	{
		int cnt = 0;//走的次数		
		while (cnt <= m)
		{
			if (num[i % n] != -1)
			{
				cnt++;
				if (cnt == m)
				{
					num[i % n] = -1;
					break;
				}
			}
			i++;
		}
		size--;
	}
	while (num[i%n] == -1)
		i++;
	int ans = num[i%n];
	return ans;
}
//约瑟夫环，可以从少到多递推最后一个数字的索引
int lastRemaining03(int n, int m)
{
	int f = 0;
	for (int i = 2; i != n + 1; ++i)
		f = (m + f) % i;
	return f;
}

//按照 1 2 3 的顺序擦除
int lastRemaining(int n)
{
	if (n <= 1) return 0;
	vector<int> num(n, 0);
	for (int i = 0; i < n; i++)
		num[i] = i + 1;
	int  m = 1;
	int index = m % n;
	while (num.size() != 1)
	{
		auto it = num.begin();
		it = it + index;
		num.erase(it);//erase参数只能为迭代器
		index = (index + (++m)) % (num.size());
	}
	return num[0];
}

int main(void)
{
	int N = 0;
	cin >> N;
	//int ans = lastRemaining01(5, 3);
	int ans = lastRemaining(N);
	cout << ans << endl;
	return 0;
}

