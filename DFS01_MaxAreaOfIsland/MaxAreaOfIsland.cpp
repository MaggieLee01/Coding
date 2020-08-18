/*	����һ��������һЩ 0 �� 1�ķǿն�ά���� grid , һ�� ���� �����ĸ����� (ˮƽ��ֱ) �� 1 (��������) ���ɵ���ϡ�
	����Լ����ά������ĸ���Ե����ˮ��Χ�š��ҵ������Ķ�ά���������ĵ��������(���û�е��죬�򷵻����Ϊ0��)

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

�������������������Ӧ���� 6��ע��𰸲�Ӧ����11����Ϊ����ֻ�ܰ���ˮƽ��ֱ���ĸ�����ġ�1����
https://leetcode-cn.com/problems/max-area-of-island */

#include<vector>
#include<algorithm>
using std::max;
using std::vector;

//��ҳ�༭OK��DFS�㷨��������
//�ٷ���⻹�н���ջ �� ���� �ķ���
int dict1[] = { 0,0,1,-1 }, dict2[] = { 1,-1,0,0 };

//BFS����value�ͣ��ʼ������ans=0��û����ã�BFS��дΪ������
int BFS01(vector<vector<int>>& grid, int row, int column, int r, int c)
{
	if (r < 0 || c < 0 || r >= row || c >= column || grid[r][c] != 1) return 0;
	int ans = 1;	//����ط�ע�⣬ϰ���Ը�ֵΪ0�����������Ϊ0
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


//BFS������
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

