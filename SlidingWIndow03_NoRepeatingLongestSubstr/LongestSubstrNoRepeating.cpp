/*����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
����: "abcabcbb"�����: 3 
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��

����: "bbbbb"�����: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters */

//ע���Ӵ� �� �����еĳ���
#include<string>
#include<unordered_map>
#include<algorithm>
using std::max;
using std::unordered_map;
using std::string;

//int lengthOfLongestSubstring(string s) 
//{
//	int ans = 0;
//	unordered_map<char, int> windows;
//
//	int sLength = s.size();
//	for (int i = 0; i < sLength; i++) 
//	{
//		if (windows.count(s[i]) != 0)
//		{
//			int wLength = windows.size();
//			ans = max(wLength, ans);
//			windows.clear();
//		}
//		windows[s[i]]++;
//	}
//	//���û�����ظ��ַ��Ĵ���
//	int wLength = windows.size();
//	ans = max(wLength, ans);
//	return ans;
//}
//����Ϊ�������������������ظ����ַ���һ���Ӵ�����ǰ��������ַ���������"dvdf"���ظ����ַ������ڵڶ������ַ����м䣬����ľ����߼�bug��
//��ʶ���������ڵ�������
int lengthOfLongestSubstring(string s)
{
	unordered_map<char, int> windows;
	int ans = 0, right = 0, left = 0;
	int sLength = s.size();
	for (right = 0; right < sLength; right++)
	{				
		//���right���ַ��Ѿ����ֹ����򲻶�����left��С���ڣ��ҵ��ظ�ֵ��
		//if (windows.count(s[right]) != 0)  key�Ķ�ӦֵΪ0 ������£�count��ȻΪ1
		//if (windows.count(s[right]) != 0 && windows[s[right]] == 1)//ȷ���ڴ����ڳ����ظ��ַ�
		if (windows[s[right]] == 1)
		{	
			ans = max(ans, right - left);
			while (s[left] != s[right])
			{
				windows[s[left]]--;
				left++;
			}	
			windows[s[left]]--;
			left++;
		}
		windows[s[right]]++;
	}
	//���һ�εĴ��ڳ���û�и���
	ans = max(ans, right - left);
	//return windows.size(); ����һ�Ѷ�ӦֵΪ0��key
	return ans;
}
//count()����ͳ��ʲô���������иùؼ��֣�����1���޸ùؼ��֣�����0����key��Ӧ��valueֵ�޹�
//����mapd size()����ʹ�ؼ�ֵ��Ӧ�ĸ���Ϊ0 ��Ҳ����ռ��һ����С��size()Ҳ��ͳ�ƹؼ��ֵ�����

//���˴𰸣�˼·һ����һ���ұ߽��ַ����ֹ����򲻶���С���ڣ���֤���������������ظ��ַ�
//��С���ڵĹ��̣������˺ܶࣻ��д����̫���ظ�����
int lengthOfLongestSubstring_answer(string s)
{
	unordered_map<char, int> windows;
	int ans = 0, right = 0, left = 0;
	int sLength = s.size();
	for (right = 0; right < sLength; right++)
	{
		windows[s[right]]++;
		while (windows[s[right]] > 1)
		{
			windows[s[left]]--;
			left++;
		}
		ans = max(ans, right - left + 1);
	}
	return ans;
}
int main(void)
{
	string s = "abcabcbb";
	int m = lengthOfLongestSubstring(s);

	s = "tmmzuxt";
	m = lengthOfLongestSubstring(s);

	s = "aaaaa";
	m = lengthOfLongestSubstring(s);

	s = "pwwkew";
	m = lengthOfLongestSubstring(s);

	s = "dvdf";
	m = lengthOfLongestSubstring(s);
	return 0;
}