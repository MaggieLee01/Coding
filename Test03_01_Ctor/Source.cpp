//̽���������ĳ�ʼ���б�д����Ĺ��캯�����᲻���Զ�����
#include<iostream>
#include<vector>
using namespace std;
class Parent 
{
public:
	Parent(int n):val(n){ cout << "Parent ctor" << endl; }
	Parent() { cout << "Parent default ctor" << endl; };//�����д���У�����ᱨ��
private:
	int val;
};

//�ǵģ�����ĳ�ʼ���б����û�л���Ĺ��캯�������Զ����û���Ĺ��캯�������ϣ��������Ѿ�д�˴������Ĺ��캯��������Ĭ�Ϲ��캯��������뱨��
//���ԣ�����Ĺ��캯��������ʱ������д������ĳ�ʼ���б���
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

//����ǰ������
class A;
class B {
	A *a;
	vector<class A>  m;
	//A b;	//���벻ͨ�������Ͳ�����
};

//���Ժ����麯������Ĵ�С
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
	cout << sizeof(d) << endl;	//12 ������ָ��Ĵ�С
}