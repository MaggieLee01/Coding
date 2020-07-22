/* 字符串转换整数 (atoi)

请你来实现一个 atoi 函数，使其能将字符串转换成整数。
首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：
如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。
在任何情况下，若函数不能进行有效的转换时，请返回 0 。
提示：
本题中的空白字符只包括空格字符 ' ' 。
假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

输入: "42"；输出: 42
输入: "   -42"；输出: -42；解释: 第一个非空白字符为 '-', 它是一个负号。	 我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
输入: "4193 with words"；输出: 4193；解释：转换截止于数字 '3' ，因为它的下一个字符不为数字。
输入: "words and 987"；输出: 0；解释: 第一个非空字符是 'w', 但它不是数字或正、负号。	 因此无法执行有效的转换。
输入: "-91283472332"；输出: -2147483648；解释: 数字 "-91283472332" 超过 32 位有符号整数范围。因此返回 INT_MIN (−231) 。
*/
#include<cmath>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<climits>
#include<regex>
#include<string>
#include<sstream>
using namespace std;
//我写的比较臃肿的代码，看了题解，我的完善之处，判断溢出的时候计算公式可以调整
int myAtoi(string str)
{
	long int ans = 0;//写完发现不符题意，环境只能存储32位
	int flag = 0, cnt = 0;
	int Len = str.length();
	int i = 0;

	while (i < Len && str[i] == ' ') i++;//string 也有专门的查找函数find_first_not_of
	if (i < Len && (str[i] == '-' || str[i] == '+'))
	{
		flag = i;
		i++;
	}
	while (i < Len && str[i] == '0') i++; //对于000开头的    
	for (; i < Len; i++)
	{
		if (cnt <= 10 && '0' <= str[i] && str[i] <= '9')//有现成的isdigit()函数。若参数c为阿拉伯数字0~9，则返回非0值，否则返回0。
		{
			ans = ans * 10 + str[i] - '0';
			cnt++;//对于2000000000000这种溢出的
		}
		else break;
	}
	if (str[flag] == '-')
	{
		if (ans > INT_MAX) ans = INT_MIN;//很神奇 直接写的最大数字VS编译没通过
		else ans = ans * (-1);
	}
	else if (ans >= INT_MAX) ans = INT_MAX;
	return ans;
}


//看着题解 修正我的代码
int myAtoi01(string str)
{
	int flag = 1, i = 0;
	int Len = str.length();

	i = str.find_first_not_of(" ");//找到第一个不是空格的
	if (i == Len) return 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')//必须else 防止+-情况
	{
		flag = -1;
		i++;
	}
	int ans = 0;//环境只能存储32位
	for (; i < Len; i++)
	{
		if (!isdigit(str[i])) break;
		if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
			return INT_MAX;

		else if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && (str[i] - '0') > -(INT_MIN % 10)))
			return INT_MIN;
		else ans = ans * 10 + flag *(str[i] - '0'); // -18 = -10 - 8
		
		/*这样子的话，返回值考虑乘以-1
		{
            int digit = str[i] - '0';
            if (ans > (INT_MAX - digit) / 10) //本来担心为INT_MIN，转念一想，这不正好返回INT_MIN吗？
			{
                // 本来应该是 ans * 10 + digit > INT_MAX
                // 但是 *10 和 + digit 都有可能越界，所有都移动到右边去就可以了。
                return negative? INT_MIN : INT_MAX;
            }
			ans = ans * 10 + digit;
		*/
	}
	return ans;
}
//尝试状态机，看着官方题解，处理溢出的地方仍不太好
class Automaton
{
	string state = "start";
	unordered_map<string, vector<string> > table=
	{
		{"start", {"start", "signed", "in_number", "end"}},
		{"signed", {"end", "end", "in_number", "end"}},
		{"in_number", {"end", "end", "in_number", "end"}},
		{"end", {"end", "end", "end", "end"}}
	};
	int get_col(char c)
	{
		if (isspace(c)) return 0;
		if (c == '+' || c == '-') return 1;
		if (isdigit(c)) return 2;
		return 3;
	}
public:
	int sign = 1;
	long int ans = 0;
	void get(char c)
	{
		state = table[state][get_col(c)];
		if (state == "in_number")
		{
			ans = ans * 10 + c - '0';
			ans = sign == 1 ? min(ans, (long)INT_MAX) : min(ans, -(long)INT_MIN);
		}
		else if (state == "signed")
			sign = c == '+' ? 1 : -1;
	}

};
int myAtoi02(string str)
{
	Automaton automaton;
	for (char c : str)
		automaton.get(c);//完全可以再优化，遇到end即break
	return automaton.sign * automaton.ans;
}

//很多用正则表达式的
void trimStart(string &s)
{
	if (!s.empty())
		s.erase(0, s.find_first_not_of(" "));	
}
int myAtoi04(string str)
{
	int result;
	string resultStr;
	smatch tmpMatch;
	trimStart(str);//必须去掉空格，后面才能转为数字
	//c++中要用\\进行转义
	regex tmpRegex("^[\\+\\-\\d]\\d*");
	regex_search(str, tmpMatch, tmpRegex);

	stringstream ss;
	if (int(tmpMatch.size()) == 0)
	{
		return 0;
	}
	string tmpStr = tmpMatch[0];
	//转换成int
	ss << tmpStr;
	cout << tmpStr << endl;
	//后面直接ss>>result 即可
	long longResult;
	ss >> longResult;
	result = max(min(longResult, long(INT_MAX)), long(INT_MIN));
	return result;
}

//如果字符串里面有字母的话，这个字母就不会输入到int型变量num中
//因为istringstream就是在格式化分解字符串，分解的依据是输出对象的类型，这里就是int啦
int myAtoi03(string str)
{
	istringstream s_str(str);
	int n = 0;
	s_str >> n;//当str的数值溢出的时候，n自动根据正负为INT_MAX或者INT_MIN了，所以不需要后面的判断也可用 
	if (n > INT_MAX)
		return INT_MAX;
	else if (n < INT_MIN)
		return INT_MIN;
	else
		return n;
}
int main(void)
{
	string s = "-2147483648";
	int ans = myAtoi04(s);
	return 0;
}
