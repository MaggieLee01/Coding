//ţ�������ԣ���Ҫ�Լ�������������������ͨ���ĳ���
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits> //INT_MIN��ͷ�ļ�
#include <algorithm>
using namespace std;
int buyandsell(vector<int> stocks)
{
	int i_0 = 0, i_1 = INT_MIN;
	for (int i : stocks)
	{
		i_0 = max(i_0, i_1 + i);
		i_1 = max(i_1, -i);
	}
	return i_0;
}
int main()
{
	vector<int> stocks;
	int a;
	while (cin >> a)
	{
		stocks.push_back(a); //һ��Ҫ������������������
	}
	int ans = buyandsell(stocks);
	cout << ans << endl;
	return 0;
}


//��⣺�ſ�Ĵ���
// https://www.nowcoder.com/questionTerminal/08f70daa78bf45fea64d72523a3641f3?commentTags=C%2FC%2B%2B

int main01() {
	int x = 0, Min = INT_MAX, s = 0;
	while (cin >> x) {
		s = max(s, x - Min);
		Min = min(Min, x);
	}
	cout << s << endl;
	return 0;
}
