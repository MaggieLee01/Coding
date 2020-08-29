#include<iostream>
#include<vector>
#include<math.h>
#include<utility>
#include<algorithm>
using namespace std;

//int main(void)
//{
//	bool full = false;
//	int N = 0;
//	cin >> N;
//	vector<int> vec(N + 1);
//	vector<int> ans;
//	for (int i = 1; i <= N; i++)
//		cin >> vec[i];
//	int depth = log2(N);
//	for (int i = 0; i <= depth; i++)
//		ans.push_back(vec[pow(2, i)]);
//	for (int i = pow(2, depth) + 1; i <= N; i++)
//		ans.push_back(vec[i]);
//	for (int i = N / 2 + 1; i < (pow(2, depth)) - 1; i++)
//		ans.push_back(vec[i]);
//
//	int i = (pow(2, depth)) - 1;
//	while (i > 1)
//	{
//		ans.push_back(vec[i]);
//		i = i / 2;
//	}
//	for(int i=0;i<ans.size();i++)
//		cout << ans[i] << ' ';
//	cout << endl;
//
//	return 0;
//}
int MaxSum(int N, vector<int>a)
{
	int sum = 0, b = 0;
	for (int i = 0; i < N; i++)
	{
		if (b > 0)
			b += a[i];
		else
			b = a[i];
		sum = max(b, sum);
	}
	return sum;
}
int main(void)
{
	int M = 0, N = 0;
	cin >> M >> N;
	vector<vector<int>> vec(M, vector<int>(N));
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> vec[i][j];
	}

	int ans = 0;
	vector<int> b(N);
	for (int i = 0; i < M; i++)
	{
		for (int j = i; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				b[k] += vec[j][k];
				ans = max(MaxSum(N, b),ans);			
			}
		}			
	}
	cout<< ans;
}