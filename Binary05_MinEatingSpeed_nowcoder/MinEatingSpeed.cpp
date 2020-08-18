/*
小招喵喜欢吃喵粮。这里有 N 堆喵粮，第 i 堆中有 p[i] 粒喵粮。喵主人离开了，将在 H 小时后回来。
小招喵可以决定她吃喵粮的速度 K （单位：粒/小时）。每个小时，她将会选择一堆喵粮，从中吃掉 K 粒。如果这堆喵粮少于 K 粒，她将吃掉这堆的所有喵粮，然后这一小时内不会再吃更多的喵粮。
小招喵喜欢慢慢吃，但仍然想在喵主人回来前吃掉所有的喵粮。
返回她可以在 H 小时内吃掉所有喵粮的最小速度 K（K 为整数）。

输入描述:
第一行输入为喵粮数组，以空格分隔的N个整数，第二行输入为H小时数

输出描述:
最小速度K

输入例子1:
3 6 7 11
8

输出例子1:
4*/
#include <sstream>        //istringstream 必须包含这个头文件
#include <iostream>
#include <vector>
#include <climits> //INT_MIN的头文件
#include <algorithm>
using namespace std;
bool canFinish(vector<int>food, int hours, int speed)
{
	int times = 0;
	for (int i : food)
	{
		int time = (((i%speed) == 0) ? (i / speed) : (i / speed + 1));
		times += time;
		if (times > hours) return false;
	}
	return true;
}
int eatFood(vector<int>food, int hours)
{
	int max1 = 0;
	for (int i : food) max1 = max(max1, i);
	int left = 1, right = max1;
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (canFinish(food, hours, mid))
			right = mid;
		else left = mid + 1;
	}
	return left;
}
int main()
{
	vector<int> food;
	int a, hours;
	//while (cin >> a)
	//{
	//	food.push_back(a); //一行要输入多个数，构成数组
	//}
	//cin >> hours;
	//这样子处理输入输出不行，看题解，把所有的输入都压入数组，再把最后一个复制hour再弹出
	//可以通过牛客网系统，但是不知道自己如何在VS上调试

	while (cin >> a)
	{
		food.push_back(a); //一行要输入多个数，构成数组
	}
	hours = food.back();
	food.pop_back();
	int ans = eatFood(food, hours);
	cout << ans << endl;
	return 0;
}

//新的处理方法
/*	 while(cin>>x)
	{
		a.push_back(x);
		if(cin.get()=='\n')break;
	}
	int h;
	cin>>h;  */

	/*	while(1)
		{
			int t;
			cin>>t;
			arr.push_back(t);
			sum+=t;
			maxk=max(maxk,t);//最大进食速度
			if(cin.get()=='\n')
				break;
		}  */

		/*	string line;
			getline(cin, line);
			istringstream iss(line);
			while(iss >> tmp)  //tmp为int变量
			{
				arr.push_back(tmp);
				mmax = max(mmax, tmp);
				sum += tmp;
			}  */