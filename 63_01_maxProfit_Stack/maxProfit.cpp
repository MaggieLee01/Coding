//�����ĳ��Ʊ�ļ۸���ʱ���Ⱥ�˳��洢�������У����������ù�Ʊһ�ο��ܻ�õ���������Ƕ��٣�
//https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
 
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


////ֻ������һ�Σ�
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
////״̬���ķ���
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