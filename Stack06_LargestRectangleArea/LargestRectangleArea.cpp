/*	给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
	求在该柱状图中，能够勾勒出来的矩形的最大面积。	
	输入: [2,1,5,6,2,3]
	输出: 10
	https://leetcode-cn.com/problems/largest-rectangle-in-histogram
*/
//和接雨水的类似，除了两层遍历的暴力解法，练习单调栈的方法
//简单暴力，即寻找左右两边的较小值
//刚开始想不明白如何使用单调栈，看了几个题解熟悉了，前几个题解加评论就很好
//单调栈，按递增的顺序存储的，栈顶元素左边的最小值即为栈中下一个元素，右边的最小值即在不断遍历中得到，用栈存储了最小元素的最小值，减少了遍历的次数
//额外的技巧，两边增加为0的哨兵更好地处理
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights)
{	
	int Len = heights.size();
	if (Len == 0) return 0;
	if (Len == 1) return heights[0];
	
	//或者直接stk push(0),然后height push 0,减少copy
	vector<int> newHeights(Len+2, 0);//增加哨兵，使得栈中所有的元素都被pop()，能计算得到
	copy(heights.begin(), heights.end(), newHeights.begin() + 1);//STL标准库的copy算法，参数为迭代器

	stack<int> stk;
	stk.push(0);//存放的索引
	int ans = 0;

	for (int i = 1; i < Len+2; i++)
	{
		while (stk.size() && newHeights[stk.top()] > newHeights[i])
		{
			int h = stk.top();
			//此处有一个细节的但重要的错误，不应该是i 与 top处的索引做减法求宽度，因为此时不知道左边的较小值，例如2 1 2就会计算1处面积为2
			//应该与弹出该值后，栈的top做减法，弹出之后的值才是左边的较小值
			//ans = max((i - top) * newHeights[top], ans);
			stk.pop();
			ans = max((i - stk.top() - 1) * newHeights[h], ans);
		}
		stk.push(i);
	}
	return ans;
}
int main(void)
{
	vector<int> num = { 2,1,5,6,5,3 };
	int ans = largestRectangleArea(num);
	return 0;
}