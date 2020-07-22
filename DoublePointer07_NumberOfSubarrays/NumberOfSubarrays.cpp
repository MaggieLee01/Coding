  /*给你一个整数数组 nums 和一个整数 k。
如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。
请返回这个数组中「优美子数组」的数目。

示例 1：
输入：nums = [1,1,2,1,1], k = 3
输出：2
解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。

示例 2：
输入：nums = [2,4,6], k = 1
输出：0
解释：数列中不包含任何奇数，所以不存在优美子数组。

示例 3：
输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
输出：16

https://leetcode-cn.com/problems/count-number-of-nice-subarrays  */

#include<vector>
#include<iostream>
using namespace std;


//int numberOfSubarrays(vector<int>& nums, int k)
//{
//	int num = nums.size();
//	if (num < k) return 0;
//
//	int left = 0, right = 0, rightMin = 0, rightMax = 0;
//	int ans = 0, cnt = 0;
//	if (nums[left] & 1 == 1) cnt++;
//
//	while (left <= right && right <= num)
//	{		
//		if (cnt <= k)
//		{
//			right++;
//			if (right < num&&(nums[right] & 1 == 1 )) cnt++;
//		}
//		if (cnt < k) rightMin = right + 1;
//		if (cnt > k || right == num && cnt == k)
//		{
//			rightMax = right - 1;
//			ans += rightMax - rightMin + 1;
//			cout << ans << endl;
//			if (left < num && (nums[left] & 1 == 1)) cnt--;
//			left++;
//		}
//	}
//	return ans;
//}

//双指针一直没有处理好，看答案，官方题解
//记录奇数所在的位置，两个奇数之间的距离即为可选择的数量
int numberOfSubarrays(vector<int>& nums, int k)
{
	int num = nums.size();
	vector<int> odd(num + 2, 0);
	
	int cnt = 0, ans = 0;	//记录奇数的个数
	for (int i = 0; i < num; i++)
	{
		if ((nums[i] & 1) == 1) odd[++cnt] = i;
	}
	//辅助，假设两端都是奇数，防止越界等情况
	odd[0] = -1;
	odd[++cnt] = num;
	for (int i = 1; i <= cnt - k; i++)
	{
		ans += (odd[i] - odd[i - 1])*(odd[i + k] - odd[i + k - 1]);
	}
	return ans;
}

//题解的另一种方法,不太好理解呀，不是特别明白
int numberOfSubarrays01(vector<int>& nums, int k)
{
	int num = nums.size();
	vector<int> cnt(num + 1, 0);
	int odd = 0, ans = 0;
	cnt[0] = 1;
	for (int i = 0; i < num; i++)
	{
		odd += nums[i] & 1;//odd为i时，奇数的个数
		ans += odd >= k ? cnt[odd - k] : 0;
		cnt[odd] += 1;//数组里面存储的是第odd个奇数有几种选择
	}
	return ans;
}
int main(void)
{
	vector<int> nums = { 2,2,2,1,2,2,1,2,2,2 };
	//nums = { 2,4,6 };
	nums = { 1,1,2,1,1 };
	int ans = numberOfSubarrays01(nums, 3);
	return ans;
}