//打家劫舍系列问题01：不能抢劫相邻房间的物品，求能抢劫的最大值
//2019-12-19
//在距离编辑上面掉过太多坑之后，这次coding顺利一些，没有太多麻烦
//前两种方法在LeetCode中文网超时，后两种OK

#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::max;

//独立尝试递归
//关键点，比较是否抢劫该房间的大小，取最大值

//本来参数想用vector，但是不知道，如何表示vector的指针向后移动？？？所以改用int *类型
//不不，单纯的指针不行，无法判断数组是否结束
//暂时解决vector指针移动方法：增加一个参数表示索引
int Rob_Traversal(vector<int> nums, int n)
{
	//递归找停止条件
	/*if (nums.size() == n) return 0;
	if (nums.size() - 1 == n) return nums[n];*/
	//依据参考答案修改
	if (n >= nums.size()) return 0;
	//分别表示 抢劫第一家 与 不抢劫第一家
	int ans = max(nums[n] + Rob_Traversal(nums, n + 2),
				Rob_Traversal(nums, n + 1)	);
	return ans;
}
int Rob_recursively(vector<int> nums)
{
	return Rob_Traversal(nums,0);
}

//改用备忘录形式
//此方法在LeetCode中文网超时，更不用说，递归的方法了
int ConsultDict(vector<int> nums, int n, vector<int> & Dict)
{
	/*if (n == nums.size()) return 0;
	if (n == nums.size() - 1) return nums[n];*/
	//直接将前面两个条件包括了，第二个判断就是为了防止在结束的第二位，在数组中溢出，
	//用==没有包括第二种情况，所以写了第二个判断，直接用>=将两种情况包括了
	if (n >= nums.size()) return 0;

	if (Dict[n] != 0) return Dict[n];
	Dict[n] = max(nums[n] + ConsultDict(nums, n + 2, Dict),
				ConsultDict(nums, n + 1, Dict) );
	return Dict[n];
}
int Rob_Dict(vector<int> nums)
{
	int Length = nums.size();
	vector<int> Dict(Length + 1, 0);
	int ans = ConsultDict(nums, 0, Dict);
	return ans;
}

//改用dp形式
int Rob_dp(vector<int> nums)
{
	int Length = nums.size();
	if (Length == 0) return 0;//为空的情况不要忘记
	if (Length == 1) return nums[0];//此处相当于base case 的特殊情况，不然base case 会出错
	vector<int> Dict(Length + 1, 0);
	Dict[0] = nums[0];
	Dict[1] = max(nums[0], nums[1]);
	for (int i = 2; i < Length; i++)
		Dict[i] = max(nums[i] + Dict[i - 2], Dict[i - 1]);
	return Dict[Length - 1];
}
//看答案的dp形式，倒着遍历，前两个初始化为0
int Rob_dp_answer(vector<int> nums)
{
	int Length = nums.size();
	//见测试程序
	//if (Length == 0) return 0;//不然for循环变成了-1
	vector<int> Dict(Length + 2, 0);
	for (int i = Length - 1; i >= 0; i--)
		Dict[i] = max(nums[i] + Dict[i + 2], Dict[i + 1]);
	return Dict[0];
}

//dp中只与前两个有关，可以降维
int Rob_dp_Dimension(vector<int> nums)
{
	int Length = nums.size();
	if (Length == 0) return 0;//为空的情况不要忘记
	if (Length == 1) return nums[0];//此处相当于base case 的特殊情况
	if (Length == 2) return max(nums[0],nums[1]);//由于降维，此处无法进入for循环

	int first = nums[0];	
	int second = max(nums[0], nums[1]);
	int ans = 0;
	for (int i = 2; i < Length; i++)
	{
		ans = max(nums[i] + first, second);
		first = second;
		second = ans;
	}
	return ans;
}
//看答案的dp形式，倒着遍历，前两个初始化为0，不用在前面增加那么多的判断条件
int Rob_dp_Dimension_answer(vector<int> nums)
{	
	int Length = nums.size();
	//LeetCode中文网 能判断 -1 < 0
	//已测试，VS也能判断 -1 < 0
	//所以，下面的没必要
	//if (Length == 0) return 0;//不然for循环变成了-1，-1 > 0
	int dp_1 = 0, dp_2 = 0;
	int ans = 0;
	for (int i = Length - 1; i >= 0; i--)
	{
		ans = max(nums[i] + dp_2, dp_1);
		dp_2 = dp_1;
		dp_1 = ans;
	}
	return ans;
}

//测试代码
int main(void)
{
	vector<int> num = {};
	std::cout << Rob_dp_Dimension_answer(num);

	vector<int> nums = { 1,2,3,1 };
	std::cout << Rob_recursively(nums) << std::endl;
	std::cout << Rob_Dict(nums) << std::endl;
	std::cout << Rob_dp(nums) << std::endl;
	std::cout << Rob_dp_Dimension(nums) << std::endl;

	std::cout << std::endl;

	nums = { 2,7,9,3,1 };
	std::cout << Rob_recursively(nums) << std::endl;
	std::cout << Rob_Dict(nums) << std::endl;
	std::cout << Rob_dp(nums) << std::endl;
	std::cout << Rob_dp_Dimension(nums) << std::endl;

	return 0;
}