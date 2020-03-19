/*请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"0123"及"-1E-16"都表示数值，
但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
 https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof */


//哎，不太喜欢这种问题
#include<string>
using std::string;

bool isNumber(string s) 
{
	int sLength = s.size();
	int pointFlag = 0;
	for (int i = 0; i < sLength; i++)
	{
		if (s[i] == '.')
		{
			if (pointFlag == 1) return false;
			pointFlag = 1;
		}
	}
	
}
