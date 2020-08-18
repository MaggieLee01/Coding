//2019-06-04
//https://mp.weixin.qq.com/s/TrN7mMdLEPCmT5mOXzgP5A
//��project�ĽⷨΪ�ݹ��㷨��ʱ�临�Ӷ�ΪO(n*n)��Ϊ���Ž�
//�����ڸ��ֱ����£���΢�޸Ŀ�ܼ��ɣ��ǳ��������
//���Ž�ķ���δ״̬��������һ��project����
//������������һ�ν���

#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::max;
using std::min;

//����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
//��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������
//ע���㲻���������Ʊǰ������Ʊ��
//leetcode-cn.com/problems/best-time-to-buy-and-sell-stock

//02������01������ܶ࣬����ͨ������
//�����������α�������ͨ������
int maxProfit_Once01(vector<int> & prices)
{
	int ans = 0;
	int Length = prices.size();
	if (Length != 0)
	{
		for (int buy = 0; buy < Length; buy++)
			for (int sell = buy + 1; sell < Length; sell++)
				ans = max(prices[sell] - prices[buy], ans);
	}
	return ans;
}

//�����˴𰸣����ű��������ʱ�䣬Ѱ�����������ֵ����ʱ�൱�������������ӣ�
//��������൱�����𽥼�С�������в�����ֵ����������൱���ڲ������ӵ������в�����ֵ
int BuySellStock_Once02(vector<int> &prices)
{
	int ans = 0;
	int Length = prices.size();
	if (Length != 0)
	{
		//���������buy����ֵ��buy�ĳ�ʼֵ����Ϊ0ѽ����������Ϊ�������������ʱ����ѽ
		int sell = 0;
		for (int buy = Length - 1; buy >= 0; buy--)
		{
			sell = max(prices[buy], sell);
			ans = max(sell - prices[buy], ans);
		}
	}
	return ans;
}

//����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
//���һ���㷨�����������ܻ�ȡ�������������Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����
//ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����
//leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii

//����˼�����ݹ�˼·��
//ÿ�����ݵ�������ѡ�񣬽���[��/��]���ǲ�����
//��Ʊ��״̬��0[����]��1[����]��2[����]��
//��Ʊ���ã�{1,0}
//��Ʊ�����룺{0,n}

//int BuySellStock_recursively(vector<int> prices, int index, int *status)
//{
//	int Length = prices.size();
//	if (Length == index) return 0;
//	
//	//���ף��ȿ���״̬
//	int doIt = 0;	
//	if (status[0] == 1)
//	{
//		status[0] = 0;
//		status[1] == prices[index];
//		doIt = BuySellStock_recursively(prices, index + 1, status);
//	}
//	if (status[1] != 0)
//	{
//		
//		doIt = prices[index] - status[1] + BuySellStock_recursively(prices, index + 1, status);
//		status[0] = 1;
//		status[1] = 0;
//	}
//	//�����ף��ѵ�Ҫ��������д�ڽ��׵ĺ��棿��
//	int doNot = BuySellStock_recursively(prices, index + 1, status);
//	return max(doIt, doNot);		
//}
//int BuySellStock_Times01(vector<int> prices)
//{
//	int Length = prices.size();
//	if (Length == 0) return 0;
//	int *status = new int[3]{1,0,0};
//	
//	int ans = BuySellStock_recursively(prices, 0, status);
//	return ans;
//}


/****************************************************************************************************/
//������ ���˴𰸣��Լ���ĺø���ѽ������
//���ϣ��ݹ��ʱ�������һ������Ϊ����
int Times_recursively(vector<int> prices, int index)
{
	int Length = prices.size();
	if (Length == index) return 0;
	//buy�ĳ�ʼֵ����Ϊ0ѽ����������Ϊ�������������ʱ����ѽ
	int ans = 0, sell = 0, buy = prices[index], profit = 0;
	for (sell = index; sell < Length; sell++)
	{
		buy = min(buy, prices[sell]);
		profit = max(profit, prices[sell] - buy);
		ans = max(ans, Times_recursively(prices, sell + 1) + profit);
	}
	return ans;
}
int BuySellStock_Times01(vector<int> prices)
{
	int Length = prices.size();
	if (Length == 0) return 0;
	int ans = Times_recursively(prices, 0);
	return ans;
}

