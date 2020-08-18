//	https://mp.weixin.qq.com/s/nJHIxQ2BbqhDv5jZ9NgXrQ 2019-06-19 ���������㷨����Ӵ�����
/*
	����һ���ַ��� s ��һ���ǿ��ַ��� p���ҵ� s �������� p ����ĸ��λ�ʵ��Ӵ���������Щ�Ӵ�����ʼ������
	�ַ���ֻ����СдӢ����ĸ�������ַ��� s �� p �ĳ��ȶ������� 20100��

	��ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����	�����Ǵ������˳��

	����: s: "cbaebabacd" p: "abc"�����:[0, 6]
	��ʼ�������� 0 ���Ӵ��� "cba", ���� "abc" ����ĸ��λ�ʡ�
	��ʼ�������� 6 ���Ӵ��� "bac", ���� "abc" ����ĸ��λ�ʡ�

	����: s: "abab" p: "ab"�����:[0, 1, 2]
	��ʼ�������� 0 ���Ӵ��� "ab", ���� "ab" ����ĸ��λ�ʡ�
	��ʼ�������� 1 ���Ӵ��� "ba", ���� "ab" ����ĸ��λ�ʡ�
	��ʼ�������� 2 ���Ӵ��� "ab", ���� "ab" ����ĸ��λ�ʡ�

	https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
*/
#include<string>
#include<vector>
#include<unordered_map>
using std::unordered_map;
using std::vector;
using std::string;

vector<int> findAnagrams(string s, string p)
{
	vector<int> ans;
	unordered_map<char, int> needs;
	unordered_map<char, int> windows;
	for (char i : p) needs[i]++;
	int left = 0, match = 0;

	int pLength = p.size();
	int sLength = s.size();
	for (int i = 0; i < sLength; i++)
	{
		if (needs.count(s[i]) == 0)
		{
			//����match֮�⣬����Ҫ���map
			//windows.clear();
			//match = 0;
			//��������������needs�е��ַ���Ҫ��ͷ�����������Ӳ��У�
			//ԭ��left�����ַ����ƣ�ֱ�����window�Ļ�����left��С�жϵĹ����в��ԡ�left �� right֮����ַ�ͳ�Ʋ��ԡ��������window�Ļ���match���޷�����if������������
			continue;
		}
		windows[s[i]]++;
		if (windows[s[i]] == needs[s[i]])
			match++;
		while (match == needs.size())
		{
			if (needs.count(s[left]) == 1)
			{
				if (i - left + 1 == pLength)
				{
					ans.push_back(left);
					//break; ����break������ļ�����Ȼ��Ҫ�أ�������ô��ַ��󴰿�����
				}
				windows[s[left]]--;
				if (windows[s[left]] < needs[s[left]])
					match--;
			}
			left++;
		}
	}
	return ans;
}
int main(void)
{
	string s = "cbaebabacd";
	string p = "abc";
	vector<int> ans = findAnagrams(s, p);

	s = "abab";
	p = "ab";
	ans = findAnagrams(s, p);
	return 0;
}
