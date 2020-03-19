/*	������ͬ����Ӳ�� coins ��һ���ܽ�� amount����дһ��������������Դճ��ܽ����������ٵ�Ӳ�Ҹ��������û���κ�һ��Ӳ�����������ܽ����� -1��

	����: coins = [1, 2, 5], amount = 11
	���: 3 
	����: 11 = 5 + 5 + 1

	https://leetcode-cn.com/problems/coin-change */
	//ѧϰdp�㷨�ĵ�һ������LeetCodeÿ��һ���ٴγ��֣���дһ��

#include<vector>
#include<iostream>
#include<algorithm>
using std::min;
using std::vector;

//��д����¼�ĵݹ�
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
	if (num < 1 || amount < 1) return -1;*/ //dict�ĺ������Ѿ�д��
	vector<int> Dict(amount + 1, INT_MAX);
	int res = coinChange_Dict(coins, amount, Dict);
	return res;
}
//ת��Ϊdp��ʽ
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
			if (Dict[i - coin] != INT_MAX)//���𰸣���ʼ��Ϊamount+1�������ֱ����min�������ж���������
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