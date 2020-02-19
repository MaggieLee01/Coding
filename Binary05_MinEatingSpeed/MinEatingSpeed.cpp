//这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 H 小时后回来。
//珂珂可以决定她吃香蕉的速度 K （单位：根 / 小时）。每个小时，她将会选择一堆香蕉，从中吃掉 K 根。
//如果这堆香蕉少于 K 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。
//珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
//返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。
//leetcode-cn.com/problems/koko-eating-bananas LeetCode 875

//2019-10-29 https://mp.weixin.qq.com/s/QC24hyg0ZgjR7-LgnEzMYg 

//完全没思路后看答案思路，字节写
#include<vector>
#include<algorithm>
using std::min;
using std::vector;

//超时 应该是此处计算需要精简，换成除数余数后OK
bool CanBeate(vector<int>piles, int n, int m)
{
	int times = 0;
	for (auto temp : piles)
		times += ( temp / m + (temp % m == 0 ? 0 : 1) );
	//return times > n ? false : true;
	return times <= n;
	/*for (int i = 0; i < Length; i++)
	{
		if (times > n) break;
		times++;
		if (piles[i] > m) 
		{
			piles[i] = piles[i] - m;
			i--;
		}			
	}
	if (times > n) return false;
	else  return true;*/
}

//通过速度 和 时间，直接求乘积和piles的总数作比较，乘法比较费时间，换成加法求和
//此方法不行呀，对于数据极差较大的情况 不可以
//n为时间
//bool CanBeate(int amount, int n, int m)
//{
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (sum >= amount) break;
//		sum = sum + m;
//	}
//	if (sum >= amount) return true;
//	else return false;
//}
int MinEatingSpeed(vector<int> piles, int n)
{
	if (piles.size() == 0) return 0;
	int max = 0;
	for (auto temp : piles)
	{		
		if (max < temp)	max = temp;
	}
	int left = 1;
	int right = max+1;//最多吃max个//很神奇，这个地方加1 不加1 都行，二分法框架的解释貌似不能解决这个地方的问题
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (CanBeate(piles, n, mid))
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
int main(void)
{
	vector<int> nums = { 3,6,7,11 };
	bool n = CanBeate(nums, 8, 4);
	int ans = MinEatingSpeed(nums, 8);

	nums = { 30,11,23,4,20 };
	n = CanBeate(nums, 6, 24);
	ans = MinEatingSpeed(nums, 5);
	return 0;
}