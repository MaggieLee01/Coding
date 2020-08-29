//假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
//https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
 
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


////只能买卖一次，
//int maxProfit(vector<int>& prices)
//{
//	if (prices.size() == 0) return 0;
//	int sell = 0;
//	int ans = 0;
//	for (int i = prices.size(); i >= 0; i--)
//	{
//		sell = max(sell, prices[i]);
//		ans = max(sell - prices[i], ans);
//	}
//	return ans;
//}
//
////状态机的方法
//int maxProfit01(vector<int>& prices)
//{
//	if (prices.size() == 0) return 0;
//	int i_0=0,i_1=-
//}

stack<int> get_num(vector<int> nums)
{
	stack<int> stk;
	int length = nums.size();
	if (length == 0) return stk;
	
	bool is_same = false;
	for (int i = 0; i < length; i++)
	{
		if (stk.size() && stk.top() == nums[i])
		{
			is_same = true;
		}
		else if (is_same)
		{
			stk.pop();
			is_same = false;
			i--;
		}
		else
			stk.push(nums[i]);
	}
	return stk;
}

int main(void)
{
	vector<int> ans = { 1,3,5,5,5,3,4,6,6,7,4 };
	get_num(ans);
}