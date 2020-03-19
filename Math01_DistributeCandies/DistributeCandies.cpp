/*排排坐，分糖果。

我们买了一些糖果 candies，打算把它们分给排好队的 n = num_people 个小朋友。

给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果。
然后，我们再回到队伍的起点，给第一个小朋友 n + 1 颗糖果，第二个小朋友 n + 2 颗，依此类推，直到给最后一个小朋友 2 * n 颗糖果。
重复上述过程（每次都比上一次多给出一颗糖果，当到达队伍终点后再次从队伍起点开始），直到我们分完所有的糖果。注意，就算我们手中的剩下糖果数不够（不比前一次发出的糖果多），这些糖果也会全部发给当前的小朋友。
返回一个长度为 num_people、元素之和为 candies 的数组，以表示糖果的最终分发情况（即 ans[i] 表示第 i 个小朋友分到的糖果数）。

输入：candies = 7, num_people = 4
输出：[1,2,3,1]
解释：
第一次，ans[0] += 1，数组变为 [1,0,0,0]。
第二次，ans[1] += 2，数组变为 [1,2,0,0]。
第三次，ans[2] += 3，数组变为 [1,2,3,0]。
第四次，ans[3] += 1（因为此时只剩下 1 颗糖果），最终数组变为 [1,2,3,1]。

 https://leetcode-cn.com/problems/distribute-candies-to-people */

#include<vector>
#include<algorithm>
using std::min;
using std::vector;
//借鉴之前取模模拟环形数组的方法尝试
vector<int> distributeCandies(int candies, int num_people) 
{	
	vector<int> ans(num_people, 0);	
	int i = 0, need = 0;
	while (candies > 0)
	{
		//int need = ans[(i - 1) % num_people] + 1;//ans数组中是多次分发的和，此次是在上一次的分发基础上加一
		need += 1;
		if (need >= candies)
		{
			ans[i % num_people] += candies;
			break;
		}
		ans[i % num_people] += need;
		candies -= need;
		i++;
	}
	return ans;
}
//看了题解，这属于暴力法，自己写麻烦了呀，need不就是i+1吗？一个变量就可以了
vector<int> distributeCandies(int candies, int num_people)
{
	vector<int> ans(num_people, 0);
	int i = 0;
	while (candies > 0)
	{
		ans[i%num_people] = min(candies, i + 1);
		candies -= (i + 1);
		i++;
	}
	return ans;
}
//官方题解还给出了数学公式题解，利用等差数列，除数余数等数学特点；
//和14_01_CuttingRope的剪绳子中数学方法差不多，最后一轮前一半人和后一半人分配法不一样，截止点通过求余数得到
int main(void)
{
	vector<int> ans = distributeCandies(10, 3);
	ans = distributeCandies(10, 3);
	ans = distributeCandies(60, 4);
	return 0;
}