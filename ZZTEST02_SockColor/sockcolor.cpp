//招行卡中心IT暑期实习笔试
//已知袜子的每个颜色对应的数量。要从抽屉里至少取出多少只袜子，才能保证一定有两只可以配成一对的。

//输入：	第一行数字T为测试数据的组数
//		对于每组数据，第一行数字n为颜色组数
//		第二行有n个数字，第i个数字ai表示第i个颜色的袜子有ai个

//输出：	对于每组数据，输出一个数字表示答案；若无解，则为-1


/*
如 输入
2
2
2 2
3
0 0 0
输出
3
-1
*/

//第一次做这种输入输出的，题目不难，但是处理不够熟练,浪费很多时间，之前一直在用LeetCode 不用处理输入
//有时候输入的数据不需要保存，直接处理就好了
//答案通过了90%，看了群里知道了特殊情况，袜子全为1 或 0 的话，也要输出-1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	vector<int> ans;

	while (n > 0)
	{
		int m = 0;
		cin >> m;

		int temp = 0;
		//vector<int> s;
		int max1 = 0, flag = 0;
		while (cin >> temp)//这种已知总数的情况下，可以直接for循环
		{
			if (temp != 0) max1++;
			//看讨论，新加的标志位
			if (temp > 1) flag = 1;
			/*s.push_back(temp);*/
			if (cin.get() == '\n') break;
		}
		if (max1 <= 0 || flag == 0)
			ans.push_back(-1);
		else
			ans.push_back(max1 + 1);
		n--;
	}
	for (int i : ans)
		cout << i << endl;
	return 0;
}