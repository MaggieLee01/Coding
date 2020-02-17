//��������Ӵ������Ĵ��������Ŷ��ͷ��Ŷ���һ�����ַ���
//�Ӵ�һ���������ģ��������в�һ����������
//2019-10-03
//https://mp.weixin.qq.com/s/ux6VSWAPwgOS32xlScr2kQ
//������������˼·����ͨ��LeetCode����

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

//dict[i]��ʾ��i�����Ļ����Ӵ��ĳ���
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

//����ʧ�ܣ���һ�α�����ͨ��nά�����¼�����Ӵ��ĳ��ȣ��κΣ������Ӵ���Ҫ����ȫ��֮����ܵó����
//���������Ҫ�������㷨
//����Ĵ��룬�����ܵó��Գ��᲻�任�Ļ����Ӵ��ĳ��ȣ����ڶԳ��᲻�ϱ任���Ӵ�������Ϊ��
//����𰸣���Ȼ��Ҫ���α�����ʱ�临�Ӷ�Ϊn*n

//��ʼʹ��std::string��׼�⺯��
using std::vector;
using std::string;

//������m nΪ���ĵĻ����ַ���
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

//����𰸣��򻯴���
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
//	auto max = max_element(dict.begin(), dict.end()) - dict.begin();//ͷ�ļ�#include<algorithm>
//	string str1 = Palindrome(str, max, max);
//	string str2 = Palindrome(str, max, max+1);
//	return str1.size() > str2.size() ? str1 : str2;
//}

//����𰸣��򻯴���
//���������洢�����ַ��������Ӵ��ĳ��ȣ�ֻ��һ���ռ䲻�ϸ������ֵ����
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
	std::cout << LongestPalindrome(str) << std::endl;//��ͷ�ļ�<string>���ܴ�ӡ
	const char* str1 = "aaaaaaaa";
	std::cout << LongestPalindrome(str1) << std::endl;
	const char* str2 = "abcbccbcba";
	std::cout << LongestPalindrome(str2) << std::endl;
	const char* str3 = "baaaaaaaa";
	std::cout << LongestPalindrome(str3) << std::endl;
	const char* str4 = "aadeccbccedddddddddd";
	std::cout << LongestPalindrome(str4) << std::endl;	
}
