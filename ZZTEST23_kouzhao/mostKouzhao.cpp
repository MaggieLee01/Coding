//奇信笔试题，很简单，没有数据结构算法的思考
#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<sstream>
using namespace std;

//11 10为特例，题目比较简单，就是简单的比较单价，数据比较少，暴力即可
//int main(void)
//{
//	int money = 0;
//	cin >> money;
//	int ans = 0;
//	if (money >= 1)
//	{
//		ans += 5;
//		money -= 1;
//		if (money >= 2)
//		{
//			ans += 3;
//			money -= 2;
//			if (money >= 2)
//			{
//				ans += 3;
//				money -= 2;
//				if (money >= 2)
//				{
//					ans += 2;
//					money -= 2;
//					if (money >= 5)
//					{
//						ans += 4;
//						money -= 5;
//						if (money >= 3)
//						{
//							ans += 1;
//							money -= 3;
//						}
//					}
//				}
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


//主要考察以，分割的输入，之前的练习都是空格为分割，cin只识别空格

//不要前面的直接把iss改成cin不行，这样子会陷入死循环，无法结束输入
	//很奇怪的是，想加入cin.get（）判断是否结束，结果，加入该行后，while循环不能正常使用了，第二次读取是str为空
	//综上，只能 getline 先读取一行，转换为stream之后，再用getline进行逗号的分割
//if (cin.get() == '\n') break;

int main(void)
{
	string line;
	getline(cin, line);
	istringstream iss(line);

	vector<int> nums;
	string str;
	while (getline(iss, str, ','))
	{
		nums.push_back(stoi(str));
	}

	//scanf是可以识别逗号分割的，上面的方法最佳
	/*vector<int> nums(9);
	scanf_s("%d,%d,%d,%d,%d,%d,%d,%d,%d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4], &nums[5], &nums[6], &nums[7], &nums[8]);*/

	//下面的方法不行，cin>> 只识别空格
	//for (int i = 0; i < 9; i++)
	//{
	//	cin >> nums[i];
	//	scanf("%d", &nums[i]);
	//}

	int sum1 = nums[0] + nums[1] + nums[2] + nums[3];
	int sum2 = nums[3] + nums[4] + nums[5] + nums[6];
	int sum3 = nums[6] + nums[7] + nums[8] + nums[0];
	bool ans = sum1 == sum2 ? sum2 == sum3 : false;
	if (ans) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}