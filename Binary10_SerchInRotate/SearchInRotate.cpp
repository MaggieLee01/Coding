/*33. ������ת��������

���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��
( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��
����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻� -1 ��
����Լ��������в������ظ���Ԫ�ء�
����㷨ʱ�临�Ӷȱ����� O(log n) ����

ʾ�� 1:
����: nums = [4,5,6,7,0,1,2], target = 0
���: 4

ʾ�� 2:
����: nums = [4,5,6,7,0,1,2], target = 3
���: -1
*/

#include<vector>
using namespace std;
//https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/yi-wen-jie-jue-4-dao-sou-suo-xuan-zhuan-pai-xu-s-2/

int search(vector<int>& nums, int target) 
{
	int left = 0, right = nums.size();
	while (left < right)
	{
		int mid = (right - left) / 2 + left;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
		{
			if (mid + 1 < nums.size() && nums[mid] < nums[mid + 1])//midΪ����ȡ��������mid+1һ�������ݣ�������
				left = mid + 1;
			else right = mid;
		}
		else
		{
			if (nums[mid] < nums[mid + 1]) right = mid;
			else left = mid + 1;
		}
	}
	return -1;
}
int main(void)
{
	vector<int> nums = { 4,5,6,7,0,1,2 };
	int ans = search(nums, 3);
	return 0;
}