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
//尝试一
//自己编写难点：此处统计时端点处是否带等号，不好处理；如2,1,3,1,4,和数组2,1,3,3,4等号的情况不一样
//写成递归式二分法的错误：最内层递归正确返回之后，进入了倒数第二层的函数后面部分
/*
int count1(int numbers[], int length, int start, int end)
{
	int m = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] >= start && numbers[i] <= end)
			m++;
	}
	return m;
}

bool duplicate_wrong(int numbers[], int length, int start, int end, int* duplication)
{
	if (numbers == nullptr || length <= 0)
	{
		duplication = nullptr;
		return false;
	}

	if (start >= end)
	{
		*duplication = start;
		return true;
	}
	int mid = (end - start) >> 1;
	mid += start;

	int no = count1(numbers, length, start, mid);
	if (no > mid - start)
		duplicate_wrong(numbers, length, start, mid, duplication);
	else
		duplicate_wrong(numbers, length, mid, end, duplication);

	return false;
}
*/

//尝试二：
//二分法模板，是while循环，不是递归
//不知道如何处理 mid=m 的情况，如{ 2, 4, 3, 1, 4, 5}；
/*
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
*/

//此处直接比较个数，将m和判断区间的数字个数进行比较，而不是mid, 容易有中间一个的误差

//看着答案改完的，不是自己写出来的
int count(std::vector<int>num, int start, int end)
{
	int m = 0;
	for (auto i : num)
		if (i >= start && i <= end)
			m++;
	return m;
}
//此方法只统计大小在前一段的个数
int duplicate(std::vector<int>num, int length) 
{
	int left = 1;
	int right = num.size() - 1;
	
	while (left <= right)
	{
		int mid = (right - left) >> 1;
		mid = mid + left;
		int m = count(num, left, mid);
		if (right == left)
		{
			if (m > 1)
				return left;
			else
				break;
		}
		if (m > mid - left + 1)
			right = mid;
		else
			left = mid + 1;
	}
	return -1;
}
int main(void)
{
	std::vector<int> num1= { 2, 1, 3, 1, 4 };
	duplicate(num1, 5);

	std::vector<int> num2 = { 2, 4, 3, 1, 4, 5};
	duplicate(num2, 6);

	std::vector<int> num3 = { 2, 4, 2, 1, 4 };
	duplicate(num3, 5);

	return 0;
}