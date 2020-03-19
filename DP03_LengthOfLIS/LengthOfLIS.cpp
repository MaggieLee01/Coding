//求最长的递增子序列（Longest Increasing Subsequence，简写 LIS）
//子串一定是连续的，而子序列不一定是连续的
//2019-07-15
//https://mp.weixin.qq.com/s/02o_OPgePjaz3dXnw9TA1w
//均已通过LeetCode测试

//https://blog.csdn.net/weixin_43557810/article/details/88768360 标准库里面有二分法的函数
//https://blog.csdn.net/qq_37774171/article/details/81203890
#include<vector>
#include<iostream>
#include<algorithm>
using std::vector;
using std::lower_bound;

//********************************未看答案的思路**********************************
//逐个遍历前面的字符，当比该字符小的时候在该字符的数字上加一，时间复杂度：n*n，空间复杂度：n
//写完发现貌似没有递归
int LengthOfLIS_dp(std::vector<int> num)
{
	if (num.size() > 0)
	{
		int numLength = num.size();
		//子序列的最短长度应该为1，所以初始化为1
		std::vector<int> LISLength(numLength, 1);
		for (int i = 0; i < numLength; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (num[j] < num[i])
					//如何使用max min 函数
					LISLength[i] = (LISLength[j] + 1) > LISLength[i] ? (LISLength[j] + 1) : LISLength[i];
			}
		}
		//最后的返回值应该为数组中的最大值，不应该是末尾
		//return LISLength[numLength - 1];

		//初探标准库函数的使用，res的类型为iterator，注意返回类型
		auto res = max_element(LISLength.begin(), LISLength.end());
		return *res;
	}
	return 0;	
}

//********************************看答案的扑克牌思路**********************************
//扑克牌思路二分法时，应该找左边界，尤其是对于含有重复数字地方子序列
//当目标值与该堆牌中的top相同时一定在放在该堆上，才能保持各个堆top的有序性，递增性

//总结：努力尝试了各种方法，还是按照答案的方法，寻找左边界后统一处理比较简单，
//本想在循环条件中直接判断出插入位置，提前结束循环【其实并没有减少循环次数，反而增加了判断次数】，需要考虑的因素太多，并不简洁。

//没看二分框架时的写法，应该正确，但是不够有条理
int LengthOfLIS_Binary01(std::vector<int> num)
{																  
	if (num.size() > 0)
	{   
		//完全可以设置长度确定的数组，二分法的时候自动减半
		//我目前的设计，数组大小自动增长，有数据时才压入，比较麻烦
		std::vector<int> poker;		
		poker.push_back(num[0]);
		for (int i = 1; i < num.size(); i++)
		{
			//较小数据时优先放在第一列
			if (poker[0] >= num[i])			
				poker[0] = num[i];
			else
			{
				//二分法开始找放置的位置，二分法写法再看
				int length = poker.size();
				int left = 0;
				int right = length - 1;
				while (right >= left)
				{
					int mid =( (right - left) >> 1 ) + left;
					if (left == right)
					{
						poker.push_back(num[i]);
						break;
					}
					//相同时该放在相同数字的堆 而不是下一堆；不相同时应该放在下一堆					
					if (poker[mid] < num[i] && num[i] < poker[mid + 1])//连写不行 哈哈
					{
						poker[mid + 1] = num[i]; break;
					}						
					else if (poker[mid] == num[i] && num[i] < poker[mid + 1])
					{
						poker[mid] = num[i]; break;
					}						
					else if (poker[mid] > num[i])
						right = mid;
					else
						left = mid + 1;
				}
			}
		}
		return poker.size();
	}
	return 0;
}

//根据答案更简洁的写法
//求最小子序列需要找出小于等于目标值的个数，
int LengthOfLIS_Binary02(std::vector<int> num)
{
	if (num.size() <= 0) return 0;
	std::vector<int> top(num.size(), 0);
	int piles = 1;//初始化牌堆数为1
	top[0] = num[0];
	for (int i = 1; i < num.size(); i++)
	{
		int left = 0;
		int right = piles - 1;//数组首位序列为0
		while (left <= right)
		{
			int mid = ((right - left) >> 1) + left;
			if (top[mid] == num[i])
				right = mid - 1;
			else if (top[mid] > num[i])
				right = mid - 1;
			else
				left = mid + 1;
		}
		//left处前面的数字小于目标值，left处为边界
		//比所有数大
		if (left == piles)	piles++;
		top[left] = num[i];
	}
	return piles;
}

