/*	对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。
	返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。

	输入：str1 = "ABCABC", str2 = "ABC"
	输出："ABC"

	https://leetcode-cn.com/problems/greatest-common-divisor-of-strings */

#include<string>
#include<algorithm>
using std::swap;
using std::string;

//网页编辑一遍成，开心
string gcdOfStrings(string str1, string str2)
{
	int Length2 = str2.size();
	int Length1 = str1.size();

	//寻找公约数       
	if (Length1 < Length2) swap(Length1, Length2); //使length1大
	while (Length1 % Length2 != 0)
	{
		int temp = Length2;
		Length2 = Length1 % Length2;
		Length1 = temp;
	}
	int divisor = Length2;

	//找公因式，可以直接用substr函数
	string ans;
	int i = 0, j = 0, k = 0;//str1 str2 ans的索引
	while (i < divisor)
	{
		if (str1[i] != str2[j]) return "";
		ans += str1[i];
		i++; j++;
	}
	//刚好前面的检验过，继续验证后面的
	Length1 = str1.size();
	Length2 = str2.size();
	while (i < Length1)
	{
		if (k == divisor) k = 0;
		if (str1[i] != ans[k]) return "";
		i++; k++;
	}
	while (j < Length2)
	{
		if (k == divisor) k = 0;
		if (str2[j] != ans[k]) return "";
		j++; k++;
	}
	return ans;
}

//数学知识，就是找到两者长度的最大值，该长度的字符串即为ans
//看了题解，发现自己写的代码并不简洁，各个功能都是自己实现的，例如，求最大公约数，求子串
//题解值得学习的点：
//	寻找ans的过程可以用substr函数，然后用 == 判断两个的子串是否相等，无需我这样子一个个判断，时间复杂度一样
//	求最大公约数的方法就是辗转相除法，我只会方法，没有对上这个名字，而且有专门的标准库函数：__gcd(len1,len2)，递归的写法
//	如果 str1 和 str2 拼接后等于 str2和 str1 拼接起来的字符串（注意拼接顺序不同），那么一定存在符合条件的字符串 X。证明没看
//但是题解一些方法，个人认为浪费时间：string的 + 会重新创建新的字符串，很多都用了+拼接字符串 和原来的判断

//官方简洁版：空间On
//string gcdOfStrings01(string str1, string str2) 
//{
//	if (str1 + str2 != str2 + str1) return "";								//检验是否有公因子
//	//return str1.substr(0, __gcd((int)str1.length(), (int)str2.length())); // __gcd() 为c++自带的求最大公约数的函数，
//	//我的vs不通过 __gcd呀，
//}


// https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/solution/1xing-c-z-by-zrita/
int gcd(int a, int b)
{
	if (a < b)       swap(a, b);
	return b == 0 ? a : gcd(b, a % b);
}
int main(void)
{
	return 0;
}