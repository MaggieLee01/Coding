////每日一题 和 LeetCode 都有，很经典的TOP K 的问题
//
////普通做法：先排序
////快速思想：时间快，但是修改了原来的数据
////			在此基础上优化改进有了BFPRT 算法：https://www.jianshu.com/p/83bb10ad1d32
////堆 二叉树之类的算法，没有改变数据，适合n很大K很小的海量数据
////			可以有很多数据结构实现，优先队列，multiset，map等，这些数据结构共同点：可以找到最值
//
//#include<ctime>
//#include<vector>
//#include<queue>
//#include<set>
//#include<map>
//#include<algorithm>
//using std::swap;
//using std::map;
//using std::multiset;
//using std::priority_queue;
//using std::vector;
//
////先练习快排的思想，看题解评论，貌似快排涉及到左右指针谁先的问题
//int Partition(vector<int>& arr, int left, int right)
//{
//	int i = left - 1;
//	int pivot = arr[right];
//	//保证i处为小于pivot的边界
//	for (int j = left; j < right; j++)
//	{
//		if (arr[j] < pivot)//此处小于 小于等于的区别是
//		{
//			i++;
//			swap(arr[j], arr[i]);
//		}
//	}
//	i++;
//	//swap(arr[i], pivot);
//	swap(arr[i], arr[right]);//最好写成交换数组的元素吧
//	return i;	
//}
//int Random_Index(vector<int> &arr,int left,int right)
//{
//	int i = rand() % (right - left + 1) + left;
//	swap(arr[i], arr[right]);
//	return Partition(arr, left, right);
//}
//void QuickSort(vector<int>& arr, int left, int right, int k)
//{
//	if (left >= right) return;
//	int index = Random_Index(arr,left,right);
//	if (index == k) return;
//   	else if (index < k )
//		QuickSort(arr, index + 1, right, k);
//	else
//		QuickSort(arr, left, index - 1, k);
//}
//vector<int> getLeastNumbers(vector<int>& arr, int k) 
//{
//	int Length = arr.size();
//	if (Length <= k) return arr;
//	
//	//随机序列
//	srand((unsigned int)time(NULL));
//	QuickSort(arr, 0, Length - 1, k - 1);//函数里面直接序列作比较
//
//	vector<int> ans(k, 0);
//	for (int i = 0; i < k; i++)
//		ans[i] = arr[i];
//	return ans;
//}
//
////堆排序的算法，设置大小为K的堆，找K小的数要设置大根堆，默认为大根堆；当发现比根顶小时，弹出堆顶，入队
//vector<int> getLeastNumbers01(vector<int>& arr, int k)
//{
//	int Length = arr.size();
//	if (Length <= k) return arr;
//
//	priority_queue<int> pq;
//	for (int i : arr)
//	{
//		if (pq.size() < k)
//			pq.push(i);
//		//也可以分两个for循环
//		else if (i < pq.top())
//			{
//				pq.pop();
//				pq.push(i);
//			}		
//	}
//	vector<int> ans(k, 0);
//	for (int i = 0; i < k; i++)
//	{
//		ans[i] = pq.top();
//		pq.pop();
//	}
//	return ans;
//}
//
//int main(void)
//{
//	vector<int> nums = { 8,7,6,6,12,45,22,12,26,33,28 };
//	vector<int> ans = getLeastNumbers01(nums, 6);
//	return 0;
//}
//


#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include <cctype>
using namespace std;


/*
4 2 3 1 5 6 7 8
*/

void QuickSort(vector<int> &input, int k, int begin, int end)
{
	int temp = input[begin];
	int i = begin, j = end;
	while (i < j)
	{
		while (i < j && temp <= input[j])
			--j;
		input[i] = input[j];
		while (i < j && temp >= input[i])
			++i;
		input[j] = input[i];
	}
	input[i] = temp;

	if (i  == k)
		return;
	else if (i  > k)
		QuickSort(input, k, begin, i - 1);
	else
		QuickSort(input, k , i + 1, end);    //左边数不足k个，需从右边再找k-i-1个
}


vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	vector<int> result;
	if (k > input.size())
		return result;
	QuickSort(input, k, 0, input.size() - 1);
	for (int i = 0; i < k; i++)
	{
		result.push_back(input[i]);
	}
	return result;
}
int main()
{
	vector<int> arr{5,5,5,5,5,5,5,5,5};
	

	vector<int> result = GetLeastNumbers_Solution(arr, 5);

	system("pause");
	return 0;
}