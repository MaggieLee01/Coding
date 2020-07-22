//�ٶȱ�����
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
//	Parent p1(p);//�����ֶ��ǿ������캯��
//	Parent p2 = p;
//	p2 = p1;
//	return 0;
//}



//������Ϊʲô�˴�����˵��delete�� ������
class A
{
public: 
	virtual void testA() = 0;//�������ִ��麯���Ĳ���ʵ����
	virtual void print() = 0;
};
class B :public A
{
public:
	virtual void testA() 
	{
		cout << "B��testA" << endl;
	}
	virtual void print() override
	{
		cout << "B��print" << endl;
	}
	virtual void testB()
	{
		cout << "B��testB" << endl;
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
	c.testB();//�˴������ڶ�̬���룬���ڼ̳У��̳��˸�������ݳ�Ա�ͺ�������Ȩ�������д���麯�������������ģ����û����д������ø����

	A *a = new B;//ע�⶯̬���룺ָ����ã�����ת�ͣ��麯��
	a->print();
	//a->testB();//��ͨ����Ҳֻ�ܵ��ô�A�м̳������ĺ������Ͼ�ָ�뻹������A���ͣ�A������û��testB������
	a->testA();
	return 0;
}