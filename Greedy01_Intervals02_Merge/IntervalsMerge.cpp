//给出一个区间的集合，请合并所有重叠的区间。
//leetcode 56
//区间问题之合并相交区间 https://mp.weixin.qq.com/s/dlgmFyONFX0GDpmqFWCIEA
#include<vector>
#include<algorithm>

using std::vector;
using std::max;

static bool EndTimeCmp(vector<int> interval1, vector<int> interval2)
{
	return (interval1[0] < interval2[0]);
}

/***********************************************************************************************************************/
//自己写，较费时
vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	int Length = intervals.size();
	if (Length <= 1) return intervals;
	std::sort(intervals.begin(), intervals.end(), EndTimeCmp);
	for (int i = 0; i < intervals.size(); i++)
	{
		for (int j = i + 1; j < intervals.size(); j++)
		{
			//可以和下面的if合并
			/*if (intervals[j][1] <= intervals[i][1])
			{
				intervals.erase(intervals.begin() + j);
				j--;
			}	*/

			if (intervals[j][0] <= intervals[i][1])
			{
				intervals[i][1] = max(intervals[i][1], intervals[j][1]);
				intervals.erase(intervals.begin() + j);
				j--;
			}
			if (intervals[j][0] > intervals[i][1])
				break;
		}
	}
	return intervals;
}
/***********************************************************************************************************************/
//看答案，不是修改输入的数组，是额外定义了一个存储数组
//vector的back函数，最后一个元素的引用
vector<vector<int>> merge01(vector<vector<int>>& intervals)
{
	int Length = intervals.size();
	if (Length <= 1) return intervals;
	std::sort(intervals.begin(), intervals.end(), EndTimeCmp);
	vector<vector<int>> ans;
	ans.push_back(intervals[0]);
	int endTime = intervals[0][1];
	for (int i = 0; i < Length; i++)
	{
		if (intervals[i][0] <= endTime)
			ans.back()[1] = max(intervals[i][1], endTime);
		if (intervals[i][0] > endTime)
			ans.push_back(intervals[i]);
		endTime = ans.back()[1];
	}
	return ans;
}

/***********************************************************************************************************************/
//特殊测试  一个元素 0个元素 元素相同
int main(void)
{
	vector<vector<int>> test1 = { {1,3},{2,6},{8,10},{15,18} };
	merge01(test1);

	test1 = { {1,3},{1,3},{1,3},{1,3} };
	merge01(test1);

	test1 = { {1,3},{2,6},{8,16},{15,18} };
	merge01(test1);
	return 0;
}