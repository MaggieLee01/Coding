/*给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
https://leetcode-cn.com/problems/jump-game */
//https://mp.weixin.qq.com/s/hMrwcLn01BpFzBlsvGE2oQ  还是没有感觉呀

#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//最后一个很大很大的数据不能通过，时间限制，不知道如何优化
bool canJump(vector<int>& nums, int index, vector<int>& visited)
{
	if (index >= (nums.size() - 1) || visited[index] == 1) return true;
	if (visited[index] == 2) return false;
	int opt = nums[index];

	for (int i = opt; i >= 1; i--)
	{
		if (canJump(nums, index + i, visited))
		{
			visited[index] = 1;
			return true;
		}
	}
	visited[index] = 2;
	return false;
}
bool canJump(vector<int>& nums)
{
	int Len = nums.size();
	if (Len == 0) return false;
	if (Len == 1) return true;
	vector<int> visited(Len);
	bool ans = canJump(nums, 0, visited);
	return ans;
}

//哎呀，题解写的太简洁了，我写的效率太低，思路不正确
//判断能到达的最大位置能否到达
bool canJump01(vector<int>& nums)
{
	int Len = nums.size();
	int rightMax = 0;
	for (int i = 0; i < Len; i++)
	{
		if (i > rightMax) return false;
		else
		{
			rightMax = max(rightMax, i + nums[i]);
			if (rightMax >= Len - 1) return true;
		}			
	}
	return false;
}
//看了labulading的改进
bool canJump02(vector<int>& nums)
{
	int Len = nums.size();
	int rightMax = 0;
	for (int i = 0; i < Len - 1; i++)
	{
		rightMax = max(rightMax, i + nums[i]);
		if (rightMax >= Len - 1) return true;
		if (rightMax <= i) return false;	//更新完之后才能到达i，所以无法前进了	
	}
	return (rightMax >= Len - 1);
}

/*给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
*/
//80/92 通过率；超时
int jump(vector<int>& nums) 
{
	int Len = nums.size();
	if (Len == 1) return 0;
	queue<int> q;
	q.push(0);
	int ans = 0;
	while (q.size())
	{
		int num = q.size();
		for (int i = 0; i < num; i++)
		{
			int top = q.front();//索引值
			q.pop();
			for (int j = nums[top]; j > 0; j--)
			{
				if (top + j >= Len - 1)return ans+1;
				else q.push(top + j);
			}							
		}
		ans++;
	}
	return ans;
}
//这就是贪心选择性质，我们不需要「递归地」计算出所有选择的具体结果然后比较求最值，
//而只需要做出那个最有「潜力」，看起来最优的选择即可。
//寻找下一次可跳跃的最大区间
int  jump01(vector<int>& nums)
{
	int Len = nums.size();
	if (Len == 0) return 0;
	int LastMax = 0;
	int RightMax = 0;
	int ans = 0;

	for (int i = 0; i <= Len; i++)
	{
		RightMax = max(i + nums[i], RightMax);
		if (RightMax >= Len - 1) return (ans + 1);
		if (i == LastMax)
		{
			LastMax = RightMax;
			ans++;
		}
	}
	return ans;	
}
int main(void)
{
	vector<int> num1{ 2,3,1,1,4 };
	vector<int> num{ 7,0,9,6,9,6,1,7,9,0,1,2,9,0,3 };
	int ans = jump(num);
	ans = jump(num1);
	return 0;
}