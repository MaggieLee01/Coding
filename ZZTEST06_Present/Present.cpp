//平分的可能性
#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	int n = 0, m = 0, a = 0, b = 0;
	cin >> n >> m >> a >> b;
	int ans = 0;
	//int ans1 = 0, ans2 = 0;
	//小朋友n少，礼物m多
	if (n < m)
	{
		int need1 = n % m;
		int need2 = n - n % m;
		ans = need2 * min(a, b);
	}
	else//小朋友多，礼物少
	{
		int need1 = n - m;
		ans = min(a, b)* need1;
	}
	cout << ans << endl;
	return 0;
}