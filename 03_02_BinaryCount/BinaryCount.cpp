// 找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在1到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。


// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:             
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字
#include<iostream>
#include<cstdio>
#include<vector>

int count(std::vector<int>num, int start, int end)
{
	int m = 0;
	for (auto i:num)
		if (i >= start && i <= end)
			m++;
	return m;
}

//二分法模板，是while循环，不是递归
int duplicate(std::vector<int>num, int length)
{
	int left = 1;
	int right = num.size();
	if (right > length)
		return -1;
	
	while (left < right)
	{
		int mid = (right - left) >> 1;//分清楚左移、右移
		right = left + mid;
		mid = right;
		int m = count(num, left, right);
		if (m > mid)
			right = mid;
		else if (m < mid)
			left = mid;
	}
	if (left = right)
		return left;
	return -1;
}
int main(void)
{
	std::vector<int> num1= { 2, 1, 3, 1, 4 };
	duplicate(num1, 5);

	std::vector<int> num2 = { 2, 4, 3, 1, 4 };
	duplicate(num2, 5);

	std::vector<int> num3 = { 2, 4, 2, 1, 4 };
	duplicate(num3, 5);

	return 0;
}