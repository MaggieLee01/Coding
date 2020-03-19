/*给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
输入: "abcabcbb"；输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

输入: "bbbbb"；输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters */

//注意子串 与 子序列的长度
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
//	//最后没遇到重复字符的处理
//	int wLength = windows.size();
//	ans = max(wLength, ans);
//	return ans;
//}
//上面为我曾经的误区，遇到重复的字符是一棒子打死，前面的所有字符，像这种"dvdf"，重复的字符出现在第二个长字符串中间，上面的就有逻辑bug了
//意识到滑动窗口的作用了
int lengthOfLongestSubstring(string s)
{
	unordered_map<char, int> windows;
	int ans = 0, right = 0, left = 0;
	int sLength = s.size();
	for (right = 0; right < sLength; right++)
	{				
		//如果right处字符已经出现过，则不断左移left缩小窗口，找到重复值。
		//if (windows.count(s[right]) != 0)  key的对应值为0 的情况下，count依然为1
		//if (windows.count(s[right]) != 0 && windows[s[right]] == 1)//确保在窗口内出现重复字符
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
	//最后一次的窗口长度没有更新
	ans = max(ans, right - left);
	//return windows.size(); 里面一堆对应值为0的key
	return ans;
}
//count()函数统计什么：容器中有该关键字，返回1；无该关键字，返回0；与key对应的value值无关
//对于mapd size()，即使关键值对应的个数为0 ，也属于占了一个大小，size()也是统计关键字的数量

//看了答案，思路一样，一旦右边界字符出现过，则不断缩小窗口，保证滑动窗口里面无重复字符
//缩小窗口的过程，精简了很多；我写的有太多重复代码
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