//	招行比赛,已AC
/*	小招在玩一款游戏：在一个N层高的金字塔上，以金字塔顶为第一层，第i层有i个落点，每个落点有若干枚金币，
	在落点可以跳向左斜向下或向右斜向下的落点。若知道金字塔的层数N及每层的金币数量分布，
	请计算小招在本次游戏中可以获得的最多金币数量。
	题目描述有误，根据自测样例，是 左向下 和 右斜向下
*/
//https://ac.nowcoder.com/acm/problem/205266?&headNav=acm
//用的dp算法，从下往上找最值
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int  getmax(vector<vector<int>> h,int cnt)
{
	vector<int> ans(h[cnt - 1]);
	vector<int> temp(cnt, 0);

	for (int i = cnt - 2; i >= 0; i--)
	{
		//temp[0] = h[i][0] + ans[1];
		for (int j = 0; j <= i; j++)
		{
			temp[j] = h[i][j] + max(ans[j], ans[j + 1]);
		}
		for (int j = 0; j <= i; j++)
			ans[j] = temp[j];
		ans[i + 1] = 0;
	}
	return ans[0];
}
int main(void)
{
	int cnt = 0;
	cin >> cnt;//测试次数
	vector<vector<int>> h(cnt);
	for (int i = 0; i < cnt; i++)
	{
		h[i].resize(i + 1);
		for (int j = 0; j <= i; j++)
		{
			cin >> h[i][j];
		}
	}
	//vector<vector<int>> h = { {8},{3,8},{8,1,0},{4,7,5,4},{3,5,2,6,5} };
	int ans = getmax(h, cnt);
	cout << ans << endl;
	return 0;
}