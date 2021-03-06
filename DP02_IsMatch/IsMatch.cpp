//判断给定的字符串与字符模式是否符合正则表达式模式
//.匹配任意的单个字符，*匹配前面0个或者无数个单字符
//https://mp.weixin.qq.com/s/TAiIIxoDXx67MNGXea6gfQ 2019-05-30
//根据链接中递归、动态规划的思路进行，书本答案中的状态机可以好好看看
//均已通过牛客网测试

#include <cstdio>
#include<iostream>
#include<vector>
using namespace std;

// 注意 \0 的写法
bool IsMatch_recursively(const char* text, const char* pattern)
{
	if (pattern == nullptr) 
		return(text == nullptr);
	if (*pattern == '\0')
		return(*text == '\0');

	//*******************************************************
	//目前难点，对于'\0'处的字符无法处理
	//for (int i = 0; pattern[i-1] != '\0'; i++)
	//{
	//		//.的情况
	//	bool before = (text[i] == pattern[i] || pattern[i] == '.' );
	//	//*的情况
	//	if (pattern[i] != '\0' && pattern[i + 1] == '*')
	//	{
	//		if (text[i] == '\0' || text[i + 1] == '\0') return true;
	//		//匹配0次，匹配一次或以上
	//		return IsMatch_recursively(text + 2, pattern) ||
	//			( before && IsMatch_recursively(text + 1, pattern));
	//	}
	//	else //长度不一致
	//		if (text[i] == '\0') return false;
	//}*******************************************************


	//看了答案，既然递归函数能够逐个字符判断，则无需使用for循环进入死胡同
	//之前的误区，如果匹配0 次的情况下，应该是patter前进两步
	bool before = (*text == *pattern || (*pattern == '.' && *text != '\0') );//.仅匹配单个字符
	if (*(pattern + 1) == '*')
	{
		if ( *text != '\0')
			return IsMatch_recursively(text, pattern + 2) || (before && IsMatch_recursively(text + 1, pattern));
		else if (*text == '\0')
			return IsMatch_recursively(text, pattern + 2) || before;
	}
	else
		return before && IsMatch_recursively(text + 1, pattern + 1);
}


using namespace std;
/*****************************尝试转换为备忘录的形式提高时间效率***********************************/
//如何引用二级的vector
// i 表示str的索引，j 表示pattern的索引 
int ConsultDict(const char* str, const char* pattern, vector< vector<int> > & Dict, int i, int j)
{
	int patternLen = strlen(pattern) + 1;//一定会遍历到'\0'处的字符，一定会返回
	while (j <= patternLen)
	{
		if (pattern[j] == '\0')
			return(str[i] == '\0');
		if (Dict[j][i] != 2)
			return Dict[j][i];

		//Dict[j][i] = (str[i] == pattern[j]) || (str[i] != '\0' && pattern[j] == '.');
		//减少代码长度，貌似差不多
		bool before = (str[i] == pattern[j]) || (str[i] != '\0' && pattern[j] == '.');
		if (pattern[j + 1] == '*')
		{
			if (str[i] != '\0')
				Dict[j][i] = (before && ConsultDict(str, pattern, Dict, i + 1, j) == 1) ||
				ConsultDict(str, pattern, Dict, i, j + 2) == 1;
			else
				//Dict[j][i] = Dict[j][i] == 1 || ConsultDict(str, pattern, Dict, i, j + 2) == 1;
				Dict[j][i] = before || ConsultDict(str, pattern, Dict, i, j + 2) == 1;
		}
		else
			//Dict[j][i] = Dict[j][i] == 1 && ConsultDict(str, pattern, Dict, i + 1, j + 1) == 1;
			Dict[j][i] = before && ConsultDict(str, pattern, Dict, i + 1, j + 1) == 1;
	}
	
}
bool isMatch_Dict(const char* str, const char* pattern)
{
	if (pattern == nullptr)
		return(str == nullptr);	

	//一定使有机会遍历到'\0'处的字符，所以长度加一
	int strLen = strlen(str) + 1;
	int patternLen = strlen(pattern) + 1;

	//如何初始化二级的vector
	//true为1，false为0，所以初始化为2，为未判断的状态，避免处理重复子问题
	vector< vector<int> > Dict(patternLen, vector<int>(strLen, 2) );

	int ans = ConsultDict(str, pattern, Dict, 0, 0);
	if (ans == 1) 
		return true;
	else 
		return false;
}



// ====================20200620第二次刷题尝试====================

