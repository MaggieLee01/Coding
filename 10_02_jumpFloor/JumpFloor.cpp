//��ָoffer��չ��Ŀ������쳲�����������Ŀ
//��ͨ��ţ��������ϵͳ
#include<iostream>
#include<vector>
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
int JumpFloor(int number)
{
	if (number <= 0) return 0;
	std::vector<int> dict(2, 0);
	dict[0] = 1;
	dict[1] = 2;
	if (number < 3) return dict[number - 1];
	int sum = 0;
	for (int i = 3; i <= number; i++)
	{
		sum = dict[0] + dict[1];
		dict[0] = dict[1];
		dict[1] = sum;		
	}
	return sum;
}
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
int JumpFloor01(int number)
{
	if (number <= 0) return 0;
	std::vector<int> dict(number + 1, 0);
	dict[0] = 1;
	dict[1] = 1;
	for (int i = 2; i <= number; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dict[i] += dict[j];
		}
	}
	return dict[number];
}
int main(void)
{
	int m = JumpFloor01(0);
	std::cout << m << std::endl;
	m = JumpFloor01(1);
	std::cout << m << std::endl;
	m = JumpFloor01(2);
	std::cout << m << std::endl;
}