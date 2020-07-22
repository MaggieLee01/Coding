/*给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。

示例 1:
输入: [1,3,5,6], 5
输出: 2

示例 2:
输入: [1,3,5,6], 2
输出: 1

示例 3:
输入: [1,3,5,6], 7
输出: 4

示例 4:
输入: [1,3,5,6], 0
输出: 0

https://leetcode-cn.com/problems/search-insert-position
*/
#include<vector>
using namespace std;

//查找左侧范围的模板写法，查找元素是否存在，查找可以插入的位置，都是这个模板
//weiwei大佬的详细题解
//mid = (right - left) / 2 + left; 取不到右边界，倘若left = mid；right =  mid - 1;可能进入死循环
int searchInsert(vector<int>& nums, int target) 
{
	int left = 0;
	int right = nums.size();
	while (left < right)
	{
		int mid = (right - left) / 2 + left;
		// 严格小于 target 的元素一定不是解
		if (target > nums[mid])
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

//weiwei大佬题解，还提到了
/*3、while (left + 1 < right) 这种写法其实很多人都在用，如果你理解了本题解介绍的方法，理解它就很容易了。
使用它在退出循环的时候，有 left + 1 = right 成立，
即 left 和 right夹成的区间里一定有 2 个元素，此时需要分别判断 left 和 right 位置的元素是不是目标元素，有时需要注意判断的先后顺序。
优点：不用去理解和处理第 2 点说的那种上取整的行为，因为不会出现死循环。
缺点：一定需要后处理，在后处理这个问题上增加了思考的负担。另外 while (left + 1 < right) 这种写法我个人认为不那么自然。
*/