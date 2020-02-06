// ������10��쳲���������
// ��Ŀ��дһ������������n����쳲�������Fibonacci�����еĵ�n�

//50��ʱ�򼴳���int��Χ
//int ������ͨ��ţ��������
//�鱾�𰸣�long long���ͣ�����Ϊunsigned����
//�漰������ӵ�������������

//���岻���������飬����vector�����У�����

//���󷽷���û�˵��ϣ������о�dp�㷨
//�鱾�𰸣�˼·�����Ǻ�
//���Ը�ֵ 1 2 ��ֵ��������0 1 ��ֵ

#include<iostream>
#include<vector>
//�ݹ飬���϶��µ�
int Fibonacci_recursively(int n)
{
	if (n == 0)		return 0;
	if (n == 1)		return 1;
	if (n > 1)
		return (Fibonacci_recursively(n - 1) + Fibonacci_recursively(n - 2));
	else
		return -1;
}
//�ǵݹ飬���¶��ϵģ�����ռ��
int Fibonacci_On(int n)
{
	if (n == 0)		return 0;
	if (n == 1)		return 1;
	if (n > 1)
	{
		//���岻����������
		//vector�е�������ջ�ϻ����ڶ���
		std::vector<int> array(n + 1, 0);
		array[0] = 0;
		array[1] = 1;
		for (int i = 2; i <= n; i++)
			array[i] = array[i - 1] + array[i - 2];
		return array[n];
	}
	else
		return -1;
}
//�ǵݹ飬���¶��ϵģ���������ռ�
int Fibonacci_O1(int n)
{
	if (n == 0)		return 0;
	if (n == 1)		return 1;
	if (n > 1)
	{
		int array[3] = { 0 };
		array[0] = 0;
		array[1] = 1;
		array[2] = 1;
		//�˷����Ͽ죬ѭ�������٣�
		//�鱾������������ռ�prev��curr������Ϊ�丳ֵ������ֵΪsum=prev+curr����Ҫn��ѭ��
		for (int i = 1; i <= n/3; i++) 
		{
			array[0] = array[1] + array[2];
			array[1] = array[0] + array[2];
			array[2] = array[1] + array[0];
		}
		return array[n % 3];
	}
	else
		return -1;
}
//��ѧ����ķ���

//������
int main(void)
{
	int a = Fibonacci_recursively(5);
	int b = Fibonacci_On(5);
	int c = Fibonacci_O1(5);
	std::cout << a << ' ' << b << ' ' << c << std::endl;


	//50��ʱ�򼴳���int��Χ
	//�鱾�𰸣�long long���ͣ�����Ϊunsigned����
	a = Fibonacci_recursively(27);
	b = Fibonacci_On(27);
	c = Fibonacci_O1(27);
	std::cout << a << ' ' << b << ' ' << c << std::endl;
}
