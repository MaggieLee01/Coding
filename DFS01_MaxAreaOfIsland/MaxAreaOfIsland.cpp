/*	给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。
	你可以假设二维矩阵的四个边缘都被水包围着。找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。
https://leetcode-cn.com/problems/max-area-of-island */

#include<vector>
#include<algorithm>
using std::max;
using std::vector;

//网页编辑OK，DFS算法基本掌握
//官方题解还有借用栈 与 队列 的方法
int dict1[] = { 0,0,1,-1 }, dict2[] = { 1,-1,0,0 };

//BFS返回value型，最开始忘记了ans=0；没处理好，BFS改写为引用型
int BFS01(vector<vector<int>>& grid, int row, int column, int r, int c)
{
	if (r < 0 || c < 0 || r >= row || c >= column || grid[r][c] != 1) return 0;
	int ans = 1;	//这个地方注意，习惯性赋值为0，最后结果返回为0
	grid[r][c] = 2;
	for (int i = 0; i < 4; i++)
		ans += BFS01(grid, row, column, r + dict1[i], c + dict2[i]);
	return ans;
}
int maxAreaOfIsland01(vector<vector<int>>& grid)
{
	int row = grid.size();
	if (row == 0) return 0;
	int column = grid[0].size();

	int ans = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			if (grid[i][j] == 1)  ans = max(ans, BFS01(grid, row, column, i, j));
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			if (grid[i][j] == 2) grid[i][j] = 1;
	return ans;
}


//BFS引用型
void BFS02(vector<vector<int>>& grid, int row, int column, int r, int c, int &area)
{
	if (r < 0 || c < 0 || r >= row || c >= column || grid[r][c] != 1) return;
	if (grid[r][c] == 1)
	{
		grid[r][c] = 2;
		area++;
		for (int i = 0; i < 4; i++)
			BFS02(grid, row, column, r + dict1[i], c + dict2[i], area);
	}
}
int maxAreaOfIsland(vector<vector<int>>& grid)
{
	int row = grid.size();
	if (row == 0) return 0;
	int column = grid[0].size();

	int ans = 0, area = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			if (grid[i][j] == 1)
			{
				area = 0;
				BFS02(grid, row, column, i, j, area);
				ans = max(ans, area);
			}

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			if (grid[i][j] == 2) grid[i][j] = 1;
	return ans;
}

