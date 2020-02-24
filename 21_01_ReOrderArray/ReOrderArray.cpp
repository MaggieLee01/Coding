// ������21����������˳��ʹ����λ��ż��ǰ��
// ��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ������
// ����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�

#include<vector>
#include<algorithm>
using std::vector;

bool isOdd(int num)
{
	return num & 01;//����ż����λ����
}
vector<int> exchange(vector<int>& nums) 
{
	int Length = nums.size();
	if (Length <= 1) return nums;

	int i = 0, j = Length - 1;	
	while (i <= j)
	{
		while (i < Length && isOdd(nums[i]))//һ��Ҫ���ж�i�ĳ���д��ǰ�� ��֤nums[i]�����壬������i<jҲ����
			i++;
		while (j >= 0 && !isOdd(nums[j]))
			j--;

		if (i < j)
		{
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}
	return nums;                                                                                     
}
//�����鱾�𰸣��漰������ָ�� �����
//���������������������ָ��֮�⻹�п���ָ�룬��˫ָ�����ϰ��
// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/solution/ti-jie-shou-wei-shuang-zhi-zhen-kuai-man-shuang-zh/
//���Կ���ָ�룬����һ��ָ������ һ��ָ��ż��
vector<int> exchange_FastPointer(vector<int>& nums)
{
	int Length = nums.size();
	if (Length <= 1) return nums;

	int fast = 0, low = 0;
	for (fast = 0; fast < Length; fast++)
	{
		if (nums[fast] & 01 == 1)//����������ǰ��
		{
			std::swap(nums[fast], nums[low]);
			low++;
		}
	}
	return nums;
}


int main(void)
{
	vector<int> nums{ 1,2,3,4,5,6,7,8,9 };
	exchange_FastPointer(nums);
	nums = { 1,3,5,7,9,0,2,4,6,8 };
	exchange_FastPointer(nums);
	nums = { 1,3,5,7,9 };
	exchange_FastPointer(nums);
	nums = { 0,2,4,6,8 };
	exchange_FastPointer(nums);
}

