//招行卡中心第二题，poj 1025 原题
//处理第一根木棍需要费力1，若处理当前的木棍的长度和重量都大于等于上一根木根的重量，则不费力，否则花费1；可以任意放置木根，请问最少花费多少

//输入输出同上一题：第一行为测试组数
//每组数据的第一行n为木根数量，第二行n个数代表木根的长度，第三行n个数代表木根的重量

//有个大概的思路，构建长度 重量的数据结构，但没想好是什么，然后排序即可。
//涉及到重复，想用multimap，但是不熟练，排序算法规则也忘记了，迭代器也使用的不顺利
//看了题解，是pair模板类呀，看了multimap的用法，就是有pair组成的，而且是排好序的，应该没有问题
//或者使用vector< pair<int,int> > 自己排序，差不多，
//尝试写multimap时，发现有一步需要前后的相互位置比较时，无法处理，map的迭代器没有重载+号，改为vector容器

//开始的思路，第一个元素排好序后，第二个元素降低即增加，后来发现了错误，第一个元素排好序后，寻找第二个元素的上升子序列个数

#include<iostream>
#include<vector>
//#include<iterator>
#include<map>
#include<algorithm>
using namespace std;

//当时就卡在这里，连second都不会用了；map的值成员类型就是pair呀，不能用容器呀，比较的是容器的元素
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
			//map的insert可以直接插入元素，但是vector容器的插入则是需要迭代器表示位置作为第一个参数，第二第三个参数表示内容及数量
			dict.push_back({ length[i], weight[i] });
		}
		sort(dict.begin(), dict.end(), comp);

		int a = 0;
		for (int i = 0; i < num - 1; i++)
		{

			/*if (dict[i].second > dict[i+1].second)
				a++;	*/
				//此处思路不对，长度排好顺序后，寻找重量的最少上升序列个数，即最长上升子序列

		}

		//for (auto it = dict.begin(); it < dict.end(); i++)//注意写法，不能是小于，因为这是迭代器
		//for (auto it = dict.begin(); it != dict.end(); it++)
		//{
		//	//好像处理不了，迭代器没有重载+号吗？不对，应该是map没有重载加号吗？这样子不行，这一步要前后比较
		//	if((*it).second>(*(it)+1.)
		//}
		ans.push_back(a);
	}
	for (int i : ans)
		cout << i << endl;
	return 0;
}