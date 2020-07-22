#include <fstream>
#include<stdlib.h>
#include <iostream>
using namespace std;
class D
{
public:
	D(int w = 48):i(w) { }
	void Get(){cout << i << endl;}
private:
	int i;
};
int main()
{
	ofstream fout("test1.txt");
	if(!fout)
	{
		cout << "Error" << endl;
		system("pause");
		return (1);
	}
	D D1(65);
	fout.write((char*)&D1, sizeof D1);//转化为char 类型，写了个A
	fout.close();
	ifstream fin("test1.txt");
	if(!fin)
	{
		cout << "Error" << endl;
		system("pause");
		return (1);
	}
	D D2;
	fin.read((char*)&D2, sizeof D2);
	D2.Get();
	fin.close();
	system("pause");
	return 0;
}


	
	