#include<iostream>
#include<string>
#include<vector>
using namespace std;

union U1
{
	char s[11];
};
union U2    //s占11字节，n占4字节，d占8字节，所以至少需11字节的空间，但11不能被8整除，所以补充字节到16
{
	int n;
	char s[11];
	double d;
};
struct B {
	short c;
	char a;
	int b;
};

struct S1
{
	int i;
	char c;
};
struct S3
{
	char c1;
	S1 s;
	char c2;
};
struct S2
{
	char c1;
	int i;
	char c;
	char c2;
};

class A
{
public:
	int b;
	float c;
	char d;
	char e[9];
	char f;
};

int main(void)
{
	string s = "h";
	cout << "sizeof(s) is " << sizeof(s) << endl;
	A object;
	cout << "sizeof(object) is " << sizeof(object) << endl;

	cout << sizeof(S3) << endl;			//S3=16
	cout << sizeof(S2) << endl;			//S2=12
	cout << sizeof(U1) << endl;        //输出：11
	cout << sizeof(U2) << endl;        //输出：16
	cout << sizeof(B) << endl;		   //输出：8

	char str1[13] = { 0 };
	char str[13] = { 'a','d' };
	const char *pstr = "Hello World!";
	cout << sizeof(str1) << endl;			//13
	cout << sizeof(str) << endl;			//13
	cout << sizeof(pstr) << endl;			//4
	cout << strlen(str1) << endl;			//0
	cout << strlen(str) << endl;			//2
	cout << strlen(pstr) << endl;			//12


	int a = 10;
	int arr[] = { 1, 2, 3 };
	char str2[] = "hello";
	int len_a = sizeof(a);					//4
	int len_arr = sizeof(arr);				//12
	int len_str = sizeof(str2);				//6
}