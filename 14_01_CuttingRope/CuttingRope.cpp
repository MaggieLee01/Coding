/*给你一根长度为n的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n > 1并且m > 1），
每段绳子的长度记为 k[0], k[1]...k[m] 。请问 k[0] * k[1] * ...*k[m] 可能的最大乘积是多少？
输入:8，输出：18，解释：2*3*3=18
输入:2，输出:  1，解释 : 2 = 1 + 1, 1 × 1 = 1
输入:10,输出：36，解释 : 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
https ://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof */

//写了前10个例子，发现规律，分解为3的加数，乘积最大。
//I 与 II 的输入范围不同
//写完之后，看了题解，大概三种方法：除3求余，0次遍历。均分为m段求乘积，1次遍历。动态规划，2次遍历
//看了书本答案，pow函数的头文件为<cmath.c>，直接计算出了3的段数，2的段数，调用一次pow函数


#include<vector>
#include<algorithm>
#include<cmath>
int GetPower(int base, int exponent)
{
	if (base < 1) return -1;
	if (exponent == 0)	return 1;
	if (exponent == 1)  return base;
	int ans = GetPower(base, exponent / 2);
	ans *= ans;
	if (exponent % 2 == 1)
		ans *= base;
	return ans;
}
int cuttingRope(int n) 
{
	//int ans1[6] = { 0,0,1,2,4,6 };
	if (n < 1) return -1;
	if (n < 4) return n-1;

	//int ans = 1, exponent = n / 3, mod = n % 3;
	//if (mod == 1)
	//{
	//	exponent--;
	//	ans = 4;//将3*1换成2*2更大
	//}
	//if (mod == 2) ans = 2;
	//ans *= GetPower(3, exponent);

	//精简以上代码
	int ans = 1, exponent = n / 3, mod = n % 3;
	if (mod == 0) ans = GetPower(3, exponent);
	if (mod == 1) ans = 4 * GetPower(3, exponent - 1);
	if (mod == 2) ans = 2 * GetPower(3, exponent);
	return ans;
}

//想尝试结果作为应用形参传入
//注意，截止条件时，即使没有返回值，也应该写return结束函数，不然一直嵌套执行
void GetPower_Quote(int base, int exponent, int &ans)
{
	if (base < 1) return;
	if (exponent == 0)
	{
		ans = 1; return;
	}
	if (exponent == 1)
	{
		ans = base; return;
	}
	GetPower_Quote(base, exponent / 2, ans);
	ans *= ans;
	if (exponent % 2 == 1)
		ans *= base;
}
int cuttingRope_Quote(int n)
{
	//int ans1[6] = { 0,0,1,2,4,6 };
	if (n < 1) return -1;
	if (n < 4) return n - 1;

	//精简以上代码
	int ans = 1, exponent = n / 3, mod = n % 3;
	GetPower_Quote(3, exponent - 1, ans);
	if (mod == 0) ans *=3;
	if (mod == 1) ans *=4;
	if (mod == 2) ans *=6;
	return ans;
}

//书本答案 根据贪心算法的精简
int cuttingRope_answer(int n)
{
	//int ans1[6] = { 0,0,1,2,4,6 };
	if (n < 1) return -1;
	if (n < 4) return n - 1;

	int timesOf3 = n / 3;
	if (n - timesOf3 * 3 == 1)	timesOf3 -= 1;
	int timesOf2 = (n - timesOf3 * 3) >> 1;
	int ans = pow(2, timesOf2) * pow(3, timesOf3);
	return ans;
}
//看了一个数学类的题解，将m长的绳子分成n段的乘积最大值
//每段均等的话，乘积最大，先每段分配n % m长度，余下的即为余数长度，余数段每段增加1
// https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/hen-duo-ren-xiang-fu-za-liao-ji-bai-shuang-100-de-/
//一次遍历即可求出最大值
int gao(int n, int m) {
	int a = n / m;
	int b = n % m;
	int ans = 1;
	for (int i = 0; i < b; i++) {
		ans *= a + 1;
	}
	for (int i = 0; i < m - b; i++) {
		ans *= a;
	}
	return ans;
}

using std::max;
using std::vector;
//看到题解有些动态规划的方法，尝试动态规划
int cuttingRope_dp(int num)
{
	//int ans1[6] = { 0,0,1,2,4,6 };
	if (num < 1) return -1;
	if (num < 4) return num - 1;
	vector<int> dp(num + 1, 0);
	dp[0] = -1;	dp[1] = 0;	dp[2] = 1; dp[3] = 2;
	for (int i = 4; i <= num; i++)
	{
		for (int j = 1; j <= (i >> 1); j++)
		{
			/*int ans = max(j*dp[i - j], (i - j)*j);
			dp[i] = max(dp[i], ans);*/
			dp[i] = max(j*dp[i - j], dp[i]);//一定有dp[i-j]>=i-j
		}			
	}
	return dp[num];
}

//关于II，2 <= n <= 1000的输入范围，要求答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
//查看题解的修改方法：
//用dp做，数据范围变得比较大时，long已经不足以去存储中间结果的状态，用long long 麻烦，没必要
//贪心手写pow函数，设置为long long 类型才可以，最后一步取模。Java有BigInteger类型处理大数据；Python不涉及数据范围之说
//while循环求幂，每次*3，取模，此时需要long类型------------------最佳选择
//至于为什么取模 1e9+7，1e9+7在int32位足够大，但它的平方不会再int64溢出，大数相乘时能保证(a∗b)%c=((a%c)∗(b%c))%c
int cuttingRope_BigData(int n)
{
	if (n < 1)return -1;
	if (n < 4)return n - 1;
	long ans = 1;
	while (n > 4)
	{
		ans *= 3;
		ans %= 1000000007;
		n -= 3;
	}
	return (ans * n) % 1000000007;
}
int main(void)
{
	int ans = 1;
	GetPower_Quote(3, 3, ans);
	GetPower_Quote(3, 4, ans);
	ans = cuttingRope(10);
	ans = cuttingRope_dp(10);
	ans = cuttingRope_answer(120);
	return ans;
}