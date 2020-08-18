//优雅求出两组区间的交集 https://mp.weixin.qq.com/s/H5eLHsHc7s7UgwmKnjr32g
//LeetCode 986
//给定两个由一些闭区间组成的列表，每个区间列表都是成对不相交的，并且已经排序。返回这两个区间列表的交集。

#include<vector>
#include<algorithm>

using std::vector;
using std::max;
using std::min;

//已经排好序是关键，自己思路coding
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B)
{
	vector<vector<int>> ans;
	int i = 0, j = 0;
	int ALength = A.size();
	int BLength = B.size();
	int begin = 0, end = 0;

	while (i < ALength && j < BLength)
	{
		if (A[i][1] < B[j][0])		//无交集
			i++;
		else if (A[i][0] > B[j][1])	//无交集
			j++;
		else						//有交集
		{
			begin = max(A[i][0], B[j][0]);
			end = min(A[i][1], B[j][1]);
			if (A[i][1] >= B[j][1])
				j++;
			else
				i++;
			ans.push_back({ begin,end });
		}
	}
	return ans;
}
/****************************************************************************************************/
//看了答案，可以把指针移动的地方合并起来，更加精简了代码，佩服膜拜
//因为无论有无交集 一定会移动指针，所以先处理有交集的情况，最后统一处理指针移动
vector<vector<int>> intervalIntersection_answer(vector<vector<int>>& A, vector<vector<int>>& B)
{
	vector<vector<int>> ans;
	int i = 0, j = 0;
	int ALength = A.size();
	int BLength = B.size();
	int begin = 0, end = 0;

	while (i < ALength && j < BLength)
	{
		if (A[i][1] >= B[j][0] && A[i][0] <= B[j][1])	//有交集
		{
			begin = max(A[i][0], B[j][0]);
			end = min(A[i][1], B[j][1]);
			ans.push_back({ begin,end });
		}
		if (A[i][1] > B[j][1])	//此种情况已经包含了没有交集时，A[i][0]>B[j][1]的情况
			j++;
		else i++;
	}
	return ans;
}

int main(void)
{
	vector<vector<int>> A = { {0, 2}, {5, 10}, {13, 23}, {24, 25} };
	vector<vector<int>> B = { {1, 5}, {8, 12}, {15, 24}, {25, 26} };
	intervalIntersection(A, B);
}