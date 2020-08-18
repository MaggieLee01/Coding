/*给你一个整数数组 nums，将该数组升序排列。

输入：[5,2,3,1]
输出：[1,2,3,5]

输入：[5,1,1,2,0,0]
输出：[0,0,1,1,2,5]

https://leetcode-cn.com/problems/sort-an-array */

//看官方题解，理解记忆模板
#include<vector>
#include<algorithm>
using namespace std;

void maxHeapify(vector<int>& nums, int index, int right)
{
	for (; (index << 1) + 1 <= right;)
	{
		int leftson = (index << 1) + 1;
		int rightson = (index << 1) + 2;
		int max = index;
		if (leftson <= right && nums[leftson] > nums[max])
			max = leftson;
		if (rightson <= right && nums[rightson] > nums[max])//right为最后一个数，一定是小于等于
			max = rightson;//使得max为三处最大值的索引
		if (max != index)//使得index处的元素在三个里面最大
		{
			swap(nums[max], nums[index]);
			index = max;
		}
		else break;//如果已经最大，则退出，下面的已经符合条件，无需变动
	}
}
void buildMaxHeap(vector<int>& nums, int right)
{
	for (int i = right >> 1; i >= 0; i--)
		maxHeapify(nums, i, right);
}
void heapSort(vector<int>& nums)
{
	int right = nums.size() - 1;
	buildMaxHeap(nums, right);
	for (int i = right; i >= 0; i--)
	{
		swap(nums[i], nums[0]);
		right--;
		maxHeapify(nums, 0, right);
	}
}
vector<int> sortArray(vector<int>& nums)
{
	heapSort(nums);
	return nums;
}
int main(void)
{
	vector<int> num{ 5,1,1,2,0,0 };
	sortArray(num);
	return 0;
}