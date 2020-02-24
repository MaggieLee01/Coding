// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。

#include<vector>
#include<algorithm>
using std::vector;

bool isOdd(int num)
{
	return num & 01;//求奇偶性用位运算
}
vector<int> exchange(vector<int>& nums) 
{
	int Length = nums.size();
	if (Length <= 1) return nums;

	int i = 0, j = Length - 1;	
	while (i <= j)
	{
		while (i < Length && isOdd(nums[i]))//一定要把判断i的长短写在前面 保证nums[i]有意义，或者用i<j也可以
			i++;
		while (j >= 0 && !isOdd(nums[j]))
			j--;

		if (i < j)
		{
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}
	return nums;                                                                                     
}
//看了书本答案，涉及到函数指针 解耦函数
//题解其他方法：除了左右指针之外还有快慢指针，找双指针的练习做
// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/solution/ti-jie-shou-wei-shuang-zhi-zhen-kuai-man-shuang-zh/
//尝试快慢指针，都是一个指向奇数 一个指向偶数
vector<int> exchange_FastPointer(vector<int>& nums)
{
	int Length = nums.size();
	if (Length <= 1) return nums;

	int fast = 0, low = 0;
	for (fast = 0; fast < Length; fast++)
	{
		if (nums[fast] & 01 == 1)//遇到奇数放前面
		{
			std::swap(nums[fast], nums[low]);
			low++;
		}
	}
	return nums;
}


int main(void)
{
	vector<int> nums{ 1,2,3,4,5,6,7,8,9 };
	exchange_FastPointer(nums);
	nums = { 1,3,5,7,9,0,2,4,6,8 };
	exchange_FastPointer(nums);
	nums = { 1,3,5,7,9 };
	exchange_FastPointer(nums);
	nums = { 0,2,4,6,8 };
	exchange_FastPointer(nums);
}

