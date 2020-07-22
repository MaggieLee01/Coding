#include<iostream>
#include<string>
using namespace std;

const string ss11;
const string &cs = ss11;
auto & ss = cs;
string result = const_cast<string&>(cs);

struct st 
{
	int a;
	st(int n):a(n){}
};

int main()
{
	int aa = 3;
	const int ab = aa;
	int *ap = (int *)&ab;
	*ap = 20;

	cout << ab << endl;


	//const 变量的探索
	const char* cp="akgsakgsad";
	//string s1 = const_cast<string>(cp);
	//char *a = static_cast<char*>(cp);	
	string s = static_cast<string>(cp);
	string s1 = cp;
	cout << s << endl;
	const_cast<char *> (cp);

	const int a = 3;
	cout <<"a address "<< &a << endl;
	int n = a;
	cout << "n address " << &n << endl;


	const double b = 3.3;
	int m = static_cast<int>(b);	
	cout << m << endl;

	const st s2(1);
	st sst = s2;

	//const 引用
	const int *ptr;
	int val = 3;
	ptr = &val; //ok
	int *ptr1 = &val;
	*ptr1 = 4;
	std::cout << *ptr << std::endl;


	int i = 42;
	int &r1 = i;

	const int &r2 = i;
	std::cout << "r2 = " << r2 << std::endl;
	r1 = 40;
	std::cout << "r2 = " << r2 << std::endl;//测试r2是否改变.

	const int &r3 = i * 2;
	std::cout << "r3 = " << r3 << std::endl;
	r1 = 30;
	std::cout << "r3 = " << r3 << "    i = " << i << std::endl;//测试r3是否改变.

	std::cout << "Double===========================" << std::endl;//测试r3是否改变.

	double val_1 = 3.14;
	const int &r4 = val;
	std::cout << "r4 = " << r4 << std::endl;
	val = 5.2;
	std::cout << "r4 = " << r4 << "     val = " << val_1 << std::endl;//测试r4是否改变.


	double val_2 = 2.1;
	const double &r5 = val_2 * 2;
	std::cout << "r5 = " << r5 << std::endl;
	val_2 = 9.35;
	std::cout << "r5 = " << r5 << "   val_2 = " << val_2 << std::endl;//测试r5是否改变.



	const int val_3 = 3;
	const double &r6 = val_3;
	std::cout << "r6 = " << r6 << "     val_3 = " << val_3 << std::endl;//测试r6是否改变.

	return 0;
}