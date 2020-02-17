//leetcode 354  leetcode-cn.com/problems/russian-doll-envelopes
//2019-08-05 https://mp.weixin.qq.com/s/PSDCjKlTh8MtANdgi-QIug
//给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。
//当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
//请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。不允许旋转信封。
/*	输入: envelopes = [[5, 4], [6, 4], [6, 7], [2, 3]]
	输出 : 3
	解释 : 最多信封的个数为 3, 组合为 : [2, 3] = > [5, 4] = > [6, 7]。*/
//已通过LeetCode测试

#include<vector>
#include<algorithm>
using std::vector;

/*只思考到对第一个元素排序，在答案提示下才意识到第一个元素相同的情况下第二个元素降序排列
因为两个宽度相同的信封不能相互包含的，而逆序排序保证在w相同的数对中最多只选取一个计入 LIS。*/
//例如，对于，{5,4},{6,4},{6,7},{2,3}，第二个元素不降序的话，结果就为4了

//不断进行特殊测试的调试下，坑坑巴巴写完了。扑克牌二分法边回忆变调试

//这种条件排序怎么写，以下两种都可以
static bool WidthSort(vector<int> envelope1, vector<int> envelope2)
{
	if (envelope1[0] == envelope2[0])
		return envelope1[1] > envelope2[1];
	return (envelope1[0] < envelope2[0]);
}
//static bool WidthSort(vector<int> envelope1, vector<int> envelope2)
//{
//	return (envelope1[0] < envelope2[0]) || (envelope1[0] == envelope2[0] && envelope1[1] > envelope2[1]);
//}

//扑克牌二分法
int maxEnvelopes(vector<vector<int>>& envelopes) 
{
	int Length = envelopes.size();
	if (Length <= 1) return Length;
	std::sort(envelopes.begin(), envelopes.end(), WidthSort);
	vector<int> poke(Length, 0);

	//初始化先保证有一个元素
	poke[0] = envelopes[0][1];
	int ans = 1;	
	
	for (auto envelop : envelopes)
	{
		int target = envelop[1];
		int left = 0;
		int right = ans - 1;//只有前面的有序，后面的都是0
		
		while (left <= right)
		{
			int mid = ((right - left) >> 1) + left;//左移一位时不加（）,计算不正确
			if (target == poke[mid])
				right = mid - 1;
			else if (target < poke[mid])
				right = mid - 1;
			else if (target > poke[mid])
				left = mid + 1;
		}
		/*if (left == ans)
		{
			poke[ans] = target;
			ans++;
		}
		else poke[left] = target;*/

		//合并代码
		if (left == ans)
			ans++;
		poke[left] = target;
	}
	return ans;
}
int main(void)
{
	vector<vector<int>> envelopes = { {5,4},{5,4},{5,4} };
	int ans = maxEnvelopes(envelopes);

	envelopes = { {5,4},{6,4},{6,7},{2,3} };
	ans = maxEnvelopes(envelopes);
}
	