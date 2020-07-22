/*������51. �����е������

�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ�����飬�����������е�����Ե������� 
ʾ�� 1������: [7,5,6,4]�����: 5
*/

#include<vector>
using namespace std;
//�����㷨��ʱ��ʹ�õݹ鷽��������⣬�ٷ���weiwei����
int mergeAndCount(vector<int>&nums, int left, int mid, int right, vector<int>&temp)
{
	for (int i = left; i <= right; i++)
		temp[i] = nums[i];
	int i = left, j = mid + 1;
	int count = 0;
	for (int k = left; k <= right; k++)
	{
		//�±���ʣ����ж��Ƿ�Խ��
		if (i == mid + 1)
		{
			//nums[k] = nums[j]; j++;
			nums[k] = temp[j]; j++;			//temp��ǰ�洢��nums�ı�����nums��ֵ�Ѿ��ı���ѽ���жϸ�ֵ��Ӧ����temp
		}
		else if (j == right + 1)
		{
			nums[k] = temp[i]; i++;
		}
		else if (temp[i] <= temp[j])		//�˴�С�ڵ��ڵĻ������ȶ�����
		{
			nums[k] = temp[i]; i++;
		}
		else
		{
			nums[k] = temp[j]; j++;

			//�ڶ�������鲢��ȥ��ʱ�����һ������ʣ���������������˼����ʱ�ĸ���
			//��������Ĵ�����������ڴ˴�
			count += mid - i + 1;
		}
	}
	return count;
}
int reversePairsCore(vector<int>& nums, int left, int right, vector<int>&temp)
{
	if (left == right) return 0;
	int mid = (right - left) / 2 + left;
	int leftPairs = reversePairsCore(nums, left, mid, temp);
	int rightPairs = reversePairsCore(nums, mid+1, right, temp);

	//��������Ѿ��ź���������ϲ�
	if (nums[mid] < nums[mid + 1]) return leftPairs + rightPairs;

	int crossPairs = mergeAndCount(nums, left, mid, right, temp);
	return crossPairs + leftPairs + rightPairs;
}
int reversePairs(vector<int>& nums)
{
	int size = nums.size();
	if (size < 2) return 0;

	vector<int> copy(nums);
	vector<int> temp(size, 0);
	return reversePairsCore(copy, 0, size - 1, temp);	
}

//����⣬������״����ķ�������ʱ�Ȳ���





int main(void)
{
	vector<int> nums = { 7,5,6,4 };
	int ans = reversePairs(nums);
	return 0;
}