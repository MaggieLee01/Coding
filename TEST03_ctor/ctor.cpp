//百度笔试题
#include<iostream>
using namespace std;
class Parent
{
public:
	Parent()
	{ cout << "ctor" << endl; }
	Parent(const Parent &p) { cout << "copy" << endl; }
	const Parent &operator=(const Parent &p) 
	{
		cout << "assignment" << endl;
		return *this;
	}
};
//int main(void)
//{
//	Parent p;
//	Parent p1(p);//这两种都是拷贝构造函数
//	Parent p2 = p;
//	p2 = p1;
//	return 0;
//}



//不明白为什么此处报错，说是delete了 不明白
class A
{
public: 
	virtual void testA() = 0;//带有这种纯虚函数的不能实例化
	virtual void print() = 0;
};
class B :public A
{
public:
	virtual void testA() 
	{
		cout << "B：testA" << endl;
	}
	virtual void print() override
	{
		cout << "B：print" << endl;
	}
	virtual void testB()
	{
		cout << "B：testB" << endl;
	}
};
class C :public B
{
public:
	virtual void testA() {}
	virtual void print() override
	{
		cout << "C:print" << endl;
	}
};
int main(void)
{
	C c;
	c.print();
	c.testA();
	c.testB();//此处不属于动态编译，属于继承，继承了父类的数据成员和函数调用权。如果重写了虚函数，则调用自身的，如果没有重写，则调用父类的

	A *a = new B;//注意动态编译：指针调用，向上转型，虚函数
	a->print();
	//a->testB();//不通过；也只能调用从A中继承下来的函数。毕竟指针还是属于A类型，A类型中没有testB函数；
	a->testA();
	return 0;
}