/*��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
���磬�ַ���"+100"��"5e2"��"-123"��"3.1416"��"0123"��"-1E-16"����ʾ��ֵ��
��"12e"��"1a3.14"��"1.2.3"��"+-5"��"12e+5.4"�����ǡ�
 https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof */


//������̫ϲ����������
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
