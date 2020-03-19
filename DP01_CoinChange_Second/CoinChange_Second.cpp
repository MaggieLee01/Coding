/*	给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

	输入: coins = [1, 2, 5], amount = 11
	输出: 3 
	解释: 11 = 5 + 5 + 1

	https://leetcode-cn.com/problems/coin-change */
	//学习dp算法的第一个程序，LeetCode每日一练再次出现，再写一遍

#include<vector>
#include<iostream>
#include<algorithm>
using std::min;
using std::vector;

//先写备忘录的递归
int coinChange_Dict(vector<int>& coins, int amount, vector<int> & Dict)
{
	if (amount < 0) return -1;
	if (amount == 0) return 0;
	if (Dict[amount] != INT_MAX) return Dict[amount];

	int ans = INT_MAX;
	for (int coin : coins)
	{
		int n = coinChange_Dict(coins, amount - coin, Dict);
		if (n < 0) continue;
		else ans = min(ans, n + 1);
	}
	Dict[amount] = ans == INT_MAX ? -1 : ans;
	return Dict[amount];
}
int coinChange(vector<int>& coins, int amount)
{
	int num = coins.size();
	/*if (amount == 0) return 0;
	if (num < 1 || amount < 1) return -1;*/ //dict的函数里已经写了
	vector<int> Dict(amount + 1, INT_MAX);
	int res = coinChange_Dict(coins, amount, Dict);
	return res;
}
//转换为dp形式
int coinChange_dp(vector<int>& coins, int amount)
{
	int num = coins.size();
	vector<int> Dict(amount + 1, INT_MAX);
	Dict[0] = 0;
	for (int i = 1; i < amount + 1; i++)
	{
		for (int coin : coins)
		{
			if (i - coin < 0) continue;
			if (Dict[i - coin] != INT_MAX)//看答案，初始化为amount+1，则可以直接求min，无需判断溢出的情况
				Dict[i] = min(Dict[i], Dict[i - coin] + 1);
		}
	}
	return Dict[amount] == INT_MAX ? -1 : Dict[amount];	
}
int main(void)
{
	int m = 0, n = 0, l = 0;
	std::vector<int> coins = { 2,6 };
	n = coinChange(coins, 11);
	/*int m = coinChange(coins, 11);*/
	l = coinChange_dp(coins, 11);
	std::cout << n << ' ' << m << ' ' << l << std::endl;

	coins = { 2,3,5 };
	n = coinChange(coins, 11);
	/*m = coinChange_recursively_dict(coins, 11);*/
	l = coinChange_dp(coins, 11);
	std::cout << n << ' ' << m << ' ' << l << std::endl;

	coins = { 2,1,5 };
	n = coinChange(coins, 11);
	/*m = coinChange_recursively_dict(coins, 11);*/
	l = coinChange_dp(coins, 11);
	std::cout << n << ' ' << m << ' ' << l << std::endl;
	return 0;
}