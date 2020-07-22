/*给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

	输入:nums = [1, 1, 1], k = 2
	输出 : 2, [1, 1] 与[1, 1] 为两种不同的情况。

	数组的长度为 [1, 20,000]。
	数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
	https://leetcode-cn.com/problems/subarray-sum-equals-k
 */ 

#include<vector>
#include<unordered_map>
using namespace std;

//本想使用滑动窗口，发现测试样例中有负数，不在如何改进。

//int subarraySum(vector<int>& nums, int target)
//{
//	if (nums.size() == 0) return 0;
//	int left = 0;
//	int right = 0;
//	int sum = nums[0];
//	int ans = 0;
//	while (right < nums.size() && left < nums.size())
//	{
//		if (sum < target)
//		{
//			right++;
//			sum += nums[right];
//		}
//		else if (left <= right)
//		{
//			if (sum == target) ans++;
//			sum -= nums[left];
//			left++;
//		}
//	}
//	return ans;
//}

//weiwei大佬：滑窗有个特点是，固定了左边界以后，右边界找到了一个可行解以后，右边界再靠右边的更大的区间肯定不存在目标值，
//			所以才将左边界继续向右滑。在这道题里显然没有这个性质。
//			很有道理，滑动窗口不适合。

//看标签，hash表，连续性，看了题解，好神奇的思路，hash表存储的是从0个数开始连续和对应的个数
int subarraySum(vector<int>& nums, int target)
{
	unordered_map<int, int> mp;
	mp[0] = 1;
	int count = 0, pre = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		pre += nums[i];
		//很关键的一步，寻找以i为结束是否有和为target的子数组，因为mp存储的全是从第0个开始的和
		if (mp.find(pre - target) != mp.end()) 
			count += mp[pre - target];
		mp[pre]++;
	}
	return count;
}