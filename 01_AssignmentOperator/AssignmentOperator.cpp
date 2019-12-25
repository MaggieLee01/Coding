//思路：根据类的定义，第一个构造函数参数为char*，第二个构造的参数为引用拷贝，
//重载=运算符，是想str1=str2赋值。

#include<cstdio>
#include<cstring>
#include<iostream>
#pragma warning(disable:4996)

class CMyString
{
public:
	CMyString(char *pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator=(const CMyString& str);

	void Print();

private:
	char* m_pData;
};

CMyString::CMyString(char *pData)
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int length = 0;
		char *m = pData;
		while (*m++ != '\0')
			length++;

		m = pData;
		
		m_pData = new char[length + 1];
		char *n = m_pData;//必须有在m_pData指向后才可以赋值给其他指针
		while (*m != '\0')
			*(n++) = *(m++);//不能直接对m_pData，pData指针操作呀，不然指针指向末尾
		*(n++) = '\0';
	}
}
CMyString::CMyString(const CMyString& str)//看答案，此处不用this也可以，也无需判断空指针
{
	char *m = str.m_pData;
	if (m == nullptr)
	{
		this->m_pData = new char[1];
		this->m_pData[0] = '\0';
	}
	else
	{
		int length = 0;
		while (*m++ != '\0')
			length++;

		m = str.m_pData;

		this->m_pData = new char[length + 1];
		char *n = this->m_pData;//必须有在m_pData有指向后才可以赋值给其他指针

		while (*m != '\0')
			*(n++) = *(m++);//不能直接对m_pData，pData指针操作呀，不然指针指向末尾
		*(n++) = '\0';
	}
}
CMyString& CMyString::operator=(const CMyString& str)
{
	//个人以为和上面的构造赋值一样
	if (this == &str)
		return *this;
	delete[] m_pData;//避免内存泄露
	m_pData = nullptr;//很重要，避免野指针

	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
	return *this;	
}
void CMyString::Print() 
{
	std::cout << this->m_pData << std::endl;
}
CMyString::~CMyString()
{
	delete[] m_pData;
}

// ====================测试代码====================


void Test1()
{
	printf("Test1 begins:\n");

	char text[] = "Hello world";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");
}

// 赋值给自己
void Test2()
{
	printf("Test2 begins:\n");

	char text[] = "Hello world";

	CMyString str1(text);
	str1 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str1.Print();
	printf(".\n");
}

// 连续赋值
void Test3()
{
	printf("Test3 begins:\n");

	char text[] = "Hello world";

	CMyString str1(text);
	CMyString str2, str3;
	str3 = str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str3.Print();
	printf(".\n");
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	system("pause");
	return 0;
}

//看完参考答案：
//字符串的长度计算、字符串的赋值，有专门的string函数strlen strcpy，无需自己再写了
//new函数的写法
//拷贝构造函数计算长度，分配空间，copy即可，没有涉及this指针，也不需要判断str是否为空

//思考，那为什么第一个char* 指针需要判断是否为空呢。
//明白了，copy构造的时候既然能传参CMyString类的成员，即已经解决了空指针的问题，直接复制即可。

//思考：什么时候用this指针，多看代码攒经验
//"zbc"这种字符串，必须加"cstrings"，char* text = "Hello world";这种定义报错，换成数组定义

//多考虑测试样例

//vs2017里面strcpy函数报错，处理方法三种，
//1加#pragma warning(disable:4996)
//2.c/c++预处理器里面预处理定义加_CRT_SECURE_NO_WARNINGS
//3.c/c++常规，SDL选项关闭【不建议】
