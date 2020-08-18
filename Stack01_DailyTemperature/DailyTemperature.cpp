// https://mp.weixin.qq.com/s/_b_QzXkL4e0y5241betVSg 2019-05-10
//根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。
//例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是[1, 1, 4, 2, 1, 1, 0, 0]。
//提示：气温 列表长度的范围是[1, 30000]。每个气温的值的均为华氏度，都是在[30, 100] 范围内的整数。
// https://leetcode-cn.com/problems/daily-temperatures
//单调栈一般用于求取下一个最大值的情况

#include<vector>
#include<stack>
#include<algorithm>
using std::vector;
using std::max;
using std::stack;

//处理的难点：数组中有重复元素：重复元素有间隔、重复元素为最大值
vector<int> dailyTemperatures(vector<int>& T)
{
	int Length = T.size();
	vector<int> ans(Length, 0);
	if (Length < 1) return ans; //已经压入栈一个元素了，必须有
	//栈里面存索引比存储对应的具体数据更易于操作，不然很难找到栈中元素在数组中的位置
	stack<int> MaxTemp;
	MaxTemp.push(Length - 1);
	for (int i = Length - 2; i >= 0; i--)//下一个最大值，所以应该倒序遍历
	{
		int NextMax = MaxTemp.top();
		/*if (T[NextMax] == T[i])
		{
			if (MaxTemp.size() == 1)
			{
				ans[i] = 0;
				continue;
			}
			else
			{
				MaxTemp.pop();
				NextMax = MaxTemp.top();
			}
		}*/
		while (T[NextMax] <= T[i])//开始把< =情况分开了，写不顺溜
		{
			MaxTemp.pop();
			if (MaxTemp.empty() == 1)
			{
				MaxTemp.push(i);
				NextMax = MaxTemp.top();
				break;
			}
			NextMax = MaxTemp.top();
		}
		ans[i] = NextMax - i;//top为下一个最大元素的索引值，-i为等待的天数
		if (T[NextMax] > T[i])
			MaxTemp.push(i);
	}
	return ans;
}
//看了答案，思路一样，但是上面写麻烦了，可读性不如下面的框架，上面直接用top()函数的话好像还行
vector<int> dailyTemperatures_answer(vector<int>& T)
{
	int Length = T.size();
	vector<int> ans(Length, 0);
	stack<int> NextMax;
	for (int i = Length - 1; i >= 0; i--)
	{
		while (!NextMax.empty() && T[i] >= T[NextMax.top()])
			NextMax.pop();
		if (NextMax.empty())  //ans数组已经初始化为-1，只需在栈不为空的情况下赋值即可
			ans[i] = 0;
		else
			ans[i] = NextMax.top() - i;
		NextMax.push(i);
	}
	return ans;
}
int main(void)
{
	vector<int> num = { 73, 74, 75, 71, 69, 72, 76, 73 };
	num = dailyTemperatures(num);

	num = { 10,9,8,7,6,5,4,3,2,1 };
	num = dailyTemperatures(num);

	num = { 89,62,70,58,47,47,46,76,100,70 };
	num = dailyTemperatures(num);

	num = { 34,80,80,34,34,80,80,80,80,34 };
	num = dailyTemperatures(num);
	return 0;
}