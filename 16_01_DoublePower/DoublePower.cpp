//实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。
//来源：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof
//-100.0 < 底数 < 100.0， 指数是32位有符号整数，其数值范围是[−2^31, 2^31 − 1] 。

//小数问题//负指数问题
//负指数问题可以通过abs()绝对值函数，abs()函数的处理类型为int；long int labs (long int n);
//如何得到double函数的小数点位，这不是问题，无需关心，double类型可以直接相乘
//此题的考察点是什么
//输入样例有1.00000，-2147483648；输入样例的2.00000，-2147483648
//根据测试样例来看，重点在考察int型数据类型溢出的处理

//求绝对值，用abs,(unsigned int)类型转换，还不太明白两者的优缺点
//double类型，最好不要用 == 判断
//int c = -2147483648;这一句编译VS不通过

#include<cmath>
#include<iostream>
using std::cout;
using std::endl;

//long double GetPower(double base, int exponent)
long double GetPower(double base, long int exponent)//-2147483648取绝对值后溢出int范围一位，如果用int类型的话又是-2147483648，
{
	if (exponent == 0)	return 1;
	if (exponent == 1)  return base;
	long double ans = GetPower(base, exponent >> 1);//能用位移就不用除法
	ans *= ans;
	//if (exponent % 2 == 1)
	if (exponent & 01 == 1)//借鉴书本答案，用位移判断是否余1
		ans *= base;
	return ans;
}
double myPow(double x, int n)
{
	if (x == 0) return 0;
	if (n == 0) return 1;
	if (n > 0) return GetPower(x, n);
	if (n < 0) return 1.0 / GetPower(x, labs(n));//此处最好用1.0,而不是1
}
//看题解，两个函数合为一个函数，则不会出现我上面的求幂运算函数需要long int 的形参情况，因为遇到指数为-1时，返回的是倒数，不会溢出
double pow_Key(double x, int n)
{
	if (x == 0 && n < 0)	return -1;
	if (n == 0) return 1;
	if (n == 1) return x;
	if (n == -1) return 1.0 / x;
	double ans = pow_Key(x, n >> 1);
	ans *= ans;
	if (n & 01) ans *= x;
	return ans;
}

//以上我写的代码，求乘方的思路正确，但是考虑不够全面
//看了书本答案，书本答案真的是考虑齐全，比题解齐全很多，根据课本答案写一遍
//考虑了输入为0，指数为负的情况
//考虑了判断两个double数值是否相等的情况，不能直接用 == 判断，更严谨一些
//除的时候最好用1.0，而不是1
bool g_InvalidTnput = false;
double PowerWithUnsignedExponent(double base, unsigned exponent)
{
	if (exponent == 0) return 1;
	if (exponent == 1) return base;
	double ans = PowerWithUnsignedExponent(base, exponent >> 1);
	ans *= ans;
	if (exponent & 01) ans *= base;
	return ans;
}
bool equal(double m, double n)
{
	if ((m - n) > -0.000000000001 && (m - n) < 0.000000000001)
		return true;
	else
		return false;
}
double power_answer(double base,int exponent)
{
	//g_InvalidTnput = false;
	if (equal(base, 0) && exponent < 0)
	{
		//g_InvalidTnput = true;
		return -1;
	}
	unsigned int absExponent = (unsigned int)exponent;
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);//直接加负号取相反数
	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;
	return result;
}


int main(void)
{
	double a = 1.2;
	double b = a * a;
	cout << b << endl;

	a = -1.2;
	b = a * a;
	cout << b << endl;

	//int c = -2147483648;
	int c = -1;
	b = (unsigned int)c;
	cout << b << endl;

	a = 2.100000;
	b = 3;
	double ans = myPow(a, b);
	ans = power_answer(a, b);

	a = 2.00000;
	b = -2;
	ans = myPow(a, b);
	ans = power_answer(a, b);
	return 0;
}
