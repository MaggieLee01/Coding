/*求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

	输入: n = 3;		输出: 6
	输入: n = 9;		输出: 45

	https://leetcode-cn.com/problems/qiu-12n-lcof */

//之前考虑位运算之后，无法解出，看答案，有构造函数，虚函数、函数指针、函数模板 各个方法
//对类的写法不是特别熟练，看着答案写
//类的应用，很多东西值得熟悉
class Temp 
{						//注意搬到LeetCode里面时，这个类要写到外面
	public:
	Temp() { N++; sum += N; }
	static void Reset()	//static 函数有什么用
	{	N = 0; sum = 0;	}
	static unsigned int GetSum() { return sum; }
	private:
	static unsigned int N;
	static unsigned int sum;
};
unsigned int Temp::N = 0;//注意在函数外初始化，和其写法
unsigned int Temp::sum = 0;

unsigned int sum01(int num)
{
	Temp::Reset();

	Temp *a = new Temp[num];
	delete[]a;
	a = nullptr;
	return Temp::GetSum();
}

//利用类 以及 虚函数
class A;
A *Array[2];
//尝试了一下，不能A继承B，因为B递归Sum
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
		return Array[!!n]->Sum(n - 1) + n;//还没太明白虚函数 继承之间的关系，为什么最后回调到A，此题需要好好琢磨
	}
};
unsigned int sum02(int n)
{
	A a;
	B b;
	Array[0] = &a;//Array 就是存放A类对象的指针数组
	Array[1] = &b;

	int val = Array[1]->Sum(n);
	return val;
}

//函数指针代替虚函数
typedef unsigned int(*fun)(unsigned int);
unsigned int sum03_Teminator(unsigned int)
{
	return 0;
}
//unsigned int sum03( int n)		//函数的参数类型必须一样才能赋值给函数数组
unsigned int sum03(unsigned int n)
{
	static fun f[2] = { sum03_Teminator,sum03 };//依旧是static
	return n + f[!!n](n - 1);
}

//模板递归 
template <unsigned int n> struct sum04
{
	enum Value 
	{	N = sum04<n - 1>::N + n	};	//{}里面不加；	
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