// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.�����������We%20are%20happy.����

//˼·���̣�	������������һ��֮���滻��ʱ�临�Ӷȣ����ԣ�
//			ϸ�����⣬�滻������ַ������������˱任�������ԭ�ַ����ϸĶ����鷳����Ҫ��ֵ���µĿռ䡣
//			��������������Ϊ�գ�
//			�˷����˷ѿռ䣬����ʱ�������ϴ�ո����ʱ������ReplaceSpace()�����в����ͷ��ڴ�ռ䣬����й¶

//����STL���string����

//��˼·�޷���ţ�������ԣ������ṹ��һ�����Լ��Ĳ���������ȫ��ͨ����

#include<iostream>
#include<string.h>

char* ReplaceSpaces(const char* string) 
{
	if (string == nullptr)
		return nullptr;

	//���峤�Ȳ������ַ����ռ䡾ջ�ռ�Ҳ�С�������ֵ����ô������ʹ��new?
	//ʹ��new�󣬵���ʱ���ܴ�replace��ֱ�Ӳ鿴�ַ��������������ڴ洦�����������newʱ��()����ֵ0�ܿ���

	int length = strlen(string);

	char* newstring = new char[length + length + length + 1]();//��()����ֵ0��úܶ�
	char* replace = newstring;

	while (*string != '\0')//�ַ��������ı�־����������
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

	//ϸ������:
	//�˴����ص�Ӧ�����ַ�������λ�������ƶ�������ָ�룬�˴�����ܶ�Σ���������
	return newstring;
}

// ====================���Դ��롾�Լ�д��====================
void Test(const char* testname,const char* string, const char* expected)
{
	std::cout << testname << "	begins:	";
	char *result = ReplaceSpaces(string);
	//Ӧ�þ�������������ټ���Ƿ�Ϊ�գ��ж��Ƿ�Ϊ��ֻ��Ϊ��ʹ��strcmp���������Բ�Ӧ���ж�string��Ӧ���ж�result

	/*if (string == nullptr)
		if (expected != nullptr)
		{
			std::cout << "Failed" << std::endl;
			return;//�˴������صĻ�������Ĵ�����Ҫ��else��������
		}
		else
		{
			std::cout << "Passed" << std::endl;
			return;//�˴������صĻ�������Ĵ�����Ҫ��else��������
		}
	*/
	if(result == nullptr && expected == nullptr)
		std::cout << "Passed" << std::endl;
	
	else if(result == nullptr || expected == nullptr)
		std::cout << "Failed" << std::endl;
	else
	{
		//ϸ�ڣ�strcmp�����Ĳ���Ϊ�գ���ô�죬ò�Ʊ���
		int test = strcmp(result, expected);
		if (!test)
			std::cout << "Passed" << std::endl;
		else
			std::cout << "Failed" << std::endl;
	}
	//��Ҫ�����ͷŶ�̬�ڴ�ռ�
	delete result;
	result = nullptr;
}
//�����м����ո�
void test1(void)
{
	const char* string = "We are happy.";
	const char* expected = "We%20are%20happy.";
	Test("Test1", string, expected);
}
//û�пո�
void test2(void)
{
	const char* string = "Wearehappy.";
	const char* expected = "Wearehappy.";
	Test("Test2", string, expected);
}
//ȫ�ǿո�
void test3(void)
{
	const char* string = "   .";
	const char* expected = "%20%20%20.";
	Test("Test3", string, expected);
}
//����Ϊ��
void test4(void)
{
	const char* string = nullptr;
	const char* expected = "%20%20%20.";
	Test("Test4", string, expected);
}
//���Ϊ��
void test5(void)
{
	const char* string = "   .";
	const char* expected = nullptr;
	Test("Test5", string, expected);
}
//ȫ��Ϊ��
void test6(void)
{
	const char* string = nullptr;
	const char* expected = nullptr;
	Test("Test6", string, expected);
}

// �ո��ھ��ӿ�ͷ
void test7(void)
{
	const char* string = " helloworld";
	const char* expected = "%20helloworld";
	Test("Test7", string, expected);
}

// �ո��ھ���ĩβ
void test8(void)
{
	const char* string = "helloworld ";
	const char* expected = "helloworld%20";
	Test("Test8", string, expected);
}
//һ���ո�
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