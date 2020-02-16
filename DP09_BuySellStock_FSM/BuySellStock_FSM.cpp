//2019-06-07 状态机方法
//递归其实是符合我们思考的逻辑的，一步步推进，遇到无法解决的就丢给递归，一不小心就做出来了，可读性还很好。
//缺点就是一旦出错，你也不容易找到错误出现的原因。还有计算冗余，但确实不容易找到。
//状态机文章中，dp[][][]表示此时手中的钱，并不是上一个project里面一支股票交易完成后的收益

//状态机：找到所有状态；查找各个状态下的所有选择
//上个project也尝试邻里状态机，但是没有理清状态与选择的关系，
//买卖不动应该为选择，状态通过加减来做出选择进而进入下一个状态
//定义，0表示手里没有股票
//dp[i][k][0]表示第i天交易了k次，手里没有股票时，手里的钱

//无限次的话，贪心算法比状态机快，但是贪心限制多，状态机递归框架的实用性强

//均已通过LeetCode测试

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

	//不知道如何初始化二级数组
	//int *dp[2] = new int[Length - 1][2]{0};

	//base case
	dp[0][0] = 0;			//没买股票没花钱
	dp[0][1] = -prices[0];	//买了股票花了钱
	for (int i = 1; i < Length; i++)	
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][1], -prices[i]);
	}
	return dp[Length - 1][0];
}
//减少空间的占用
int Stock_Once02(vector<int> prices)
{
	int Length = prices.size();
	//第0天的状态初始化
	//int i_0 = 0, i_1 = -prices[0];此时需要保证有元素，可以直接用-1天的状态初始化，循环从0开始
	int i_0 = 0, i_1 = INT_MIN;
	for (int i = 0; i < Length; i++)
	{
		i_0 = max(i_0, i_1 + prices[i]);
		i_1 = max(i_1, -prices[i]);
	}
	return i_0;
}
/****************************************************************************************************/
//无限次
int Stock_Times(vector<int> prices)
{
	int Length = prices.size();
	//第0天的状态初始化
	//int i_0 = 0, i_1 = -prices[0];
	int i_0 = 0, i_1 = INT_MIN;
	for (int i = 0; i < Length; i++)
	{
		i_0 = max(i_0, i_1 + prices[i]);
		i_1 = max(i_1, i_0 - prices[i]);//一次的时候第二项直接为-prices[i]，感受一下不同
	}
	return i_0;
}
/****************************************************************************************************/
//冻结期一天
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
	//此处需要保证输入的数据量
	dp[0][0] = 0;			//没买股票没花钱
	dp[0][1] = -prices[0];	//买了股票花了钱
	dp[1][0] = max(0, prices[1] - prices[0]);
	dp[1][1] = max(-prices[0], -prices[1]);
	for (int i = 2; i < Length; i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);//想买股票的话，至少是两天前卖了股票
	}
	return dp[Length - 1][0];
}
//思考如何变成O(1)的空间，与前两个状态有关系
//无限次
int Stock_Frozen02(vector<int> prices)
{
	int Length = prices.size();
	if (Length <= 1) return 0;
	//第0天的状态初始化【prices从0开始的】
	int i_0 = 0, i_1 = -prices[0];
	//第0天之前的
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
//有具体交易次数的限制，k有具体的数值
int Stock_kTimes01(vector<int> prices,int k)
{
	int Length = prices.size();
	if (Length <= 1) return 0;//base case需要保证有值
	if (k > Length >> 1) return Stock_Times(prices);//k大于length/2时，k限制不起作用
	//貌似new只能逐渐分配
	//int ***dp = new int[Length][n][2];不通过
	//vector构造函数类型
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
	//最糟糕的情况股票一直递减，当天买当天卖也算是完成了一次交易，收益为0，因此不会出现随着交易次数增多而收益减小的情况
	//所以第k次交易收益最大
	return dp[Length - 1][k][0];
}
//不知道怎么降维呀，参考labuladong题解的评论
int Stock_kTimes02(vector<int> prices, int k)
{
	int Length = prices.size();
	if (Length <= 1) return 0;						//base case需要保证有值
	if (k > Length >> 1) return Stock_Times(prices);//k大于length/2时，k限制不起作用
	vector< vector<int> >  dp(k + 1, vector<int>(2, 0));
	//思考降维，三维降到二维就行呀。主要是i的变化在更新，但是直接去掉i最外维度的话，
	//base case
	for (int j = k; j > 0; j--)
	{
		dp[j][0] = 0;
		dp[j][1] = -prices[0];
	}
	//有点想不明白为什么可以直接降维，j变化后，dp[j][1]就表示这个i下的状态了，为什么还是可以呢 
	//疑惑解答：j发生变化后，遍历的位置发生了变化，不再是上一个j处的位置。
	//此时，未比较赋值，dp[j][1]依然是上一个i下的状态，和一次交易的降维情况一样，i更新一次，这个二维数组表所有位置更新一次
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