//递归的方法，超时，不确定正确性
bool isMatch0620_recursive(string s, string p, int i, int j)
{
	if (j == p.size()) return i == s.size();
	bool before = ( s[i] == p[j] || i < s.size() && p[j] == '.' );

	if (j < p.size() && p[j + 1] == '*')
	{
		if (i < s.size())
			//匹配0次 匹配多次；匹配0次的时候无需考虑before是否相等，
			return isMatch0620_recursive(s, p, i, j + 2) || before && isMatch0620_recursive(s, p, i + 1, j);
		else
			return isMatch0620_recursive(s, p, i, j + 2) || before;
	}
	else
		return before && isMatch0620_recursive(s, p, i + 1, j + 1);
}
//递归的方法，从后往前存储结果，这个AC
//参考题解：https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-dong-tai-gui-hua-by-jy/
bool isMatch0620_dict(string s, string p, int i, int j, vector<vector<int>> & dp)
{
	if (j >= p.size()) return i >= s.size();
	if (dp[i][j] != 2) return dp[i][j];

	bool before = (s[i] == p[j] || i < s.size() && p[j] == '.');
	dp[i][j] = 0;
	if (j < p.size() && p[j + 1] == '*')
	{
		if (i < s.size())
			//匹配0次，匹配多次；匹配0次无需考虑是否defore，匹配多次时需要基于before的值
			dp[i][j] = isMatch0620_dict(s, p, i, j + 2, dp) || before && isMatch0620_dict(s, p, i + 1, j, dp);
		else
			dp[i][j] = isMatch0620_dict(s, p, i, j + 2, dp) || before;
	}
	else
		dp[i][j] = before && isMatch0620_dict(s, p, i + 1, j + 1, dp);
	return dp[i][j];
}
bool isMatch0620(string s, string p)
{
	int sLen = s.length();
	int pLen = p.length();
	//初始化元素的内容为2
	vector<vector<int>> dp(sLen + 1, vector<int>(pLen + 1, 2));   
	int i = 0, j = 0;
	//return isMatch0620_recursive(s, p, i, j);	
	return isMatch0620_dict(s, p, i, j, dp);	
}

//看题解，动态规划的方法
bool isMatch0620_01(string s, string p)
{
	int sLen = s.length();
	int pLen = p.length();
	vector<vector<int>> dp(sLen + 1, vector<int>(pLen + 1, 0));

	dp[0][0] = 1;
	for (int j = 2; j <= pLen; j++)
		dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
	//第0行已经初始化，i为1时即为第0个字符
	for (int i = 1; i <= sLen; i++)
		for (int j = 1; j <= pLen; j++)
		{
			if (p[j - 1] == '*')
				//第j-1个字符是*，所以为dp[i-1]
				dp[i][j] = dp[i][j - 2] || dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
			else if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
				dp[i][j] = dp[i - 1][j - 1];
		}
	return dp[sLen][pLen];
}
// ====================测试代码====================
void Test(const char* testName, const char* string, const char* pattern, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (isMatch_Dict(string, pattern) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
	isMatch0620_01("aa", "a*");
	/*Test("Test01", "", "", true);
	Test("Test02", "", ".*", true);
	Test("Test03", "", ".", false);
	Test("Test04", "", "c*", true);
	Test("Test05", "a", ".*", true);
	Test("Test06", "a", "a.", false);
	Test("Test07", "a", "", false);
	Test("Test08", "a", ".", true);
	Test("Test09", "a", "ab*", true);
	Test("Test10", "a", "ab*a", false);
	Test("Test11", "aa", "aa", true);
	Test("Test12", "aa", "a*", true);
	Test("Test13", "aa", ".*", true);
	Test("Test14", "aa", ".", false);
	Test("Test15", "ab", ".*", true);
	Test("Test16", "ab", ".*", true);
	Test("Test17", "aaa", "aa*", true);
	Test("Test18", "aaa", "aa.a", false);
	Test("Test19", "aaa", "a.a", true);
	Test("Test20", "aaa", ".a", false);
	Test("Test21", "aaa", "a*a", true);
	Test("Test22", "aaa", "ab*a", false);
	Test("Test23", "aaa", "ab*ac*a", true);
	Test("Test24", "aaa", "ab*a*c*a", true);
	Test("Test25", "aaa", ".*", true);
	Test("Test26", "aab", "c*a*b", true);
	Test("Test27", "aaca", "ab*a*c*a", true);
	Test("Test28", "aaba", "ab*a*c*a", false);
	Test("Test29", "bbbba", ".*a*a", true);
	Test("Test30", "bcbbabab", ".*a*a", false);*/

	return 0;
}