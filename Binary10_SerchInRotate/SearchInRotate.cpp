/*33. 搜索旋转排序数组

假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。

示例 1:
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4

示例 2:
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/

#include<vector>
using namespace std;
//https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/yi-wen-jie-jue-4-dao-sou-suo-xuan-zhuan-pai-xu-s-2/

int search(vector<int>& nums, int target) 
{
	int left = 0, right = nums.size();
	while (left < right)
	{
		int mid = (right - left) / 2 + left;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
		{
			if (mid + 1 < nums.size() && nums[mid] < nums[mid + 1])//mid为向下取整。所以mid+1一定有数据，上升期
				left = mid + 1;
			else right = mid;
		}
		else
		{
			if (nums[mid] < nums[mid + 1]) right = mid;
			else left = mid + 1;
		}
	}
	return -1;
}
int main(void)
{
	vector<int> nums = { 4,5,6,7,0,1,2 };
	int ans = search(nums, 3);
	return 0;
}