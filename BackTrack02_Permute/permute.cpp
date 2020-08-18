/*全排列
给定一个 没有重复 数字的序列，返回其所有可能的全排列。
https://leetcode-cn.com/problems/permutations/
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

//上一题，生成括号，提到了回溯算法，看了labuladong的题解框架，根据思路，自己写一下
//labuladong 和 weiwei 大佬的题解，还讲述了回溯法的使用场景

//交换的优化
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> ans;

//或者查找track中是否有该元素，find查找vector中的元素，这个简单易懂但是费时一些
//对于交换处理的理解：每一次回溯相当于对index及其后元素的排序，index之前的已经存储在track之中
//例如，对于 1 2 3 4，index=2时，第二轮循环时，i为3，因此为 1 3 开头的排列，但此时index处的2没有机会被遍历到，所以交换位置，使得3的位置固定
void backTrack(vector<int> num, int index, vector<int>& track)
{
	if (track.size() == num.size())
	{
		ans.push_back(vector<int>(track));
		return;
	}

	for (int i = index; i < num.size(); i++)
	{
		track.push_back(num[i]);
		swap(num[i], num[index]);//交换的处理是为了避免重复元素
		backTrack(num, index + 1, track);
		swap(num[index], num[i]);
		track.pop_back();
	}
}
vector<vector<int>> permute(vector<int>& nums)
{
	vector<int> track;
	backTrack(nums, 0, track);
	return ans;
}
int main(void)
{
	vector<int> num{ 1,2,3 ,4,5 };
	vector<vector<int>> ans = permute(num);
	return 0;
}
//weiwei大佬的题解：用 hash 或者 位掩码 来标记是否已经遍历过，比交换好理解一下，