//答案思路：	已知数组的容纳长度，先遍历一遍，得到空格长度，计算出替换后长度，从后往前逐步赋值迁移，
//			时间复杂度线性，不用额外的空间

//看完答案自己写出来了，答案细节的巧妙之处值得学习；已通过牛客网测试
#include<iostream>
void ReplaceBlank(char str[], int length)
{
	if (str == nullptr || length <= 0)//不要忘记判断length
		return;
	
	int i = 0;
	int strLength = 0;
	int spaceLength = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			++spaceLength;
		++strLength;
		++i;
	}
		
	int newLength = strLength + spaceLength + spaceLength;
	if (length <newLength)
		return;

	--i;//索引值比长度小1
	int j = newLength - 1;
	str[newLength] = '\0';//最好给字符串加结束标志，不然牛客网系统不通过，最后一位是空格

	//答案的细节优化：
	//		i j从length赋值时，不用减一，直接将原始字符串的'\0'传递过去，不用本代码这样子多写了三行（i-1，j-1，str[length]赋值结束符）
	//		while循环内，前移逐个字符赋值时，当i j 两处索引相同时，说明前面已经没有空格，即可跳出while循环，提前结束，无需遍历到字符串的开头

	while (i >= 0 && j > i)//看完答案，思考，此处j > i的判断非常有必要，尤其是对于没有空格的情况
	{
		if (str[i] != ' ')
			str[j] = str[i];
		else
		{
			str[j] = '0';
			str[--j] = '2';
			str[--j] = '%';
		}
		--j;
		--i;
	}
}

// ====================测试代码【copy答案】====================
void Test(const char* testName, char str[], int length, const char expected[])
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	ReplaceBlank(str, length);

	if (expected == nullptr && str == nullptr)
		printf("passed.\n");
	else if (expected == nullptr && str != nullptr)
		printf("failed.\n");
	else if (strcmp(str, expected) == 0)
		printf("passed.\n");
	else
		printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
	const int length = 100;

	char str[length] = "hello world";
	Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
	const int length = 100;

	char str[length] = " helloworld";
	Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
	const int length = 100;

	char str[length] = "helloworld ";
	Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
	const int length = 100;

	char str[length] = "hello  world";
	Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
	Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
	const int length = 100;

	char str[length] = "";
	Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
	const int length = 100;

	char str[length] = " ";
	Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
	const int length = 100;

	char str[length] = "helloworld";
	Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
	const int length = 100;

	char str[length] = "   ";
	Test("Test9", str, length, "%20%20%20");
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
	Test8();
	Test9();

	return 0;
}

