// https://leetcode-cn.com/problems/trapping-rain-water/ LeetCode 42
//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。链接有图。
//上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

//题解里面额外提高一直栈的方法，和括号匹配很类似，还没见过这种题型
//https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
//和单调栈很类似，以后再看

#include<vector>
#include<algorithm>
#include<stack>
using std::stack;
using std::vector;
using std::max;
using std::min;

//凭借记忆的思路：每个位置的雨水量等于min(左边最大值，右边最大值）- 本位置高度
//暴力写法，时间空间均为线性，已通过LeetCode测试
//答案为另一种暴力写法，时间换空间，O(n*n)时间，O(1)空间，一个大for循环，求最值的循环嵌套在大for循环里面，
int trap(vector<int>& height)
{
	int Length = height.size();
	if (Length < 3) return 0;
	vector<int>left(Length, 0);
	vector<int>right(Length, 0);
	for (int i = 0; i < Length - 1; i++)	
		left[i + 1] = max(left[i], height[i]);
	
	for (int i = Length - 1; i > 0; i--)
		right[i - 1] = max(right[i], height[i]);

	int sum = 0;
	for (int i = 0; i < Length; i++)
	{
		int store = min(left[i], right[i]) - height[i];
		if (store > 0)
			sum = sum + store;
	}		
	return sum;	
}
//用双指针的方法优化，时间O(n)，一次遍历，O(1)的空间
int trap_DoublePointer(vector<int>& height)
{
	int Length = height.size();
	if (Length < 3) return 0;

	int left = 0, right = Length - 1;
	int lMax = height[0];
	int rMax = height[right];
	int ans = 0;
	while (left <= right)
	{
		lMax = max(height[left], lMax);
		rMax = max(height[right], rMax);
		//单变量存储状态，在寻找min(左边最大值，右边最大值)的过程，确定完该位置的min后直接运算，
		if (lMax < rMax)
		{
			ans += lMax - height[left];
			//此时，lMax一定是height[left]左边的最大值，rMax一定是height[right]左边的最大值，
			//rMax不是height[left]右边最大值，但 lMax < rMax,所以lMax一定小于右边的最大值
			left++;
		}
		else
		{
			ans += rMax - height[right];
			right--;
		}
	}
	return ans;
}

//记得题解里有提到栈的方法，尝试，空间复杂度为O(n)，练习栈的使用
//单调栈时无法接雨水，当需要弹出栈中数据时才能接水
int trap_Stack(vector<int>& height)
{
	stack<int> s;//存放索引
	int ans = 0;
	for (int i = height.size() - 1; i >= 0; i--)
	{
		/*while (s.size() && height[s.top()] < height[i])
		{			 
			int temp = s.top();
			s.pop();
			if (s.empty()) break;
			ans += min(height[temp], height[s.top()]);
		}*/
		/*if (!s.empty()) 
			ans += height[s.top()] - height[i];*/

		//看了题解，修改，没有把宽度考虑进去，自己写的时候总想着一次性把该列求出来，对于凹凸型，宽的地方和下一个弹出值有关系呀
		while (s.size() && height[s.top()] < height[i])
		{
			int temp = s.top();
			s.pop();
			if (s.empty()) break;
			int distance = (s.top() - i - 1);
			int h = min(height[i], height[s.top()]);//找栈顶 和 当前元素的最小值
			ans += distance * (h - height[temp]);
		}
		s.push(i);
	}
	return ans;
}
int main(void)
{
	vector<int> heights = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int ans = trap_Stack(heights);
	return 0;
}