// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

#include<vector>
#include<iostream>
#include<algorithm>
using std::min;
using std::vector;

// 因为旋转后基本有序，遍历一次，时间On
// LeetCode中形参为引用类型，不能直接返回数组元素，VS中可以
int minArray01(vector<int> & numbers) 
{
	int Length = numbers.size();
	if (Length == 0) return 0;
	int i = 0;
	for (i = 1; i < Length; i++)
	{
		if (numbers[i] < numbers[i - 1])
			return numbers[i];
	}
	if (i == Length) return numbers[0];	
}

// 思考缩短时间，二分法变形，通过和两端数值的比较确定缩小哪一半的范围
//难点：如何处理有相同元素的情况；多次尝试未果，看答案
//int minArray02(vector<int> & numbers)
//{
//	int Length = numbers.size();
//	if (Length == 0) return 0;
//	if (Length == 1) return numbers[0];
//	if (Length == 2) return min(numbers[0], numbers[1]);
//
//	int left = 0;
//	int right = Length - 1;
//	int ans = 0;
//	while (left <= right)
//	{
//		int mid = ((right - left) >> 1) + left;
//		if (mid >= Length - 1 || mid == 0)
//		{
//			ans = min(numbers[0], numbers[Length - 1]);
//			break;
//		}
//		if (numbers[mid] < numbers[mid + 1] && numbers[mid] < numbers[mid - 1])	//	找到的情况：小于两边的值
//		{
//			ans = numbers[mid];
//			break;
//		}
//		else if (numbers[mid] < numbers[right])	//	首位在mid的左边
//			right = mid - 1;
//		else if (numbers[mid] >= numbers[right])
//			left = mid + 1;
//	}
//	return ans;
//}

//上方的尝试已成功意识到与右端点比较较好
//对于无法处理相同元素的困难，看了答案，对于此种困难额外特殊处理，不能采用二分法思想
//书上答案，判断left right mid三处相等时重新一个新函数；
//题解答案，相等时，right-- 或者 left++
int minArray02(vector<int> & numbers)
{
	int Length = numbers.size();
	if (Length == 0) return 0;

	int left = 0;
	int right = Length - 1;
	int ans = 0;

	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (numbers[mid] == numbers[right])	
			right--;
		else if (numbers[mid] < numbers[right])	
			right = mid;
		else if (numbers[mid] > numbers[right])
			left = mid + 1;
	}
	return numbers[right];
}
//很疑惑的一个点，本来想，while条件处 left <= right,然后 right = mid-1;但是结果不对。思考为什么
//二分法还不是足够熟练

//应该是只有通过左右两边不断和右端点比较，当左右两端点一个大一个小 最后逼近的那一个即为首位
//当mid处元素和右端点相同时，不断缩小右边的范围
// 先前的写法，numbers[mid] < numbers[right]时，有可能mid即是所求值，不应该mid-1，忽略过去
//因为数组中一定有解，所以可以大胆 left < right,当 left == right 时，该元素即为解

//特殊样例：无 一个元素 元素相同 元素全部正序
int main(void)
{
	vector<int> numbers = {};
	int ans = minArray02(numbers);

	numbers = { 1 };
	ans = minArray02(numbers);

	numbers = { 1,1,1,1,1,1 };
	ans = minArray02(numbers);

	numbers = { 2,2,2,2,0,1 };
	ans = minArray02(numbers);

	numbers = { 1,3,5 };
	ans = minArray02(numbers);

	numbers = { 10,1,10,10,10 };
	ans = minArray02(numbers);

}
