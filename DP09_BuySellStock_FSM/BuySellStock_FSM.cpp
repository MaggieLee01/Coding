//2019-06-07 ״̬������
//�ݹ���ʵ�Ƿ�������˼�����߼��ģ�һ�����ƽ��������޷�����ľͶ����ݹ飬һ��С�ľ��������ˣ��ɶ��Ի��ܺá�
//ȱ�����һ��������Ҳ�������ҵ�������ֵ�ԭ�򡣻��м������࣬��ȷʵ�������ҵ���
//״̬�������У�dp[][][]��ʾ��ʱ���е�Ǯ����������һ��project����һ֧��Ʊ������ɺ������

//״̬�����ҵ�����״̬�����Ҹ���״̬�µ�����ѡ��
//�ϸ�projectҲ��������״̬��������û������״̬��ѡ��Ĺ�ϵ��
//��������Ӧ��Ϊѡ��״̬ͨ���Ӽ�������ѡ�����������һ��״̬
//���壬0��ʾ����û�й�Ʊ
//dp[i][k][0]��ʾ��i�콻����k�Σ�����û�й�Ʊʱ�������Ǯ

//���޴εĻ���̰���㷨��״̬���죬����̰�����ƶ࣬״̬���ݹ��ܵ�ʵ����ǿ

//����ͨ��LeetCode����

