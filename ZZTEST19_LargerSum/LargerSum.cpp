//富途的面试题
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<vector<int>> LargerSum(vector<int> nums, int larger)
{
	if (nums.size() == 0) return {};
	sort(nums.begin(), nums.end());

	int left = 0;
	int right = nums.size() - 1;

	vector<vector<int>>ans;
	while (left < right)
	{
		if (nums[left] + nums[right] > 8)//找到两数之和大于目标的范围，则两数之间的均符合要求
		{
			int temp = left;
			while (temp < right)
			{
				ans.push_back({ nums[temp],nums[right] });
				temp++;
			}			
			right--;
		}			
		else
			left++;
	}
	return ans;
}
int main(void)
{
	vector<int> nums = { 1,5,7,2,4 };
	vector<vector<int>> ans = LargerSum(nums, 8);
	return 0;
}


class RWQueue
{
private:
	static queue<string> q;
public:	
	string read(void)
	{
		string temp = q.front();
		q.pop();
		return temp;
	}
private:
	static void write(string s)
	{
		q.push(s);
	}
};
