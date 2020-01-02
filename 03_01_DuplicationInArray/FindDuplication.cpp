// 找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在1到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

#include <cstdio>
#include<iostream>
// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:             
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字


bool duplicate(int numbers[], int length, int* duplication)
{
	//if (0 == length)
	if (numbers == nullptr || length <= 0)
	{
		duplication = nullptr;
		return false;
	}
	//对数组初始化的工具，除了for遍历	,考虑vector数组呀，不知道vector的内存分配情况
	int i = 0;
	int *array = new int[length + 1];
	
	for (i = 0; i < length+1; i++)
		array[i] = 0;
	
	for (i=0;i<length;i++)
	{
		if (array[numbers[i]] != 0)
		{
			*duplication = numbers[i];
			return true;
		}			
		array[numbers[i]] = 1;
	}
	if (i == length)
	{
		duplication = nullptr;
		return false;
	}
	delete array;
	array = nullptr;
}
//测试样例：空数组；无；全是
bool contains(int array[], int length, int number)
{
	for (int i = 0; i < length; ++i)
	{
		if (array[i] == number)
			return true;
	}

	return false;
}

void test(const char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
	printf("%s begins: ", testName);

	int duplication;
	bool validInput = duplicate(numbers, lengthNumbers, &duplication);

	if (validArgument == validInput)
	{
		if (validArgument)
		{
			if (contains(expected, expectedExpected, duplication))
				printf("Passed.\n");
			else
				printf("FAILED.\n");
		}
		else
			printf("Passed.\n");
	}
	else
		printf("FAILED.\n");
}

// 重复的数字是数组中最小的数字
void test1()
{
	int numbers[] = { 2, 1, 3, 1, 4 };
	int duplications[] = { 1 };
	test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2()
{
	int numbers[] = { 2, 4, 3, 1, 4 };
	int duplications[] = { 4 };
	test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3()
{
	int numbers[] = { 2, 4, 2, 1, 4 };
	int duplications[] = { 2, 4 };
	test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4()
{
	int numbers[] = { 2, 1, 3, 0, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5()
{
	int numbers[] = { 2, 1, 3, 5, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6()
{
	int* numbers = nullptr;
	int duplications[] = { -1 }; // not in use in the test function
	test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

void main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
}
//思路：根据数字有范围，使用n长度的数组记录，第一个数字为2则array[2]=1
//细节：bool 型变量打印出来为0 或者 1
//思考：当为空的时候，如何打印结果，如何表现数字

//看参考博客https://blog.csdn.net/coolwriter/article/details/81362533
//除了第一种方法，其他的想不到
//学会习惯使用STL标准库：vector的内存分配情况

//看课本代码，关注测试程序的写法：作者是直接给出了结果，写了测试接口，判断测试程序执行是否正确
//有的判断了输入范围是否有效
//此方法已通过牛客网