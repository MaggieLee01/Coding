/*在给定的网格中，每个单元格可以有以下三个值之一：
	值 0 代表空单元格；
	值 1 代表新鲜橘子；
	值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。
返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。
https://leetcode-cn.com/problems/rotting-oranges  */

#include<vector>
#include<queue>
#include<unordered_map>
using std::unordered_map;
using std::queue;
using std::vector;

//void orangesRotting_Core(vector<vector<int>>& grid, int row, int column, int r, int c, int &ans)
//{
//	if (r < 0 || r >= row || c < 0 || c >= column) 
//		return;	
//	//if (grid[r][c] == 0 || grid[r][c] == 3) //遍历过或者没有桔子时，返回0 
//	//	return ;
//	
//	if (grid[r][c] == 1)	
//		grid[r][c] = 2;			
//	if (grid[r][c] == 2)
//	{
//		ans++;//一次腐坏四个，所以在此处++
//		grid[r][c] = 3;	//避免重复遍历
//
//		if (r < row - 1 && grid[r + 1][c] == 1)	
//			orangesRotting_Core(grid, row, column, r + 1, c, ans);
//		if (r > 0 && grid[r - 1][c] == 1)
//			orangesRotting_Core(grid, row, column, r - 1, c, ans);
//		if (c < column - 1 && grid[r][c + 1] == 1)
//			orangesRotting_Core(grid, row, column, r, c + 1, ans);
//		if (c > 0 && grid[r][c - 1] == 1)
//			orangesRotting_Core(grid, row, column, r, c - 1, ans);
//		
//	}
//}
//
//int orangesRotting(vector<vector<int>>& grid) 
//{
//	int row = grid.size();
//	if (row == 0) return 0;
//	int column = grid[0].size();
//	//寻找第一个腐坏的桔子
//	int i = 0, j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < column; j++)
//		{
//			if (grid[i][j] == 2) break;
//		}
//		if (j < column) break;
//	}
//	if (i >= row || j >= column) return 0;//没有腐败的桔子
//
//	int ans = -1;
//	orangesRotting_Core(grid, row, column, i, j, ans);
//	//在遍历一次，如果有新鲜桔子则返回-1
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < column; j++)
//		{
//			if (grid[i][j] == 1) break;
//		}
//		if (j < column) break;
//	}
//	if (i < row && j < column) ans = -1;
//	return ans;
//}

//上面的思路为，找到一个腐坏桔子向四周扩散递归，这样子是dfs遍历，思路不对；
//bfs遍历是所有腐坏桔子同时扩散，不能递归，递归属于dfs
//思路：找到所有的坏桔子，存队列，依次；依据按层次打印二叉树的思路想到队列的数据结构
int orangesRotting(vector<vector<int>>& grid)
{
	int row = grid.size();
	if (row == 0) return 0;
	int column = grid[0].size();

	//什么样的数据结构表示坐标点，含两个元素的数组？
	queue<vector<int> > OnceRotPosition;
	int ans = -1;//最开始的腐坏桔子不需要时间，但是计算中加++了

	//寻找腐坏的桔子
	int fresh = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{	
			if (grid[i][j] == 1) fresh++;
			if (grid[i][j] == 2) OnceRotPosition.push({i,j});			
		}
	}
	if (OnceRotPosition.empty())//没腐坏的苹果
	{
		if (fresh > 0) return -1;//有新鲜的水果
		else return 0;
	}
	OnceRotPosition.push({ -1,-1 });
	while (OnceRotPosition.size())
	{
		vector<int> top = OnceRotPosition.front();
		OnceRotPosition.pop();
		int r = top[0], c = top[1];
		if (r == -1 && c == -1  )//每分钟扩散结束标志
		{
			ans++;
			if (OnceRotPosition.empty()) break;//遍历完了没有了
			OnceRotPosition.push({ -1,-1 });
			continue;
		}
		//if (grid[r][c] == 1) grid[r][c] = 2;//压入队列的时候就应该变为2，可能在一层中重复遍历某个节点，但此时还未遍历到该节点，还未来得及变为2
		if (r < row - 1 && grid[r + 1][c] == 1)
		{
			grid[r + 1][c] = 2;
			OnceRotPosition.push({ r + 1, c });
		}						
		if (r > 0 && grid[r - 1][c] == 1)
		{
			grid[r - 1][c] = 2;
			OnceRotPosition.push({ r - 1, c });
		}						
		if (c < column - 1 && grid[r][c + 1] == 1)
		{
			grid[r][c + 1] = 2;
			OnceRotPosition.push({ r , c + 1 });
		}				
		if (c > 0 && grid[r][c - 1] == 1)
		{
			grid[r][c - 1] = 2;
			OnceRotPosition.push({ r , c - 1 });
		}			
	}
	//在遍历一次，如果有新鲜桔子则返回-1
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (grid[i][j] == 1) 
				return -1;
		}
	}
	return ans;
}
//感觉自己写的有点繁琐，看题解，大部分都是队列处理，部分处理细节不同，大家写的为不同处理细节的组合
//用四个点表示四个方向，减少向四个方向扩散的代码量
//可以用pair表示坐标点，我用的是数组表示，都还行
//层与层之间的区分方法：我在每层末尾插入{-1,-1}作为结束符，有的是求当时queue的数量n，然后for循环遍历前n个点
//是否有未被遍历到的桔子：可以根据桔子的数量判断；我是又重新遍历了一遍数组

//bfs遍历有基本的框架。用 BFS 来求最短路径的话，这个队列中第 1 层和第 2 层的结点会紧挨在一起，无法区分。
//因此，我们需要稍微修改一下代码，在每一层遍历开始前，记录队列中的结点数量 nnn ，然后一口气处理完这一层的 nnn 个结点。
// https://leetcode-cn.com/problems/rotting-oranges/solution/li-qing-si-lu-wei-shi-yao-yong-bfsyi-ji-ru-he-xie-/

//根据题解的各种处理方法，完善自己的代码
int orangesRotting_answer(vector<vector<int>>& grid)
{
	int row = grid.size();
	if (row == 0) return 0;
	int column = grid[0].size();

	queue<vector<int> > OnceRotPosition;
	int fresh = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (grid[i][j] == 1) fresh++;
			if (grid[i][j] == 2) OnceRotPosition.push({ i,j });
		}
	}
	if (fresh == 0) return 0;
	if (OnceRotPosition.empty()) return -1;
	
	vector<int> dx = { 0,0,1,-1 };
	vector<int> dy = { 1,-1,0,0 };
	
	int ans = 0;
	while (OnceRotPosition.size() && fresh > 0)
	{
		ans++;
		int num = OnceRotPosition.size();
		for (int i = 0; i < num; i++){
			vector<int> top = OnceRotPosition.front();
			OnceRotPosition.pop();
			/*for (auto m : dx){
				for (auto n : dy){*/ //只能4个方向呀，这样子组合了16种
			for (int j = 0; j < 4; j++)
			{
				int x = top[0] + dx[j], y = top[1] + dy[j];
				if (0 <= x && x < row && 0 <= y && y < column && grid[x][y] == 1) {
					grid[x][y] = 2;
					fresh--;
					OnceRotPosition.push({ x, y });
				}
			}			
		}
	}
	if (fresh > 0) return -1;
	return ans;
}
int main(void)
{
	vector<vector<int>> grid = { {2,1,1},{1,1,0},{0,1,1} };
	int ans = orangesRotting_answer(grid);

	grid = { {2,1,1},{0,1,1},{1,0,1} };
	ans = orangesRotting_answer(grid);

	grid = { {0,2}};
	ans = orangesRotting_answer(grid);
	return 0;
}