//根据答案，改进01方法：设置为固定大小的数组；改进二分法查找左边界的写法【按照插入方法03】
//top数组的内容符合扑克牌思路
int LengthOfLIS_Binary03(std::vector<int> num)
{
	if (num.size() <= 0) return 0;
	std::vector<int> top(num.size(), 0);
	int piles = 1;//初始化牌堆数为1
	top[0] = num[0];
	for (int i = 1; i < num.size(); i++)
	{
		//较小数据时优先放在第一列
		if (top[0] >= num[i])
			top[0] = num[i];
		else	//二分法开始找放置的位置
		{			
			int left = 0;
			int right = piles - 1;//数组首位序列为0
			while (left <= right)
			{
				int mid = ((right - left) >> 1) + left;
				if (mid == piles - 1) break;
				//相同时该放在相同数字的堆 而不是下一堆；不相同时应该放在下一堆
				if (top[mid] == num[i] && num[i] < top[mid + 1])
				{					
					top[mid] = num[i];
					break;
				}
				else if (top[mid] < num[i] && num[i] < top[mid + 1])
				{
					//应该放在相同数字的堆 而不是下一堆
					top[mid + 1] = num[i];
					break;
				}
				else if (top[mid] > num[i])
					right = mid - 1;
				else
					left = mid + 1;
			}
			//比所有数大
			if (left == piles - 1)
			{
				top[piles] = num[i];
				piles++;
			}
		}
	}
	return piles;	
}
/******************************************************************************************/
//20200314LeetCode每日一题网页版完成，运用标准库函数 和 手写二分法 两种方法，比之前熟悉一些了
int LengthOfLIS_Binary0314_STL(std::vector<int> num)
{
	int Length = num.size();
	if (Length == 0) return 0;
	int ans = 1;
	vector<int> dict(Length, 0);
	dict[0] = num[0];
	for (int i = 0; i < Length; i++)
	{
		auto low = lower_bound(dict.begin(), dict.begin() + ans, num[i]); //注意标准库函数的使用，返回值为迭代器
		int index = low - dict.begin(); //小小处理才能得到索引值
		dict[index] = num[i];
		if (index >= ans)ans++;
	}
	return ans;
}
int lower_bound(vector<int>& num, int begin, int end, int target);
int LengthOfLIS_Binary0314_self(std::vector<int> num)
{
	int Length = num.size();
	if (Length == 0) return 0;
	int ans = 1;
	vector<int> dict(Length, 0);
	dict[0] = num[0];
	for (int i = 0; i < Length; i++)
	{
		int index = lower_bound(dict, 0, ans, num[i]); // 注意此处为dict的查找，曾犯错误写成num数组
		dict[index] = num[i];
		if (index >= ans)ans++;
	}
	return ans;	
}
int lower_bound(vector<int>& num, int begin, int end, int target) //二分法应该熟练了吧
{
	int left = begin;
	int right = end;
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (num[mid] == target) right = mid;
		else if (num[mid] > target) right = mid;
		else if (num[mid] < target) left = mid + 1;
	}
	return left;
}

/**************************************测试代码********************************************/
void Testdp(const char* Testname, std::vector<int>num, int except)
{
	if (Testname != nullptr)
		std::cout << Testname << "	begins:  ";
	int result = LengthOfLIS_dp(num);
	if (result == except)
		std::cout << "Passed" << std::endl;
	else
		std::cout << "Failed" << std::endl;
}
void Test01(const char* Testname, std::vector<int>num, int except)
{
	if (Testname != nullptr)
		std::cout << Testname << "	begins:  ";
	int result = LengthOfLIS_Binary01(num);
	if (result == except)
		std::cout << "Passed" << std::endl;
	else
		std::cout << "Failed" << std::endl;
}
void Test02(const char* Testname, std::vector<int>num, int except)
{
	if (Testname != nullptr)
		std::cout << Testname << "	begins:  ";
	int result = LengthOfLIS_Binary02(num);
	if (result == except)
		std::cout << "Passed" << std::endl;
	else
		std::cout << "Failed" << std::endl;
}
void Test03(const char* Testname, std::vector<int>num, int except)
{
	if (Testname != nullptr)
		std::cout << Testname << "	begins:  ";
	int result = LengthOfLIS_Binary03(num);
	if (result == except)
		std::cout << "Passed" << std::endl;
	else
		std::cout << "Failed" << std::endl;
}
int main(void)
{
	std::vector<int> nums = { 6,3,5,10,11,2,9,14,13,7,4,8,12 };
	Testdp("Test1", nums, 5);
	Test01("Test1", nums, 5);
	Test02("Test1", nums, 5);
	Test03("Test1", nums, 5);

	nums = {2, 6,3,5,3,2,4};
	Testdp("Test2", nums, 3);
	Test01("Test2", nums, 3);
	Test02("Test2", nums, 3);
	Test03("Test2", nums, 3);

	nums = { 1,2,3,4,5,6,1,2,3 };
	Testdp("Test2", nums, 6);
	Test01("Test2", nums, 6);
	Test02("Test2", nums, 6);
	Test03("Test2", nums, 6);

	nums = {  };
	Testdp("Test3", nums, 0);
	Test01("Test3", nums, 0);
	Test02("Test3", nums, 0);
	Test03("Test3", nums, 0);

	nums = { 1 };
	Testdp("Test4", nums, 1);
	Test01("Test4", nums, 1);
	Test02("Test4", nums, 1);
	Test03("Test4", nums, 1);

	nums = { 7,6,5,4,3,2,1,0 };
	Testdp("Test5", nums, 1);
	Test01("Test5", nums, 1);
	Test02("Test5", nums, 1);
	Test03("Test5", nums, 1);

	nums = { 1,3,5,7,9,2,4,6,8,10,12 };
	Testdp("Test6", nums, 7);
	Test01("Test6", nums, 7);
	Test02("Test6", nums, 7);
	Test03("Test6", nums, 7);

	nums = { 7,6,5,4,3,2,1,0,7,6,5,4,3,2,1 };
	Testdp("Test7", nums, 2);
	Test01("Test7", nums, 2);
	Test02("Test7", nums, 2);
	Test03("Test7", nums, 2);
	return 0;
}