/*�� 1+2+...+n ��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����

	����: n = 3;		���: 6
	����: n = 9;		���: 45

	https://leetcode-cn.com/problems/qiu-12n-lcof */

//֮ǰ����λ����֮���޷���������𰸣��й��캯�����麯��������ָ�롢����ģ�� ��������
//�����д�������ر����������Ŵ�д
//���Ӧ�ã��ܶණ��ֵ����Ϥ
class Temp 
{						//ע��ᵽLeetCode����ʱ�������Ҫд������
	public:
	Temp() { N++; sum += N; }
	static void Reset()	//static ������ʲô��
	{	N = 0; sum = 0;	}
	static unsigned int GetSum() { return sum; }
	private:
	static unsigned int N;
	static unsigned int sum;
};
unsigned int Temp::N = 0;//ע���ں������ʼ��������д��
unsigned int Temp::sum = 0;

unsigned int sum01(int num)
{
	Temp::Reset();

	Temp *a = new Temp[num];
	delete[]a;
	a = nullptr;
	return Temp::GetSum();
}

//������ �Լ� �麯��
class A;
A *Array[2];
//������һ�£�����A�̳�B����ΪB�ݹ�Sum
class A 
{
	public:
	virtual unsigned int Sum(unsigned int n) 	{ return 0;	}
};
class B :public A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return Array[!!n]->Sum(n - 1) + n;//��û̫�����麯�� �̳�֮��Ĺ�ϵ��Ϊʲô���ص���A��������Ҫ�ú���ĥ
	}
};
unsigned int sum02(int n)
{
	A a;
	B b;
	Array[0] = &a;//Array ���Ǵ��A������ָ������
	Array[1] = &b;

	int val = Array[1]->Sum(n);
	return val;
}

//����ָ������麯��
typedef unsigned int(*fun)(unsigned int);
unsigned int sum03_Teminator(unsigned int)
{
	return 0;
}
//unsigned int sum03( int n)		//�����Ĳ������ͱ���һ�����ܸ�ֵ����������
unsigned int sum03(unsigned int n)
{
	static fun f[2] = { sum03_Teminator,sum03 };//������static
	return n + f[!!n](n - 1);
}

//ģ��ݹ� 
template <unsigned int n> struct sum04
{
	enum Value 
	{	N = sum04<n - 1>::N + n	};	//{}���治�ӣ�	
};
template<> struct sum04<1>
{
	enum Value { N = 1 };
};



int main(void)
{
	int ans = 0;
	ans = sum01(6);
	ans = sum02(6);
	ans = sum03(6);
	ans = sum04<6>::N;

	return 0;
}