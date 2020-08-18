//	https://mp.weixin.qq.com/s/nJHIxQ2BbqhDv5jZ9NgXrQ 2019-06-19 ���������㷨����Ӵ�����
/*	����һ���ַ��� S��һ���ַ��� T�������ַ��� S �����ҳ������� T ������ĸ����С�Ӵ���
	���� : S = "ADOBECODEBANC", T = "ABC"
	��� : "BANC"
	https://leetcode-cn.com/problems/minimum-window-substring */

	//�ڻ����������͵������ж���������ָ�롣һ�������������д��ڵ� rightrightrightָ�룬��һ�������������ڵ�leftleftleft ָ�롣
	//������ʱ�̣�ֻ��һ��ָ���˶�������һ�����־�ֹ��

	//�������� ����
#include<string>
#include<unordered_map>
using std::unordered_map;
using std::string;

string minWindow(string s, string t)
{
	int minLength = INT_MAX;
	int left = 0, start = 0;

	string ans;
	int sLength = s.size();
	unordered_map<char, int> needs;
	unordered_map<char, int> windows;
	for (char i : t)	needs[i]++;

	int match = 0;//���ִ��������ַ�����
	for (int i = 0; i < sLength; i++)
	{
		if (needs.count(s[i]) == 0) continue;
		windows[s[i]]++;
		//if (windows[s[i]] >= needs[s[i]])��������matchҲ��Ӧ����++�ˣ�match��ָ�����ַ�����,����������
		if (windows[s[i]] == needs[s[i]])
			match++;

		//�Ѿ���������������ʼ��С���ڴ�С		
		/*if (match >= tLength)
		{
			ans = s.substr(0, i + 1);
			while(++left < i)
			{
				if (needs.count(s[left])==0 )
					continue;
				if (windows[s[left]] == needs[s[left]])
				{
					if (i - left + 1 < ans.size())
						ans = s.substr(left, i - left + 1);
					break;
				}
				else windows[s[left]]--;
			}
		}*/
		//�����������һ��˼�ڿ��ǳ��ֵĴ����������˴�ƥ���ַ��ĸ������ǣ��۲���ʲôʱ���ƶ���ߵĴ���

		//while (match == tLength)//�˴�Ӧ���Ǵ���������ַ��������˴��ܹؼ�
		while (match == needs.size())
		{
			//�����ֺ��ʵ��Ӵ�ʱ����¼��ʼλ�úͳ��ȣ�Ȼ������������ߵĴ��ڣ�
			//����ߵĴ��ڲ�����ʱ��matchֵ�仯���󴰿ڱ��ֲ��䣬���������ұߵĴ��ڣ���������match��ʹ֮����
			//�˴���˼·�����ǲ����������޷�д������Ĵ��롣�߼���Ҫ������������ĥ
			if (i - left + 1 < minLength)
			{
				start = left;
				minLength = i - left + 1;
			}
			if (needs.count(s[left]))
			{
				windows[s[left]]--;
				if (windows[s[left]] < needs[s[left]]) match--;
			}
			left++;//��λ�ô����Ѽ��㣬��Ҫ���뵽��һ���ڵ�
		}
	}
	ans = (minLength == INT_MAX) ? ans : s.substr(start, minLength);
	return ans;
}

int main(void)
{
	string s = "ADOBECODEBANC";
	string t = "ABC";
	string ans = minWindow(s, t);

	s = "aa";
	t = "aa";
	ans = minWindow(s, t);
	return 0;
}
