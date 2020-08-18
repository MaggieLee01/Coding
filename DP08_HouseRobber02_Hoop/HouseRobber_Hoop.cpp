//打家劫舍系列问题02：不能抢劫相邻房间，输入依然是一个数组，但是这些房子不是一排，而是围成了一个圈。求能抢劫的最大值
//2019-12-19
//已在LeetCode中文网OK

//也即首尾不能同时抢劫
//抢劫第一家：nums[0]..[size-2]
//不抢劫第一家：nums[1]...[size-1]
//思考，和单调栈有什么关系，如何利用
//思路，计算两种，比较结果，答案也是，依旧没发现和单调栈有什么关系

#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::max;

int Rob_dp_Hoop(vector<int> nums)
{
	int Length = nums.size();
	//VS 能判断 -1 < 0 ，已测试
	//if (Length == 0) return 0;//不然for循环变成了-1

	//不要忽略一个的情况，此时没有进入for循环，ans为初始化的值
	if (Length == 1) return nums[0];
	int ans = max(Rob_dp(nums, 0, Length - 2), Rob_dp(nums, 1, Length - 1));
	return ans;
}
int Rob_dp(vector<int> nums, int start, int end)
{
	int dp_1 = 0, dp_2 = 0;
	int ans = 0;
	for (int i = end; i >= start; i--)
	{
		ans = max(nums[i] + dp_2, dp_1);
		dp_2 = dp_1;
		dp_1 = ans;
	}
	return ans;
}