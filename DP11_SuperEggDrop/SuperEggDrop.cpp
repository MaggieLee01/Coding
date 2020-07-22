//������Ӽ�������
//https://leetcode-cn.com/problems/super-egg-drop/solution/ji-ben-dong-tai-gui-hua-jie-fa-by-labuladong/ ��labuladong���еĽ��⡿
//https://www.bilibili.com/video/BV1KE41137PK?from=search&seid=17973611971894816621 ����������ʦ���Ӽ������⡿

#include<vector>
#include<algorithm>
using namespace std;
//K��������N��¥
//д�����ˣ����Ŵ�д��
//int superEggDrop(int K, int N) 
//{
//	vector<vector<int>> dict(K+1, vector<int>(N+1, 0));
//	for (int i = 1; i <= N; i++) dict[1][i] = i;
//	for (int i = 1; i <= K; i++) dict[i][1] = 1;
//
//	//ת�Ʒ����������min������max���޷�һ����λ
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

//egg * floor�����񣬴�0��ʼ����ţ�����egg floor��Ӧ������Ϊdict[egg - 1][floor - 1]
//��ֹ�������￪ʼд�Ĳ��ã�
int dp(vector<vector<int>>& dict, int egg, int floor)
{
	if (egg < 1 || floor < 1) return 0;
	if (floor == 1) return 1;
	if (egg == 1) return floor;

	if (dict[egg - 1][floor - 1] != 0) return dict[egg - 1][floor - 1];
	int res = INT_MAX;
	for (int i = 1; i <= floor; i++)//floor=1ʱ�������ѭ����������Ҫ��ǰ����
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

//���Ŵ𰸣��ĳɶ�̬�滮�汾
int superEggDrop02(int K, int N) 
{
	vector<vector<int>> dict(K + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) dict[1][i] = i;
	for (int i = 1; i <= K; i++) dict[i][1] = 1;

	//ת�Ʒ����������min������max���޷�һ����λ
	for (int i = 2; i <= K; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			int temp = INT_MAX;
			for (int ll = 1; ll <= j; ll++)//ll�ǵ�0�㵽��j��¥��ı���ѽ������j��¥��ѡ����ʵĵ㣬������Ҫһ������
			{
				temp = min(temp, max(	dict[i - 1][ll - 1],
										dict[i][j - ll]) + 1 ) ;
			}
			dict[i][j] = temp;
		}		
	}
	return dict[K][N];
}

//���������Դ�1��j���Ա���Ѱ����Сֵ��dict[i - 1][ll - 1]����ll����������dict[i][j - ll]����ll�����ݼ�������ͨ�����ַ�Ѱ�����ߵ���Сֵ��
int superEggDrop03(int K, int N)
{
	vector<vector<int>> dict(K + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) dict[1][i] = i;
	for (int i = 1; i <= K; i++) dict[i][1] = 1;

	//ת�Ʒ����������min������max���޷�һ����λ
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
			//while�Ľ�ֹ����left=right�����Դ˴���left right һ��
			dict[i][j] = max(dict[i - 1][left - 1], dict[i][j - left]) + 1;
		}
	}
	return dict[K][N];
}

//�����dp�㷨�������ڻ������ر����ף�Ѱ��m������



int main(void)
{
	int ans = superEggDrop03(2, 6);
	return 0;
}