`#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	vector<string> ans;
	for (int i = 0; i < n; i++)
	{
		int m = 0;
		cin >> m;
		bool res = false;
		vector<int> num;
		for (int j = 0; j < m; j++)
		{
			int temp = 0;
			cin >> temp;
			num.push_back(temp);
		}
		sort(num.begin(), num.end());
		int sum = 0;
		for (int j = 0; j < num.size(); j++)
			sum += num[j];
		int last = (m - 1)*m / 2;
		if (sum > last)
		{
			int move = sum - last;
			if (move % 2 == 1) res = false;
			else res = true;
		}
		else
		{
			res = false;

		}

		if (res == false) ans.push_back("man");
		if (res == true) ans.push_back("woman");
	}
	for (auto w : ans)
		cout << w << endl;
	return 0;
}