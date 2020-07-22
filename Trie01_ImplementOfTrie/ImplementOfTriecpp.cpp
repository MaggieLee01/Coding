/*
ʵ��һ�� Trie (ǰ׺��)������ insert, search, �� startsWith ������������

ʾ��:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // ���� true
trie.search("app");     // ���� false
trie.startsWith("app"); // ���� true
trie.insert("app");
trie.search("app");     // ���� true

˵��:����Լ������е����붼����Сд��ĸ a-z ���ɵġ�
	��֤���������Ϊ�ǿ��ַ�����

https://leetcode-cn.com/problems/implement-trie-prefix-tree
*/


//�ٷ����������������ֵ����Ľṹ���ֵ������ڴ洢������Ҳ�ο��ٷ���������C++�� 
//����ɾ�� �� ͳ�ƣ������
//�����������������µı�����path������ӵ�ǰ�ڵ㾭���ĵ���������end�������Ե�ǰ�ڵ�Ϊ�����ĵ�������
//https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/quan-ji-chu-ti-mu-yao-qiu-zi-dian-shu-wan-zheng-zh/
#include<string>
#include<vector>
using std::vector;
using std::string;

//�ܶ�ѽڵ���Ϊһ���ṹ�壬��ĳ�Ա����Ϊ�ṹ��
class Trie 
{
private:
	bool isEnd = false;
	Trie *next[26] = { nullptr };
	//һ��ʼ���ﲻ����ָ�룬������vector���������������ָ�룬���뵽�����Ǵ��26��ָ�������
	//vector<Trie *> next(26, nullptr);		//����ѽ���������������vector���캯��ֱ�Ӹ�ֵ
public:
	Trie() {}

	void insert(string word) 
	{
		Trie *root = this;//��˿��� this��Զ�ڸ��ڵ�
		for (const auto w : word)
		{
			if (root->next[w - 'a'] == nullptr)//˵����ָ��û��ָ����һ���ַ�
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
