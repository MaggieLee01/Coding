//腾讯的笔试题
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isOk(vector<int> num, int k)
{
	int cnt = 1;
	for (int i = 1; i < num.size(); i++)
	{
		if (num[i] == num[i - 1]) cnt++;
		else cnt = 1;
		if (cnt >= k) return true;
	}
	return cnt >= k;
}
int move(vector<int> h, int k)
{
	sort(h.begin(), h.end());
	if (isOk(h, k))
		return 0;

	h[0]++;
	int left = move(h, k) + 1;
	h[0]--;
	h[h.size() - 1]--;
	int right = move(h, k) + 1;
	h[h.size() - 1]++;
	return min(left, right);
}
int main(void)
{
	//int cnt = 0, k = 0;
	//vector<int> h(cnt, 0);
	//cin >> cnt >> k;//测试次数
	//for (int i = 0; i < cnt; i++)
	//{
	//	cin >> h[i];
	//}
	vector<int> h = { 1,2,2,4,2,3 };
	int ans = move(h, 5);
	cout << ans << endl;
	return 0;
}