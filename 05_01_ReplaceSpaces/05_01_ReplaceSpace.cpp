// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，则输出“We%20are%20happy.”。

//思路历程：	暴力法，遍历一遍之后替换，时间复杂度，线性；
//			细节问题，替换后后续字符的索引发生了变换，因此在原字符串上改动较麻烦，需要赋值到新的空间。
//			特殊条件：输入为空；
//			此方法浪费空间，尤其时数据量较大空格较少时；且在ReplaceSpace()函数中不能释放内存空间，容易泄露

//考虑STL库的string函数

//该思路无法在牛客网测试，函数结构不一样，自己的测试样例已全部通过。

#include<iostream>
#include<string.h>

char* ReplaceSpaces(const char* string) 
{
	if (string == nullptr)
		return nullptr;

	//定义长度不定的字符串空间【栈空间也行】并赋初值，怎么操作，使用new?
	//使用new后，调试时不能从replace处直接查看字符串，必须跳到内存处，解决方法：new时加()赋初值0能看到

	int length = strlen(string);

	char* newstring = new char[length + length + length + 1]();//加()赋初值0会好很多
	char* replace = newstring;

	while (*string != '\0')//字符串结束的标志基础忘记了
	{
		if (*string != ' ')
		{
			*replace = *string;
			++string;
			++replace;
		}
		else if (*string == ' ')
		{
			*replace = '%';
			*(++replace) = '2';
			*(++replace) = '0';
			++string;
			++replace;
		}
	}
	*replace = '\0';

	//细节问题:
	//此处返回的应该是字符串的首位，不是移动到最后的指针，此处犯错很多次！！！！！
	return newstring;
}

// ====================测试代码【自己写】====================
void Test(const char* testname,const char* string, const char* expected)
{
	std::cout << testname << "	begins:	";
	char *result = ReplaceSpaces(string);
	//应该经过函数处理后再检查是否为空，判断是否为空只是为了使用strcmp函数，所以不应该判断string，应该判断result

	/*if (string == nullptr)
		if (expected != nullptr)
		{
			std::cout << "Failed" << std::endl;
			return;//此处不返回的话，后面的代码需要在else的条件下
		}
		else
		{
			std::cout << "Passed" << std::endl;
			return;//此处不返回的话，后面的代码需要在else的条件下
		}
	*/
	if(result == nullptr && expected == nullptr)
		std::cout << "Passed" << std::endl;
	
	else if(result == nullptr || expected == nullptr)
		std::cout << "Failed" << std::endl;
	else
	{
		//细节，strcmp函数的参数为空，怎么办，貌似报错
		int test = strcmp(result, expected);
		if (!test)
			std::cout << "Passed" << std::endl;
		else
			std::cout << "Failed" << std::endl;
	}
	//不要忘记释放动态内存空间
	delete result;
	result = nullptr;
}
//正常有几个空格
void test1(void)
{
	const char* string = "We are happy.";
	const char* expected = "We%20are%20happy.";
	Test("Test1", string, expected);
}
//没有空格
void test2(void)
{
	const char* string = "Wearehappy.";
	const char* expected = "Wearehappy.";
	Test("Test2", string, expected);
}
//全是空格
void test3(void)
{
	const char* string = "   .";
	const char* expected = "%20%20%20.";
	Test("Test3", string, expected);
}
//输入为空
void test4(void)
{
	const char* string = nullptr;
	const char* expected = "%20%20%20.";
	Test("Test4", string, expected);
}
//输出为空
void test5(void)
{
	const char* string = "   .";
	const char* expected = nullptr;
	Test("Test5", string, expected);
}
//全部为空
void test6(void)
{
	const char* string = nullptr;
	const char* expected = nullptr;
	Test("Test6", string, expected);
}

// 空格在句子开头
void test7(void)
{
	const char* string = " helloworld";
	const char* expected = "%20helloworld";
	Test("Test7", string, expected);
}

// 空格在句子末尾
void test8(void)
{
	const char* string = "helloworld ";
	const char* expected = "helloworld%20";
	Test("Test8", string, expected);
}
//一个空格
void test9(void)
{
	const char* string = " .";
	const char* expected = "%20.";
	Test("Test9", string, expected);
}
int main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
}