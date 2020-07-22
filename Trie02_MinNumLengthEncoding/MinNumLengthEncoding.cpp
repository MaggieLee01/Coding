/*	����һ�������б����ǽ�����б�����һ�������ַ��� S ��һ�������б� A��
	���磬�������б��� ["time", "me", "bell"]�����ǾͿ��Խ����ʾΪ S = "time#bell#" �� indexes = [0, 2, 5]��
	����ÿһ�����������ǿ���ͨ�����ַ��� S ��������λ�ÿ�ʼ��ȡ�ַ�����ֱ�� "#" ���������ָ�����֮ǰ�ĵ����б�
	��ô�ɹ��Ը��������б���б������С�ַ��������Ƕ����أ�

	����: words = ["time", "me", "bell"]
	���: 10
	˵��: S = "time#bell#" �� indexes = [0, 2, 5] ��
	https://leetcode-cn.com/problems/short-encoding-of-words
*/

#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//�ֵ�������������洢���ʣ������ֵ��������뵥�ʵ�ʱ��ͷ��س���
//�����Ǽ���߶ȵĳ�Ա�������������ͳ����ÿ�����ʵĳ��ȣ���Ч
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

		//for (auto i = word.end() - 1; i != word.begin(); i--) ��ʱ��*i��������word[i]
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
	//�Ȱ����Ƚ��������ٲ���
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