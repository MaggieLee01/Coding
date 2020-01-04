// �ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���1��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��


// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
//        duplication: (���) �����е�һ���ظ�������
// ����ֵ:             
//        true  - ������Ч�����������д����ظ�������
//        false - ������Ч������������û���ظ�������
#include<iostream>
#include<cstdio>
#include<vector>
//����һ
//�Լ���д�ѵ㣺�˴�ͳ��ʱ�˵㴦�Ƿ���Ⱥţ����ô�����2,1,3,1,4,������2,1,3,3,4�Ⱥŵ������һ��
//д�ɵݹ�ʽ���ַ��Ĵ������ڲ�ݹ���ȷ����֮�󣬽����˵����ڶ���ĺ������沿��
/*
int count1(int numbers[], int length, int start, int end)
{
	int m = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] >= start && numbers[i] <= end)
			m++;
	}
	return m;
}

bool duplicate_wrong(int numbers[], int length, int start, int end, int* duplication)
{
	if (numbers == nullptr || length <= 0)
	{
		duplication = nullptr;
		return false;
	}

	if (start >= end)
	{
		*duplication = start;
		return true;
	}
	int mid = (end - start) >> 1;
	mid += start;

	int no = count1(numbers, length, start, mid);
	if (no > mid - start)
		duplicate_wrong(numbers, length, start, mid, duplication);
	else
		duplicate_wrong(numbers, length, mid, end, duplication);

	return false;
}
*/

//���Զ���
//���ַ�ģ�壬��whileѭ�������ǵݹ�
//��֪����δ��� mid=m ���������{ 2, 4, 3, 1, 4, 5}��
/*
int duplicate(std::vector<int>num, int length)
{
	int left = 1;
	int right = num.size();
	if (right > length)
		return -1;
	
	while (left < right)
	{
		int mid = (right - left) >> 1;//��������ơ�����
		right = left + mid;
		mid = right;
		int m = count(num, left, right);
		
		if (m > mid)
			right = mid;
		else if (m < mid)
			left = mid;
	}
	if (left = right)
		return left;
	return -1;
}
*/

//�˴�ֱ�ӱȽϸ�������m���ж���������ָ������бȽϣ�������mid, �������м�һ�������

//���Ŵ𰸸���ģ������Լ�д������
int count(std::vector<int>num, int start, int end)
{
	int m = 0;
	for (auto i : num)
		if (i >= start && i <= end)
			m++;
	return m;
}
//�˷���ֻͳ�ƴ�С��ǰһ�εĸ���
int duplicate(std::vector<int>num, int length) 
{
	int left = 1;
	int right = num.size() - 1;
	
	while (left <= right)
	{
		int mid = (right - left) >> 1;
		mid = mid + left;
		int m = count(num, left, mid);
		if (right == left)
		{
			if (m > 1)
				return left;
			else
				break;
		}
		if (m > mid - left + 1)
			right = mid;
		else
			left = mid + 1;
	}
	return -1;
}
int main(void)
{
	std::vector<int> num1= { 2, 1, 3, 1, 4 };
	duplicate(num1, 5);

	std::vector<int> num2 = { 2, 4, 3, 1, 4, 5};
	duplicate(num2, 6);

	std::vector<int> num3 = { 2, 4, 2, 1, 4 };
	duplicate(num3, 5);

	return 0;
}