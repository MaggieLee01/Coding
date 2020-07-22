/*给你一个整数数组 nums，将该数组升序排列。

输入：[5,2,3,1]
输出：[1,2,3,5]

输入：[5,1,1,2,0,0]
输出：[0,0,1,1,2,5]

https://leetcode-cn.com/problems/sort-an-array */

//看官方题解，理解记忆模板，已通过测试
#include<vector>
#include<algorithm>
using namespace std;

vector<int> tmp;
void MergeSort(vector<int> &nums,int left,int right)
{
	if (left >= right) return;//这种判断截止条件的，能用大于等于 就不用 等于
	int mid = (right - left) / 2 + left;
	MergeSort(nums, left, mid);
	MergeSort(nums, mid + 1, right);
	//开始合并
	int i = left;
	int j = mid + 1;
	int cnt = 0;
	while (i <= mid && j <= right)
	{
		if (nums[i] <= nums[j])	//此处小于等于的话，才是稳定排序
			tmp[cnt++] = nums[i++];
		else
			tmp[cnt++] = nums[j++];
	}
	while (i <= mid) tmp[cnt++] = nums[i++];
	while (j <= right) tmp[cnt++] = nums[j++];

	for (int i = 0; i < right - left + 1; i++)//注意此处的赋值
		nums[i + left] = tmp[i];	
}
vector<int> SortArray(vector<int>& nums)
{
	tmp.resize((int)nums.size(), 0);//注意全局变量的使用
	MergeSort(nums, 0, nums.size() - 1);
	return nums;
}
int main(void)
{
	vector<int> num{ 5,1,1,2,0,0 };
	SortArray(num);
	return 0;
}