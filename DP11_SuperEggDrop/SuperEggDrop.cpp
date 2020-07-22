//经典的扔鸡蛋问题
//https://leetcode-cn.com/problems/super-egg-drop/solution/ji-ben-dong-tai-gui-hua-jie-fa-by-labuladong/ 【labuladong大佬的讲解】
//https://www.bilibili.com/video/BV1KE41137PK?from=search&seid=17973611971894816621 【李永乐老师讲扔鸡蛋问题】

#include<vector>
#include<algorithm>
using namespace std;
//K个鸡蛋，N层楼
//写不好了，看着答案写吧
//int superEggDrop(int K, int N) 
//{
//	vector<vector<int>> dict(K+1, vector<int>(N+1, 0));
//	for (int i = 1; i <= N; i++) dict[1][i] = i;
//	for (int i = 1; i <= K; i++) dict[i][1] = 1;
//
//	//转移方程里面既求min，又求max，无法一步到位
//	for (int i = 2; i <= K; i++)
//	{
//		for (int j = 2; j <= N; j++)
//		{
//			int temp = INT_MAX;
//			for (int l = 2; l <= j; l++)
//			{
//				temp = min(temp, max(dict[l -1][j - 1], dict[l][N - j]) + 1);
//			}
//			dict[i][j] = temp;
//		}		
//	}
//	return dict[K][N];
//}

//egg * floor个方格，从0开始的序号，所以egg floor对应的坐标为dict[egg - 1][floor - 1]
//截止条件这里开始写的不好，
int dp(vector<vector<int>>& dict, int egg, int floor)
{
	if (egg < 1 || floor < 1) return 0;
	if (floor == 1) return 1;
	if (egg == 1) return floor;

	if (dict[egg - 1][floor - 1] != 0) return dict[egg - 1][floor - 1];
	int res = INT_MAX;
	for (int i = 1; i <= floor; i++)//floor=1时不会进入循环，所以需要提前返回
	{
		res = min(res, max(	dp(dict, egg, floor - i), 
							dp(dict, egg - 1, i - 1) ) + 1);
	}
	dict[egg - 1][floor - 1] = res;
	return res;
}
int superEggDrop(int K, int N)
{
	vector<vector<int>> dict(K, vector<int>(N, 0));
	for (int i = 0; i < N; i++) dict[0][i] = i + 1;
	for (int i = 0; i < K; i++) dict[i][0] = 1;
	int ans = dp(dict, K, N);
	return ans;
}

//看着答案，改成动态规划版本
int superEggDrop02(int K, int N) 
{
	vector<vector<int>> dict(K + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) dict[1][i] = i;
	for (int i = 1; i <= K; i++) dict[i][1] = 1;

	//转移方程里面既求min，又求max，无法一步到位
	for (int i = 2; i <= K; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			int temp = INT_MAX;
			for (int ll = 1; ll <= j; ll++)//ll是第0层到第j层楼层的遍历呀，对于j层楼，选择合适的点，所以需要一点点遍历
			{
				temp = min(temp, max(	dict[i - 1][ll - 1],
										dict[i][j - ll]) + 1 ) ;
			}
			dict[i][j] = temp;
		}		
	}
	return dict[K][N];
}

//上面是线性从1到j线性遍历寻找最小值，dict[i - 1][ll - 1]关于ll单调递增，dict[i][j - ll]关于ll单调递减，可以通过二分法寻找两者的最小值，
int superEggDrop03(int K, int N)
{
	vector<vector<int>> dict(K + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) dict[1][i] = i;
	for (int i = 1; i <= K; i++) dict[i][1] = 1;

	//转移方程里面既求min，又求max，无法一步到位
	for (int i = 2; i <= K; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			int left = 1, right = j;
			while (left < right)
			{
				int mid = ((right - left) >> 1) + left;
				if (dict[i - 1][mid - 1] < dict[i][j - mid])
					left = mid + 1;
				else right = mid;
			}
			//while的截止条件left=right，所以此处用left right 一样
			dict[i][j] = max(dict[i - 1][left - 1], dict[i][j - left]) + 1;
		}
	}
	return dict[K][N];
}

//逆向的dp算法，到现在还不是特别明白，寻找m个鸡蛋



int main(void)
{
	int ans = superEggDrop03(2, 6);
	return 0;
}