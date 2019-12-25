#include <cstdio>
#include <iostream>
// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:             
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字

//基数排序的思路，元素放在索引为该元素的位置，思考：对于不连续的数组，如何基数排序的
bool duplicate(int numbers[], int length, int* duplication) 
{
	if (numbers == nullptr || length == 0)
		return false;
	for (int i = 0; i < length; i++)
	{
		if(numbers[i]>length-1||numbers[i]<=0)
			return false;
	}
	for (int i = 0; i < length; i++)
	{
		
		while(i != numbers[i])
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			//此处想交换numbers[i] numbers[numbers[i]]的逻辑不对，第三行numbers[numbers[i]]里面的number[i]发生了变换
			//int tump = numbers[i];
			//numbers[i] = numbers[numbers[i]];
			//numbers[numbers[i]] = tump;

			//倘若这边直接写成swap函数，则可以直接swap(numbers[i], numbers[numbers[i]]) ),没有刚才的问题
			int temp = numbers[i];
			numbers[i] = numbers[numbers[i]];
			numbers[temp] = temp;
		}			
	}
}

// ====================测试代码====================
bool contains(int array[], int length, int number)
{
	for (int i = 0; i < length; ++i)
	{
		if (array[i] == number)
			return true;
	}

	return false;
}

void test(const char*  testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
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
	system("pause");
}
//深入理解基数排序，对于不连续的数组，如何处理排序的
//swap函数不需要额外的头文件，直接加std即可。
//习惯用库函数