#include <iostream>
#include <assert.h>

using namespace std;

// ���Ǹ���
class Tfather
{
public:
	virtual void f() { cout << "father's f()" << endl; }
};

// ��������
class Tson : public Tfather
{
public:
	void f() { cout << "son's f()" << endl; }
	int data; // ����������г�Ա
};
class C :public Tson
{
public:
	void f() { cout << "C's f()" << endl; }

	int Cdata; // ����C����г�Ա
};
class D :public Tson,public Tfather
{
public:
	void f() { cout << "D's f()" << endl; }

	int Ddata; // ����C����г�Ա
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
//	/* ����ת����û�����⣬��̬��Ч */
//	ps = &son;
//	pf = dynamic_cast<Tfather *>(ps);
//	pf->f();
//
//	/* ����ת����pfʵ��ָ��������󣩣�û������ */
//	pf = &son;
//	ps = dynamic_cast<Tson *>(pf);
//	ps->f();
//	cout << ps->data << endl;		// ����������г�Ա��Ч
//
//	/* ����ת����pfʵ��ָ������󣩣����в���ȫ������dynamic_cast�������÷���NULL */
//	//pf = &father;
//	//ps = dynamic_cast<Tson *>(pf);
//	//assert(ps != NULL);			 	// Υ�����ԣ���ֹ���²���ȫ����
//	//ps->f();
//	//cout << ps->data << endl;		// ����ȫ����������ʵ������û��data��Ա
//
//	/* ����ת����pfʵ��ָ������󣩣����в���ȫ������static_cast���� */
//	pf = &father;
//	ps = static_cast<Tson *>(pf);
//	assert(ps != NULL);
//	ps->f();
//	cout << ps->data << endl;		// ����ȫ����������ʵ������û��data��Ա
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
	//InputInt(constant); //error C2664: ��InputInt��: ���ܽ����� 1 �ӡ�const int��ת��Ϊ��int *��
	InputInt(const_cast<int*>(&constant));
	system("pause");
}