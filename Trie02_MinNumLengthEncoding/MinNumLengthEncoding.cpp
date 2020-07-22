/*	给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。
	例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。
	对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。
	那么成功对给定单词列表进行编码的最小字符串长度是多少呢？

	输入: words = ["time", "me", "bell"]
	输出: 10
	说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
	https://leetcode-cn.com/problems/short-encoding-of-words
*/

#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//字典树方法，倒序存储单词，构建字典树，插入单词的时候就返回长度
//曾考虑加入高度的成员变量，结果发现统计了每个单词的长度，无效
class Trie
{
private:	
	bool isEnd = false;
	Trie *next[26] = { nullptr };
public:
	Trie() {}

	int insert(string word)
	{
		Trie *root = this;
		bool isNewWord = false;

		//for (auto i = word.end() - 1; i != word.begin(); i--) 此时用*i，而不是word[i]
		for (int i = word.length() - 1; i >= 0; i--)
		{
			if (root->next[word[i] - 'a'] == nullptr)
			{
				root->next[word[i] - 'a'] = new Trie();
				isNewWord = true;
			}			
			root = root->next[word[i] - 'a'];
		}
		root->isEnd = true;
		
		return isNewWord == true ? (word.length() + 1) : 0;
	}	
};
bool comp(string str1, string str2)
{
	return (str1.length() > str2.length() );
}
int minimumLengthEncoding(vector<string>& words)
{
	Trie *root = new Trie();
	int ans = 0;
	//先按长度降序排序，再插入
	sort(words.begin(), words.end(), comp);
	for (const auto word : words)	
		ans += root->insert(word);	
	return ans;
}
int main(void)
{
	vector<string> words = { "time", "me", "bell" };
	int ans = minimumLengthEncoding(words);
	return 0;
}