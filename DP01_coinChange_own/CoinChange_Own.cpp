//����k����ֵ��Ӳ�ң���ֵ�ֱ�Ϊc1, c2 ... ck��
//ÿ��Ӳ�ҵ��������ޣ��ٸ�һ���ܽ��amount��
//����������Ҫ��öӲ�Ҵճ��������������ܴճ����㷨���� -1 ��
//https://mp.weixin.qq.com/s/1V3aHVonWBEXlNUvK3S28w 2019-05-14
//https://mp.weixin.qq.com/s/Cw39C9MY9Wr2JlcvBQZMcA 2019-11-30

//˼·��dp�����µ���Ŀ��dp�ļ����ã����Զ���coding
//û����ţ�ͻ���LeetCode���ԣ�Ӧ��û����

//#include<iostream>
//#include<vector>

//int coinChange(int[] coins, int amount);���ַ�����ͨ������
//coins ���ǿ�ѡӲ����ֵ��amount ��Ŀ����

//��������������⣺amount-c1 ... amount-ck
//�����⣺�Ƿ��ܴչ����չ��ĸ��������ٸ���

//********************�˷����������ڲ�ĵݹ鲻��ֱ�ӷ��ص������************
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

//********************���Կ˷���һ������************************
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
//	int minCoin = -1;//-1�ܴ�����Сֵʱ��ʼֵӦ������Ϊ�ܴ�
//	//int min = 0;	//-1�޷��Ƚϴ�С
//	if (amount > 0  && coins.size() > 0)
//	{
//		//���ѣ���α���δ֪���������飬�����Ե�for���ԣ��ο�����Ҳ��for��for��:��������vector
//		//���ڲ�֪���ʹVS2017֧��for�����ԣ��Ĳ���Ϊvector
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

//���˴𰸣�û�п��ǵ�������������һ�㣬
#include<iostream>
#include<vector>

//�ݹ鷽��
//int coinChange_recursively(std::vector<int> coins, int amount)
//{
//	int minCoin = -1;
//	std::vector<int> dict(amount + 1, amount + 1);
//	if (amount >= 0 && coins.size() > 0)
//	{
//		for (int i = 0; i < coins.size(); i++)
//		{
//			if (amount == 0) continue;//֮ǰ�ڴ˴����أ����׽���
//			int sub = coinChange_recursively(coins, amount - coins[i]);
//			if (sub == -1) continue;
//			dict[i] = ( (sub + 1) < dict[i] ? (sub + 1): dict[i] );			   
//		}
//	}
//	return minCoin;
//}

//�Լ�д������������
int coinChange_recursively(std::vector<int> coins, int amount)
{
	//���ϲ�����ȷ�Լ��
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
//������¼�ĵݹ鷽�������ݵݹ��˼·�Լ�д
int coinDict(std::vector<int>coins, int amount, std::vector<int> & dict)
{
	if (dict[amount] == INT_MAX && amount > 0)
	{
		for (int coin : coins)
		{
			if (amount - coin < 0) continue;
			int n = coinDict(coins, amount - coin, dict);
			if (n == INT_MAX) continue;//����޷��չ�������ִ������һ�У�
			//����Ϊ���ʱע�������м�һ��Ӱ��
			dict[amount] = (n + 1) < dict[amount] ? (n + 1) : dict[amount];//����޷��չ��Ļ����˴�n+1Ӱ�췵��ֵ��Ӧ���������һ���ж�
		}
	}
	return dict[amount];
}
int coinChange_recursively_dict(std::vector<int> coins, int amount)
{
	int minCoin = -1;
	if (amount >= 0 && coins.size() > 0)
	{
		std::vector<int> dict(amount + 1, INT_MAX);//���������ֵ���С������������
		dict[0] = 0;
		int subProb = coinDict(coins, amount, dict);
		minCoin = (subProb == INT_MAX ? -1 : subProb);
	}
	return minCoin;
}


//��̬�滮������д����¼�ĵݹ����Ȼд������̬�滮��ֱ��д����̬�滮Ŀǰ������
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
	//n = coinChange_recursively(coins, 103); �ݹ�̫����
	m = coinChange_recursively_dict(coins, 103);
	l = coinChange_dp(coins, 103);
	std::cout << n << ' ' << m << ' ' << l << std::endl;
}