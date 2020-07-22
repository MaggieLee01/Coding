/*����һ���������� nums�����������������С�

���룺[5,2,3,1]
�����[1,2,3,5]

���룺[5,1,1,2,0,0]
�����[0,0,1,1,2,5]

https://leetcode-cn.com/problems/sort-an-array */

#include<vector>
#include<ctime>
//#include<cstdlib>
#include<algorithm>
using namespace std;

//���Ž�ָoffer�α������ƴ���
//���Źٷ���⣬��ϰ�˿��ŵ�ϸ�ڣ������õĿ���ָ�������֣����볢������ָ�룬û�ɣ�ֱ��������𰸵�ģ��
//int partition(vector<int>& nums, int left, int right)
//{
//	int temp = nums[right];
//	int i = left, j = right - 1;
//	while (i < j)
//	{
//		while (i < j && nums[i] <= temp)
//			i++;
//		while (i < j &&nums[j] >= temp)
//			j--;
//		if (nums[i] > nums[j])
//			swap(nums[i], nums[j]);
//	}	
//	swap(nums[i], nums.back());
//	return i;
//}

//jΪ�ƶ�ָ�룬iΪС��pivot����߽磬i����һ��ֵ������pivot�����Ե�j����С��ֵʱ������i=i+1;swap(nums[i],num[j])
int partition(vector<int>& nums, int left, int right)
{
	int pivot = nums[right];
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (nums[j] <= pivot)
		{
			i = i + 1;
			swap(nums[j], nums[i]);
		}
	}
	swap(nums[i + 1], nums[right]);
	return i + 1;
}
int randomized_partition(vector<int>& nums, int left, int right)
{
	int i = rand() % (right - left + 1) + left;//��left��ʼ��
	swap(nums[i], nums[right]);
	return partition(nums, left, right);
}

void fastsort(vector<int>& nums, int left, int right)
{
	//if (begin == end) return;
	if (left >= right) return;
	int index = randomized_partition(nums, left, right);
	fastsort(nums, left, index - 1);//���Ҿ��պϣ������ڶ��ַ��������ǵݹ�ѽ�����
	fastsort(nums, index + 1, right);
}
vector<int> sortArray(vector<int>& nums)
{
	srand((unsigned int)(time(NULL)));
	fastsort(nums, 0, nums.size() - 1);
	return nums;
}
int main(void)
{
	vector<int> num{ 5,1,1,2,0,0 };
	sortArray(num);
	return 0;
}