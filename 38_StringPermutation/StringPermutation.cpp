//输入一个字符串，打印出该字符串中字符的所有排列。你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

#include<vector>
#include<string>
#include<unordered_set>
using namespace std;


//昨天刚复习的回溯，为啥子还是写不对
void backTrack(string &s, int num, string &str, vector<string>& ans, int index)
{
	//if (str.size() == (num * 2))
	if (str.size() == num)//我是智障吗？全排列，为啥要个数乘以2呢
	{
		ans.push_back(str);
		return;
	}

	unordered_set<char> set;//局部变量，保存在index位出现的字符
	for (int i = index; i < num; i++)
	{
		if (set.count(s[i])) continue;
		set.insert(s[i]);

		str.push_back(s[i]);
		//swap(str[i], str[index]);	//交换的是原数组呀，str是放答案的数组
		swap(s[i], s[index]);
		backTrack(s, num, str, ans, index + 1);
		swap(s[index], s[i]);
		str.pop_back();
	}
}


//测试数据中有"aab"这种含有重复元素的，如何处理，上次写的没有重复元素
//直接用set储存了字符串；
//高赞的题解：为排除重复方案，需在固定某位字符时，保证 “每种字符只在此位固定一次” ，即遇到重复字符时不交换，直接跳过。从 DFS 角度看，此操作称为 “剪枝” 。
//如果index和i之间有字符等于s[i]，则跳过。
//https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/c-dfs-mian-shi-ti-38-zi-fu-chuan-de-pai-lie-by-yue/


//bool judge(string& s, int start, int end) 
//{
//	for (int i = start; i < end; ++i) 
//	{
//		if (s[i] == s[end]) return true;
//	}
//	return false;
//}
//
//void backTrack1(string &s, int num, string &str, vector<string>& ans, int index)
//{
//	if (str.size() == num )
//	{
//		ans.push_back(str);
//		return;
//	}	
//	for (int i = index; i < num; i++)
//	{
//		if (judge(str, index, i)) 
//			continue;		//不是特别懂这个判断的写法，先放着，用set
//
//		str.push_back(s[i]);
//		swap(s[i], s[index]);
//		backTrack1(s, num, str, ans, index + 1);
//		swap(s[index], s[i]);
//		str.pop_back();
//	}
//}

vector<string> permutation(string s)
{
	int num = s.size();
	if (num == 0) return {};
	vector<string> ans;
	string str;
	backTrack(s, num, str, ans, 0);
	return ans;
}

int main(void)
{
	string s = "aba";
	vector<string> ans = permutation(s);
	return 0;
}