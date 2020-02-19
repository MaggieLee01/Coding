/*传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。
我们装载的重量不会超过船的最大运载重量。
返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。
https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days
*/

//2019-10-29 https://mp.weixin.qq.com/s/QC24hyg0ZgjR7-LgnEzMYg 
//根据上一题吃香蕉的思路，二分法的范围，数组的最大值到数组的和

#include<vector>
#include<algorithm>
using std::max;
using std::min;
using std::vector;
//自己写的，OK，思路：统计运载能力为load时，运载全部包裹所需的天数，如果已经大于D，直接break
//答案更简洁一些，思路：统计运载能力为load时，D天能运载的包裹数
//bool Canbeship(vector<int>&weight, int D, int load)
//{
//	int surplus = load-weight[0];
//	int day = 1;
//	int Length = weight.size();
//	for (int i = 0; i < Length - 1; i++)//倒数第一个不用遍历，必须加上1，放在了day的起始值
//	{
//		surplus -= weight[i+1];
//		if (surplus < 0)
//		{
//			day++;
//			surplus = load - weight[i + 1];
//		}		
//		if (day > D)
//			break;
//	}
//	return (day <= D);
//}

//计算D天内能运载的包裹数
bool CanFinish(vector<int>&weight, int D, int load)
{
	int pack = 0;
	for (int i = 0; i < D; i++)
	{
		int maxload = load;
		while ((maxload -= weight[pack]) >= 0)   //一个while循环得出：pack下一个的包裹需要等下一次传送
		{
			pack++;
			if (pack == weight.size()) return true;
		}
	}
	return false;
}

int shipWithinDays(vector<int>& weights, int D) 
{
	int Length = weights.size();
	if (Length == 0) return 0;
	int max = 0, sum = 0;
	for (auto temp : weights)
	{
		sum += temp;
		if (max < temp)	max = temp;
	}

	int left = max;
	int right = sum;
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (CanFinish(weights, D, mid))
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
int main(void)
{
	vector<int> weights = { 1,2,3,4,5,6,7,8,9,10 };
	bool n = CanFinish(weights, 5, 14);
	n = CanFinish(weights, 5, 15);
	int m = shipWithinDays(weights, 5);

	weights = { 3,2,2,4,1,4 };
	n = CanFinish(weights, 3, 6);
	n = CanFinish(weights, 3, 5);
	m = shipWithinDays(weights, 3);
	return 0;
}