#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::endl;
/****************************************************************************************************/
int Stock_Once01(vector<int> prices)
{
	int Length = prices.size();
	vector<vector<int> > dp(Length, vector<int>(2, 0));

	//��֪����γ�ʼ����������
	//int *dp[2] = new int[Length - 1][2]{0};

	//base case
	dp[0][0] = 0;			//û���Ʊû��Ǯ
	dp[0][1] = -prices[0];	//���˹�Ʊ����Ǯ
	for (int i = 1; i < Length; i++)	
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][1], -prices[i]);
	}
	return dp[Length - 1][0];
}
//���ٿռ��ռ��
int Stock_Once02(vector<int> prices)
{
	int Length = prices.size();
	//��0���״̬��ʼ��
	//int i_0 = 0, i_1 = -prices[0];��ʱ��Ҫ��֤��Ԫ�أ�����ֱ����-1���״̬��ʼ����ѭ����0��ʼ
	int i_0 = 0, i_1 = INT_MIN;
	for (int i = 0; i < Length; i++)
	{
		i_0 = max(i_0, i_1 + prices[i]);
		i_1 = max(i_1, -prices[i]);
	}
	return i_0;
}
/****************************************************************************************************/
//���޴�
int Stock_Times(vector<int> prices)
{
	int Length = prices.size();
	//��0���״̬��ʼ��
	//int i_0 = 0, i_1 = -prices[0];
	int i_0 = 0, i_1 = INT_MIN;
	for (int i = 0; i < Length; i++)
	{
		i_0 = max(i_0, i_1 + prices[i]);
		i_1 = max(i_1, i_0 - prices[i]);//һ�ε�ʱ��ڶ���ֱ��Ϊ-prices[i]������һ�²�ͬ
	}
	return i_0;
}
/****************************************************************************************************/
//������һ��
int Stock_Frozen01(vector<int> prices)
{
	int Length = prices.size();
	vector<vector<int> > dp(Length, vector<int>(2, 0));
	if (Length <= 2)
	{
		if (Length == 2 && prices[1] > prices[0])
			return prices[1] - prices[0];
		else return 0;
	}
	//base case
	//�˴���Ҫ��֤�����������
	dp[0][0] = 0;			//û���Ʊû��Ǯ
	dp[0][1] = -prices[0];	//���˹�Ʊ����Ǯ
	dp[1][0] = max(0, prices[1] - prices[0]);
	dp[1][1] = max(-prices[0], -prices[1]);
	for (int i = 2; i < Length; i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);//�����Ʊ�Ļ�������������ǰ���˹�Ʊ
	}
	return dp[Length - 1][0];
}
//˼����α��O(1)�Ŀռ䣬��ǰ����״̬�й�ϵ
//���޴�
int Stock_Frozen02(vector<int> prices)
{
	int Length = prices.size();
	if (Length <= 1) return 0;
	//��0���״̬��ʼ����prices��0��ʼ�ġ�
	int i_0 = 0, i_1 = -prices[0];
	//��0��֮ǰ��
	int before_0 = 0;
	int temp = 0;
	for (int i = 1; i < Length; i++)
	{
		temp = i_0;
		i_0 = max(i_0, i_1 + prices[i]);
		i_1 = max(i_1, before_0 - prices[i]);
		before_0 = temp;
	}
	return i_0;
}
/****************************************************************************************************/
//�о��彻�״��������ƣ�k�о������ֵ
int Stock_kTimes01(vector<int> prices,int k)
{
	int Length = prices.size();
	if (Length <= 1) return 0;//base case��Ҫ��֤��ֵ
	if (k > Length >> 1) return Stock_Times(prices);//k����length/2ʱ��k���Ʋ�������
	//ò��newֻ���𽥷���
	//int ***dp = new int[Length][n][2];��ͨ��
	//vector���캯������
	//std::vector<int> second(4, 100);     four ints with value 100
	vector< vector< vector<int> > > dp(Length, vector<vector<int> >(k + 1, vector<int>(2,0)));
	//base case
	for (int i = 0; i < Length; i++)
	{
		dp[i][0][0] = 0;
		dp[i][0][1] = INT_MIN;
	}
	for (int i = 0; i < k + 1; i++)
	{
		dp[0][i][0] = 0;
		dp[0][i][1] = -prices[0];
	}
	
	for (int i = 1; i < Length; i++)
	{
		for (int j = 1; j < k + 1; j++)
		{
			dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
			dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
		}
	}
	//�����������Ʊһֱ�ݼ�������������Ҳ���������һ�ν��ף�����Ϊ0����˲���������Ž��״�������������С�����
	//���Ե�k�ν����������
	return dp[Length - 1][k][0];
}
//��֪����ô��άѽ���ο�labuladong��������
int Stock_kTimes02(vector<int> prices, int k)
{
	int Length = prices.size();
	if (Length <= 1) return 0;						//base case��Ҫ��֤��ֵ
	if (k > Length >> 1) return Stock_Times(prices);//k����length/2ʱ��k���Ʋ�������
	vector< vector<int> >  dp(k + 1, vector<int>(2, 0));
	//˼����ά����ά������ά����ѽ����Ҫ��i�ı仯�ڸ��£�����ֱ��ȥ��i����ά�ȵĻ���
	//base case
	for (int j = k; j > 0; j--)
	{
		dp[j][0] = 0;
		dp[j][1] = -prices[0];
	}
	//�е��벻����Ϊʲô����ֱ�ӽ�ά��j�仯��dp[j][1]�ͱ�ʾ���i�µ�״̬�ˣ�Ϊʲô���ǿ����� 
	//�ɻ���j�����仯�󣬱�����λ�÷����˱仯����������һ��j����λ�á�
	//��ʱ��δ�Ƚϸ�ֵ��dp[j][1]��Ȼ����һ��i�µ�״̬����һ�ν��׵Ľ�ά���һ����i����һ�Σ������ά���������λ�ø���һ��
	for (int i = 1; i < Length; i++)
	{
		for (int j = k; j > 0; j--)
		{
			dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
			dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i]);
		}
	}
	return dp[k][0];
}

/****************************************************************************************************/
int main(void)
{
	vector<int> prices = { 5,2,7,9 };
	int ans1 = Stock_Once01(prices);
	int ans2 = Stock_Once02(prices);
	cout << ans1 << ' ' << ans2 << endl;

	prices = { 7,1,5,3,6,4 };
	ans1 = Stock_Once01(prices);
	ans2 = Stock_Once02(prices);
	cout << ans1 << ' ' << ans2 << endl;

	prices = { 1,2,3,0,2 };
	ans1 = Stock_Frozen01(prices);
	//ans2 = Stock_Once02(prices);
	cout << ans1 << ' ' << 0 << endl;

	prices = { 3,2,6,5,0,3 };
	ans1 = Stock_kTimes01(prices, 2);
	ans1 = Stock_kTimes02(prices, 2);
	cout << ans1 << ' ' << ans2 << endl;

	prices = { 21,15,14,13,9,7,4,1 };
	ans1 = Stock_kTimes01(prices, 2);
	cout << ans1 << endl;
	return 0;
}