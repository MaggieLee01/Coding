/*��������һλ���а����׶�԰��ʦ����Ҫ���׶�԰��С������һЩС�ǹ������ǣ�ÿ���������ֻ�ܸ�һ���ǹ���
��ÿ������ i ������һ��θ��ֵ gi ���������ú���������θ�ڵ��ǹ�����С�ߴ磻����ÿ���ǹ� j ������һ���ߴ� sj ��
��� sj >= gi �����ǿ��Խ�����ǹ� j ��������� i ��������ӻ�õ����㡣���Ŀ���Ǿ���������Խ�������ĺ��ӣ��������������ֵ��

ע�⣺
����Լ���θ��ֵΪ����
һ��С�������ֻ��ӵ��һ���ǹ���
*/

//������ˣ�����һ������˫ָ��

//���п�����2019�����
//https://www.nowcoder.com/profile/224937117/test/31944430/285377#summary
//�ص������������г���ȷ��������Ĵ�����������˷���ʹ��˫ָ�봦��ȽϷ���
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void)
{
	vector<int> can;
	vector<int> size;
	int a = 0;
	while (cin >> a)
	{
		can.push_back(a);
		if (cin.get() == '\n')break;
	}
	int b = 0;
	while (cin >> b)
	{
		size.push_back(b);
		if (cin.get() == '\n') break;
	}
	sort(can.begin(), can.end());
	sort(size.begin(), size.end());

	int ans = 0;
	int i = 0, j = 0;
	while (i < can.size() && j < size.size())
	{
		if (can[i] <= size[j])
		{
			i++;
			ans++;
		}
		j++;
	}
	cout << ans << endl;

	return 0;
}

//���𰸣������Ĵ�������getline �ȶ�ȡһ�У�Ȼ��stringstream����
/*
	vector<int> g, s;
	int tmp;
	string str;

	getline(cin, str);
	stringstream sin1(str);
	while(sin1 >> tmp) g.push_back(tmp);

	getline(cin, str);
	stringstream sin2(str);
	while(sin2 >> tmp) s.push_back(tmp);

*/

//û������򵥣�getline �Զ���ȡ�����з�
/*
	vector<string> strs;
	string str;
	while (getline(cin, str, '\n'))
		strs.push_back(str);

	vector<int> g, s;
	stringstream ss1(strs[0]), ss2(strs[1]);
	while (getline(ss1, str, ' '))    g.push_back(stoi(str));
	while (getline(ss2, str, ' '))    s.push_back(stoi(str));
*/