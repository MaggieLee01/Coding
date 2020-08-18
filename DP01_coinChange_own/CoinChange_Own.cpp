//给你k种面值的硬币，面值分别为c1, c2 ... ck，
//每种硬币的数量无限，再给一个总金额amount，
//问你最少需要几枚硬币凑出这个金额，如果不可能凑出，算法返回 -1 。
//https://mp.weixin.qq.com/s/1V3aHVonWBEXlNUvK3S28w 2019-05-14
//https://mp.weixin.qq.com/s/Cw39C9MY9Wr2JlcvBQZMcA 2019-11-30

//思路：dp文章下的题目，dp的简单易用，尝试独立coding
//没有在牛客或者LeetCode测试，应该没问题

//#include<iostream>
//#include<vector>

//int coinChange(int[] coins, int amount);这种方法不通过编译
//coins 中是可选硬币面值，amount 是目标金额

//暴力解决：子问题：amount-c1 ... amount-ck
//子问题：是否能凑够、凑够的个数，最少个数

//********************此方法错误，最内层的递归不能直接返回到最外层************
//int numCoin = 0;
//int NumOfGather(std::vector<int>coins, int amount)
//{
//	if (amount >= 0 && coins.size() > 0)
//	{
//		if (amount == 0)
//			return numCoin;
//		for (int i = 0; i < coins.size(); i++)
//		{
//			numCoin++;
//			NumOfGather(coins, amount - coins[i]);
//		}
//	}
//	return numCoin;
//}

//********************尝试克服上一个问题************************
//int numCoin = 0;
//int NumOfGather(std::vector<int>coins, int amount)
//{
//	if (amount >= 0 && coins.size() > 0)
//	{
//		if (amount == 0)
//			return 0;
//		for (int i = 0; i < coins.size(); i++)
//		{
//			numCoin++;
//			return  ( NumOfGather(coins, amount - coins[i]) + 1);
//		}
//	}
//	return numCoin;
//}

//int coinChange(std::vector<int> coins, int amount)
//{
//	int minCoin = -1;//-1很大，求最小值时初始值应该设置为很大
//	//int min = 0;	//-1无法比较大小
//	if (amount > 0  && coins.size() > 0)
//	{
//		//困难：如何遍历未知个数的数组，新特性的for可以，参考文章也是for，for的:遍历用于vector
//		//现在不知如何使VS2017支持for新特性，改参数为vector
//		for (int i = 0; i < coins.size(); i++)
//		{
//			int n = NumOfGather(coins, amount - coins[i]);
//			if (n != 0)
//				if (minCoin > n)
//					minCoin = n;
//		}
//	}
//	return minCoin;
//}

//看了答案，没有考虑到最优子问题这一点，
#include<iostream>
#include<vector>

//递归方法
//int coinChange_recursively(std::vector<int> coins, int amount)
//{
//	int minCoin = -1;
//	std::vector<int> dict(amount + 1, amount + 1);
//	if (amount >= 0 && coins.size() > 0)
//	{
//		for (int i = 0; i < coins.size(); i++)
//		{
//			if (amount == 0) continue;//之前在此处返回，容易进坑
//			int sub = coinChange_recursively(coins, amount - coins[i]);
//			if (sub == -1) continue;
//			dict[i] = ( (sub + 1) < dict[i] ? (sub + 1): dict[i] );			   
//		}
//	}
//	return minCoin;
//}

//自己写不出来，看答案
int coinChange_recursively(std::vector<int> coins, int amount)
{
	//加上参数正确性检测
	if (amount == 0) return 0;
	int ans = INT_MAX;
	for (int coin : coins)
	{
		if (amount - coin < 0) continue;
		int subProb = coinChange_recursively(coins, amount - coin);
		if (subProb == -1) continue;
		ans = (ans < (subProb + 1) ? ans : (subProb + 1));
	}
	return ans == INT_MAX ? -1 : ans;
}
//带备忘录的递归方法，根据递归的思路自己写
int coinDict(std::vector<int>coins, int amount, std::vector<int> & dict)
{
	if (dict[amount] == INT_MAX && amount > 0)
	{
		for (int coin : coins)
		{
			if (amount - coin < 0) continue;
			int n = coinDict(coins, amount - coin, dict);
			if (n == INT_MAX) continue;//如果无法凑够，则不能执行下面一行，
			//设置为最大时注意对其进行加一的影响
			dict[amount] = (n + 1) < dict[amount] ? (n + 1) : dict[amount];//如果无法凑够的话，此处n+1影响返回值，应该在上面加一句判断
		}
	}
	return dict[amount];
}
int coinChange_recursively_dict(std::vector<int> coins, int amount)
{
	int minCoin = -1;
	if (amount >= 0 && coins.size() > 0)
	{
		std::vector<int> dict(amount + 1, INT_MAX);//将各个数字的最小数量存入数组
		dict[0] = 0;
		int subProb = coinDict(coins, amount, dict);
		minCoin = (subProb == INT_MAX ? -1 : subProb);
	}
	return minCoin;
}


//动态规划方法，写备忘录的递归后依然写不出动态规划，直接写出动态规划目前很困难
int coinChange_dp(std::vector<int> coins, int amount)
{
	std::vector<int> dict(amount + 1, amount + 1);
	dict[0] = 0;
	for (int i = 0; i < dict.size(); i++)
	{
		for (int coin : coins)
		{
			if (i - coin < 0) continue;
			dict[i] = (dict[i] < (1 + dict[i - coin]) ? dict[i] : (1 + dict[i - coin]));
		}
	}
	return (dict[amount] == amount + 1) ? -1 : dict[amount];
}
int main(void)
{
	std::vector<int> coins = { 2,6 };
	int n = coinChange_recursively(coins, 11);
	int m = coinChange_recursively_dict(coins, 11);
	int l = coinChange_dp(coins, 11);
	std::cout << n << ' ' << m << ' ' << l << std::endl;

	coins = { 2,3,5 };
	n = coinChange_recursively(coins, 11);
	m = coinChange_recursively_dict(coins, 11);
	l = coinChange_dp(coins, 11);
	std::cout << n << ' ' << m << ' ' << l << std::endl;

	coins = { 2,1,5 };
	n = coinChange_recursively(coins, 11);
	m = coinChange_recursively_dict(coins, 11);
	l = coinChange_dp(coins, 11);
	std::cout << n << ' ' << m << ' ' << l << std::endl;

	coins = { 2,1,5 };
	n = coinChange_recursively(coins, 12);
	m = coinChange_recursively_dict(coins, 12);
	l = coinChange_dp(coins, 12);
	std::cout << n << ' ' << m << ' ' << l << std::endl;

	coins = { 2,1,5 };
	n = coinChange_recursively(coins, 4);
	m = coinChange_recursively_dict(coins, 4);
	l = coinChange_dp(coins, 4);
	std::cout << n << ' ' << m << ' ' << l << std::endl;

	coins = { 2,1,5 };
	//n = coinChange_recursively(coins, 103); 递归太慢了
	m = coinChange_recursively_dict(coins, 103);
	l = coinChange_dp(coins, 103);
	std::cout << n << ' ' << m << ' ' << l << std::endl;
}