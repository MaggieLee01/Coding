/*
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");
trie.search("app");     // 返回 true

说明:你可以假设所有的输入都是由小写字母 a-z 构成的。
	保证所有输入均为非空字符串。

https://leetcode-cn.com/problems/implement-trie-prefix-tree
*/


//官方题解很清晰讲述了字典树的结构，字典树用于存储；代码也参考官方题解的评论C++版 
//关于删除 和 统计，题解有
//解决方法：添加两个新的变量。path：代表从当前节点经过的单词数量；end：代表以当前节点为结束的单词数量
//https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/quan-ji-chu-ti-mu-yao-qiu-zi-dian-shu-wan-zheng-zh/
#include<string>
#include<vector>
using std::vector;
using std::string;

//很多把节点作为一个结构体，类的成员变量为结构体
class Trie 
{
private:
	bool isEnd = false;
	Trie *next[26] = { nullptr };
	//一开始这里不明白指针，想着用vector，看到树，链表的指针，才想到这里是存放26个指针的数组
	//vector<Trie *> next(26, nullptr);		//错误呀，不能再类里调用vector构造函数直接赋值
public:
	Trie() {}

	void insert(string word) 
	{
		Trie *root = this;//如此看来 this永远在根节点
		for (const auto w : word)
		{
			if (root->next[w - 'a'] == nullptr)//说明此指针没有指向下一个字符
				root->next[w - 'a'] = new Trie();
			root = root->next[w - 'a'];
		}
		root->isEnd = true;
	}
	
	bool search(string word) 
	{
		Trie *root = this;
		for (const auto w : word)
		{
			if (root->next[w - 'a'] == nullptr) return false;
			root = root->next[w - 'a'];
		}
		return root->isEnd;
	}

	bool startsWith(string prefix) 
	{

		Trie *root = this;
		for (const auto w : prefix)
		{
			if (root->next[w - 'a'] == nullptr) return false;
			root = root->next[w - 'a'];
		}
		return true;
	}
};
