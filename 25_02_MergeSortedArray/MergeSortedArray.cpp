/*给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。		
	初始化 A 和 B 的元素数量分别为 m 和 n。
	输入:	A = [1,2,3,0,0,0], m = 3
			B = [2,5,6],       n = 3
	输出:	[1,2,2,3,5,6]
	https://leetcode-cn.com/problems/sorted-merge-lcci */

#include<vector>
using std::vector;
void merge(vector<int>& A, int m, vector<int>& B, int n)
{
	int aIndex = m - 1, bIndex = n - 1, ansIndex = n + m - 1;
	while (bIndex >= 0)
	{		
		//此处应用了与的性质，当aIndex为-1之后，逻辑表达式直接为1，后面的不会再判断，所以不会出现数组越界的情况
		if (aIndex == -1 || A[aIndex] <= B[bIndex]) 
		{
			A[ansIndex] = B[bIndex];
			bIndex--;
		}
		else
		{
			A[ansIndex] = A[aIndex];
			aIndex--;
		}
		ansIndex--;
	}
}
//看了题解，还没有更好的方法
int main(void)
{
	vector<int> a = { 7,8,9,0,0,0 };
	vector<int> b = { 1,2,3 };
	merge(a, 3, b, 3);
	return 0;
}