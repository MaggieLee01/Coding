/*
给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
不占用额外内存空间能否做到？

给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
https://leetcode-cn.com/problems/rotate-matrix-lcci

*/
#include<vector>
#include<algorithm>
using namespace std;

//由于不让借助数组，没太多思路，看题解
//关键点：找到新坐标的表达式
//原地旋转
void rotate(vector<vector<int>>& matrix)
{
	int n = matrix.size();
	for (int i = 0; i < (n >> 1); i++)
		for (int j = 0; j < ((n + 1) >> 1); j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[n - j - 1][i];
			matrix[n - j - 1][i] = matrix[n - j - 1][n - i - 1];
			matrix[n - j - 1][n - i - 1] = matrix[i][n - i - 1];
			matrix[i][n - i - 1] = temp;
		}
}
//翻转【水平加对角线】完成旋转
// matrix[row][col]→→→→→水平轴翻转→→→→→matrix[n−row−1][col]→→→→→主对角线翻转matrix→→→→→matrix[col][n−row−1]

void rotate01(vector<vector<int>>& matrix)
{
	int n = matrix.size();
	for (int i = 0; i < (n >> 1); i++)
		for (int j = 0; j < n; j++)
			swap(matrix[i][j], matrix[n - i - 1][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			swap(matrix[i][j], matrix[j][i]);
}