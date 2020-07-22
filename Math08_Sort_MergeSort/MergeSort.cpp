/*����һ���������� nums�����������������С�

���룺[5,2,3,1]
�����[1,2,3,5]

���룺[5,1,1,2,0,0]
�����[0,0,1,1,2,5]

https://leetcode-cn.com/problems/sort-an-array */

//���ٷ���⣬������ģ�壬��ͨ������
#include<vector>
#include<algorithm>
using namespace std;

vector<int> tmp;
void MergeSort(vector<int> &nums,int left,int right)
{
	if (left >= right) return;//�����жϽ�ֹ�����ģ����ô��ڵ��� �Ͳ��� ����
	int mid = (right - left) / 2 + left;
	MergeSort(nums, left, mid);
	MergeSort(nums, mid + 1, right);
	//��ʼ�ϲ�
	int i = left;
	int j = mid + 1;
	int cnt = 0;
	while (i <= mid && j <= right)
	{
		if (nums[i] <= nums[j])	//�˴�С�ڵ��ڵĻ��������ȶ�����
			tmp[cnt++] = nums[i++];
		else
			tmp[cnt++] = nums[j++];
	}
	while (i <= mid) tmp[cnt++] = nums[i++];
	while (j <= right) tmp[cnt++] = nums[j++];

	for (int i = 0; i < right - left + 1; i++)//ע��˴��ĸ�ֵ
		nums[i + left] = tmp[i];	
}
vector<int> SortArray(vector<int>& nums)
{
	tmp.resize((int)nums.size(), 0);//ע��ȫ�ֱ�����ʹ��
	MergeSort(nums, 0, nums.size() - 1);
	return nums;
}
int main(void)
{
	vector<int> num{ 5,1,1,2,0,0 };
	SortArray(num);
	return 0;
}