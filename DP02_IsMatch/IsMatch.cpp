//�жϸ������ַ������ַ�ģʽ�Ƿ����������ʽģʽ
//.ƥ������ĵ����ַ���*ƥ��ǰ��0���������������ַ�
//https://mp.weixin.qq.com/s/TAiIIxoDXx67MNGXea6gfQ 2019-05-30
//���������еݹ顢��̬�滮��˼·���У��鱾���е�״̬�����Ժúÿ���
//����ͨ��ţ��������

#include <cstdio>
#include<iostream>
#include<vector>

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
	Test("Test01", "", "", true);
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
	Test("Test30", "bcbbabab", ".*a*a", false);

	return 0;
}