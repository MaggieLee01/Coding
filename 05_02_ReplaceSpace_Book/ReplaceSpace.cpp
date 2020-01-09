//��˼·��	��֪��������ɳ��ȣ��ȱ���һ�飬�õ��ո񳤶ȣ�������滻�󳤶ȣ��Ӻ���ǰ�𲽸�ֵǨ�ƣ�
//			ʱ�临�Ӷ����ԣ����ö���Ŀռ�

//������Լ�д�����ˣ���ϸ�ڵ�����֮��ֵ��ѧϰ����ͨ��ţ��������
#include<iostream>
void ReplaceBlank(char str[], int length)
{
	if (str == nullptr || length <= 0)//��Ҫ�����ж�length
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

	--i;//����ֵ�ȳ���С1
	int j = newLength - 1;
	str[newLength] = '\0';//��ø��ַ����ӽ�����־����Ȼţ����ϵͳ��ͨ�������һλ�ǿո�

	//�𰸵�ϸ���Ż���
	//		i j��length��ֵʱ�����ü�һ��ֱ�ӽ�ԭʼ�ַ�����'\0'���ݹ�ȥ�����ñ����������Ӷ�д�����У�i-1��j-1��str[length]��ֵ��������
	//		whileѭ���ڣ�ǰ������ַ���ֵʱ����i j ����������ͬʱ��˵��ǰ���Ѿ�û�пո񣬼�������whileѭ������ǰ����������������ַ����Ŀ�ͷ

	while (i >= 0 && j > i)//����𰸣�˼�����˴�j > i���жϷǳ��б�Ҫ�������Ƕ���û�пո�����
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

// ====================���Դ��롾copy�𰸡�====================
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

// �ո��ھ����м�
void Test1()
{
	const int length = 100;

	char str[length] = "hello world";
	Test("Test1", str, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
	const int length = 100;

	char str[length] = " helloworld";
	Test("Test2", str, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
	const int length = 100;

	char str[length] = "helloworld ";
	Test("Test3", str, length, "helloworld%20");
}

// �����������ո�
void Test4()
{
	const int length = 100;

	char str[length] = "hello  world";
	Test("Test4", str, length, "hello%20%20world");
}

// ����nullptr
void Test5()
{
	Test("Test5", nullptr, 0, nullptr);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
	const int length = 100;

	char str[length] = "";
	Test("Test6", str, length, "");
}

//��������Ϊһ���ո���ַ���
void Test7()
{
	const int length = 100;

	char str[length] = " ";
	Test("Test7", str, length, "%20");
}

// ������ַ���û�пո�
void Test8()
{
	const int length = 100;

	char str[length] = "helloworld";
	Test("Test8", str, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
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

