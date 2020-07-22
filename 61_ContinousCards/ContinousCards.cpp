/*从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

输入: [1,2,3,4,5]
输出: True

输入: [0,0,1,2,5]
输出: True

https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof */

#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//set方式
bool isStraight01(vector<int>& nums)
{
	set<int> s;
	int min1 = 20;
	int max1 = 0;

	for (int i : nums)
	{
		if (i == 0) continue;
		if (s.count(i)) return false;
		s.insert(i);				//注意set为insert
		min1 = min(min1, i);
		max1 = max(max1, i);
		if (max1 - min1 > 4) return false;
	}
	return max1 - min1 < 5;
}

//排序的方式，整个代码写的非常巧妙
bool isStraight(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int cnt = 0;//王的个数
	
	for (int i = 0; i < 4; i++)						//只遍历了前4个，第五个数直接在返回处比较
	{
		if (nums[i] == 0)
		{
			cnt++;									//统计0的个数
			continue;
		}
		else if (nums[i]==nums[i+1]) 
			return false;							//如果重复，提前返回
	}
	return nums[4] - nums[cnt] < 5;					//max 与 min相差5以内，则可以构成顺子
}