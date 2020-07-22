#include <iostream>
#include <assert.h>

using namespace std;

// 我是父类
class Tfather
{
public:
	virtual void f() { cout << "father's f()" << endl; }
};

// 我是子类
class Tson : public Tfather
{
public:
	void f() { cout << "son's f()" << endl; }
	int data; // 我是子类独有成员
};
class C :public Tson
{
public:
	void f() { cout << "C's f()" << endl; }

	int Cdata; // 我是C类独有成员
};
class D :public Tson,public Tfather
{
public:
	void f() { cout << "D's f()" << endl; }

	int Ddata; // 我是C类独有成员
};


//int main()
//{
//	Tfather *pA = new C;
//	
//	if (Tson *pb = dynamic_cast<Tson*>(pA))
//	{
//		pb->f();
//	}
//		
//	else	
//		cout << pb << endl;
//
//	Tson *pbb = new Tson;
//	if (C *pc = dynamic_cast<C*>(pbb))
//		pc->f();
//	else
//		cout << pc << endl;
//
//	Tfather *paa = new D;
//	if (Tson *pbbb = dynamic_cast<Tson*>(paa))
//		pbbb->f();
//	else
//		cout << pbbb << endl;
//
//
//	
//	Tfather father;
//	Tson son;
//	son.data = 123;
//
//	Tfather *pf;
//	Tson *ps;
//
//	/* 上行转换：没有问题，多态有效 */
//	ps = &son;
//	pf = dynamic_cast<Tfather *>(ps);
//	pf->f();
//
//	/* 下行转换（pf实际指向子类对象）：没有问题 */
//	pf = &son;
//	ps = dynamic_cast<Tson *>(pf);
//	ps->f();
//	cout << ps->data << endl;		// 访问子类独有成员有效
//
//	/* 下行转换（pf实际指向父类对象）：含有不安全操作，dynamic_cast发挥作用返回NULL */
//	//pf = &father;
//	//ps = dynamic_cast<Tson *>(pf);
//	//assert(ps != NULL);			 	// 违背断言，阻止以下不安全操作
//	//ps->f();
//	//cout << ps->data << endl;		// 不安全操作，对象实例根本没有data成员
//
//	/* 下行转换（pf实际指向父类对象）：含有不安全操作，static_cast无视 */
//	pf = &father;
//	ps = static_cast<Tson *>(pf);
//	assert(ps != NULL);
//	ps->f();
//	cout << ps->data << endl;		// 不安全操作，对象实例根本没有data成员
//
//	system("pause");
//}


void InputInt(int * num)
{
	cout << *num << endl;
}
int main()
{
	const int constant = 21;
	//InputInt(constant); //error C2664: “InputInt”: 不能将参数 1 从“const int”转换为“int *”
	InputInt(const_cast<int*>(&constant));
	system("pause");
}