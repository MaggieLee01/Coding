// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

// 思路历程：发现行与列已排序，单纯的考虑用二分法，仔细思考发现转换为一维数字后不是sorted，每行的后半部分和下一行的前半部分大小无法得知
//          然后思考和中心数字比较后，但这样子将数组分成了4块，仅仅能排除一块，其他三块无法比较，后续无法处理
//			然后纠结于将目标数字和1 4 位置上的数字判断比较，依然和上面一样的困难，看完答案，换个角度，应该和2 3 位置上的数字进行比较，进而排除一行或者一列。
//			看完答案后自己写,遇到问题：数组中0开始的原因引起的，按照二维数组下标的标准写即可

//while内写比较条件的时候如果先比较不等，再比较相等，效率会有提升
#include<cstdio>
#include<iostream>
bool find(int *matrix, int rows, int columns, int number)
{	
	/*int left = 0;
	int right = rows * columns - 1;
	while (left<=right)
	{
		int mid = (right - left) >> 1 + left;
		if (matrix[mid] == number)
			return true;
		else if (matrix[mid] > number)
			right = mid - 1;
		else if (matrix[mid] < number)
			left = mid + 1;
	}
	return false;*/

	/*
	int mid_r = rows >> 1;
	int mid_c = columns >> 1;
	if (matrix[(mid_r - 1)*columns] == number)
		return true;
	if(matrix[(mid_r - 1)*columns] > number)
	*/

	//也可以定义一个bool值，赋值为false，在正确的场合赋值为true，最后返回该bool值

	if (matrix == nullptr || columns > 0 || rows > 0)//此处还应该判断行数和列数
		return false;
	int r = 0, c = columns - 1;
	while(r < rows && c >= 0 )
	{
		if (matrix[r * columns + c] == number)
			return true;
		else if (matrix[r * columns + c] < number)
			//r++;
			++r;
		else if (matrix[r * columns + c] > number)
			//c--;
			--c;
		
	}
	return false;
}
//测试代码
void Test(const char* testname, int* matrix, int rows, int columns, int number, bool expected)
{
	if (testname != nullptr)
		std::cout << testname << "   begins:";
	bool result = find(matrix, rows, columns, number);
	if (expected == result)
		std::cout << "Passed" << std::endl;
	else std::cout << "Failed" << std::endl;
}
//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数在数组中
void Test1()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数不在数组中
void Test2()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最小的数字
void Test3()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最大的数字
void Test4()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最小的数字还小
void Test5()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最大的数字还大
void Test6()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test6", (int*)matrix, 4, 4, 16, false);
}

// 鲁棒性测试，输入空指针
void Test7()
{
	Test("Test7", nullptr, 0, 0, 16, false);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();

	return 0;
}