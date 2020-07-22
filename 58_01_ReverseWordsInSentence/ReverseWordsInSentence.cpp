/*输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。
输入: "the sky is blue"
输出: "blue is sky the"

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

说明：
	无空格字符构成一个单词。
	输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
	如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

	https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof */

#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

//我自己写的，并不大众的方法：从末尾开始遍历，i j分别为单词的边界，临时变量k从i 递增至j 来赋值
string reverseWords(string s)
{
	int Length = s.size();
	string ans;
	if (Length == 0) return ans;
	int i = Length - 1, j = Length - 1;
	while (i >= 0 && j >= 0)
	{
		if (s[i] != ' ')
		{
			if (i == (Length - 1) || s[i + 1] == ' ')
				j = i;
			//内部可以使用substr的函数，我糊涂了，误以为索引值不知道，i就是从头开始计算是索引值呀，所以，也可以直接用copy函数呀
			//不不 copy不行 ，因为ans的size为0，应该用insert函数
			if (i == 0 || s[i - 1] == ' ')
			{
				/*int k = i;
				while (k <= j)
				{
					ans += s[k];
					k++;
				}*/
				ans.insert(ans.end(), s.begin() + i, s.begin() + j + 1);
				//copy(s.begin() + i, s.begin() + j + 1, ans.begin() + ans.size()); 没有内存呀 不能copy
				ans += ' ';
			}
		}
		i--;
	}
	if (ans.size() && ans.back() == ' ') ans.pop_back();//防止"  "的情况
	return ans;
}

//貌似常规的方法，先翻转整个句子，然后再翻转单词，可以扩展到旋转字符串的应用场景
string reverseWords01(string s)
{
	reverse(s.begin(), s.end());
	int Len = s.size();
	int idx = 0;
	for (int start = 0; start < Len; start++)
	{
		if (s[start] != ' ')
		{
			if (idx != 0) s[idx++] = ' ';
			int end = start;
			while (end < Len && s[end] != ' ') //这是为了去掉中间多余空格的搬移
				s[idx++] = s[end++];
			reverse(s.begin() + idx - (end - start), s.begin() + idx);
			start = end;
		}
	}
	s.erase(s.begin() + idx, s.end());
	return s;
}

//利用stringstream来处理，很方便
//https://leetcode-cn.com/problems/reverse-words-in-a-string/solution/c-zhong-gui-zhong-ju-de-8msjie-fa-bao-li-by-gary_c/
string reverseWords03(string s)
{
	istringstream words(s);
	string ans = "", w;
	while (words >> w)//自动根据空格切分单词
		ans = " " + w + ans;
	return ans.empty() ? "" : string(ans.begin() + 1, ans.end());//之所以能返回临时变量，和string构造函数的常引用形参有关
}
//瓜哥的代码
string reverseWords04(string s)//复杂一点的写法
{
	istringstream ss(s);
	string buf;
	vector<string> token;
	while (ss >> buf)	
		token.push_back(buf);
	string ans;
	for (int i = token.size() - 1; i >= 0; i--)
	{
		ans += token[i];
		ans += " ";
	}
	return ans;
}




int main(void)
{
	string s = "     s    ed      df     ";
	string ans = reverseWords(s);
	return 0;
}