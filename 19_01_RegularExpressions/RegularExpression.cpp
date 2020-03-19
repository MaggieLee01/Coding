/*请实现一个函数用来匹配包含'. '和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。

链接：https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof */

//之前在DP算法里面写过，现在根据理解自己写
#include<string>
#include<vector>
using std::vector;
using std::string;
//递归方法，s为字符串，p为模式
bool isMatch_ReCore(string s, string p,int m,int n) 
{
	//递归结束整不明白了，看了答案，写的和答案是一样的
	/*if (n >= p.size() && m >= s.size()) return true;
	if (n >= p.size()) return false;*/
	if (n >= p.size())
		return(m >= s.size());
	
	bool before = false;
	if (m < s.size() && (s[m] == p[n] || p[n] == '.'))
		before = true;//对于.的处理
	if (p[n + 1] == '*') //是不是需要确保p[n+1]存在
		return (before && isMatch_ReCore(s, p, m + 1, n)) || isMatch_ReCore(s, p, m, n + 2);
	else
		return before && (isMatch_ReCore(s, p, m + 1, n + 1));
}

//备忘录
int isMatch_DictCore(string s, string p, int m, int n, vector<vector<int> >& Dict)//Dict的引用相当主要呀，忘记了打引用，程序卡机
{
	if (n >= p.size() && m >= s.size())
		return 1;
	if (n >= p.size() && m < s.size())
		return 0;
	if (Dict[m][n] != -1) 
		return Dict[m][n];

	bool before = false;
	if (m < s.size() && (s[m] == p[n] || p[n] == '.'))//先保证m有效再判断
		before = true;//对于.的处理
	if (p[n + 1] == '*')//是不是需要确保p[n+1]存在
		Dict[m][n] = (before && isMatch_DictCore(s, p, m + 1, n,Dict)) || isMatch_DictCore(s, p, m, n + 2, Dict);
	else
		Dict[m][n] = before && (isMatch_DictCore(s, p, m + 1, n + 1, Dict));
	return Dict[m][n];
}
bool isMatch_Dict(string s, string p, int m, int n)
{
	int sLength = s.size();
	int pLength = p.size();
	vector<vector<int> > Dict(sLength + 1, vector<int>(pLength + 1, -1));
	
	int ans = isMatch_DictCore(s, p, 0, 0, Dict);
	return (ans == 1);
}


int main(void)
{
	string s = "aaa";
	string p = "ab*ac*a";
	bool n = isMatch_ReCore(s, p, 0, 0);
	n = isMatch_ReCore(s, p, 0, 0);

	s = "";
	p = ".*";
	n = isMatch_ReCore(s, p, 0, 0);
	n = isMatch_Dict(s, p, 0, 0);

	s = "ab";
	p = ".*c";
	n = isMatch_ReCore(s, p, 0, 0);
	n = isMatch_Dict(s, p, 0, 0);

	s = "mississippi";
	p = "mis*is*p*.";
	n = isMatch_ReCore(s, p, 0, 0);
	n = isMatch_Dict(s, p, 0, 0);

	s = "aab";
	p = "c*a*b";
	n = isMatch_ReCore(s, p, 0, 0);
	n = isMatch_Dict(s, p, 0, 0);

	s = "ab";
	p = ".*";
	n = isMatch_ReCore(s, p, 0, 0);
	n = isMatch_Dict(s, p, 0, 0);	
		
	s = "aaaaaaaaaaaaab";
	p = "a*a*a*a*a*a*a*a*a*a*c";
	n = isMatch_ReCore(s, p, 0, 0);
	n = isMatch_Dict(s, p, 0, 0);

	return 0;
}