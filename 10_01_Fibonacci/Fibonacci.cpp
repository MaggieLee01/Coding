// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。

//50的时候即超出int范围
//int 类型已通过牛客网测试
//书本答案：long long类型，参数为unsigned类型
//涉及大数相加的数据类型问题

//定义不定长的数组，除了vector，还有？？？

//矩阵方法还没顾得上，继续研究dp算法
//书本答案，思路基本吻合
//可以赋值 1 2 的值，而不是0 1 的值

#include<iostream>
#include<vector>
//递归，自上而下的
int Fibonacci_recursively(int n)
{
	if (n == 0)		return 0;
	if (n == 1)		return 1;
	if (n > 1)
		return (Fibonacci_recursively(n - 1) + Fibonacci_recursively(n - 2));
	else
		return -1;
}
//非递归，自下而上的，额外空间多
int Fibonacci_On(int n)
{
	if (n == 0)		return 0;
	if (n == 1)		return 1;
	if (n > 1)
	{
		//定义不定长的数组
		//vector中的数据在栈上还是在堆上
		std::vector<int> array(n + 1, 0);
		array[0] = 0;
		array[1] = 1;
		for (int i = 2; i <= n; i++)
			array[i] = array[i - 1] + array[i - 2];
		return array[n];
	}
	else
		return -1;
}
//非递归，自下而上的，三个额外空间
int Fibonacci_O1(int n)
{
	if (n == 0)		return 0;
	if (n == 1)		return 1;
	if (n > 1)
	{
		int array[3] = { 0 };
		array[0] = 0;
		array[1] = 1;
		array[2] = 1;
		//此方法较快，循环次数少；
		//书本答案是两个额外空间prev、curr，轮流为其赋值，返回值为sum=prev+curr，需要n个循环
		for (int i = 1; i <= n/3; i++) 
		{
			array[0] = array[1] + array[2];
			array[1] = array[0] + array[2];
			array[2] = array[1] + array[0];
		}
		return array[n % 3];
	}
	else
		return -1;
}
//数学矩阵的方法

//主程序
int main(void)
{
	int a = Fibonacci_recursively(5);
	int b = Fibonacci_On(5);
	int c = Fibonacci_O1(5);
	std::cout << a << ' ' << b << ' ' << c << std::endl;


	//50的时候即超出int范围
	//书本答案：long long类型，参数为unsigned类型
	a = Fibonacci_recursively(27);
	b = Fibonacci_On(27);
	c = Fibonacci_O1(27);
	std::cout << a << ' ' << b << ' ' << c << std::endl;
}
