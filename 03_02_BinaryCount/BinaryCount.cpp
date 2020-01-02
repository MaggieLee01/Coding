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

int count(std::vector<int>num, int start, int end)
{
	int m = 0;
	for (auto i:num)
		if (i >= start && i <= end)
			m++;
	return m;
}

//���ַ�ģ�壬��whileѭ�������ǵݹ�
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
int main(void)
{
	std::vector<int> num1= { 2, 1, 3, 1, 4 };
	duplicate(num1, 5);

	std::vector<int> num2 = { 2, 4, 3, 1, 4 };
	duplicate(num2, 5);

	std::vector<int> num3 = { 2, 4, 2, 1, 4 };
	duplicate(num3, 5);

	return 0;
}