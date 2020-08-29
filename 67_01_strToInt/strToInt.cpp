/*写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。*/
//https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/
//输入: "words and 987"; 输出: 0

#include<string>
#include<sstream>
using namespace std;

//没有考虑溢出的情况，超过int类型
//int strToInt(string str) 
//{
//	string ans ;
//	int cnt = 0;
//	bool flag = true;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == ' ') continue;
//		if (flag && (str[i] == '+' || str[i] == '-'))
//		{
//			ans += str[i];
//			flag = false;
//		}
//		else if (str[i] >= '0' && '9' >= str[i])
//			ans += str[i];
//		else
//			break;
//	}
//	if (ans.size() == 0) return 0;
//	int i = 0;
//	if (ans[0] == '-')
//	{
//		flag = false;
//		i++;
//	}
//	if (ans[0] == '+')
//	{
//		flag = true;
//		i++;
//	}
//
//	for (; i < ans.size(); i++)
//	{
//		cnt = cnt * 10 + ans[i] - '0';
//	}
//	if (false == flag)
//		cnt = cnt *( -1);
//	return cnt;
//}

int strToInt(string str)
{
	if (str.empty()) return 0;
	int i = 0;
	while (i < str.size() && str[i] == ' ') i++;
	if (i == str.size() || ('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z'))
		return 0;
	int sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-') sign = -1;
		i++;
	}
	int val = 0;
	int bndry = INT_MAX / 10;
	while (i < str.size() && '0' <= str[i] && str[i] <= '9')
	{
		if (val > bndry || val == bndry && str[i] > '7')
			return (sign == -1) ? INT_MIN : INT_MAX;
		val = val * 10 + (str[i] - '0');//这个地方必须加括号，不然在临近INT_MAX的时候加几十，会溢出
		i++;
	}
	return sign * val;
}

//很神奇的题解答案
int myAtoi(string str)
{
	int num = 0;
	istringstream str_1(str);
	str_1 >> num;
	return num;
}
int main(void)
{
	strToInt("2147483646");
	return 0;
}