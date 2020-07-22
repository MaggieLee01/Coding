//����һ���ַ�������ӡ�����ַ������ַ����������С������������˳�򷵻�����ַ������飬�����治�����ظ�Ԫ�ء�

#include<vector>
#include<string>
#include<unordered_set>
using namespace std;


//����ո�ϰ�Ļ��ݣ�Ϊɶ�ӻ���д����
void backTrack(string &s, int num, string &str, vector<string>& ans, int index)
{
	//if (str.size() == (num * 2))
	if (str.size() == num)//����������ȫ���У�ΪɶҪ��������2��
	{
		ans.push_back(str);
		return;
	}

	unordered_set<char> set;//�ֲ�������������indexλ���ֵ��ַ�
	for (int i = index; i < num; i++)
	{
		if (set.count(s[i])) continue;
		set.insert(s[i]);

		str.push_back(s[i]);
		//swap(str[i], str[index]);	//��������ԭ����ѽ��str�ǷŴ𰸵�����
		swap(s[i], s[index]);
		backTrack(s, num, str, ans, index + 1);
		swap(s[index], s[i]);
		str.pop_back();
	}
}


//������������"aab"���ֺ����ظ�Ԫ�صģ���δ����ϴ�д��û���ظ�Ԫ��
//ֱ����set�������ַ�����
//���޵���⣺Ϊ�ų��ظ����������ڹ̶�ĳλ�ַ�ʱ����֤ ��ÿ���ַ�ֻ�ڴ�λ�̶�һ�Ρ� ���������ظ��ַ�ʱ��������ֱ���������� DFS �Ƕȿ����˲�����Ϊ ����֦�� ��
//���index��i֮�����ַ�����s[i]����������
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
//			continue;		//�����ر�����жϵ�д�����ȷ��ţ���set
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