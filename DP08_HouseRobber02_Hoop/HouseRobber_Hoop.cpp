//��ҽ���ϵ������02�������������ڷ��䣬������Ȼ��һ�����飬������Щ���Ӳ���һ�ţ�����Χ����һ��Ȧ���������ٵ����ֵ
//2019-12-19
//����LeetCode������OK

//Ҳ����β����ͬʱ����
//���ٵ�һ�ң�nums[0]..[size-2]
//�����ٵ�һ�ң�nums[1]...[size-1]
//˼�����͵���ջ��ʲô��ϵ���������
//˼·���������֣��ȽϽ������Ҳ�ǣ�����û���ֺ͵���ջ��ʲô��ϵ

#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::max;

int Rob_dp_Hoop(vector<int> nums)
{
	int Length = nums.size();
	//VS ���ж� -1 < 0 ���Ѳ���
	//if (Length == 0) return 0;//��Ȼforѭ�������-1

	//��Ҫ����һ�����������ʱû�н���forѭ����ansΪ��ʼ����ֵ
	if (Length == 1) return nums[0];
	int ans = max(Rob_dp(nums, 0, Length - 2), Rob_dp(nums, 1, Length - 1));
	return ans;
}
int Rob_dp(vector<int> nums, int start, int end)
{
	int dp_1 = 0, dp_2 = 0;
	int ans = 0;
	for (int i = end; i >= start; i--)
	{
		ans = max(nums[i] + dp_2, dp_1);
		dp_2 = dp_1;
		dp_1 = ans;
	}
	return ans;
}