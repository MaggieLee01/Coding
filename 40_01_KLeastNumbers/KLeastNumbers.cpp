////ÿ��һ�� �� LeetCode ���У��ܾ����TOP K ������
//
////��ͨ������������
////����˼�룺ʱ��죬�����޸���ԭ��������
////			�ڴ˻������Ż��Ľ�����BFPRT �㷨��https://www.jianshu.com/p/83bb10ad1d32
////�� ������֮����㷨��û�иı����ݣ��ʺ�n�ܴ�K��С�ĺ�������
////			�����кܶ����ݽṹʵ�֣����ȶ��У�multiset��map�ȣ���Щ���ݽṹ��ͬ�㣺�����ҵ���ֵ
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
////����ϰ���ŵ�˼�룬��������ۣ�ò�ƿ����漰������ָ��˭�ȵ�����
//int Partition(vector<int>& arr, int left, int right)
//{
//	int i = left - 1;
//	int pivot = arr[right];
//	//��֤i��ΪС��pivot�ı߽�
//	for (int j = left; j < right; j++)
//	{
//		if (arr[j] < pivot)//�˴�С�� С�ڵ��ڵ�������
//		{
//			i++;
//			swap(arr[j], arr[i]);
//		}
//	}
//	i++;
//	//swap(arr[i], pivot);
//	swap(arr[i], arr[right]);//���д�ɽ��������Ԫ�ذ�
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
//	//�������
//	srand((unsigned int)time(NULL));
//	QuickSort(arr, 0, Length - 1, k - 1);//��������ֱ���������Ƚ�
//
//	vector<int> ans(k, 0);
//	for (int i = 0; i < k; i++)
//		ans[i] = arr[i];
//	return ans;
//}
//
////��������㷨�����ô�СΪK�Ķѣ���KС����Ҫ���ô���ѣ�Ĭ��Ϊ����ѣ������ֱȸ���Сʱ�������Ѷ������
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
//		//Ҳ���Է�����forѭ��
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
		QuickSort(input, k , i + 1, end);    //���������k��������ұ�����k-i-1��
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