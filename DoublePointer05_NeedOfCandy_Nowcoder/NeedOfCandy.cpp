/*假设你是一位很有爱的幼儿园老师，想要给幼儿园的小朋友们一些小糖果。但是，每个孩子最多只能给一块糖果。
对每个孩子 i ，都有一个胃口值 gi ，这是能让孩子们满足胃口的糖果的最小尺寸；并且每块糖果 j ，都有一个尺寸 sj 。
如果 sj >= gi ，我们可以将这个糖果 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

注意：
你可以假设胃口值为正。
一个小朋友最多只能拥有一块糖果。
*/

//分类错了，是另一道题用双指针

//招行卡中心2019秋笔试
//https://www.nowcoder.com/profile/224937117/test/31944430/285377#summary
//重点在于输入两行长度确定的数组的处理方法，此外此方法使用双指针处理比较方便
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

//看答案，其他的处理方法，getline 先读取一行，然后stringstream处理
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

//没有上面简单，getline 自动读取到换行符
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