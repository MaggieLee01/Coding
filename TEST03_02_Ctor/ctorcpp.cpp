#include<vector>
using namespace std;

vector<int> find(vector<int> nums,int target)
{
	int left = 0;
	int right = nums.size()-1;
	vector<int> ans;
	while (left < right)
	{
		int mid = (right - left) / 2 + left;
		if (nums[mid] < target)
			left = mid + 1;
		else 
			right = mid;
	}
	if (nums[left] == target) 
		ans.push_back(left);
	else 
		return ans;

	while (nums[left++] != target);
	ans.push_back(left - 1);
	return ans;
}
int main(void)
{
	vector<int> nums = { 1,1,1,2,2,2,3,4,5,6 };
	vector<int> ans = find(nums, 1);
	return 0;
}