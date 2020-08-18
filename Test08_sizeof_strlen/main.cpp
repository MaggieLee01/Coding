//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//union U1
//{
//	char s[11];
//};
//union U2    //s占11字节，n占4字节，d占8字节，所以至少需11字节的空间，但11不能被8整除，所以补充字节到16
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
//	cout << sizeof(U1) << endl;        //输出：11
//	cout << sizeof(U2) << endl;        //输出：16
//	cout << sizeof(B) << endl;		   //输出：8
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
	//unique_ptr<string> p_s1(new string("this is  a string"));//临时右值是可以用来赋值的
	//cout << *p_s1.get() << endl;
	////unique_ptr<string> p_s2 = p_s1;	//会报错，禁用了赋值构造函数
	//unique_ptr<string> p_s2 = std::move(p_s1);	//move将p_s1变为临时右值，利用移动赋值函数赋值给p_s2后，p_s1被释放为nullptr
	//p_s1 = string("hello world");	//如果不给新值，p_s1为nullptr
	//cout << *p_s2.get() << p_s1 << endl;
	//return 0;

	int a = 1;
	char c = *((char*)&a);
	if (c == 1)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}
