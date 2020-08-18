//����һ������������ַ������������������ַ�����
//�������Ϊ: k[encoded_string]����ʾ���з������ڲ��� encoded_string �����ظ� k �Ρ�ע�� k ��֤Ϊ��������
//�������Ϊ�����ַ���������Ч�ģ������ַ�����û�ж���Ŀո�������ķ��������Ƿ��ϸ�ʽҪ��ġ�
//���⣬�������Ϊԭʼ���ݲ��������֣����е�����ֻ��ʾ�ظ��Ĵ��� k �����粻������� 3a �� 2[4] �����롣
/*  s = "3[a]2[bc]", ���� "aaabcbc".
	s = "3[a2[c]]", ���� "accaccacc".
	s = "2[abc]3[cd]ef", ���� "abcabccdcdcdef".
	https://leetcode-cn.com/problems/decode-string  */


	/*
	����ĺ���˼·��: Ҫ��˼����ջӦ�洢ʲôԪ�أ���ʱ��ջ����ջ
		������a2[b]�����ӣ�
		1 ������'['����'['����֮ƥ���']'֮�����ĸ��Ҫ�ظ��Ĵ�����'['֮ǰ���ַ���ջ�������н�ջ{2,a}
		2 ������']'�������е��ַ���res����b,����Ҫ�ظ�����ĸ����ʱ��ջ֮ǰ��ջ��{2,a}��res���a+2*b = abb
		3 ����ע�����ע�ͼ���
	 https://leetcode-cn.com/problems/decode-string/solution/zhi-xing-yong-shi-0-ms-zai-suo-you-c-ti-jiao-zh-47/
	*/
#include<string>
#include<stack>
#include<cmath>
using std::stack;
using std::string;

//�漰string�Ľ�ȡ��ƴ�Ӳ���
//�����뷨��������ջ������[ʱ����������ظ�����
//д��һ�棬����ѹ��ջ��������ظ�ֵ��[]��int��ֵ����¼����������
//������Ƕ���Ե������������е��ѶԸ�ѽ������ֵҲ�����仯�ˣ�
//����Ƕ������ʶ�������� �� [Ӧ�÷���һ��ջ����
//����һ�������⣬û���ظ�����ô����
//����һ�������⣬] ]֮����ַ��ظ������ٵ���δ���
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
//		//[2[jk]e1[f]]] ����д���Ĵ�����
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
//				//substr�ĵ�һ����������ʼλ�ã��ڶ��������ǳ���
//				subsub = s.substr(indexStack.top() + 1, i - 1 - indexStack.top());
//			else
//				subsub = s.substr(indexStack.top() + 1, lastSignIndex - indexStack.top()) + subsub;
//			indexStack.pop();//��� [ ƥ��� ]
//
//			int exponent = 0;
//			while (indexStack.size() && s[indexStack.top()] != '[')
//			{	
//				repeat =( s[indexStack.top()] - '0' )*pow(10, exponent)+ repeat;//��λ�ȵ����ļ��㷽��
//				//repeat = s[indexStack.top()] - '0' + repeat * 10;//���Ǹ�λ�ȵ����ļ��㷽ʽ
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

//����д���ܴ���򵥵����ͣ�����Ƕ�׵������⣬˼·��Ҫ�޸ģ�ͨ����27/29
//����⣬����������ջ����ģ�һ�������ַ�����һ����������
//����ջ�洢�ظ������֣��ַ���ջ���ÿһ�鴦��� ����ƴ�ӵ�����
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
			ans.push_back(s[i]);//ע��string�����÷�
		else if (s[i] == ']')
		{
			for (int j = 0; j < repeatStack.top(); j++)
				subStack.top() += ans;//��һ���벻����ѽ			
			repeatStack.pop();
			ans = subStack.top();
			subStack.pop();
		}
	}
	return ans;
}
//�ݹ�Ҳ�Ǳ߿�����д�ģ���ʹ������һ�黹�ǲ�̫��Ϥ��û��ջ�����
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
				ans += subsub;*/		//ͬʱ����repeat����ѽ

				/*while (repeat-- > 0)*/ //������дҲ����ѽ���ж�һ�ξͼ���1
			while (repeat > 0)
			{
				ans += subsub;
				repeat--;
			}

		}
	}
	return ans;
}
//������]��������������ʾ��д���ˣ������׵����Լ����Ѷ���д����
int main(void)
{
	//string s = "3[a]2[bc]";
	//string ans = decodeString(s);

	//s = "3[a2[c]]";
	//ans = decodeString(s);

	//s = "2[abc]3[cd]ef";
	//ans = decodeString(s);

	////ͨ����19/28�����ǲ���ȫ��
	//s = "100[leetcode]";//����repeatʱ��������
	//ans = decodeString(s); 

	//s = "3[a]2[b4[F]c]";//����]]֮����ַ�
	//ans = decodeString(s);

	//s = "3[a]bc2[b4[F]c]bc";//����]]֮����ַ�
	//ans = decodeString(s);

	string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";//����]]֮����ַ�
	string ans = decodeString_recursively(s);

}
