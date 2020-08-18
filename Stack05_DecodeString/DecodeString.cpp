//给定一个经过编码的字符串，返回它解码后的字符串。
//编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
//你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
//此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
/*  s = "3[a]2[bc]", 返回 "aaabcbc".
	s = "3[a2[c]]", 返回 "accaccacc".
	s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
	https://leetcode-cn.com/problems/decode-string  */


	/*
	此题的核心思路是: 要先思考：栈应存储什么元素，何时进栈、出栈
		以下用a2[b]举例子：
		1 当遇到'['，把'['和与之匹配的']'之间的字母需要重复的次数和'['之前的字符进栈，本例中进栈{2,a}
		2 当遇到']'，代码中的字符串res即：b,就是要重复的字母，此时出栈之前进栈的{2,a}，res变成a+2*b = abb
		3 部分注意事项看注释即可
	 https://leetcode-cn.com/problems/decode-string/solution/zhi-xing-yong-shi-0-ms-zai-suo-you-c-ti-jiao-zh-47/
	*/
#include<string>
#include<stack>
#include<cmath>
using std::stack;
using std::string;

//涉及string的截取，拼接操作
//初步想法，有数字栈，遇到[时弹出计算出重复数字
//写完一版，数字压入栈，计算出重复值，[]用int数值来记录左右索引，
//看到了嵌套性的样例，发现有点难对付呀，索引值也发生变化了；
//由于嵌套性意识到，数字 和 [应该放在一个栈里面
//还有一部分问题，没有重复的怎么处理
//又有一部门问题，] ]之间的字符重复次数少的如何处理
//string decodeString(string s) 
//{
//	int sLength = s.size();
//	string ans;
//	if (sLength == 0) return ans;
//	stack<int> indexStack;
//	string sub, subsub;
//	int repeat = 0, lastSignIndex = 0;	
//
//	for (int i = 0; i < sLength; i++)
//	{
//		//[2[jk]e1[f]]] 这种写法的处理不好
//		if ('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z')
//		{
//			if (subsub != "") subsub.append(1, s[i]);
//			else if (indexStack.empty()) ans.append(1, s[i]);
//			else continue;
//		}			
//		if ('0' <= s[i] && s[i] <= '9' || s[i] == '[')
//			indexStack.push(i);		
//		
//		if (s[i] == ']')
//		{
//			if (subsub == "")
//				//substr的第一个参数是起始位置，第二个参数是长度
//				subsub = s.substr(indexStack.top() + 1, i - 1 - indexStack.top());
//			else
//				subsub = s.substr(indexStack.top() + 1, lastSignIndex - indexStack.top()) + subsub;
//			indexStack.pop();//与该 [ 匹配的 ]
//
//			int exponent = 0;
//			while (indexStack.size() && s[indexStack.top()] != '[')
//			{	
//				repeat =( s[indexStack.top()] - '0' )*pow(10, exponent)+ repeat;//低位先弹出的计算方法
//				//repeat = s[indexStack.top()] - '0' + repeat * 10;//这是高位先弹出的计算方式
//				lastSignIndex = indexStack.top() - 1;
//				indexStack.pop();
//				exponent++;
//			}
//
//			for (int j = 0; j < repeat; j++)
//				sub.append(subsub);
//			subsub = sub;
//			sub = "";
//			repeat = 0;	
//				
//			if (indexStack.empty())
//			{
//				ans.append(subsub);
//				subsub = "";
//				lastSignIndex = 0;
//			}
//		}
//	}
//	return ans;
//}

//上面写的能处理简单的类型，复杂嵌套的有问题，思路需要修改，通过率27/29
//看题解，都是用两个栈处理的，一个处理字符串。一个处理数字
//数字栈存储重复的数字，字符串栈存放每一块处理好 可以拼接的数据
string decodeString(string s)
{
	int sLength = s.size();
	stack<int> repeatStack;
	stack<string> subStack;
	string ans;
	int repeat = 0;
	for (int i = 0; i < sLength; i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
			repeat = repeat * 10 + s[i] - '0';
		else if (s[i] == '[')
		{
			repeatStack.push(repeat);
			subStack.push(ans);
			repeat = 0;
			ans = "";
		}
		else if ('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z')
			ans.push_back(s[i]);//注意string容器用法
		else if (s[i] == ']')
		{
			for (int j = 0; j < repeatStack.top(); j++)
				subStack.top() += ans;//这一步想不起来呀			
			repeatStack.pop();
			ans = subStack.top();
			subStack.pop();
		}
	}
	return ans;
}
//递归也是边看题解边写的，即使调试了一遍还是不太熟悉，没有栈好理解
string decodeString_recursively(string s)
{
	int repeat = 0;
	int sLength = s.size();
	string ans;
	for (int i = 0; i < sLength; i++)
	{
		if ('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z')
			ans.push_back(s[i]);
		else if ('0' <= s[i] && s[i] <= '9')
			repeat = repeat * 10 + s[i] - '0';
		else if (s[i] == '[')
		{
			int cnt = 0;
			i++;
			string substr;
			while (s[i] != ']' || cnt != 0)
			{
				if (s[i] == '[') cnt++;
				else if (s[i] == ']') cnt--;
				substr.push_back(s[i]);
				i++;
			}
			string subsub = decodeString_recursively(substr);
			/*for (int j = 0; j < repeat; j++)
				ans += subsub;*/		//同时得让repeat清零呀

				/*while (repeat-- > 0)*/ //这样子写也不行呀，判断一次就减了1
			while (repeat > 0)
			{
				ans += subsub;
				repeat--;
			}

		}
	}
	return ans;
}
//处理不好]的情况，在题解提示下写完了，能明白但是自己很难独立写出来
int main(void)
{
	//string s = "3[a]2[bc]";
	//string ans = decodeString(s);

	//s = "3[a2[c]]";
	//ans = decodeString(s);

	//s = "2[abc]3[cd]ef";
	//ans = decodeString(s);

	////通过率19/28，考虑不够全面
	//s = "100[leetcode]";//计算repeat时计算有误
	//ans = decodeString(s); 

	//s = "3[a]2[b4[F]c]";//处理]]之间的字符
	//ans = decodeString(s);

	//s = "3[a]bc2[b4[F]c]bc";//处理]]之间的字符
	//ans = decodeString(s);

	string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";//处理]]之间的字符
	string ans = decodeString_recursively(s);

}
