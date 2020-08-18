/*����һ���������� nums�����������������С�

���룺[5,2,3,1]
�����[1,2,3,5]

���룺[5,1,1,2,0,0]
�����[0,0,1,1,2,5]

https://leetcode-cn.com/problems/sort-an-array */

//���ٷ���⣬������ģ��
#include<vector>
#include<algorithm>
using namespace std;

void maxHeapify(vector<int>& nums, int index, int right)
{
	for (; (index << 1) + 1 <= right;)
	{
		int leftson = (index << 1) + 1;
		int rightson = (index << 1) + 2;
		int max = index;
		if (leftson <= right && nums[leftson] > nums[max])
			max = leftson;
		if (rightson <= right && nums[rightson] > nums[max])//rightΪ���һ������һ����С�ڵ���
			max = rightson;//ʹ��maxΪ�������ֵ������
		if (max != index)//ʹ��index����Ԫ���������������
		{
			swap(nums[max], nums[index]);
			index = max;
		}
		else break;//����Ѿ�������˳���������Ѿ���������������䶯
	}
}
void buildMaxHeap(vector<int>& nums, int right)
{
	for (int i = right >> 1; i >= 0; i--)
		maxHeapify(nums, i, right);
}
void heapSort(vector<int>& nums)
{
	int right = nums.size() - 1;
	buildMaxHeap(nums, right);
	for (int i = right; i >= 0; i--)
	{
		swap(nums[i], nums[0]);
		right--;
		maxHeapify(nums, 0, right);
	}
}
vector<int> sortArray(vector<int>& nums)
{
	heapSort(nums);
	return nums;
}
int main(void)
{
	vector<int> num{ 5,1,1,2,0,0 };
	sortArray(num);
	return 0;
}