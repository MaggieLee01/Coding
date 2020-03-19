/*	给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
	你可以假设数组是非空的，并且给定的数组总是存在多数元素。

	输入: [3,2,3];			输出: 3
	输入: [2,2,1,1,1,2,2];	输出: 2

	https://leetcode-cn.com/problems/majority-element	*/


//看到题目，就想到了 map方法 与 排序方法
#include<vector>
#include<unordered_map>
#include<algorithm>
using std::sort;
using std::unordered_map;
using std::vector;

int majorityElement(vector<int>& nums)
{
	int Length = nums.size();
	unordered_map<int, int>  dict;
	for (int i : nums)
	{
		dict[i]++;
		if (dict[i] > (Length >> 1)) return i;
	}
	return -1;
}

int majorityElement(vector<int>& nums)
{
	int Length = nums.size();
	sort(nums.begin(), nums.end());
	return nums[Length >> 1];
}

//看了题解，官方题解给了很多种方法，每一种方法都有值得学习的点
//哈希映射：题解定义了一个变量维护最大值，这种方法称为打擂台的方法，第一次听说这个名词，更适合寻找众数，我的只限于一半以上
//排序算法：语言自带算法，时间复杂度：O(nlogn)，空间复杂度O(logn)
//随机方法：因为超过一半的数组下标被众数占据了，这样我们随机挑选一个下标对应的元素并验证，有很大的概率能找到众数。
//			期望的时间复杂度为 O(n)，计算方法用到了概率论知识。【随机方法之前没怎么接触过】
//分治算法：如果数 a 是数组 nums 的众数，如果我们将 nums 分成两部分，那么 a 必定是至少一部分的众数。时间复杂度：O(nlogn)，空间复杂度O(logn)
//投票算法：如果我们把众数记为 +1，把其他数记为 −1，将它们全部加起来，显然和大于 0，从结果本身我们可以看出众数比其他数多。
//			投票方法仅适用于众数过半的情况，也可以用栈解决


//以下是上述方法的官方题解
int majorityElement01(vector<int>& nums) 
{
	unordered_map<int, int> dict;
	int ans = 0, cnt = 0;
	for (int i : nums)
	{
		dict[i]++;
		if (dict[i] > cnt)
		{
			ans = i;
			cnt = dict[i];
		}
	}
	return ans;
}

int majorityElement02(vector<int>& nums)
{
	while (true)
	{
		int ans = nums[rand() % nums.size()];//产生了随机索引
		int cnt = 0;
		for (int num : nums)		
			if (num == ans)
				cnt++;		
		if (cnt > (nums.size() >> 1) ) return ans;//写在循环里面：减少遍历次数但是增加了判断次数
	}
}
//分治算法不想写了
//投票方法
int majorityElement04(vector<int>& nums)
{
	int cnt = 0, ans = 0;
	for (int i : nums)
	{
		if (cnt == 0) ans = i;	 
		if (i == ans) cnt++;
		else cnt--;		
	}
	return ans;
}
