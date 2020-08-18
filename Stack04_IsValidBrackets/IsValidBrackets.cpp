//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
//��Ч�ַ��������㣺�����ű�������ͬ���͵������űպϡ������ű�������ȷ��˳��պϡ�ע����ַ����ɱ���Ϊ����Ч�ַ�����
// https://leetcode-cn.com/problems/valid-parentheses

//��Ϊջ�ļ��⣬�����˼���ջ����ϰ����
#include<string>
#include<stack>
#include<iostream>
#include<unordered_map>
using std::unordered_map;
using std::string;
using std::stack;

//����ȷ��һ�����飬string�е�һ���ַ� ���Ը�ֵΪchar�������Ѳ��� ����
bool Isvalid(string s)
{
	int sLength = s.size();
	if (sLength == 0) return true;
	unordered_map<char, char> dictMap;
	stack<char> signStack;
	dictMap['('] = ')';
	dictMap['{'] = '}';
	dictMap['['] = ']';
	int i = 0;
	for (i = 0; i < sLength; i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			signStack.push(s[i]);
		else if (signStack.size() && dictMap[signStack.top()] == s[i])
			signStack.pop();
		else break;
	}
	return (signStack.empty() && i == sLength);
}

//������⣬���鳤��Ϊ���� ֱ���ų�����һ�㲻�ף����������ַ���
//https://leetcode-cn.com/problems/valid-parentheses/solution/javazui-jian-ji-de-mo-ni-zhan-1-ms-by-dreshadow/
//������ģ��ջ��˼·���������Ŀ��ȡ�ɽⷨ��ֱ���á����滻�ɶԵ����ţ�������ڲ�û����Ϊfalse ����ʵ���Բ���
//https://leetcode-cn.com/problems/valid-parentheses/solution/javascript-you-xiao-de-gua-hao-by-rhinoc/
//https://leetcode-cn.com/problems/valid-parentheses/solution/cyu-yan-jian-jian-dan-dan-de-ji-xing-dai-ma-jie-14/
int main(void)
{
	string s = "moring";
	s = "()";
	Isvalid(s);
	s = "()[]{}";
	Isvalid(s);
	s = "(]";
	Isvalid(s);
	s = "{[]}";
	Isvalid(s);
	return 0;
}