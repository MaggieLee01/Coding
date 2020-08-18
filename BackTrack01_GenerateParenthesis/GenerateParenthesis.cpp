/*���� n �����������ŵĶ������������һ�������������ܹ��������п��ܵĲ��� ��Ч�� ������ϡ�
https://leetcode-cn.com/problems/generate-parentheses
���룺n = 3
�����[
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
//�Լ�д�ģ���ʼʱ��ʹ���˺����ڵ�ȫ�ֱ���ͳ���������ŵ�ֵ��
//��ϸ˼�������ڲ�ͬ���ַ������������ŵ���ֵ��һ������ˣ�Ӧ�����ÿһ���ַ�����һ��ͳ��
vector<string> generateParenthesis(int n)
{
	deque<string> dict;
	vector<string> ans;
	if (n <= 0) return ans;
	dict.push_back("(");
	// int left=1, right=0;//���ڲ�ͬ�����left right����ֵ��һ������˲�Ӧ����ȫ�ֱ���ͳ��
	while (dict.front().size() < (n << 1))
	{
		string front = dict.front();
		int left = 0, right = 0;
		//����ط�ÿ�ζ�Ҫ�������е��鷳�����߿ռ任ʱ�䣬��ⶨ����һ���ṹ�壬left right ����������
		//ʹ��˫�˶��бȽϼ򵥣�ʹ��ջ ���� ���˶��еĻ�����Ҫ���Ǹ���һ�� 
		//ͻȻ��������Ҫ�ľ��ǵ��˶���ѽ���׶˳���β�˽���
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
//������⣬���ڻ��ݷ���˼·��һ��ʹ����ȱ����ȽϺ�
//����dfs����

//��֪��const��ʹ�ã�����const�Ļ�������s+'('�����벻ͨ��������constʱ��s+='('���벻ͨ��
void backTrack(int n, vector<string>& ans, const string& s, int left, int right)
{
	if (s.size() == (n << 1))
	{
		ans.push_back(s);
		return;
	}
	if (right < left)
		backTrack(n, ans, s + ")", left, right + 1);  //��Ϊ�˴�������ʱ������������ֵ�����ڲ��ܽ���ʱ������ʼ�������ñ�����ֻ�ܸ�ֵΪconst����	
	if (left < n)
		backTrack(n, ans, s + '(', left + 1, right);
}
vector<string> generateParenthesis01(int n)
{
	vector<string> ans;
	backTrack(n, ans, "", 0, 0);
	return ans;
}

//�ݹ���㷨�����棺�κ�һ���������ж�һ������ ( ��ͷ�����ҵ�һ�� ( һ����һ��Ψһ��֮��Ӧ�� )��
//����һ����ÿһ���������п����� (a)b ����ʾ������ a �� b �ֱ���һ���Ϸ����������У�����Ϊ�գ���
//�����õ�����ָ�룬
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
			for (const string & left : *lefts)		//lefts �� rights �е�Ԫ�ء���Ϊn����n-i-1���ȵ���Ч���š��������
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
	for (int i = 1; i <= n; i++) //��0��n ���¶��ϴ洢��Ч����
	{
		for (int j = 0; j < i; j++) //����������ַ������ŵĸ�����i-j-1��Ϊ��һ�����ŵĸ���
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


