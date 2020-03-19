/*	给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。
	形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。
	https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum */

#include<vector>
using std::vector;

//题目不难，自己的思路也大概是对的，就是求和，除以3，然后遍历寻找和为平均数的次数
//特殊测试用例：1. 第三个部分为平均数本身 和 一大疙瘩和为9 组成 2.和为0，正负数间隔出现，分别为两对 四对的情况【10,-10,10,-10】

//但是过程中遇到了很多问题：一开始是想着和等于平均数时，就计数，当为3次的时候就break，最后判断是否遍历到数组的末端，结果遇到了用例1的情况
//然后看到群里聊两次，就想着取巧，判断两次就break，然后遇到了2的情况，然后想着返回值判断处添加遍历的i不能为最后一个元素的情况，然后遇到了最后最后一个元素为平均数的情况
//想了各种方法处理都没有成功，最后不想折腾了，老老实实重新考虑计数到3，终于把程序给写对了

//最重要的错误，一开始是先判断average是否已经减至0，然后才判断次数 做减法；最佳的处理应该是先做减法
//考虑问题不全面，依靠测试用例不断修改程序逻辑的习惯可是不太好呀

//额外的方法，看双指针，从左右两边分别找，中间一段不管了，大概都差不多
bool canThreePartsEqualSum(vector<int>& A)
{
	if (A.size() == 0) return false;
	int sum = 0;
	for (int temp : A)  sum += temp;
	//if (sum == 0 || sum % 3 != 0) return false; 
	//之前是为了防止A为空，省事在此处加了sum==0 即false的情况，忽略了和就是为0的情况
	if (sum % 3 != 0) return false;

	int average = sum / 3, times = 0;
	for (int i:A)
	{
		average -= i;
		if (average == 0)
		{
			average = sum / 3;
			times++;
		}
		if (times == 3) break;	
		//average -= i; 应该先减呀，不然会出现最后一次无法判断的情况
	}
	return (times == 3);
}
//bool canThreePartsEqualSum(vector<int>& A)
//{
//	if (A.size() == 0) return false;
//	int sum = 0;
//	for (int temp : A)  sum += temp;
//	//if (sum == 0 || sum % 3 != 0) return false; 之前是为了防止A为空，省事在此处加了sum==0 即false的情况，忽略了和就是为0 的情况
//	if ( sum % 3 != 0) return false;
//
//	int average = sum / 3, times = 0;
//	int Length = A.size(), i = 0;
//	for ( auto i:A)
//	{
//		if (times == 3) break;
//		if (average == 0 && times > 0)
//		{
//			average = sum / 3;
//			times++;
//		}
//		//if (times == 0 && i < Length) break;
//		//if (times == 0) break;
//		average -= i;
//	}
//	return (times == 3);
//}

//bool canThreePartsEqualSum(vector<int>& A)
//{
//	int sum = 0;
//	for (int temp : A)  sum += temp;
//	if (sum == 0 || sum % 3 != 0) return false;
//	int Length = A.size(), average = sum / 3, times = 3, i = 0;
//	for (i = 0; i < Length; i++)
//	{
//		if (average == 0 && times > 0)
//		{
//			average = sum / 3;
//			times--;
//		}
//		else  average -= A[i]; 
//	}
//	return (i == Length && times == 0);
//}


//bool canThreePartsEqualSum(vector<int>& A)
//{
//	int sum = 0;
//	for (int temp : A)  sum += temp;
//	if (sum == 0 || sum % 3 != 0) return false;
//	int Length = A.size(), average = sum / 3, times = 2, i = 0;
//	for (i = 0; i < Length; i++)
//	{
//		if (average == 0 && times >= 0)
//		{
//			average = sum / 3;
//			times--;
//		}
//		average -= A[i];
//	}
//	return (i == Length && times == 0 && average == 0);
//}
int main(void)
{
	vector<int> nums = { 0,2,1,-6,6,-7,9,1,2,0,1 };
	bool n = canThreePartsEqualSum(nums);

	nums = { 0,2,1,-6,6,7,9,-1,2,0,1 };
	n = canThreePartsEqualSum(nums);

	nums = { 18,12,-18,18,-19,-1,10,10 };
	n = canThreePartsEqualSum(nums);

	nums = { 18,-18,18,-18 };
	n = canThreePartsEqualSum(nums);

	nums = { 12,-4,16,-5,9,-3,3,8,0 };//这个就属于特例，0的位置在末尾
	n = canThreePartsEqualSum(nums);

	nums = { 10,-7,13,-14,30,16,-3,-16,-27,27,19 };
	//思路有问题呀 就要找到两次就可以接受了，毕竟总和平均数都求出来了，第三次可能还有遇到一堆和为0的情况
	//NONO 呀，还是得记到3次，不然无法处理【-10,10,-10,10】
	n = canThreePartsEqualSum(nums);
	return 0;
}