//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//union U1
//{
//	char s[11];
//};
//union U2    //sռ11�ֽڣ�nռ4�ֽڣ�dռ8�ֽڣ�����������11�ֽڵĿռ䣬��11���ܱ�8���������Բ����ֽڵ�16
//{
//	int n;
//	char s[11];
//	double d;
//};
//struct B {
//	short c;
//	char a;
//	int b;
//};
//
//struct S1
//{
//	int i;
//	char c;
//};
//struct S3
//{
//	char c1;
//	S1 s;
//	char c2;
//};
//struct S2
//{
//	char c1;
//	int i;
//	char c;
//	char c2;
//};
//
//class A
//{
//public:
//	int b;
//	float c;
//	char d;
//	char e[9];
//	char f;
//};
//
//int main(void)
//{
//	string s = "h";
//	cout << "sizeof(s) is " << sizeof(s) << endl;
//	A object;
//	cout << "sizeof(object) is " << sizeof(object) << endl;
//
//	cout << sizeof(S3) << endl;			//S3=16
//	cout << sizeof(S2) << endl;			//S2=12
//	cout << sizeof(U1) << endl;        //�����11
//	cout << sizeof(U2) << endl;        //�����16
//	cout << sizeof(B) << endl;		   //�����8
//
//	char str1[13] = { 0 };
//	char str[13] = { 'a','d' };
//	const char *pstr = "Hello World!";
//	cout << sizeof(str1) << endl;			//13
//	cout << sizeof(str) << endl;			//13
//	cout << sizeof(pstr) << endl;			//4
//	cout << strlen(str1) << endl;			//0
//	cout << strlen(str) << endl;			//2
//	cout << strlen(pstr) << endl;			//12
//
//
//	int a = 10;
//	int arr[] = { 1, 2, 3 };
//	char str2[] = "hello";
//	int len_a = sizeof(a);					//4
//	int len_arr = sizeof(arr);				//12
//	int len_str = sizeof(str2);				//6
//}

#include<memory>
#include<string>
#include <iostream>
using namespace std;
int main() 
{
	//unique_ptr<string> p_s1(new string("this is  a string"));//��ʱ��ֵ�ǿ���������ֵ��
	//cout << *p_s1.get() << endl;
	////unique_ptr<string> p_s2 = p_s1;	//�ᱨ�������˸�ֵ���캯��
	//unique_ptr<string> p_s2 = std::move(p_s1);	//move��p_s1��Ϊ��ʱ��ֵ�������ƶ���ֵ������ֵ��p_s2��p_s1���ͷ�Ϊnullptr
	//p_s1 = string("hello world");	//���������ֵ��p_s1Ϊnullptr
	//cout << *p_s2.get() << p_s1 << endl;
	//return 0;

	int a = 1;
	char c = *((char*)&a);
	if (c == 1)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}
