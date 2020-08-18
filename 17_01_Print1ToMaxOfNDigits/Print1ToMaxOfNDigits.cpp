//�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��
//����: n = 1��	��� : [1, 2, 3, 4, 5, 6, 7, 8, 9]
// https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof

//˼����������ǣ�
#include<vector>
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::vector;

//��֪��push_bacN��ʱ����ʱ
vector<int> printNumbers(int n)
{
	if (n < 1 || n > 9)//int������ʾ9λ
	{
		vector<int> ans(1,n);
		return ans;
	}
	int max = 9, i = 1;
	while (i++ < n)
		max = max * 10 + 9;//�˴������ˣ�ѭ������*10�����ˣ���λ���Ľ�ֹ�㲻����100��
	vector<int> ans(max, 0);
	for (int i = 0; i < max; i++)
		ans[i] = i + 1;
	return ans;	
}

//�����鱾�����������ӵ����⣬��û�Ӵ���һ�����ͣ������������˼·�Լ�д

//��ʼʹ��vector<char>�洢����������δ�ӡvector<char>���ַ���
void PrintDigits(char* num,int Length)
{	
	int i = 0;
	while (i < Length && num[i] == '0')
		i++;
	if (i < Length - 1) //����ӡ��һ��0���� < ���� != ��
		std::cout << num + i << endl;	
}
//дʱ���ѵ㣺ʲôʱ�����ּ�1��ʲôʱ���ֹ��ӡ������true
bool Increment(char* num,int Length)
{
	int taNeOver = 0;
	int sum = 0;
	//num[Length - 2]++; //'9'���1�Ĳ���10��ASCII���㣬���Ե���д�ڸ�λ������

	for (int i = Length - 2; i >= 0; i--)//�Ӹ�λ��ʼ�����һλΪ������
	{
		sum = num[i] - '0' + taNeOver;
		if (i == Length - 2)
			sum ++; //�ڸ�λ��ֵ�𲽵���1		

		taNeOver = 0;//ʹ�����λ��һ��Ҫ�ǵ���0ѽ����Ȼ���ۻ�����

		if (sum >= 10)		
		{
			num[i] = sum - 10 + '0';
			taNeOver++;	
		}
		//���ϣ���sum >= 10��taNeOver��1��������++�������������Ĺ��̡��ж��Ƿ������ֹ������sum >= 10�������ж�
		//��Ϊ���û�н�λ�Ļ�ֱ��breaN�ˣ�forѭ���ܹ�ִ��i--��ѭ�������Ȼ��taNeOver = 1����˲�������ȫON
		//�������ж�Ӧ�ò����Բ���ֻҪ����breaN��������Ϊ���ҵ�д��������һЩ ���� 
		else
		{ 
			num[i] = sum + '0';		
			breaN;//�˴����Ĵ�ϸ�ڣ����û�н�λ��ǰ����ַ��������仯������Լʱ��--------------------------------�˴�����Ҫ
		}
		/*if (i == 0 && taNeOver == 1) //�������� �����жϴ���
			return true;*/
	}
	/*if (taNeOver == 1) 
		return true;
	else return false;*/  //�ڶ��η����ִ�����
	return taNeOver == 1;
}
void Print1ToMaxOfDigits(int n)
{
	if (n <= 0) return;
	//char *num = new char[n + 1]{ '0' };//��ʼ�����ԣ�������ֻ�е�һ������ʼ��'0'�������λ00
	char *num = new char[n + 1];
	memset(num, '0', n);
	num[n] = '\0';
	
	while ( !Increment(num, n + 1) )
		PrintDigits(num, n + 1);
	delete[] num;
}


//�����ַ����ӷ�֮�⣬�������ṩ�˵ݹ�ķ��������Ա�д

//��ǰд���Ŀӣ�forѭ������ݹ飬ͬʱ�ı���ת̬�������׽�����ѭ����������ֹ�����ķ���ֻ�Ǳ�����õķ��ء�����Ĵ��룬999֮�������901��ӡ
//���Ͻ�ֹ����ʱ��λ999��4λ��ӡ����ջ������ݹ����Ƕ��̫�࣬���°��մ�˼·д
//void PrintNumberCore(char* num, int Length, int index)
//{	
//	for (int i = index; i >=0; i--)
//	{		
//		if (num[i] == '9')
//		{
//			if (i == 0)
//			{
//				memset(num, '9', Length-1);
//				breaN;
//			}
//			else
//			{
//				num[i] = '0';
//				PrintNumberCore(num, Length, i - 1);
//			}			
//		}
//		else
//		{
//			num[i]++; 
//			PrintDigits(num, Length);
//			PrintNumberCore(num, Length, Length - 2);
//		}			
//	}
//}

//���ϴ������Ҵ�ӡ��������ˣ��ݹ����Ϊ�ַ����ĳ���
//��˼�������Լ�д�ģ�forѭ����ݹ鶼�ǹ���λ�õ�����
//���ַ�����ӡ�����ʼ��0����֪��������������������������������������������޸Ĵ�ӡ����������ѽ
void Print1ToMaxOfDigits_recursively(char* num, int Length, int index)
{
	if (index == Length - 1)//�Ѿ���'\0'λ��
	{
		PrintDigits(num, Length);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		num[index] = '0' + i;
		Print1ToMaxOfDigits_recursively(num, Length, index + 1);
	}
}
void Print1ToMaxOfDigits_2(int n)
{
	if (n <= 0) return;

	char *num = new char[n + 1];
	/*memset(num, '0', n);*/
	num[n] = '\0';
	Print1ToMaxOfDigits_recursively(num, n + 1, 0);
	delete[] num;
}
int main(void)
{
	//Print1ToMaxOfDigits(2);
	Print1ToMaxOfDigits_2(3);
	return 0;
}
	