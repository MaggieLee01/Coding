/*����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣Ϊ������������ź���ͨ��ĸһ���������������ַ���"I am a student. "�������"student. a am I"��
����: "the sky is blue"
���: "blue is sky the"

����: "  hello world!  "
���: "world! hello"
����: �����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����

����: "a good   example"
���: "example good a"
����: ����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����

˵����
	�޿ո��ַ�����һ�����ʡ�
	�����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
	����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����

	https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof */

#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

//���Լ�д�ģ��������ڵķ�������ĩβ��ʼ������i j�ֱ�Ϊ���ʵı߽磬��ʱ����k��i ������j ����ֵ
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
			//�ڲ�����ʹ��substr�ĺ������Һ�Ϳ�ˣ�����Ϊ����ֵ��֪����i���Ǵ�ͷ��ʼ����������ֵѽ�����ԣ�Ҳ����ֱ����copy����ѽ
			//���� copy���� ����Ϊans��sizeΪ0��Ӧ����insert����
			if (i == 0 || s[i - 1] == ' ')
			{
				/*int k = i;
				while (k <= j)
				{
					ans += s[k];
					k++;
				}*/
				ans.insert(ans.end(), s.begin() + i, s.begin() + j + 1);
				//copy(s.begin() + i, s.begin() + j + 1, ans.begin() + ans.size()); û���ڴ�ѽ ����copy
				ans += ' ';
			}
		}
		i--;
	}
	if (ans.size() && ans.back() == ' ') ans.pop_back();//��ֹ"  "�����
	return ans;
}

//ò�Ƴ���ķ������ȷ�ת�������ӣ�Ȼ���ٷ�ת���ʣ�������չ����ת�ַ�����Ӧ�ó���
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
			while (end < Len && s[end] != ' ') //����Ϊ��ȥ���м����ո�İ���
				s[idx++] = s[end++];
			reverse(s.begin() + idx - (end - start), s.begin() + idx);
			start = end;
		}
	}
	s.erase(s.begin() + idx, s.end());
	return s;
}

//����stringstream�������ܷ���
//https://leetcode-cn.com/problems/reverse-words-in-a-string/solution/c-zhong-gui-zhong-ju-de-8msjie-fa-bao-li-by-gary_c/
string reverseWords03(string s)
{
	istringstream words(s);
	string ans = "", w;
	while (words >> w)//�Զ����ݿո��зֵ���
		ans = " " + w + ans;
	return ans.empty() ? "" : string(ans.begin() + 1, ans.end());//֮�����ܷ�����ʱ��������string���캯���ĳ������β��й�
}
//�ϸ�Ĵ���
string reverseWords04(string s)//����һ���д��
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