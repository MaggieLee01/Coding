/*200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
示例 1:
输入:
11110
11010
11000
00000
输出: 1

示例 2:
输入:
11000
11000
00100
00011
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
https://leetcode-cn.com/problems/number-of-islands/
*/

#include<vector>
#include<queue>
using namespace std;

//自己写的大概思路：找到一个陆地后四周扩散，如果为陆地则入队，直到队列为空，则入队的陆地形成一个岛屿
//代码缩进太多，影响美观
//为了防止重复遍历，入队列的时候就要做已访问标记
int numIslands(vector<vector<char>>& grid)
{
	int row = grid.size();
	if (row == 0) return 0;
	int column = grid[0].size();

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	int ans = 0;
	queue<vector<int>> temp;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (grid[i][j] == '1')
			{
				ans++;
				temp.push({ i,j });
				grid[i][j] = '2';
				while (temp.size())
				{
					vector<int> top = temp.front();
					temp.pop();
					int x = top[0], y = top[1];
					for (int k = 0; k < 4; k++)
					{
						int xNew = x + dx[k];
						int yNew = y + dy[k];
						if (0 <= xNew && xNew < row && 0 <= yNew && yNew < column && grid[xNew][yNew] == '1')
						{
							temp.push({ xNew,yNew });
							grid[xNew][yNew] = '2';
						}
					}
				}
			}
		}
	}
	return ans;
}
//看题解，学习并查集的写法，写在了UF的工程里面