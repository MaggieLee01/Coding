//给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。
//nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 - 1。
/*	输入: nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2].
	输出 : [-1, 3, -1]
	对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 - 1。
	对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
	对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 - 1
	https://leetcode-cn.com/problems/next-greater-element-i
*/
#include<vector>
#include<stack>
#include<unordered_map>
#include<map>
using std::unordered_map;
using std::map;
using std::stack;
using std::vector;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
	stack<int> NextGreater;//命名规则 是不是 要体现栈 map
	unordered_map<int, int> GreaterMap;
	int Length = nums2.size();
	for (int i = Length - 1; i >= 0; i--)
	{
		while (NextGreater.size() && nums2[NextGreater.top()] < nums2[i])
			NextGreater.pop();
		if (NextGreater.empty())
			GreaterMap.emplace(nums2[i], -1);
		else
			GreaterMap.emplace(nums2[i], nums2[NextGreater.top()]);
		NextGreater.push(i);
	}
	/*for (auto num : nums1)//这样子无法改变数组元素的内容
	{
		auto GetIndex = GreaterMap.find(num);
		if (GetIndex == GreaterMap.end())
			num = -2;
		else
			num = GetIndex->second;
	}*/
	int nums1Length = nums1.size();
	for (int i = 0; i < nums1Length; i++)
	{
		auto GetIndex = GreaterMap.find(nums1[i]);
		if (GetIndex == GreaterMap.end())
			nums1[i] = -2;
		else
			nums1[i] = GetIndex->second;
	}
	return nums1;
}
//看了题解，栈的写法可以精简一下，map的写法也可以精简一下
//此时 栈里面可以存放 较大的数值 而不是 索引了，当地气温那个是为了计算等待天数
vector<int> nextGreaterElement_answer(vector<int>& nums1, vector<int>& nums2)
{
	stack<int> NextGreater;
	unordered_map<int, int> GreaterMap;
	for (int value : nums1)
		GreaterMap[value] = -1;  //map可以这样子插入元素，调试的时候map每插入一个键，都会调到主函数函数调用的下一行，不要误以为函数结束了
	int nums2Length = nums2.size();
	for (int i = nums2Length - 1; i >= 0; i--)
	{
		while (NextGreater.size() && NextGreater.top() < nums2[i])
			NextGreater.pop();
		if (NextGreater.size())	//栈为空时即为初始化的-1，省略了为空的判断		
			GreaterMap[nums2[i]] = NextGreater.top();
		NextGreater.push(nums2[i]);
	}
	int nums1Length = nums1.size();
	for (int i = 0; i < nums1Length; i++)
		nums1[i] = GreaterMap[nums1[i]];
	return nums1;
}
int main(void)
{
	vector<int> nums1 = { 4,1,2 };
	vector<int> nums2 = { 1,3,4,2 };
	nextGreaterElement_answer(nums1, nums2);
}