/*数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
https://leetcode-cn.com/problems/generate-parentheses
输入：n = 3
输出：[
	   "((()))",
	   "(()())",
	   "(())()",
	   "()(())",
	   "()()()"
	 ]	 */

#include<vector>
#include<memory>
#include<deque>
#include<iostream>
#include<string>
using namespace std;
//自己写的，开始时候使用了函数内的全局变量统计左右括号的值，
//仔细思考，对于不同的字符串，左右括号的数值不一样，因此，应该针对每一个字符串有一个统计
vector<string> generateParenthesis(int n)
{
	deque<string> dict;
	vector<string> ans;
	if (n <= 0) return ans;
	dict.push_back("(");
	// int left=1, right=0;//对于不同情况，left right的数值不一样，因此不应该是全局变量统计
	while (dict.front().size() < (n << 1))
	{
		string front = dict.front();
		int left = 0, right = 0;
		//这个地方每次都要遍历，有点麻烦，或者空间换时间，题解定义了一个结构体，left right 属于其属性
		//使用双端队列比较简单，使用栈 或者 单端队列的话，需要考虑复杂一点 
		//突然发现我需要的就是单端队列呀，首端出，尾端进，
		for (auto i : front)
		{
			if (i == '(') left++;
			else right++;
		}
		dict.pop_front();

		if (right < left)
		{
			dict.push_back(front + ')');
			//right++;
		}
		if (left < n)
		{
			dict.push_back(front + '(');
			//left++;
		}
	}
	while (dict.size())
	{
		ans.push_back(dict.front());
		dict.pop_front();
	}
	return ans;
}
//看了题解，属于回溯法的思路，一般使用深度遍历比较好
//尝试dfs方法

//不知道const的使用：不加const的话，参数s+'('处编译不通过；加了const时，s+='('编译不通过
void backTrack(int n, vector<string>& ans, const string& s, int left, int right)
{
	if (s.size() == (n << 1))
	{
		ans.push_back(s);
		return;
	}
	if (right < left)
		backTrack(n, ans, s + ")", left, right + 1);  //因为此处属于临时变量，不是左值，属于不能将临时变量初始化给引用变量，只能赋值为const引用	
	if (left < n)
		backTrack(n, ans, s + '(', left + 1, right);
}
vector<string> generateParenthesis01(int n)
{
	vector<string> ans;
	backTrack(n, ans, "", 0, 0);
	return ans;
}

//递归的算法很神奇：任何一个括号序列都一定是由 ( 开头，并且第一个 ( 一定有一个唯一与之对应的 )。
//这样一来，每一个括号序列可以用 (a)b 来表示，其中 a 与 b 分别是一个合法的括号序列（可以为空）。
//官网用的智能指针，
shared_ptr<vector<string>> cache[100] = { nullptr };
shared_ptr<vector<string>> generate(int n)
{
	if (cache[n] != nullptr) return cache[n];
	if (n == 0) cache[0] = shared_ptr<vector<string>>(new vector<string>{ "" });
	else
	{
		auto result = shared_ptr<vector<string>>(new vector<string>);
		for (int i = 0; i < n; i++)
		{
			auto lefts = generate(i);
			auto rights = generate(n - i - 1);
			for (const string & left : *lefts)		//lefts 与 rights 中的元素【即为n或者n-i-1长度的有效括号】两两组合
				for (const string & right : *rights)
					result->push_back("(" + left + ")" + right);
		}
		cache[n] = result;
	}
	return cache[n];
}
vector<string> generateParenthesis02(int n)
{
	return *generate(n);
}

vector<string> generateParenthesis03(int n)
{
	vector<vector<string>> v(n + 1);
	v[0].push_back("");
	for (int i = 1; i <= n; i++) //从0到n 自下而上存储有效括号
	{
		for (int j = 0; j < i; j++) //决定了左侧字符串括号的个数，i-j-1即为另一侧括号的个数
		{
			for (string &str1 : v[j])
			{
				for (string &str2 : v[i - j - 1])
					v[i].push_back("(" + str2 + ")" + str1);
			}
		}
	}
	return v[n];
}
int main(void)
{
	vector<string> ans = generateParenthesis03(3);
	return 0;
}


