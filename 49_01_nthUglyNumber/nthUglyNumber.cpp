/*我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
输入: n = 10;	输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
https://leetcode-cn.com/problems/chou-shu-lcof */


//这个题解清晰，相当于合并三个有序数组，数组之间含有重复元素
//https://leetcode-cn.com/problems/chou-shu-lcof/solution/chou-shu-ii-qing-xi-de-tui-dao-si-lu-by-mrsate/

#include<vector>
#include<algorithm>
using namespace std;

int nthUglyNumber(int n)
{
	vector<int> ans(n);
	ans[0] = 1;
	int p2 = 0, p3 = 0, p5 = 0;
	for (int i = 1; i < n; i++)
	{
		ans[i] = min(min(ans[p2] * 2, ans[p3] * 3), ans[p5] * 5);
		if (ans[i] == ans[p2] * 2) p2++;
		if (ans[i] == ans[p3] * 3) p3++;
		if (ans[i] == ans[p5] * 5) p5++;
	}
	return ans[n - 1];
}
//https://leetcode-cn.com/problems/chou-shu-lcof/solution/dui-he-dong-tai-gui-hua-si-lu-xiang-jie-by-jerry_n/
//评论里有优先级队列不用set去重，而是直接和上一次弹出的值作比较的方法去重


//https://leetcode-cn.com/problems/ugly-number/
//判断是不是丑数，自己写的
bool ugly(int n)
{
	if (n == 0) return false;
	if (n == 1) return true;
	bool flag = true;
	while (n > 1 && flag)
	{
		if (n % 2 == 0)
			n = n / 2;
		else if (n % 3 == 0)
			n = n / 3;
		else if (n % 5 == 0)
			n = n / 5;
		else
			flag = false;
	}
	return (n == 1);
}
//题解里面的
bool isUgly(int num) 
{
	//需要特判0
	if (num < 1) return false;
	while (num % 2 == 0) num /= 2;
	while (num % 3 == 0) num /= 3;
	while (num % 5 == 0) num /= 5;
	return num == 1;
}
