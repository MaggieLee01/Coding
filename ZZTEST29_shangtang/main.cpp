#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//int main(void)
//{
//	int G = 0;
//	int o = 0;
//	int d = 0;
//	int ans = 0;
//
//	string str;
//	while (cin >> str)
//	{
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (str[i] == 'G')
//				G++;
//			if (str[i] == 'o' && G > 0)
//				o++;
//			if (str[i] == 'd' && G > 0 && o > 1)
//			{
//				ans++;
//				G--;
//				o -= 2;	
//			}
//		}
//	}	
//	cout << ans << endl;
//	return 0;
//}


void dfs(vector<vector<int>> nums, vector<vector<int>> &dict, int x, int y, int M, int N, vector<vector<int>>& flag)
{
	if (flag[x][y] == -1) return;
	flag[x][y] = -1;
	vector<int> dx = { 1,-1,0,0 };
	vector<int> dy = { 0,0,1,-1 };
	
	for (int i = 0; i < 4; i++)
	{
		int x_new = x + dx[i];
		int y_new = y + dy[i];
		if (0 <= x_new && x_new < M && 0 <= y_new && y_new < N)
		{
			if (nums[x][y] < nums[x_new][y_new])
			{
				dfs(nums, dict, x_new, y_new, M, N, flag);
				dict[x][y] = max(dict[x_new][y_new] + 1, dict[x][y]);
			}
		}
	}
}
int main(void)
 {
	int M = 0, N = 0;
	cin >> M >> N;
	vector<vector<int>> nums(M, vector<int>(N));
	vector<vector<int>> temp(M, vector<int>(N));
	vector<vector<int>> flag = nums;
	int ans = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> nums[i][j];
			temp[i][j] = 1;
		}
	}
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (temp[i][j] > 1) continue;
			flag = nums;
			dfs(nums, temp, i, j, M, N,flag);
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ans = max(ans, temp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}