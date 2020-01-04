// ������4����ά�����еĲ���
// ��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
// �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

// ˼·���̣����������������򣬵����Ŀ����ö��ַ�����ϸ˼������ת��Ϊһά���ֺ���sorted��ÿ�еĺ�벿�ֺ���һ�е�ǰ�벿�ִ�С�޷���֪
//          Ȼ��˼�����������ֱȽϺ󣬵������ӽ�����ֳ���4�飬�������ų�һ�飬���������޷��Ƚϣ������޷�����
//			Ȼ������ڽ�Ŀ�����ֺ�1 4 λ���ϵ������жϱȽϣ���Ȼ������һ�������ѣ�����𰸣������Ƕȣ�Ӧ�ú�2 3 λ���ϵ����ֽ��бȽϣ������ų�һ�л���һ�С�
//			����𰸺��Լ�д,�������⣺������0��ʼ��ԭ������ģ����ն�ά�����±�ı�׼д����

//while��д�Ƚ�������ʱ������ȱȽϲ��ȣ��ٱȽ���ȣ�Ч�ʻ�������
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

	//Ҳ���Զ���һ��boolֵ����ֵΪfalse������ȷ�ĳ��ϸ�ֵΪtrue����󷵻ظ�boolֵ

	if (matrix == nullptr || columns > 0 || rows > 0)//�˴���Ӧ���ж�����������
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
//���Դ���
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
// Ҫ���ҵ�����������
void Test1()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������
void Test2()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С������
void Test3()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������������
void Test4()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С�����ֻ�С
void Test5()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ������������������ֻ���
void Test6()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test6", (int*)matrix, 4, 4, 16, false);
}

// ³���Բ��ԣ������ָ��
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