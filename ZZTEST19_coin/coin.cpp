//	���б���,��AC
/*	С������һ����Ϸ����һ��N��ߵĽ������ϣ��Խ�������Ϊ��һ�㣬��i����i����㣬ÿ�����������ö��ң�
	��������������б���»�����б���µ���㡣��֪���������Ĳ���N��ÿ��Ľ�������ֲ���
	�����С���ڱ�����Ϸ�п��Ի�õ������������
	��Ŀ�������󣬸����Բ��������� ������ �� ��б����
*/
//https://ac.nowcoder.com/acm/problem/205266?&headNav=acm
//�õ�dp�㷨��������������ֵ
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
	cin >> cnt;//���Դ���
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