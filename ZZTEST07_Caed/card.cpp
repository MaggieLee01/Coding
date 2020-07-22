#include<algorithm>
#include<vector>
#include<utility>
#include<iostream>
using namespace std;
bool comp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second == p2.second ? p1.first > p2.first:p1.second > p2.second;
}
int main(void)
{
	int n = 0;
	cin >> n;
	vector<pair<int, int>> num;
	for (int i = 0; i < n; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		num.push_back({ a,b });
	}
	sort(num.begin(), num.end(), comp);
	int ans = 0;
	int cnt = 1;
	for (auto i : num)
	{
		cnt = cnt + i.second;
		ans = ans + i.first;
		cnt--;
		if (cnt <= 0) break;
	}	
	cout << ans << endl;
}