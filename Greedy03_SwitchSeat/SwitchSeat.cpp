/*链接：https://ac.nowcoder.com/acm/contest/5246/B
在一场集体婚礼上，有n对新人需要坐在连续排列的 2n个座位上合影，同一对新人彼此挨着。由于进场时各对新人并未按序入座，请计算最少交换座位的次数，以便使每对新人均可并肩坐在一起。一次交换可选择任意两人，让他们互换座位。
	   全部新人的序号可用 0 到 2n-1 的整数表示，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2n-2, 2n-1)。
	   row[i]指最初坐在第 i 个座位上的新人编号，i是从0到（2n-1）的一个升序全排列，row不存在重复值。
输入描述:
	输入共有2行，第一行为n，即共有多少对新人(2≤n≤100000 )，第二行为row，即2n个座位上的初始新人编号。
输出描述:
	输出最少交换座位的次数

输入
2
0 2 1 3
输出
1
说明：我们只需要交换1和2的位置即可

输入
2
3 2 0 1
输出
0
说明：无需交换座位，所有的新人都已经并肩坐在一起
*/

//招行比赛题，不太明白这种题目的算法，和面试题套路不一样
//原来这是贪心算法
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//https://ac.nowcoder.com/acm/problem/blogs/205267
//可参考的解决方法，体会不到最小的概念，感觉就是正常的交换流程
int main(void)
{
	int N = 0;
	cin >> N;
	N = N * 2;
	vector<int> nums(N);
	vector<int> guest(N);
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];			//第i个位置的客人编号
		guest[nums[i]] = i;		//第nums[i]客人的位置在i处，相当于hash存储，找到客人的位置是关键点
	}
	for (int i = 0; i < N; i += 2)//每次递进2，保持偶数处的人不动，可能这个是最小值的来源
	{
		int temp1 = nums[i];
		int temp2 = 0;
		if (temp1 % 2 == 0) temp2 = temp1 + 1;
		else temp2 = temp1 - 1;

		//if (guest[temp1] / 2 != guest[temp2] / 2)	//不相邻的话，交换位置												
		if (temp2 != nums[i + 1])	//不相邻的话，交换位置												
		{
			swap(nums[i + 1], nums[guest[temp2]]);					//temp2 为 temp1的情侣，应该在一起，guest[temp2]为temp2当前的位置
			swap(guest[nums[i + 1]], guest[nums[guest[temp2]]]);	//情侣换位子后更新hash存储的索引
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}