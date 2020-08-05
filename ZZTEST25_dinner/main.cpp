//拼多多 提前批 笔试题 吃晚饭
#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

bool cmp(vector<int> vec1, vector<int> vec2)
{
	if (vec1[1] == vec2[1])
		return vec1[0] < vec2[0];
	return vec1[1] > vec2[1];
}

//超时，通过75%
int main(void)
{
	int m = 0, n = 0, T = 0;
	cin >> m >> n >> T;
	vector<vector<int>> lunch(m, vector<int>(2));
	vector<vector<int>> dinner(n, vector<int>(2));
	for (int i = 0; i < m; i++)
		cin >> lunch[i][0] >> lunch[i][1];
	for (int i = 0; i < n; i++)
		cin >> dinner[i][0] >> dinner[i][1];

	sort(lunch.begin(), lunch.end(), cmp);
	sort(dinner.begin(), dinner.end(), cmp);

	int ans = 2147483647;
	if (T == 0)	ans = 0;	
	if ((lunch[0][1] + dinner[0][1]) < T) ans = -1;
	else
	{
		for (int i = 0; i < m; i++)
		{
			if (i > 0 && lunch[i][1] == lunch[i - 1][1]) break;
			if ((lunch[i][1] + dinner[0][1]) < T) break;
			if (lunch[i][1] >= T)
				ans = min(ans, lunch[i][0]);
			for (int j = 0; j < n; j++)
			{				
				if (dinner[j][1] >= T)
					ans = min(ans, dinner[j][0]);
				else if ((lunch[i][1] + dinner[j][1]) >= T)
					ans = min(ans, lunch[i][0] + dinner[j][0]);
				else
					break;
			}
		}
	}	
	if (ans == 2147483647) ans = -1;
	cout << ans << endl;	
	return 0;
}

//通过94%
//int main(void)
//{
//	int dis = 0, num = 0;
//	cin >> dis >> num;
//	vector<int> vec(num);
//
//	int length = 0;
//	int flag = 0;
//	int back = 0;
//	for (int i = 0; i < num; i++)
//	{
//		cin >> vec[i];
//		length += vec[i];
//		if (length == dis) flag = 1;
//		else if (length > dis)
//		{
//			length = dis - (length - dis);
//			back++;
//		}
//	}
//	if (flag == 1) cout << "paradox" << endl;
//	else
//		cout << length - dis << ' ' << back << endl;
//	return 0;	
//}

//void bfs(vector<vector<char>> &vec, vector<vector<int>> &num, int m, int n)
//{
//	num[m][n] = 6;
//	vec[m][n] = '$';
//	if (0 <= (m + 1) < 6 && vec[m + 1][n] == '#')
//	{
//		num[m + 1][n] = 5;
//	}
//	if (0 <= (n + 1) < 6 && vec[m][n + 1] == '#')
//	{
//		num[m ][n + 1] = 5;
//	}
//
//}
//int main(void)
//{
//	vector<vector<char>> vec(6, vector<char>(6));
//	vector<vector<int>> num(6, vector<int>(6,-1));
//	for (int i = 0; i < 6; i++)	
//		cin >> vec[i][0] >> vec[i][1] >> vec[i][2] >> vec[i][3] >> vec[i][4] >> vec[i][5];
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = 0; j < 6; j++)
//			if (vec[i][j] == '#')
//				bfs(vec, num, i, j);
//	}
//	
//}
//
