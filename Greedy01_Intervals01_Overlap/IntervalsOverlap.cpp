//贪心算法之区间调度问题 https://mp.weixin.qq.com/s/NH8GFMcRm5UK0HmVhdNjMQ

//计算这些区间中最多有几个互不相交的区间。
//LeetCode 435 452
//intvs=[[1,3],[2,4],[3,6]]，这里最多有两个区间互不相交，即[[1,3],[3,6]]，你的算法应该返回2。注意边界相同并不算相交。

//瞄了题解，有根据起始时间排序的，有递归的，未仔细看，
#include<iostream> 
#include<vector>
#include<algorithm>

using std::vector;
using std::cout;
using std::endl;
/***********************************************************************************************************/
//根据思路自己写的，时间很慢，占用空间也高，已通过LeetCode测试

//不加static时，vs能通过顺利执行，但是LeetCode编译不通过，需要加static，不明白
static bool EndTimeCmp(vector<int> interval1, vector<int> interval2)
{
	return (interval1[1] < interval2[1]);
}
int eraseOverlapIntervals01(vector<vector<int> > & intervals)
{
	if (intervals.size() == 0) return 0;
	//不能再函数里面定义函数呀
	/*bool EndTimeCmp(vector<int> interval1, vector<int> interval2)
	{	return (interval1[1] < interval2[1]);	}*/

	//尝试使用标准库的sort函数
	std::sort(intervals.begin(), intervals.end(), EndTimeCmp);
	for (int i = 0; i < intervals.size(); i++)
	{
		//本想把无效区间的索引压入一个数组，i遍历到无效区间后就continue，结果发现vector没有查找的功能函数，
		//那如何避开无效区间才能不影响计数呢
		//使用erase()函数呀
		for (int j = i + 1; j < intervals.size(); j++)
		{
			if (intervals[j][0] < intervals[i][1])
			{
				intervals.erase(intervals.begin() + j);
				j--;
				//移除的话，后面的补上，所以此时不能j++递增，漏掉补上的第一位，此时先j--一下，然后for循环的++才能不变
				//这个易被忽略
			}

		}
	}
	return intervals.size();
}
/*************************************************************************************************************/
//想办法优化上面的代码，不用j循环的遍历，直接i+1比较后面的即可【因为erase后后面的会自动补上，所以i+1即可】，
//貌似时间空间占用依然很高，不懂，看答案
//erase函数占用较高，此时，数组的大小在不断发生变化，占用就会较大，答案是直接计数的
int eraseOverlapIntervals02(vector<vector<int> >  intervals)
{
	if (intervals.size() == 0) return 0;
	std::sort(intervals.begin(), intervals.end(), EndTimeCmp);
	for (int i = 0; i < intervals.size() - 1; i++)
	{
		if (intervals[i + 1][0] < intervals[i][1])
		{
			intervals.erase(intervals.begin() + i + 1);
			i--;
		}
	}
	return intervals.size();
}
/*************************************************************************************************************/
//上面的思路是发现无效区间后剔除，剔除的过程浪费时间，看答案直接计数，思考反向行之，寻找有效区间并更新
int eraseOverlapIntervals_answer(vector<vector<int> >  intervals)
{
	int Length = intervals.size();
	if (Length == 0) return 0;
	std::sort(intervals.begin(), intervals.end(), EndTimeCmp);
	int endTime = intervals[0][1];
	int ans = 1;
	for (int i = 1; i < Length; i++)
	{
		if (intervals[i][0] >= endTime)
		{
			ans++;
			endTime = intervals[i][1];
		}
	}
	return ans;
}
int main(void)
{
	vector<vector<int> > intervals = { {1,2},{2,3},{3,4},{1,3} };
	int ans = eraseOverlapIntervals02(intervals);//形参不能为引用，改变了形参的元素；或者其他函数不能再后面继续用intervals
	cout << ans << ' ';
	ans = eraseOverlapIntervals_answer(intervals);
	cout << ans << endl;

	intervals = { {1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2} };
	ans = eraseOverlapIntervals02(intervals);
	cout << ans << ' ';
	ans = eraseOverlapIntervals_answer(intervals);
	cout << ans << endl;

	return 0;
}