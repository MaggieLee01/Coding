// 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。
//数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。
// https://leetcode-cn.com/problems/next-greater-element-ii
// https://mp.weixin.qq.com/s/_b_QzXkL4e0y5241betVSg 2019-05-10 栈的应用

#include<vector>
#include<stack>
using std::stack;
using std::vector;

//环形数组的构造非常巧妙，在没有额外构造数组的情况下，利用取模完成了环形数组模拟
//此时栈中可以存放较大的数值 而不是 索引，天气预报那个是由于需要计算等待天数
vector<int> nextGreaterElements(vector<int>& nums)
{
	int Length = nums.size();
	vector<int> ans(Length, 0);
	stack<int> NextMax;
	for (int i = (Length << 1) - 1; i >= 0; i--) //在此处掉坑，左移右移的优先级很低，已经犯过这种错误
	{
		while (NextMax.size() && nums[NextMax.top()] <= nums[i % Length])
			NextMax.pop();
		if (NextMax.empty())
			ans[i%Length] = -1;
		else
			ans[i%Length] = nums[NextMax.top()]; //此题要的是数组中的数据
		NextMax.push(i%Length);
	}
	return ans;
}

int main(void)
{
	vector<int> nums = { 1,2,1 };
	nums = nextGreaterElements(nums);
	return 0;
}