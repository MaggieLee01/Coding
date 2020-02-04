//未在系统上测试，测试代码没问题 
//2019-06-11
//根据labuladong文章，二分法的框架：右边界不同赋值下，循环条件不同、对应的mid有不同的赋值

//01方法：搜索区间两端都是闭的，即 [left, right]，当我们发现索引mid不是要找的target时，
//		  下一步应该去搜索 [left, mid - 1] 或者 [mid + 1, right] 
//02方法:「搜索区间」是 [left, right) 左闭右开，当 nums[mid] 被检测之后，
//		  下一步的搜索区间应该去掉mid分割成两个区间，即 [left, mid) 或 [mid + 1, right)

#include<iostream>
#include<vector>

//二分法查找 有序数组中是否存在目标元素
int BinarySearch01(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{ 
		int mid = ((right - left) >> 1) + left;//此处不加（），调试时计算的结果不对，不明白为什么
		if (nums[mid] == target)return mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	return -1;
}

int BinarySearch02(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size();//根本点，此处right的赋值不同
	while (left < right)	//此处不同
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)return mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid;		//此处不同
	}
	return -1;
}

//*********************************************************************************

//查找元素 与 寻找重复数字左右边界 的区别：
//		等于目标值时的处理不同，后者应该不断缩小搜索边界，所以将 mid相应的处理 赋值为left或者right
//		找不到时，返回-1的情况不同


//二分法查找 包含重复数字的有序数组中是否存在目标元素，若无，返回-1
//如有序数组 nums = [1,2,2,2,3]，target = 2，target 的左侧边界为索引1，target的右侧边界为索引3
int BinarySearchLeftBorder01(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			right = mid - 1;
		//此处注释的思路不对，这是自己最开始的想法
		//因为找左边界，如果目标值比该数值大，该数仍可能为左边界，所以mid不能加一
		//如果目标值比该数值小，则该数不可能为边界，所以mid减一
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	//target比所有值都大
	if ( left == nums.size() )return -1;
	return nums[left] == target ? left : -1;
}

int BinarySearchLeftBorder02(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size();
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			right = mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid;
	}
	if (left == nums.size())return -1;
	return nums[left] == target ? left : -1;
}

//与查找左边界的区别：返回值不同
//01方法左边界、02方法左边界为闭合，所以处理返回值或者-1的时候，两种方法处理一样
//01方法右边界为闭合，所以结尾处理和上面的类似
//02方法右边界为开区间，所以结尾处有特殊操作

//如有序数组 nums = [1,2,2,2,3]，target = 2，target 的左侧边界为索引1，target的右侧边界为索引3
int BinarySearchRightBorder01(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			left = mid + 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;

	}
	if (right == -1)return -1;
	return nums[right] == target ? right : -1;
}

int BinarySearchRightBorder02(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size();
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			left = mid + 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid;
	}

	//right处为开区间，没有机会等于-1，等于 0 即结束循环
	//right处为开区间，没机会得到nums[right]处的值，所以返回 right - 1；
	//或者理解为：left的更新为left = mid + 1， while循环结束，nums[left]一定不等于target了，而 nums[left - 1] 可能是target。
	//			且循环结束时 right==left, 所以返回left- 1 也可以
	
	//if (right == -1)return -1;
	if (right == 0)return -1;//当目标值比所有者都大
	return nums[right - 1] == target ? (right - 1) : -1;
}

//在 含重复数字的有序数组中 插入 一个数字 保持有序
//和查找的区别：查找：没有目标值时返回-1，插入：找到边界即可确定插入位置

//左边界返回值含义，在该索引处左边插入
//右边界返回值含义，在该索引处右边插入
//【含重复数字处比较好理解，实则为重复数字的边界索引值】
int BinaryInsertLeftBorder01(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			right = mid - 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	return left;
}

int BinaryInsertLeftBorder02(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size();
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			right = mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid;
	}
	return left;
}

int BinaryInsertRightBorder01(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			left = mid + 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	return right;
}

int BinaryInsertRightBorder02(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size();
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			left = mid + 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid;
	}
	return right - 1;//减一理由同上
}

//自己的二分法想法
//设定统一返回值为 在索引值为返回值的后面插入，此时不考虑重复数字，考虑也行
int BinaryInsert03(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = ((right - left) >> 1) + left;
		//此时用到mid+1，所以mid不能取到最后一个，为最后一个时应该结束循环
		if (mid == nums.size() - 1) break;
		if (nums[mid] <= target && target < nums[mid + 1])
			return mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}	
	if (right == -1)//比所有者都小
		return -1;
	if (left == nums.size() - 1)//比所有者都大
		return left;
}

