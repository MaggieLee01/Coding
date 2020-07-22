/*
你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。
其中 0 代表海洋，1 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。
我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。
如果我们的地图上只有陆地或者海洋，请返回 -1。

输入：[[1,0,1],[0,0,0],[1,0,1]]
输出：2
解释：
海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
https://leetcode-cn.com/problems/as-far-from-land-as-possible
*/

#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;

//初步想法，找到所有的岛屿存起来，每遍历一个海洋，计算所有的距离；关键是，这样子，没有发挥广度遍历的作用呀
//看了看腐烂的桔子，大概有想法了，每一个岛屿向四周扩散知道发现海洋即停止。
//思路不对，看了甜姨的题解，层层扩散，最后扩散到的海洋就是最远区域。按照这个想法写。想不到这一点就不会写呀

int maxDistance(vector<vector<int>>& grid) 
{
	int row = grid.size();
	if (row == 0) return 0;
	int column = grid[0].size();

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	
	queue<pair<int, int> >island;
	int islandnum = 0;
	int  ans = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)		
			if (grid[i][j] == 1)
			{
				island.push({ i,j });
				grid[i][j] = 2;
				islandnum++;
			}
	if (island.size() == 0 || islandnum == row * column) return -1;
	while(island.size())
	{
		int s = island.size();
		for (int i = 0; i < s; i++)
		{
			auto top1 = island.front();
			island.pop();
			for (int j = 0; j < 4; j++)
			{
				int x = top1.first + dx[j], y = top1.second + dy[j];
				if (0 <= x && x < row && 0 <= y && y < column && grid[x][y] == 0)
				{
					island.push({ x,y });
					grid[x][y] = 3;
				}					
			}
		}
		ans++;
	}
	return ans - 1;//每扩散一层距离增加1，减去最开始第一次的岛屿计算
}
int main(void)
{
	vector<vector<int>> grid = { {1,0,0},{0,0,0},{0,0,0} };
	int ans = maxDistance(grid);
	return ans;
}