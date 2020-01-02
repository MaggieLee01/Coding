#include<iostream>
#include<cstdio>
//自己编写难点：此处统计时端点处是否带等号，不好处理；如2,1,3,1,4,和数组2,1,3,3，等号的情况不一样
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
//写成递归式二分法的错误：最内层递归正确返回之后，进入了倒数第二层的函数后面部分
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

