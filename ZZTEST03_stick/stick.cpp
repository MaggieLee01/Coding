//���п����ĵڶ��⣬poj 1025 ԭ��
//�����һ��ľ����Ҫ����1��������ǰ��ľ���ĳ��Ⱥ����������ڵ�����һ��ľ�����������򲻷��������򻨷�1�������������ľ�����������ٻ��Ѷ���

//�������ͬ��һ�⣺��һ��Ϊ��������
//ÿ�����ݵĵ�һ��nΪľ���������ڶ���n��������ľ���ĳ��ȣ�������n��������ľ��������

//�и���ŵ�˼·���������� ���������ݽṹ����û�����ʲô��Ȼ�����򼴿ɡ�
//�漰���ظ�������multimap�����ǲ������������㷨����Ҳ�����ˣ�������Ҳʹ�õĲ�˳��
//������⣬��pairģ����ѽ������multimap���÷���������pair��ɵģ��������ź���ģ�Ӧ��û������
//����ʹ��vector< pair<int,int> > �Լ����򣬲�࣬
//����дmultimapʱ��������һ����Ҫǰ����໥λ�ñȽ�ʱ���޷�����map�ĵ�����û������+�ţ���Ϊvector����

//��ʼ��˼·����һ��Ԫ���ź���󣬵ڶ���Ԫ�ؽ��ͼ����ӣ����������˴��󣬵�һ��Ԫ���ź����Ѱ�ҵڶ���Ԫ�ص����������и���

#include<iostream>
#include<vector>
//#include<iterator>
#include<map>
#include<algorithm>
using namespace std;

//��ʱ�Ϳ��������second���������ˣ�map��ֵ��Ա���;���pairѽ������������ѽ���Ƚϵ���������Ԫ��
//bool camp(multimap<int, int>dict1, multimap<int, int> dict2)
bool comp(pair<int, int>dict1, pair<int, int> dict2)
{
	if (dict1.first == dict2.first)
		return (dict1.second < dict2.second);
	else
		return (dict1.first < dict2.first);
}
int main(void)
{
	int n = 0;
	cin >> n;
	vector<int> ans;

	while (n > 0)
	{
		int num = 0;
		cin >> num;

		vector<int> length;
		vector<int> weight;

		int temp = 0;
		while (cin >> temp)
		{
			length.push_back(temp);
			if (cin.get() == '\n') break;
		}
		while (cin >> temp)
		{
			weight.push_back(temp);
			if (cin.get() == '\n') break;
		}
		//multimap<int, int> dict;
		vector< pair<int, int> > dict;
		for (int i = 0; i < num; i++)
		{
			//dict.insert({ length[i],weight[i]});
			//map��insert����ֱ�Ӳ���Ԫ�أ�����vector�����Ĳ���������Ҫ��������ʾλ����Ϊ��һ���������ڶ�������������ʾ���ݼ�����
			dict.push_back({ length[i], weight[i] });
		}
		sort(dict.begin(), dict.end(), comp);

		int a = 0;
		for (int i = 0; i < num - 1; i++)
		{

			/*if (dict[i].second > dict[i+1].second)
				a++;	*/
				//�˴�˼·���ԣ������ź�˳���Ѱ�������������������и������������������

		}

		//for (auto it = dict.begin(); it < dict.end(); i++)//ע��д����������С�ڣ���Ϊ���ǵ�����
		//for (auto it = dict.begin(); it != dict.end(); it++)
		//{
		//	//�������ˣ�������û������+���𣿲��ԣ�Ӧ����mapû�����ؼӺ��������Ӳ��У���һ��Ҫǰ��Ƚ�
		//	if((*it).second>(*(it)+1.)
		//}
		ans.push_back(a);
	}
	for (int i : ans)
		cout << i << endl;
	return 0;
}