//����¼������//��ȡ��������ʱ�����α���һ�α�����д�������ԣ����Ƕ���ʱ��
int Times_Dict(vector<int> prices, int index, int *Dict)
{
	int Length = prices.size();
	if (Length == index) return 0;
	if (Dict[index] != 0) return Dict[index];
	int ans = 0;
	for (int buy = index; buy < Length; buy++)
		for (int sell = buy + 1; sell < Length; sell++)
		{
			ans = max(ans, Times_Dict(prices, sell + 1, Dict) + prices[sell] - prices[buy]);
		}
	Dict[index] = ans;
	return Dict[index];
}
int BuySellStock_Times02(vector<int> prices)
{
	int Length = prices.size();
	if (Length == 0) return 0;
	int *Dict = new int[Length + 1]();
	int ans = Times_Dict(prices, 0, Dict);
	delete[]Dict;//ע��delete�����д��
	return ans;
}
//�𰸵�̰���㷨��ʡʱ
//��û̫�����̰���㷨
int BuySellStock_Greedy(vector<int> prices)
{
	int Length = prices.size();
	int ans = 0;
	for (int i = 1; i < Length; i++)
	{
		if (prices[i] > prices[i - 1])
			ans += prices[i] - prices[i - 1];
	}
	return ans;
}
/****************************************************************************************************/
//�н��״������ƣ�������һ����� k ������
//��������������һ�ν��ף������ݹ飬������������һ�ν���Ϊһ������
int kTimes_ConsultDict(vector<int> prices, int index, int k, vector <vector<int> > &Dict)
{
	int Length = prices.size();
	if (k <= 0) return 0;
	if (index >= Length) return 0;
	if (Dict[index][k] != -1) return Dict[index][k];
	int buy = prices[index], profit = 0, ans = 0;
	for (int sell = index + 1; sell < Length; sell++)
	{
		buy = min(prices[sell], buy);
		profit = max(profit, prices[sell] - buy);
		ans = max(ans, profit + kTimes_ConsultDict(prices, sell + 1, k - 1, Dict));
	}
	Dict[index][k] = ans;
	return ans;
}
int BuySellStocks_KTimes(vector<int> prices, int k)
{
	int Length = prices.size();
	if (Length == 0) return 0;
	vector <vector<int> > Dict(Length + 1, vector<int>(k + 1, -1));
	int ans = kTimes_ConsultDict(prices, 0, k, Dict);
	return ans;
}
/****************************************************************************************************/
//����������Ŀ���������ȥ�����Ѽ���
//��Ʊ������Ϊ1�죬�ݹ������ֵ���ǵ���1�����ǵ���2
int Frozen_Dict(vector<int>prices, int index, int *Dict)
{
	int Length = prices.size();
	if (index >= Length) return 0;
	if (Dict[index] != 0) return Dict[index];
	int buy = prices[index], profit = 0, ans = 0;
	for (int sell = index + 1; sell < Length; sell++)
	{
		buy = min(prices[sell], buy);
		profit = max(profit, prices[sell] - buy);
		ans = max(ans, profit + Frozen_Dict(prices, sell + 2, Dict));
	}
	Dict[index] = ans;
	return Dict[index];
}
int BuySellStock_Frozen(vector<int> prices)
{
	int Length = prices.size();
	if (Length == 0) return 0;
	int *Dict = new int[Length + 1]();//�˴���ʼ������Ҫ����ȻզDict������ֱ�Ӳ�Ϊ0����������
	int ans = Frozen_Dict(prices, 0, Dict);
	delete[]Dict;
	return ans;
}

/****************************************************************************************************/
int main(void)
{
	int ans2 = 0;
	vector<int> prices = { 5,2,7,9 };
	int ans = BuySellStock_Once02(prices);
	cout << ans << endl;

	prices = { 7,1,5,3,6,4 };
	ans = BuySellStock_Once02(prices);
	cout << ans << endl;

	prices = { 7,1,5,3,6,4 };
	ans = BuySellStock_Times01(prices);
	ans2 = BuySellStock_Times02(prices);
	cout << ans << ' ' << ans2 << endl;

	prices = { 1,2,3,4,5 };
	ans = BuySellStock_Times01(prices);
	ans2 = BuySellStock_Times02(prices);
	cout << ans << ' ' << ans2 << endl;

	prices = { 1, 8, 6, 9, 3, 2, 11 };
	ans = BuySellStock_Times01(prices);
	ans2 = BuySellStock_Times02(prices);
	cout << ans << ' ' << ans2 << endl;

	prices = { 3,2,6,5,0,3 };
	ans = BuySellStocks_KTimes(prices, 2);
	cout << ans << endl;

	prices = { 70, 4, 83, 56, 94, 72, 78, 43, 2, 86, 65, 100 };
	ans = BuySellStocks_KTimes(prices, 5);
	cout << ans << endl;

	return 0;
}