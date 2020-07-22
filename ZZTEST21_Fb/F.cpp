#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	vector<string> ans(n);
	vector<int> nums{ 1,1,2,0,2,2,1,0 };
	for (int i = 0; i < n; i++)
	{
		int A = 0, B = 0, N = 0;
		cin >> A >> B >> N;

		if (A % 3 == 1 && B % 3 == 1)
		{
			if (nums[N % 7] == 0) ans[i] = "YES";
			else ans[i] = "NO";
		}
		else if (A % 3 == 1 && B % 3 == 2)
		{
			if (nums[(N+1) % 7] == 0) ans[i] = "YES";
			else ans[i] = "NO";
		}
		else if (A % 3 == 2 && B % 3 == 0)
		{
			if (nums[(N + 2) % 7] == 0) ans[i] = "YES";
			else ans[i] = "NO";
		}
		else if (A % 3 == 0 && B % 3 == 2)
		{
			if (nums[(N + 3) % 7] == 0) ans[i] = "YES";
			else ans[i] = "NO";
		}
		else if (A % 3 == 2 && B % 3 == 2)
		{
			if (nums[(N + 4) % 7] == 0) ans[i] = "YES";
			else ans[i] = "NO";
		}
		else if (A % 3 == 2 && B % 3 == 1)
		{
			if (nums[(N + 5) % 7] == 0) ans[i] = "YES";
			else ans[i] = "NO";
		}
		else if (A % 3 == 1 && B % 3 == 0)
		{
			if (nums[(N + 6) % 7] == 0) ans[i] = "YES";
			else ans[i] = "NO";
		}
		else if (A % 3 == 0 && B % 3 == 1)
		{
			if (nums[(N + 7) % 7] == 0) ans[i] = "YES";
			else ans[i] = "NO";
		}
	}
	for (string s : ans)
		cout << s << endl;
	return 0;
}