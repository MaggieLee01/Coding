//	https://mp.weixin.qq.com/s/nJHIxQ2BbqhDv5jZ9NgXrQ 2019-06-19 滑动窗口算法解决子串问题
/*	给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
	输入 : S = "ADOBECODEBANC", T = "ABC"
	输出 : "BANC"
	https://leetcode-cn.com/problems/minimum-window-substring */

	//在滑动窗口类型的问题中都会有两个指针。一个用于延伸现有窗口的 rightrightright指针，和一个用于收缩窗口的leftleftleft 指针。
	//在任意时刻，只有一个指针运动，而另一个保持静止。

	//看完文章 尝试
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

	int match = 0;//出现次数达标的字符数量
	for (int i = 0; i < sLength; i++)
	{
		if (needs.count(s[i]) == 0) continue;
		windows[s[i]]++;
		//if (windows[s[i]] >= needs[s[i]])当超出后match也不应该再++了，match仅指达标的字符个数,不能再增多
		if (windows[s[i]] == needs[s[i]])
			match++;

		//已经满足了条件，开始缩小窗口大小		
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
		//上面的误区，一心思在考虑出现的次数，忽略了从匹配字符的个数考虑，捋不清什么时候移动左边的窗口

		//while (match == tLength)//此处应该是窗口里面的字符数量，此处很关键
		while (match == needs.size())
		{
			//当出现合适的子串时即记录起始位置和长度，然后慢慢右移左边的窗口，
			//当左边的窗口不合适时，match值变化，左窗口保持不变，继续扩大右边的窗口，进而更新match，使之合适
			//此处有思路，但是不够清晰，无法写出下面的代码。逻辑需要多练，慢慢琢磨
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
			left++;//该位置处均已计算，需要进入到下一个节点
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
