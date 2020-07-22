//�жϸ������ַ������ַ�ģʽ�Ƿ����������ʽģʽ
//.ƥ������ĵ����ַ���*ƥ��ǰ��0���������������ַ�
//https://mp.weixin.qq.com/s/TAiIIxoDXx67MNGXea6gfQ 2019-05-30
//���������еݹ顢��̬�滮��˼·���У��鱾���е�״̬�����Ժúÿ���
//����ͨ��ţ��������

#include <cstdio>
#include<iostream>
#include<vector>
using namespace std;

// ע�� \0 ��д��
bool IsMatch_recursively(const char* text, const char* pattern)
{
	if (pattern == nullptr) 
		return(text == nullptr);
	if (*pattern == '\0')
		return(*text == '\0');

	//*******************************************************
	//Ŀǰ�ѵ㣬����'\0'�����ַ��޷�����
	//for (int i = 0; pattern[i-1] != '\0'; i++)
	//{
	//		//.�����
	//	bool before = (text[i] == pattern[i] || pattern[i] == '.' );
	//	//*�����
	//	if (pattern[i] != '\0' && pattern[i + 1] == '*')
	//	{
	//		if (text[i] == '\0' || text[i + 1] == '\0') return true;
	//		//ƥ��0�Σ�ƥ��һ�λ�����
	//		return IsMatch_recursively(text + 2, pattern) ||
	//			( before && IsMatch_recursively(text + 1, pattern));
	//	}
	//	else //���Ȳ�һ��
	//		if (text[i] == '\0') return false;
	//}*******************************************************


	//���˴𰸣���Ȼ�ݹ麯���ܹ�����ַ��жϣ�������ʹ��forѭ����������ͬ
	//֮ǰ�����������ƥ��0 �ε�����£�Ӧ����patterǰ������
	bool before = (*text == *pattern || (*pattern == '.' && *text != '\0') );//.��ƥ�䵥���ַ�
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
/*****************************����ת��Ϊ����¼����ʽ���ʱ��Ч��***********************************/
//������ö�����vector
// i ��ʾstr��������j ��ʾpattern������ 
int ConsultDict(const char* str, const char* pattern, vector< vector<int> > & Dict, int i, int j)
{
	int patternLen = strlen(pattern) + 1;//һ���������'\0'�����ַ���һ���᷵��
	while (j <= patternLen)
	{
		if (pattern[j] == '\0')
			return(str[i] == '\0');
		if (Dict[j][i] != 2)
			return Dict[j][i];

		//Dict[j][i] = (str[i] == pattern[j]) || (str[i] != '\0' && pattern[j] == '.');
		//���ٴ��볤�ȣ�ò�Ʋ��
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

	//һ��ʹ�л��������'\0'�����ַ������Գ��ȼ�һ
	int strLen = strlen(str) + 1;
	int patternLen = strlen(pattern) + 1;

	//��γ�ʼ��������vector
	//trueΪ1��falseΪ0�����Գ�ʼ��Ϊ2��Ϊδ�жϵ�״̬�����⴦���ظ�������
	vector< vector<int> > Dict(patternLen, vector<int>(strLen, 2) );

	int ans = ConsultDict(str, pattern, Dict, 0, 0);
	if (ans == 1) 
		return true;
	else 
		return false;
}



// ====================20200620�ڶ���ˢ�Ⳣ��====================

//�ݹ�ķ�������ʱ����ȷ����ȷ��
bool isMatch0620_recursive(string s, string p, int i, int j)
{
	if (j == p.size()) return i == s.size();
	bool before = ( s[i] == p[j] || i < s.size() && p[j] == '.' );

	if (j < p.size() && p[j + 1] == '*')
	{
		if (i < s.size())
			//ƥ��0�� ƥ���Σ�ƥ��0�ε�ʱ�����迼��before�Ƿ���ȣ�
			return isMatch0620_recursive(s, p, i, j + 2) || before && isMatch0620_recursive(s, p, i + 1, j);
		else
			return isMatch0620_recursive(s, p, i, j + 2) || before;
	}
	else
		return before && isMatch0620_recursive(s, p, i + 1, j + 1);
}
//�ݹ�ķ������Ӻ���ǰ�洢��������AC
//�ο���⣺https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-dong-tai-gui-hua-by-jy/
bool isMatch0620_dict(string s, string p, int i, int j, vector<vector<int>> & dp)
{
	if (j >= p.size()) return i >= s.size();
	if (dp[i][j] != 2) return dp[i][j];

	bool before = (s[i] == p[j] || i < s.size() && p[j] == '.');
	dp[i][j] = 0;
	if (j < p.size() && p[j + 1] == '*')
	{
		if (i < s.size())
			//ƥ��0�Σ�ƥ���Σ�ƥ��0�����迼���Ƿ�defore��ƥ����ʱ��Ҫ����before��ֵ
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
	//��ʼ��Ԫ�ص�����Ϊ2
	vector<vector<int>> dp(sLen + 1, vector<int>(pLen + 1, 2));   
	int i = 0, j = 0;
	//return isMatch0620_recursive(s, p, i, j);	
	return isMatch0620_dict(s, p, i, j, dp);	
}

//����⣬��̬�滮�ķ���
bool isMatch0620_01(string s, string p)
{
	int sLen = s.length();
	int pLen = p.length();
	vector<vector<int>> dp(sLen + 1, vector<int>(pLen + 1, 0));

	dp[0][0] = 1;
	for (int j = 2; j <= pLen; j++)
		dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
	//��0���Ѿ���ʼ����iΪ1ʱ��Ϊ��0���ַ�
	for (int i = 1; i <= sLen; i++)
		for (int j = 1; j <= pLen; j++)
		{
			if (p[j - 1] == '*')
				//��j-1���ַ���*������Ϊdp[i-1]
				dp[i][j] = dp[i][j - 2] || dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
			else if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
				dp[i][j] = dp[i - 1][j - 1];
		}
	return dp[sLen][pLen];
}
// ====================���Դ���====================
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