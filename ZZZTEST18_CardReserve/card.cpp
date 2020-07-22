#include<algorithm>
#include<vector>
#include<utility>
#include<iostream>
#include<algorithm>
using namespace std;

void swapCard(vector<int>& c1, vector<int>& c2)
{
	swap(c1[0], c1[1]);
	swap(c2[0], c2[1]);
	swap(c1, c2);
}
int main(void)
{
	int n = 0;
	cin >> n;
	vector<vector<int>> num(n, vector<int>(n, 0));
	vector<int> first(n, 0);

	bool flag = true;
	for (int i = 0; i < n; i++)
	{		
		cin >> first[i];
		if (flag && i > 0 && first[i] < first[i - 1]) flag = false;
	}
	if (flag)
	{
		cout << 0 << endl;
		return 0;				//输入即非降
	}

	for (int i = 0; i < n; i++)
	{
		int a = 0;
		cin >> a;
		num.push_back({ first[i], a });
	}

	int ans = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (num[i - 1][0] > num[i][0] && num[i-1][0] <= num[i][1])
			ans++;
		swapCard(num[i], num[i + 1]);
	}
	cout << ans << endl;
	return 0;
}


//群里讨论的答案，ret初始应该-1，但是我a了，他测试用例都要翻吧，翻不了是-1
//这是冒泡排序吗？？？
#include<iostream>
#include<vector>
using namespace std;
int Min_Ope(vector<int>& va, vector<int>& vb, int n)
{
	int ret = 0;
	while (true)
	{
		bool flag = false;
		for (int i = 0; i < n - 1; i++)
		{
			if (va[i] > va[i + 1])
			{
				swap(va[i], va[i + 1]);
				swap(vb[i], vb[i + 1]);
				swap(va[i], vb[i]);
				swap(va[i + 1], vb[i + 1]);
				ret++;
				flag = true;
			}
			if (i == n - 2)
				break;
		}
		if (flag == false)
			break;
	}
	return ret;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> va(n);
		vector<int> vb(n);
		for (int i = 0; i < n; i++)
			cin >> va[i];
		for (int i = 0; i < n; i++)
			cin >> vb[i];
		cout << Min_Ope(va, vb, n) << endl;
	}
	return 0;
}
