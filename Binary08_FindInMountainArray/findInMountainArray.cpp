/*给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 等于 target 最小 的下标 index 值。
如果不存在这样的下标 index，就请返回 -1。 

何为山脉数组？如果数组 A 是一个山脉数组的话，那它满足如下条件：
首先，A.length >= 3
其次，在 0 < i < A.length - 1 条件下，存在 i 使得：
	A[0] < A[1] < ... A[i-1] < A[i]
	A[i] > A[i+1] > ... > A[A.length - 1]
 

你将 不能直接访问该山脉数组，必须通过 MountainArray 接口来获取数据：
	MountainArray.get(k) - 会返回数组中索引为k 的元素（下标从 0 开始）
	MountainArray.length() - 会返回该数组的长度 

注意：
对 MountainArray.get 发起超过 100 次调用的提交将被视为错误答案。此外，任何试图规避判题系统的解决方案都将会导致比赛资格被取消。

示例 1：
输入：array = [1,2,3,4,5,3,1], target = 3
输出：2
解释：3 在数组中出现了两次，下标分别为 2 和 5，我们返回最小的下标 2。

示例 2：
输入：array = [0,1,2,4,2,1], target = 3
输出：-1
解释：3 在数组中没有出现，返回 -1。

https://leetcode-cn.com/problems/find-in-mountain-array */
//山脉数组

#include<vector>
using namespace std;
class MountainArray 
{
public:
	MountainArray(vector<int> n)
	{
		nums = n;
	}
	int get(int index) 
	{
		return nums[index];
	}
	int length() 
	{
		return nums.size();
	}
private:
	vector<int> nums;
};

//看甜姨  weiwei大佬的题解，先找到封顶，然后两边二分法

//左闭右开的搜索
int binarySearch(int target, MountainArray &mountainArr, int l, int r,bool asc)//一个正序，一个逆序
{
	int left = l;
	int right = r;
	while (left < right)
	{
		int mid = (right - left) / 2 + left;
		if (mountainArr.get(mid) == target)
			return mid;
		else if (mountainArr.get(mid) > target)
		{
			right = asc ? mid : right;
			left = asc ? left : mid + 1;
		}
		else
		{
			right = asc ? right : mid;
			left = asc ? mid + 1 : left;
		}
	}
	//左闭右开，迭代时left = mid + 1，right = mid
	//左闭右开，右边初值为最后一个的下一个时，直接可以返回-1，
	//左闭右开，右边初值为最后一个元素时，循环之后需要确定最后一个值是否为target
	//以上区别在于，第一种遍历完所有的元素，结束条件可能是left = right = num.size();第二种可能最后一个值没遍历到，
	return -1;
}

//二分法，除了要考虑right left 的赋值以外，还要考虑right的初值
MountainArray nums({ 1,2,3,4,5,3,1 });
int findInMountainArray(int target, MountainArray &mountainArr)
{
	int left = 0;
	//找到山顶的索引时，结束条件为left=right，所以right的初值应该取得到
	//选择插入位置的时候，可能插在最后一个元素的末尾，所以right的初值为size大小
	int right = mountainArr.length() - 1;	
	while (left < right)
	{
		int mid = (right - left) / 2 + left;
		if (mountainArr.get(mid) < mountainArr.get(mid + 1))
			left = mid + 1;
		else
			right = mid;
	}
	//找到了封顶，甜姨是用 while(left + 1 < right)的方法，left  right处有两个元素，比较大小即为封顶
	//左右两边寻找值
	int leftIndex = binarySearch(target, mountainArr, 0, left + 1, true);//搜索区间、左闭右闭
	if (leftIndex != -1) return leftIndex;
	else
	{
		int rightIndex = binarySearch(target, mountainArr, left + 1, mountainArr.length(), false);
		return rightIndex;
	}
}
//二分法，关于right的初值，关于left right的递进