//*************************测试代码*****************************
int main(void)
{
	
	std::vector<int> v = { 1,3,5,7,10,13,17,18,20,27,33,46 };
	int l = BinaryInsert03(v, 3);
	std::cout << l << std::endl;//1
	l = BinaryInsert03(v, 6);
	std::cout << l << std::endl;//2.
	l = BinaryInsert03(v, 19);
	std::cout << l << std::endl;//7
	l = BinaryInsert03(v, 30);
	std::cout << l << std::endl;//9
	l = BinaryInsert03(v, 0);
	std::cout << l << std::endl;//-1
	l = BinaryInsert03(v, 301);
	std::cout << l << std::endl;//11

	v = { 0,3,4,6,9,11,14,15,16,23,25,29,32,35,56,66,76,87 };
	l = BinaryInsert03(v, 3);
	std::cout << l << std::endl;//1
	l = BinaryInsert03(v, 5);
	std::cout << l << std::endl;//2
	l = BinaryInsert03(v, 19);
	std::cout << l << std::endl;//8
	l = BinaryInsert03(v, 30);
	std::cout << l << std::endl;//11
	l = BinaryInsert03(v, -1);
	std::cout << l << std::endl;//-1
	l = BinaryInsert03(v, 301);
	std::cout << l << std::endl;//17

	//第一个10的索引值为8，最后一个10索引值为11
	std::vector<int> nums = { 1,3,3,3,3,3,5,7,10,10,10,10,13,17,18,20,27,33,46 };
	int m = BinarySearchLeftBorder01(nums, 10);
	int n = BinarySearchLeftBorder02(nums, 10);	
	std::cout << ' ' << m << ' ' << n << std::endl;
	m = BinarySearchRightBorder01(nums, 10);
	n = BinarySearchRightBorder02(nums, 10);
	std::cout << ' ' << m << ' ' << n << std::endl;

	//第一个78的索引值为12，最后一个78索引值为14
	nums = { 2,2,4,5,8,8,13,13,13,34,64,67,78,78,78,79,83 };
	m = BinarySearchLeftBorder01(nums, 78);
	n = BinarySearchLeftBorder02(nums, 78);
	std::cout << ' ' << m << ' ' << n << std::endl;
	m = BinarySearchRightBorder01(nums, 78);
	n = BinarySearchRightBorder02(nums, 78);
	std::cout << ' ' << m << ' ' << n << std::endl;

	//无此值 -1
	nums = { 2,2,4,5,8,8,13,13,13,34,64,67,78,78,78,79,83 };
	m = BinarySearchLeftBorder01(nums, 66);
	n = BinarySearchLeftBorder02(nums, 66);
	std::cout << ' ' << m << ' ' << n << std::endl;
	m = BinarySearchRightBorder01(nums, 66);
	n = BinarySearchRightBorder02(nums, 66);
	std::cout << ' ' << m << ' ' << n << std::endl;

	//第一个78的索引值为12，最后一个78索引值为14
	nums = { 2,2,4,5,8,8,13,13,13,34,64,67,78,78,78,79,83 };
	m = BinarySearchLeftBorder01(nums, 78);
	n = BinarySearchLeftBorder02(nums, 78);
	std::cout << ' ' << m << ' ' << n << std::endl;
	m = BinarySearchRightBorder01(nums, 78);
	n = BinarySearchRightBorder02(nums, 78);
	std::cout << ' ' << m << ' ' << n << std::endl;

	//在索引值为11的左边，索引值为10的右边
	nums = { 2,2,4,5,8,8,13,13,13,34,64,67,78,78,78,79,83 };
	m = BinaryInsertLeftBorder01(nums, 66);
	n = BinaryInsertLeftBorder02(nums, 66);
	std::cout << ' ' << m << ' ' << n << std::endl;
	m = BinaryInsertRightBorder01(nums, 66);
	n = BinaryInsertRightBorder02(nums, 66);
	std::cout << ' ' << m << ' ' << n << std::endl;

	//3的左边界1； 3的右边界5
	nums = { 1,3,3,3,3,3,5,7,10,10,10,10,13,17,18,20,27,33,46 };
	m = BinaryInsertLeftBorder01(nums, 3);
	n = BinaryInsertLeftBorder02(nums, 3);
	std::cout << ' ' << m << ' ' << n << std::endl;
	m = BinaryInsertRightBorder01(nums, 3);
	n = BinaryInsertRightBorder02(nums, 3);
	std::cout << ' ' << m << ' ' << n << std::endl;

	//出界了，左边0，右边8
	nums = { 1,3,5,7,10,13,27,33,46 };
	m = BinaryInsertLeftBorder01(nums, 0);
	n = BinaryInsertLeftBorder02(nums, 0);
	std::cout << ' ' << m << ' ' << n << std::endl;
	m = BinaryInsertRightBorder01(nums, 100);
	n = BinaryInsertRightBorder02(nums, 100);
	std::cout << ' ' << m << ' ' << n << std::endl;


	nums = { 1,3,5,7,10,13,17,18,20,27,33,46 };
	m = BinarySearch01(nums, 10);
	n = BinarySearch02(nums, 10);
	std::cout << ' ' << m << ' ' << n << std::endl;

	nums = { 1,3,5,7,10,13,17,18,20,27,33,46 };
	m = BinarySearch01(nums, 20);
	n = BinarySearch02(nums, 20);
	std::cout << ' ' << m << ' ' << n << std::endl;
	return 0;
}