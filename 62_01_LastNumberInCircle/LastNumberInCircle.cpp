/*
0,1, ,n-1��n�������ų�һ��ԲȦ��������0��ʼ��ÿ�δ����ԲȦ��ɾ����m�����֡�������ԲȦ��ʣ�µ����һ�����֡�
���磬0��1��2��3��4��5���������һ��ԲȦ��������0��ʼÿ��ɾ����3�����֣���ɾ����ǰ4������������2��0��4��1��������ʣ�µ�������3��

����: n = 5, m = 3
���: 3

����: n = 10, m = 17
���: 2

https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof
*/
#include<iostream>
#include<vector>
using namespace std;

//ģ��ķ�����56795��87778 �������볬ʱ�ˣ�˵��erase̫��ʱ��ɣ�������������������취��
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
		num.erase(it);//erase����ֻ��Ϊ������
		index = (index + (m - 1)) % (num.size());
	}
	return num[0];
}
//����erase���������ɳ�ʱ�������������˼·
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
		int cnt = 0;//�ߵĴ���		
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
//Լɪ�򻷣����Դ��ٵ���������һ�����ֵ�����
int lastRemaining03(int n, int m)
{
	int f = 0;
	for (int i = 2; i != n + 1; ++i)
		f = (m + f) % i;
	return f;
}

//���� 1 2 3 ��˳�����
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
		num.erase(it);//erase����ֻ��Ϊ������
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

