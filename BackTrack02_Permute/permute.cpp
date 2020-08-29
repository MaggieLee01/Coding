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

//回溯的两种这种，交换法 和 做标记法，标记法的时候在for循环选判断

//交换的优化
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
vector<vector<int>> ans;

//或者查找track中是否有该元素，find查找vector中的元素，这个简单易懂但是费时一些
//对于交换处理的理解：每一次回溯相当于对index及其后元素的排序，index之前的已经存储在track之中
//例如，对于 1 2 3 4，index=2时，第二轮循环时，i为3，因此为 1 3 开头的排列，但此时index处的2没有机会被遍历到，所以交换位置，使得3的位置固定
void backTrack(vector<int> num, int index, vector<int>& track)
{
	if (track.size() == 3)
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


// 有重复数字的情况
////对于含重复数字的话，标记法的时候要先排序
// 不能对数组排序的情况，类似于老虎的笔试题，仅限于特定区间的全排列，哦哦，貌似也可以排序
// 题解还涉及到map unordered_map 的讨论
// https://leetcode-cn.com/problems/permutations-ii/solution/c-jian-dan-hui-su-by-da-li-wang/

//例如，对于 1 2 2 4 全排列，m 已经按序排列好了，深层递归的时候，for循环每次从头开始遍历，当该元素已经被排列的时候，个数减少，为0时，开始排列下一个元素
//在每层递归的for循环里面，--后++，push后pop，因此每一个数都有在最前面的机会
void backtrace(map<int, int>&m, int index,int end, vector<int>& v)
{
	if (index == end)
	{
		ans.push_back(v);
		return;
	}
	for (auto &p:m)
	{
		if (p.second == 0)continue;
		p.second--;
		v.push_back(p.first);
		backtrace(m, index + 1, end, v);
		v.pop_back();
		p.second++;
	}
}
vector<vector<int>> permute01(vector<int>& nums)
{
	map<int, int> m;
	for (auto i : nums) ++m[i];
	vector<int> v;
	backtrace(m, 0, nums.size(), v);
	return ans;
}


//在第一种无重复数字方法加几行代码就可
//https://leetcode-cn.com/problems/permutations-ii/solution/jin-xu-zeng-jia-san-xing-dai-ma-cong-wu-zhong-fu-s/
void backTrack02(vector<int> num, int index, vector<int>& track)
{
	if (track.size() == num.size())
	{
		ans.push_back(track);
		return;
	}
	set<int> s;
	for (int i = index; i < num.size(); i++)
	{
		//对于排列后的数组相同的位置【在同一层递归的for循环里面】不能出现两次一样的数字
		if (s.count(num[i]))
			continue;
		s.insert(num[i]);

		//先push 再交换呀
		track.push_back(num[i]);
		swap(num[i], num[index]);//交换的处理是为了避免重复元素
		backTrack02(num, index + 1, track); //注意递减的是index呀
		swap(num[index], num[i]);
		track.pop_back();
	}
}
vector<vector<int>> permute02(vector<int>& nums)
{
	vector<int> track;
	backTrack02(nums, 0, track);
	return ans;
}



int main(void)
{
	vector<int> num{ 1,2,4,5 };
	vector<vector<int>> ans = permute02(num);
	return 0;
}
//weiwei大佬的题解：用 hash 或者 位掩码 来标记是否已经遍历过，比交换好理解一下，