// �ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���1��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��

#include <cstdio>
#include<iostream>
// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
//        duplication: (���) �����е�һ���ظ�������
// ����ֵ:             
//        true  - ������Ч�����������д����ظ�������
//        false - ������Ч������������û���ظ�������


bool duplicate(int numbers[], int length, int* duplication)
{
	//if (0 == length)
	if (numbers == nullptr || length <= 0)
	{
		duplication = nullptr;
		return false;
	}
	//�������ʼ���Ĺ��ߣ�����for����	,����vector����ѽ����֪��vector���ڴ�������
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
//���������������飻�ޣ�ȫ��
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

// �ظ�����������������С������
void test1()
{
	int numbers[] = { 2, 1, 3, 1, 4 };
	int duplications[] = { 1 };
	test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �ظ�����������������������
void test2()
{
	int numbers[] = { 2, 4, 3, 1, 4 };
	int duplications[] = { 4 };
	test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �����д��ڶ���ظ�������
void test3()
{
	int numbers[] = { 2, 4, 2, 1, 4 };
	int duplications[] = { 2, 4 };
	test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// û���ظ�������
void test4()
{
	int numbers[] = { 2, 1, 3, 0, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// û���ظ�������
void test5()
{
	int numbers[] = { 2, 1, 3, 5, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// ��Ч������
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
//˼·�����������з�Χ��ʹ��n���ȵ������¼����һ������Ϊ2��array[2]=1
//ϸ�ڣ�bool �ͱ�����ӡ����Ϊ0 ���� 1
//˼������Ϊ�յ�ʱ����δ�ӡ�������α�������

//���ο�����https://blog.csdn.net/coolwriter/article/details/81362533
//���˵�һ�ַ������������벻��
//ѧ��ϰ��ʹ��STL��׼�⣺vector���ڴ�������

//���α����룬��ע���Գ����д����������ֱ�Ӹ����˽����д�˲��Խӿڣ��жϲ��Գ���ִ���Ƿ���ȷ
//�е��ж������뷶Χ�Ƿ���Ч
//�˷�����ͨ��ţ����