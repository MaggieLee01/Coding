/*面试题51. 数组中的逆序对

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。 
示例 1：输入: [7,5,6,4]；输出: 5
*/

#include<vector>
using namespace std;
//暴力算法超时，使用递归方法，看题解，官方，weiwei大佬
int mergeAndCount(vector<int>&nums, int left, int mid, int right, vector<int>&temp)
{
	for (int i = left; i <= right; i++)
		temp[i] = nums[i];
	int i = left, j = mid + 1;
	int count = 0;
	for (int k = left; k <= right; k++)
	{
		//下标访问，先判断是否越界
		if (i == mid + 1)
		{
			//nums[k] = nums[j]; j++;
			nums[k] = temp[j]; j++;			//temp提前存储了nums的变量，nums的值已经改变了呀，判断赋值都应该用temp
		}
		else if (j == right + 1)
		{
			nums[k] = temp[i]; i++;
		}
		else if (temp[i] <= temp[j])		//此处小于等于的话，是稳定排序
		{
			nums[k] = temp[i]; i++;
		}
		else
		{
			nums[k] = temp[j]; j++;

			//第二个区间归并回去的时候，则第一个区间剩余的数都比它大，因此计算此时的个数
			//计算个数的代码仅仅发生在此处
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

	//这个数组已经排好序，则无需合并
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

//看题解，还有树状数组的方法，暂时先不看





int main(void)
{
	vector<int> nums = { 7,5,6,4 };
	int ans = reversePairs(nums);
	return 0;
}