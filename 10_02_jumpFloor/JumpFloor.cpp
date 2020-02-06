//剑指offer扩展题目，基于斐波那契数列题目
//已通过牛客网测试系统
#include<iostream>
#include<vector>
//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
int JumpFloor(int number)
{
	if (number <= 0) return 0;
	std::vector<int> dict(2, 0);
	dict[0] = 1;
	dict[1] = 2;
	if (number < 3) return dict[number - 1];
	int sum = 0;
	for (int i = 3; i <= number; i++)
	{
		sum = dict[0] + dict[1];
		dict[0] = dict[1];
		dict[1] = sum;		
	}
	return sum;
}
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
int JumpFloor01(int number)
{
	if (number <= 0) return 0;
	std::vector<int> dict(number + 1, 0);
	dict[0] = 1;
	dict[1] = 1;
	for (int i = 2; i <= number; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dict[i] += dict[j];
		}
	}
	return dict[number];
}
int main(void)
{
	int m = JumpFloor01(0);
	std::cout << m << std::endl;
	m = JumpFloor01(1);
	std::cout << m << std::endl;
	m = JumpFloor01(2);
	std::cout << m << std::endl;
}