//十进制转5进制
#include<iostream>
#include<string>
#include<limits>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
void tran(int num)
{
	if (num == 0) return;
	tran(num / 5);
	cout << num % 5;
}
//int main(void)
//{
//	string str;
//	cin >> str;
//	int num = 0;
//	int i = str.size() - 1;
//	while (str[i] == '0') i--;
//	for (; i >= 0; i--)
//		num = (str[i] - '0') + num * 10;
//	tran(num);
//	return 0;
//}

int dp(vector<int> vec, int i,int j, int ans, int m, vector<int>& dict)
{
	if (j < 0) return 0;
	if (m <= 0)
	{
		if (m == 0)
		{			
			dict[i] ++;
		}
		return dict[i];
	}
	dp(vec, i, j - 1, ans, m - vec[j], dict);
}
//int main(void)
//{
//	int N = 0, M = 0;
//	cin >> N >> M;
//	vector<int> vec(N);
//
//	for (int i = 0; i < N; i++)
//		cin >> vec[i];
//	sort(vec.begin(), vec.end());
//	int ans = 0;
//	vector<int> dict(M + 1);
//	dict[0] = 1;
//	for (int i = 1; i <= M; i++)
//	{
//		for (int j = N - 1; j >= 0; j--)
//		{
//			if (i - vec[j] >= 0)
//				dict[i] = (dict[i] + dict[i - vec[j]]) % 1000000007;
//			//dict[i] = dp(vec, i, j, ans, i - vec[j], dict);
//		}
//	}
//	cout << dict[M] << endl;
//	return 0;
//}

//int main(void)
//{
//	string s;
//	char a, b;
//	char a1, b1;
//	cin >> s;
//	cin >> a >> b;
//	if ('a' <= a && a <= 'z') a1 = a + 32;
//	if ('A' <= a && a <= 'A') a1 = a - 32;
//	if ('a' <= b && b <= 'z') b1 = a + 32;
//	if ('A' <= b && b <= 'A') b1 = a - 32;
//	int a_left = INT_MAX;
//	int b_left = INT_MAX;
//	int a_right = INT_MIN;
//	int b_right = INT_MIN;
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] == a || s[i] == a1)
//			a_left = min(a_left, i);
//		if (s[i] == b || s[i] == b1)
//			b_left = min(b_left, i);
//		if (s[i] == a || s[i] == a1)
//			a_right = max(a_right, i);
//		if (s[i] == b || s[i] == b1)
//			b_right = max(a_right, i);
//	}
//	int ans = max(abs(b_right - a_left), abs(a_right - b_left));
//	cout << ans << endl;
//	return 0;
//}

int main(void)
{
	int A = 0, B = 0, C = 0, N = 0;
	cin >> A >> B >> C >> N;
	int aa, ab, ba, bb, ca, cb;
	cin >> aa >> ab;
	cin >> ba >> bb;
	cin >> ca >> cb;
	for (int i = 0; i < N; i++)
	{
		int b_new = aa * A + cb * C;
		int a_new = ba * B + ca * C;
		int c_new = ab * A + bb * B;
		A += a_new % 1000000007;
		B += b_new % 1000000007;
		C += c_new % 1000000007;
	}
	cout << A << ' ' << B << ' ' << C << endl;
	return 0;
}