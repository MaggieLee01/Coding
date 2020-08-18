//2019-06-04
//https://mp.weixin.qq.com/s/TrN7mMdLEPCmT5mOXzgP5A
//此project的解法为递归算法，时间复杂度为O(n*n)，为次优解
//但是在各种变形下，稍微修改框架即可，非常便于理解
//最优解的方法未状态机，在下一个project里面
//买入卖出算是一次交易

#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::max;
using std::min;

//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
//注意你不能在买入股票前卖出股票。
//leetcode-cn.com/problems/best-time-to-buy-and-sell-stock

//02方法比01方法快很多，均已通过测试
//暴力法，两次遍历，已通过测试
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

//看完了答案，倒着遍历买入的时间，寻找卖出的最大值；此时相当于数据量的增加，
//正序遍历相当于在逐渐减小的数据中查找最值，倒序遍历相当于在不断增加的数据中查找最值
int BuySellStock_Once02(vector<int> &prices)
{
	int ans = 0;
	int Length = prices.size();
	if (Length != 0)
	{
		//如果不断求buy的最值，buy的初始值不能为0呀，这样子作为减数相减求利润时出错呀
		int sell = 0;
		for (int buy = Length - 1; buy >= 0; buy--)
		{
			sell = max(prices[buy], sell);
			ans = max(sell - prices[buy], ans);
		}
	}
	return ans;
}

//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii

//独立思考，递归思路，
//每个数据点有两种选择，交易[买/卖]还是不交易
//股票的状态，0[限制]、1[买入]、2[卖出]，
//股票闲置：{1,0}
//股票已买入：{0,n}

//int BuySellStock_recursively(vector<int> prices, int index, int *status)
//{
//	int Length = prices.size();
//	if (Length == index) return 0;
//	
//	//交易，先看看状态
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
//	//不交易，难道要将不交易写在交易的后面？？
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
//呜呜呜 看了答案，自己想的好复杂呀！！！
//答案上，递归的时候以完成一个交易为周期
int Times_recursively(vector<int> prices, int index)
{
	int Length = prices.size();
	if (Length == index) return 0;
	//buy的初始值不能为0呀，这样子作为减数相减求利润时出错呀
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

//备忘录方法，//求取单词利润时，两次遍历一次遍历的写法都可以，但是都超时了
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
	delete[]Dict;//注意delete数组的写法
	return ans;
}
//答案的贪心算法更省时
//还没太搞清楚贪心算法
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
//有交易次数限制，增加了一项参数 k 的限制
//买入卖出后算是一次交易，函数递归，就是买入卖出一次交易为一个周期
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
//含手续费题目，利润里减去手续费即可
//股票冻结期为1天，递归的索引值不是递增1，而是递增2
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
	int *Dict = new int[Length + 1]();//此处初始化很重要，不然咋Dict函数中直接不为0，返回乱码
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