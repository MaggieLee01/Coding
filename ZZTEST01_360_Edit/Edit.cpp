//#include <sstream>        //istringstream 必须包含这个头文件
#include <iostream>
#include <vector>
//#include <climits> //INT_MIN的头文件
#include <algorithm>
using namespace std;
int main()
{
	string input;
	char a;
	while (cin >> a)
		input.push_back(a); //一行要输入多个数，构成数组
	int Length = input.size();

	string str1, str2;
	int strLength = Length >> 1;
	for (int i = 0; i < strLength; i++)
		str1.push_back(input[i]);
	
	str2 = input.substr(strLength, strLength);

	int up = 0;
	int down = 0;

	vector<int> Dict(strLength + 1, 0);
	for (int i = 0; i <= strLength; i++)
		Dict[i] = i;
	//第0行相当于空字符，第一行对应第一个字母，相当于base case
	for (int i = 0; i < strLength; i++)
	{
		//相当于首字符上面的一行
		up = Dict[0];
		Dict[0]++;

		for (int j = 0; j < strLength; j++)
		{
			//dict[j+1]要更新，先把以前的值保存下来
			down = Dict[j + 1];
			//相当于第 i 处的距离存储在第i+1行
			if (str1[i] == str2[j])
				Dict[j + 1] = up;
			else
				Dict[j + 1] = min(min(Dict[j + 1], up), Dict[j]) + 1;

			up = down;
		}
	}
	int l= Dict[strLength];


	/*vector< vector<int> > Dict(strLength + 1, vector<int>(strLength + 1, 0));
	int i = 0, j = 0;
	for (i = 0; i < strLength; i++)
		Dict[i][strLength] = strLength - i;
	for (j = 0; j < strLength; j++)
		Dict[strLength][j] = strLength - j;

	for (i = strLength - 1; i >= 0; i--)
	{
		for (j = strLength - 1; j >= 0; j--)
		{
			if (str1[i] == str2[j])
				Dict[i][j] = Dict[i + 1][j + 1];
			else
				Dict[i][j] = min(min(Dict[i + 1][j], Dict[i + 1][j + 1]), Dict[i + 1][j + 1]) + 1;
		}
	}
	int l = Dict[0][0];*/
	std::cout << l << std::endl;
	return 0;
}