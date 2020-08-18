//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//有效字符串需满足：左括号必须用相同类型的右括号闭合。左括号必须以正确的顺序闭合。注意空字符串可被认为是有效字符串。
// https://leetcode-cn.com/problems/valid-parentheses

//此为栈的简单题，在做了几道栈的练习后尝试
#include<string>
#include<stack>
#include<iostream>
#include<unordered_map>
using std::unordered_map;
using std::string;
using std::stack;

//首先确定一件事情，string中的一个字符 可以赋值为char类型吗？已测试 可以
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

//看了题解，数组长度为奇数 直接排除，这一点不妥，若有其他字符；
//https://leetcode-cn.com/problems/valid-parentheses/solution/javazui-jian-ji-de-mo-ni-zhan-1-ms-by-dreshadow/
//有数组模拟栈的思路，有针对题目的取巧解法，直接用‘’替换成对的括号，如果最内部没有则为false 但是实用性不高
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