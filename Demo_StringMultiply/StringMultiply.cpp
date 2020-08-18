/*给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"

示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"

https://leetcode-cn.com/problems/multiply-strings */

#include<string>
#include<vector>
using namespace std;

string multiply(string num1, string num2)
{
	int m = num1.size(), n = num2.size();
	//最多m+n位
	vector<int> res(m + n, 0);
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)//注意倒序，从最低位开始运算
		{
			int multi = (num1[i] - '0')*(num2[j] - '0');
			int p1 = i + j, p2 = i + j + 1;
			int sum = multi + res[p2];
			res[p2] = sum % 10;
			res[p1] += sum / 10;//此处可能大于10，在下一步循环是变成了第二位累加到sum里面了，处理得很巧妙
		}
	}
	//处理开头的0
	int i = 0;
	while (i < res.size() && res[i] == 0)
		i++;
	string str;
	for (; i < res.size(); i++)
	{
		str.push_back(res[i] + '0');//这一步加0不要忘记
	}
	//为0 的话不能返回空
	return str.size() == 0 ? "0" : str;//注意此处判断的是str长度
}

int main(void)
{
	string n1 = "99999999";
	string n2 = "9999";
	string ans = multiply(n1, n2);
	return 0;
}