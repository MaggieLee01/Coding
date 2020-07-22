/*给你一个整数数组 nums，将该数组升序排列。

输入：[5,2,3,1]
输出：[1,2,3,5]

输入：[5,1,1,2,0,0]
输出：[0,0,1,1,2,5]

https://leetcode-cn.com/problems/sort-an-array */

#include<vector>
#include<ctime>
//#include<cstdlib>
#include<algorithm>
using namespace std;

//看着剑指offer课本，完善代码
//看着官方题解，复习了快排的细节，都是用的快慢指针来区分，我想尝试左右指针，没成，直接理解记忆答案的模板
//int partition(vector<int>& nums, int left, int right)
//{
//	int temp = nums[right];
//	int i = left, j = right - 1;
//	while (i < j)
//	{
//		while (i < j && nums[i] <= temp)
//			i++;
//		while (i < j &&nums[j] >= temp)
//			j--;
//		if (nums[i] > nums[j])
//			swap(nums[i], nums[j]);
//	}	
//	swap(nums[i], nums.back());
//	return i;
//}

//j为移动指针，i为小于pivot的左边界，i的下一个值即大于pivot，所以当j遇到小的值时，可以i=i+1;swap(nums[i],num[j])
int partition(vector<int>& nums, int left, int right)
{
	int pivot = nums[right];
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (nums[j] <= pivot)
		{
			i = i + 1;
			swap(nums[j], nums[i]);
		}
	}
	swap(nums[i + 1], nums[right]);
	return i + 1;
}
int randomized_partition(vector<int>& nums, int left, int right)
{
	int i = rand() % (right - left + 1) + left;//从left开始的
	swap(nums[i], nums[right]);
	return partition(nums, left, right);
}

void fastsort(vector<int>& nums, int left, int right)
{
	//if (begin == end) return;
	if (left >= right) return;
	int index = randomized_partition(nums, left, right);
	fastsort(nums, left, index - 1);//左右均闭合，类似于二分法，这里是递归呀，大哥
	fastsort(nums, index + 1, right);
}
vector<int> sortArray(vector<int>& nums)
{
	srand((unsigned int)(time(NULL)));
	fastsort(nums, 0, nums.size() - 1);
	return nums;
}
int main(void)
{
	vector<int> num{ 5,1,1,2,0,0 };
	sortArray(num);
	return 0;
}