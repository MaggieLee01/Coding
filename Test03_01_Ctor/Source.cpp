//探究如果子类的初始化列表不写父类的构造函数，会不会自动调用
#include<iostream>
#include<vector>
using namespace std;
class Parent 
{
public:
	Parent(int n):val(n){ cout << "Parent ctor" << endl; }
	Parent() { cout << "Parent default ctor" << endl; };//如果不写该行，子类会报错
private:
	int val;
};

//是的，子类的初始化列表，如果没有基类的构造函数，会自动调用基类的构造函数，如上，但基类已经写了带参数的构造函数覆盖了默认构造函数，则编译报错
//所以，基类的构造函数带参数时，必须写在子类的初始化列表中
class son :public Parent
{
public:
	son(int m):val_b(m)
	{
		cout << "son ctor" << endl;
	}
private:
	int val_b;
};

//测试前向声明
class A;
class B {
	A *a;
	vector<class A>  m;
	//A b;	//编译不通过；类型不完整
};

//测试含有虚函数对象的大小
class C
{
public:
	virtual void test(){}
	int a;
};
class D :public C
{
public:
	int b;
};






int main(void)
{
	son s(1);
	D d;
	cout << sizeof(d) << endl;	//12 包含了指针的大小
}