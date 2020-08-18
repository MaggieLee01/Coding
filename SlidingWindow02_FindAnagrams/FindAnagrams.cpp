//	https://mp.weixin.qq.com/s/nJHIxQ2BbqhDv5jZ9NgXrQ 2019-06-19 滑动窗口算法解决子串问题
/*
	给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
	字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

	字母异位词指字母相同，但排列不同的字符串。	不考虑答案输出的顺序。

	输入: s: "cbaebabacd" p: "abc"；输出:[0, 6]
	起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
	起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。

	输入: s: "abab" p: "ab"；输出:[0, 1, 2]
	起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
	起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
	起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

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
			//除了match之外，还需要清空map
			//windows.clear();
			//match = 0;
			//本想着遇到不在needs中的字符需要从头来过，这样子不行，
			//原因：left在逐字符右移，直接清空window的话，在left缩小判断的过程中不对【left 与 right之间的字符统计不对】，不清空window的话，match处无法符合if条件进而递增
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
					//break; 不能break，后面的计算仍然需要呢，处理完该处字符左窗口右移
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
