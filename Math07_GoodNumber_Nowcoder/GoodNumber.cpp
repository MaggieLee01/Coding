/*
我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。
如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。
0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方；6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。
现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？
*/
//招行卡中心2019秋笔试
//https://www.nowcoder.com/profile/224937117/test/31944430/285352#summary
//开始的误区，有25这种即为好数，发现了23这种不行，出现3这种就不可能是好数
#include<iostream>
using namespace std;
int main(void)
{
	int num = 0;
	cin >> num;
	int ans = 0;

	for (int i = 1; i <= num; i++)
	{
		int temp = i, vaild = 0;
		while (temp > 0)
		{
			int digit = temp % 10;
			if (digit == 3 || digit == 4 || digit == 7)//出现这些数字就不可能为好数
			{
				vaild = 0;
				break;
			}
			else if (digit == 2 || digit == 5 || digit == 6 || digit == 9) //一定要出现这些数字，不然可能11这种为自己自身           
				vaild = 1;
			temp = temp / 10;
		}
		if (vaild == 1)
			ans++;
	}
	cout << ans << endl;
}