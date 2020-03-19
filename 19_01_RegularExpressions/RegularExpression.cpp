/*��ʵ��һ����������ƥ�����'. '��'*'��������ʽ��
ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ���0�Σ���
�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
���磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬����"aa.a"��"ab*a"����ƥ�䡣

���ӣ�https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof */

//֮ǰ��DP�㷨����д�������ڸ�������Լ�д
#include<string>
#include<vector>
using std::vector;
using std::string;
//�ݹ鷽����sΪ�ַ�����pΪģʽ
bool isMatch_ReCore(string s, string p,int m,int n) 
{
	//�ݹ�������������ˣ����˴𰸣�д�ĺʹ���һ����
	/*if (n >= p.size() && m >= s.size()) return true;
	if (n >= p.size()) return false;*/
	if (n >= p.size())
		return(m >= s.size());
	
	bool before = false;
	if (m < s.size() && (s[m] == p[n] || p[n] == '.'))
		before = true;//����.�Ĵ���
	if (p[n + 1] == '*') //�ǲ�����Ҫȷ��p[n+1]����
		return (before && isMatch_ReCore(s, p, m + 1, n)) || isMatch_ReCore(s, p, m, n + 2);
	else
		return before && (isMatch_ReCore(s, p, m + 1, n + 1));
}

//����¼
int isMatch_DictCore(string s, string p, int m, int n, vector<vector<int> >& Dict)//Dict�������൱��Ҫѽ�������˴����ã����򿨻�
{
	if (n >= p.size() && m >= s.size())
		return 1;
	if (n >= p.size() && m < s.size())
		return 0;
	if (Dict[m][n] != -1) 
		return Dict[m][n];

	bool before = false;
	if (m < s.size() && (s[m] == p[n] || p[n] == '.'))//�ȱ�֤m��Ч���ж�
		before = true;//����.�Ĵ���
	if (p[n + 1] == '*')//�ǲ�����Ҫȷ��p[n+1]����
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