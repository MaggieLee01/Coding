#include<iostream>
#include<vector>
#include<stack>
#include<deque>
#include<algorithm>
using namespace std;

//int main(void)
//{
//	int num = 0;
//	cin >> num;
//	vector<int> box(num, 0);
//	for (int i = 0; i < num; i++)
//	{
//		cin >> box[i];
//	}
//	sort(box.begin(), box.end());
//	int next = 0;
//	for (int i = 1; i < num; i++)
//	{
//		if (box[i] == box[i - 1])
//		{
//			int j = i;
//			int temp = box[i];
//			while (++temp >= box[++j])
//				next = j;
//		}
//	}
//
//}

bool comp(double a, double b)
{
	return (a - b) < 0.00000001;
}
double Getmax(vector<int> nums)
{
	if (nums.size() < 2) return -1;
	stack<int> s;//单调递减栈，存放索引
	double ans = INT_MAX;
	int max = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		while (s.size() && nums[s.top()] < nums[i])
			s.pop();
		if (s.empty()) max = nums[i];
		s.push(i);
		if (s.size() > 1)
		{
			double b = (double)nums[s.top()] / (double)max;
			ans = comp(ans, b) ? ans : b;
		}
	}
	return 1 - ans;
}

// j-i <= k ，k > 0
double Getmax01(vector<int> nums, int k)
{
	if (nums.size() < 2) return -1;
	deque<int> dq;			//存放索引，头部到尾部单调递减，
	double ans = INT_MAX;

	for (int i = 0; i < nums.size(); i++)
	{
		while (dq.size() && nums[dq.back()] < nums[i])
			dq.pop_back();
		dq.push_back(i);

		while (dq.back() - dq.front() > k)
			dq.pop_front();
		if (dq.size() > 1)
		{
			double b = (double)nums[dq.back()] / (double)nums[dq.front()];
			ans = comp(ans, b) ? ans : b;
		}
	}
	return 1 - ans;
}

int main(void)
{
	vector<int> nums{ 8,9,2,5,6,7,3 };
	vector<int> nums1{ 1,2,3,4,5,6 };
	vector<int> nums2{ 6,5,4,3,2,1,10,6,7,4,1 };
	double ans = Getmax(nums2);
	double ans1 = Getmax01(nums2, 3);
	return 0;
}