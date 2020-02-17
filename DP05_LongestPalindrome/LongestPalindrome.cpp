//求最长回文子串。回文串就是正着读和反着读都一样的字符串
//子串一定是连续的，而子序列不一定是连续的
//2019-10-03
//https://mp.weixin.qq.com/s/ux6VSWAPwgOS32xlScr2kQ
//基本按照文章思路，已通过LeetCode测试

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

//dict[i]表示以i结束的回文子串的长度
//char* LongestPalindrome(const char* str)
//{
//	if (str == nullptr)
//		return nullptr;
//	int strLength = strlen(str);
//	std::vector<int> dict(strLength + 1, 1);
//	if (str[0] == str[1]) dict[1] = 2;
//	for (int i = 2; i < strLength; i++)
//	{
//		if (str[i] == str[i - 1])
//			dict[i] = 2;
//		/*if (str[i] == str[i - 1])
//			dict[i] = dict[i - 1] + 1;*/
//		if (str[i] == str[i - 2])
//			dict[i] = dict[i - 2] + 2;		
//		if (dict[i - 1] != 1)
//		{
//			if (str[i] == str[i - 1 - dict[i - 1] ] )
//				dict[i] = dict[i - 1] + 2;
//		}
//	}
//	return nullptr;
//}

//尝试失败，想一次遍历，通过n维数组记录回文子串的长度，奈何，回文子串需要遍历全部之后才能得出结果
//这种情况需要马拉车算法
//上面的代码，仅仅能得出对称轴不变换的回文子串的长度，对于对称轴不断变换的子串，无能为力
//看完答案，仍然需要两次遍历，时间复杂度为n*n

//开始使用std::string标准库函数
using std::vector;
using std::string;

//返回以m n为中心的回文字符串
//string Palindrome(string str,int m,int n)
//{
//	int Length = str.size();
//	int i = m, j = n;
//	while (i >= 0 && j <= Length && str[i] == str[j])
//	{
//		i--; 
//		j++;
//	}
//	string substr = str.substr(i + 1, j - 1 - i);
//	return substr;
//}

//看完答案，简化代码
string Palindrome(string str, int i, int j)
{
	int Length = str.size();
	while (i >= 0 && j <= Length && str[i] == str[j])
	{
		i--; 
		j++;
	}
	return str.substr(i + 1, j - 1 - i);
}
//string LongestPalindrome(string str)
//{
//	int Length = str.size();
//	vector<int> dict(Length, 0);
//	
//	for (int i = 0; i < Length; i++)
//	{
//		string str1 = Palindrome(str, i, i);
//		string str2 = Palindrome(str, i, i + 1);
//		dict[i] = str2.size() > str1.size() ? str2.size() : str1.size();		
//	}
//	auto max = max_element(dict.begin(), dict.end()) - dict.begin();//头文件#include<algorithm>
//	string str1 = Palindrome(str, max, max);
//	string str2 = Palindrome(str, max, max+1);
//	return str1.size() > str2.size() ? str1 : str2;
//}

//看完答案，简化代码
//无需向量存储各个字符串回文子串的长度，只需一个空间不断更新最大值即可
string LongestPalindrome(string str)
{
	int Length = str.size();
	string max;

	for (int i = 0; i < Length; i++)
	{
		string str1 = Palindrome(str, i, i);
		string str2 = Palindrome(str, i, i + 1);
		max = max.size() > str1.size() ? max : str1;
		max = max.size() > str2.size() ? max : str2;
	}
	return max;
}

int main(void)
{
	const char* str = "abcdcbeabccba";
	std::cout << LongestPalindrome(str) << std::endl;//加头文件<string>才能打印
	const char* str1 = "aaaaaaaa";
	std::cout << LongestPalindrome(str1) << std::endl;
	const char* str2 = "abcbccbcba";
	std::cout << LongestPalindrome(str2) << std::endl;
	const char* str3 = "baaaaaaaa";
	std::cout << LongestPalindrome(str3) << std::endl;
	const char* str4 = "aadeccbccedddddddddd";
	std::cout << LongestPalindrome(str4) << std::endl;	
}
