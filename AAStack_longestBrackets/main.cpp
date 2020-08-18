/*给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

https://leetcode-cn.com/problems/longest-valid-parentheses */

#include<string>
#include<vector>
#include<stack>
using namespace std;

int longestValidParentheses(string s) 
{

	stack<char> stk;
	for (int i = 0; i < s.size(); i++)
	{
		stk.push(s[i]);
		int ans = 0;
		if (s[i] == ')')
		{
			if (stk.size() && stk.top() == '(')
				ans++;
		}

	}

}