/*	输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
	序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

	输入：target = 9
	输出：[[2,3,4],[4,5]]

	输入：target = 15
	输出：[[1,2,3,4,5],[4,5,6],[7,8]]

	https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof */

#include<vector>
#include<algorithm>
#include<cmath>
using std::swap;
using std::vector;
using std::sort;

//bool compare(vector<int> a, vector<int> b)
//{
//	return a[0] < b[0]; //升序排列
//}
//vector<vector<int> > findContinuousSequence(int target) 
//{
//	vector< vector<int> > ans;
//	int squareRoot = (int)pow(target, 0.5);	
//	int temp = target;
//	
//	for (int m = 2; m <= target>>1; m++)
//	{
//		if (target % m == 0)
//		{
//			int i = m, cnt = 2;//不然交换之后该变i的大小了
//			int midSrc = target / i;
//			int mid = target / i;
//			if (mid % 2 == 0 && i % 2 == 0) continue;	//双偶数 不成立
//			if (mid % 2 == 1 && i % 2 == 0) swap(mid, i);
//			while (i % 2 == 1 && i / 2 < mid && cnt > 0)//i为奇数，且mid大于i，mid最有可能为中间数
//			{
//				vector<int> res(i, 0);
//				res[0] = mid - i / 2;
//				for (int j = 1; j < i; j++)
//					res[j] = res[j - 1] + 1;
//				ans.push_back(res);
//				swap(mid, i);
//				cnt--;
//				if (mid == i) break;
//			}	
//			//i为偶数，则i对，个数2*i，中间两数和为mid
//			if (m % 2 == 0 && m <= midSrc / 2)
//			{
//				vector<int> res(2 * m, 0);
//				res[0] = midSrc/ 2 + 1 - m;
//				for (int j = 1; j < 2 * m; j++)
//					res[j] = res[j - 1] + 1;
//				ans.push_back(res);				
//			}			
//		}
//	}
//	if (target % 2 == 1)
//		ans.push_back({ target / 2,target / 2 + 1 });
//	sort(ans.begin(), ans.end(), compare);
//	return ans;
//}

//一开始指向这奇数个数，例如35=7*5；看到10的情况意识到，可以一奇一偶
//上面的方法找出的数组有限，例如：93；输出：[[30, 31, 32], [46, 47]]；预期：[[13, 14, 15, 16, 17, 18], [30, 31, 32], [46, 47]]
//上面的思路不对，这个题基础方法滑动窗口，暴力写法我的也不对
//看了题解，有暴力方法，数学公式方法：求根法、间隔法
//哎，看到有序 而且 连续数组 ，应该想到滑动窗口呀
vector<vector<int> > findContinuousSequence_answer01(int target)
{
	int left = 1, right = 2;
	vector< vector<int> > ans;
	if (target == 1) ans.push_back({ 1 });
	while (left < right &&  left <= target >> 1)
	{
		int result = ((left + right)*(right - left + 1)) / 2;
		if (result == target)
		{
			vector<int> res;
			for (int i = left; i <= right; i++)
				res.push_back(i);
			ans.push_back(res);
			left++;
		}
		if (result < target)		
			right++;		
		else if (result > target)
			left++;
	}
	return ans;
}
//滑动窗口可以一直跟进sum的计算，窗口滑动时sum即变化；不用专门求和公式

//再看题解，
// https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/gen-ju-qu-jian-chang-du-qiu-jie-by-suibianfahui/
//这个和我的想法很类似，为啥我一直写不对？？？

//我的误区：开始执拗于在寻找因子遍历条件截止于根号下，然后就需要交换两个因子，例如5*7这种，
//这个时候就需要考虑那个是奇数哪个是偶数，交换之后，改变了遍历的i，一直在处理交换带来的影响
//去掉交换之后，发现了更严重的误区，寻找完因子之后，我执拗于寻找中位数，这是一个误区，
//例如：93；输出：[[30, 31, 32], [46, 47]]；预期：[[13, 14, 15, 16, 17, 18], [30, 31, 32], [46, 47]]
//输入93， 我只能通过因子得到中位数为31的数组与46的数组，我无法得到13开头的数组，因此，题解中，该方法，是首先寻找数组长度

//如果le为奇数, 那么target%le应该为0才可以, 而target//le即为最中心的数字
//如果le为偶数, 那么target / le应该为x.5, 也即(target + le//2)%le需要为0

vector<vector<int> > findContinuousSequence(int target)
{
	vector< vector<int> > ans;
	int start = 0;
	//for (int i = 2; i < (target >> 1) + 1; i++) 为了使结果从小到大，则长度从大到小
	for (int i = (target >> 1) + 1; i > 1; i--)
	{
		if ((i & 1) == 1 && target % i == 0)//用位运算判断奇数
			start = target / i - (i >> 1);

		//if ((i & 1) == 0 && ((target + (i >> 1)) % i == 0) )
		//乘除取模 加减 左右移 大于小于 == 位与 位异或 位或 逻辑与 逻辑或
		//注意此处用到很多（）,位与 优先级竟然在==的后面，位与在优先级方面易出错，位运算在==后，在逻辑与前
		if (i % 2 == 0 && (target + i /2 ) % i == 0 )//注意此处用到很多（）,位与 优先级竟然在==的后面
			start = target / i - (i >> 1) + 1;
		if (start > 0)
		{
			vector<int> findSeq(i, 0);
			findSeq[0] = start;
			for (int j = 1; j < i; j++)
				findSeq[j] = findSeq[j - 1] + 1;
			ans.push_back(findSeq);
			start = 0;
		}
		else continue;
	}
	return ans;
}
//还提到一种削尖的新方法
//https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/san-chong-fang-fa-cong-jian-dao-fan-zai-dao-jian-b/
//https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/java-shuang-100-by-vapormax/
//找到了这个，和我的思路一模一样，我没考虑到偶数个数的中位数问题
//https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/cchun-shu-xue-bu-jie-er-ci-fang-cheng-100nei-cun-s/
int main(void)
{
	vector< vector<int> > ans = findContinuousSequence(35);
	ans = findContinuousSequence(81);

	ans = findContinuousSequence(10);
	ans = findContinuousSequence(20);
	return 0;
}