//https://mp.weixin.qq.com/s/GqehrBu9m7qf5FgFqlV-Uw 2019-06-14 单调队列解决滑动窗口问题 
//https://mp.weixin.qq.com/s/yLc7-CZdti8gEMGWhd0JTg 2019-06-16 双指针技巧汇总
//https://mp.weixin.qq.com/s/nJHIxQ2BbqhDv5jZ9NgXrQ 2019-06-19 滑动窗口算法解决子串问题
//https://mp.weixin.qq.com/s/o7tdyLiYm668dpUWd-x7Lg 2019-07-30 图文详解二叉堆，实现优先级队列
//https://mp.weixin.qq.com/s/4TxF0xVhlUO6v3teip9Jzg 2019-08-23 前缀和技巧：解决子数组问题
//https://mp.weixin.qq.com/s/6Eb7gKqNqXH9B0hSZvMs5A 2019-09-16 如何高效对有序数组/链表去重？
//https://mp.weixin.qq.com/s/CVHfkEiIG3KTw65Z7FLGXg 2019-09-18 这个问题不简单：寻找缺失元素
//https://mp.weixin.qq.com/s/o3GQ4fXjPkS04Sr9uPH8ZQ 2020-03-01 高效寻找缺失和重复的数字
//https://mp.weixin.qq.com/s/3CMQaY1mO1Iqt4j30bUVcA 2019-09-23 Two Sum 问题的核心思想
//https://mp.weixin.qq.com/s/zjJ43PrJdYg3xFzGTwtqhA 2019-10-22 数据结构设计：用栈实现队列/用队列实现栈 


//https://leetcode-cn.com/problems/sliding-window-maximum/solution/239-hua-dong-chuang-kou-zui-da-zhi-by-alexer-660/ 滑动窗口练习题
/*	给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。
	滑动窗口每次只向右移动一位。返回滑动窗口中的最大值。
	https://leetcode-cn.com/problems/sliding-window-maximum
*/
//queue是单端队列；deque是双端队列的数据结构
#include<deque>
#include<vector>
#include<algorithm>
using std::max;
using std::vector;
using std::deque;

class Monotonicqueue {
private:
	deque<int> data;
public:
	void push(int n)//从队尾加入，从对头删除
	{
		while (data.size() && data.back() < n)
			data.pop_back();
		data.push_back(n);
	}
	void pop(int n)
	{
		if (data.size() && data.front() == n)//此处为if，若队列中有元素则pop
			data.pop_front();
	}
	int max()
	{
		return data.front();
	}
};
vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
	Monotonicqueue window;
	int Length = nums.size();
	vector<int> ans;
	if (Length == 0) return ans;
	//答案将前k个和后面的放到一个for循环里面了，用if判断，差不多，每次if判断也费时间
	for (int i = 0; i < k; i++)
		window.push(nums[i]);
	ans.push_back(window.max());//这句应该放在有元素的情况下，数组无元素时此处乱值；或者提前加判断
	for (int i = k; i < Length; i++)
	{		
		window.pop(nums[i - k]);
		window.push(nums[i]);
		ans.push_back(window.max());
	}
	return ans;
}
//看了官方题解，直接deque的方法，存储索引值，为了控制滑动窗口的大小
vector<int> maxSlidingWindow_deque(vector<int>& nums, int k)
{
	int Length = nums.size();
	vector<int> ans;
	deque<int> monotonic;				//头部到尾部，单调递减
	for (int i = 0; i < Length; i++)
	{
		while (monotonic.size() && nums[monotonic.back()] < nums[i])
			monotonic.pop_back();
		monotonic.push_back(i);		
		if (monotonic.front() <= i - k)//在窗口之外应该pop
			monotonic.pop_front();
		if (i + 1 >= k)
			ans.push_back(nums[monotonic.front()]);
	}
	return ans;
}
//官方题解的分块动态规划，不是特别容易想得到
vector<int> maxSlidingWindow_dp(vector<int>& nums, int k)
{
	int Length = nums.size();
	//vector<int> ans(Length - k + 1, 0);//此处赋值0了，length为0 时返回值不对
	vector<int> ans;
	if (Length * k == 0) return ans;
	//if (k == 1) return nums;//

	vector<int> left(Length, 0);
	vector<int> right(Length, 0);
	left[0] = nums[0];
	right[Length - 1] = nums[Length - 1];

	for (int i = 1; i < Length; i++)//dp的base case已确定，如果从0开始传递时前一个状态会溢出
	{
		if (i % k == 0) left[i] = nums[i];//左边
		else left[i] = max(nums[i], left[i - 1]);

		int j = Length - 1 - i;//从右往左
		if ((j + 1) % k == 0) right[j] = nums[j];
		else right[j] = max(nums[j], right[j + 1]);
	}
	//right[i] 是左侧块内的最大元素， left[j] 是右侧块内的最大元素。因此滑动窗口中的最大元素为 max(right[i], left[j])。
	//对于横跨在两个块的窗口，分别找左边块的最大值 和右边块的最大值，均是从块的边界往两边扩散
	for (int i = 0; i < Length - k + 1; i++)
		ans.push_back( max(right[i], left[i + k - 1]) );//vector不可以通过[]增加新元素
	return ans;
}
int main(void)
{
	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	vector<int> ans = maxSlidingWindow_dp(nums, 3);

	nums = { -7,-8,7,5,7,1,6,0 };
	ans = maxSlidingWindow(nums, 4);

	nums = { 1,-1 };
	ans = maxSlidingWindow_dp(nums, 1);
	return 0;
}