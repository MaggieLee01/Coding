// 两道全AC
// 寻找小于n的两个数字的最大公约数
#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

//int gcd(int a, int b)
//{
//	if (a == 0) return b;
//	else
//		return gcd(b%a, a);
//}
//int main(void)
//{
//	int N = 0;
//	cin >> N;
//	for (int m = 0; m < N; m++)
//	{
//		int num = 0;
//		int ans = 0;
//		cin >> num;
//		
//		ans = num / 2;
//		cout << ans << endl;	
//	}
//	return 0;
//}

int main(void)
{
	string chara = "abcdefghijklmnopqrstuvwxyz";
	int T = 0;
	cin >> T;
	int n = 0;
	for (int m = 0; m < T; m++)
	{
		int num = 0;
		cin >> num;
		vector<int> vec(num);
		vector<string> ans(num + 1);
		for (int i = 0; i < num; i++)
		{
			cin >> vec[i];
			if (vec[i] == 0)
			{
				ans[i] += chara[n % 26];
				n++;
				ans[i + 1] += chara[n % 26];
				n++;
			}
			for (int j = 0; j < vec[i]; j++)
			{
				if (j < ans[i].size())
					ans[i + 1] += ans[i][j];
				else
				{
					ans[i] += chara[n % 26];
					ans[i + 1] += chara[n % 26];
					n++;
				}
			}
		}
		for (int i = 0; i <= num; i++)
		{
			cout << ans[i]<<endl;
		}
	}
	return 0;
}