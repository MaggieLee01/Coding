//https://leetcode-cn.com/problems/01-matrix/
/*给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
两个相邻元素间的距离为 1 。
输入:
0 0 0
0 1 0
1 1 1
输出:
0 0 0
0 1 0
1 2 1
*/
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
//为啥子几天不写BFS就不会了呀，
//这样子的dfs行不通呀，还是我写的不对
//陷入了死循环，就像{ {0,0,0},{0,1,0},{1,1,1} }的（1,1）取决于（2,1），（2,1）取决于（2,2），（2,2）取决于（2,1）
int getDIstance(vector<vector<int>>& matrix, int row, int column, int i, int j, vector<vector<int>>& ans)
{
	if (ans[i][j] != 0) return ans[i][j];
	if (matrix[i][j] == 0) return 0;
	int min1 = INT_MAX;
	for (int m = 0; m < 4; m++)
	{
		int dis = 1;
		int x = i + dx[m], y = j + dy[m];
		if (x >= 0 && x < row && y >= 0 && y < column)
		{
			dis += getDIstance(matrix, row, column, x, y, ans);			
		}
		min1 = min(min1, dis);
		if (min1 == 1) break; //如果不为0 ，则1已经为最小值
	}
	ans[i][j] = min1;
	return ans[i][j];
}

//vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
//{
//	int row = matrix.size();
//	if (row == 0) return {};
//	int column = matrix[0].size();
//	vector<vector<int>> ans(row, vector<int>(column, 0));
//	queue<vector<int>> q;
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < column; j++)
//		{
//			//getDIstance(matrix, row, column, i, j, ans);   DSF写不通
//			if (matrix[i][j] == 1 && ans[i][j] == 0)
//			{
//				for (int m = 0; m < 4; m++)
//				{
//					int x = i + dx[m], y = j + dy[m];
//					if (x >= 0 && x < row && y >= 0 && y < column)
//						q.push({ x,y });
//				}
//				int cnt = 0;
//				while (q.size())
//				{
//					vector<int> top = q.front();
//					q.pop();
//					int size = q.size();
//					for (int temp = 0; temp < size; temp++)
//					{
//						if (matrix[top[0]][top[1]] == 0)
//					}
//					cnt++;
//				}
//				ans[i][j] = cnt;
//			}				
//		}
//	}
//	return ans;
//}

//看了题解，和岛屿一样，将所有的0压入队列，值为1，然后BFS遍历寻找1，一定要标记是否被访问过
//BFS的运用不熟练呀
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
{
	int row = matrix.size();
	if (row == 0) return {};
	int column = matrix[0].size();
	vector<vector<int>> ans(row, vector<int>(column, 0));
	vector<vector<int>> visited(row, vector<int>(column, 0));
	queue<vector<int>> q;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (matrix[i][j] == 0)
			{
				visited[i][j] = 1;
				q.push({ i,j });
			}
		}
	}
	int cnt = 0;
	while (q.size())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			vector<int> top = q.front();
			q.pop();

			for (int m = 0; m < 4; m++)
			{
				int x = top[0] + dx[m], y = top[1] + dy[m];
				if (x >= 0 && x < row && y >= 0 && y < column && visited[x][y] != 1)
				{
					if (matrix[x][y] == 1)				//0全部被压入队列了，这个时候肯定是1呀
						ans[x][y] = ans[top[0]][top[1]] + 1;
					/*else*/    //把每轮遍历到的节点压入队列，方便进行下一轮的扩散
						q.push({ x,y });
					visited[x][y] = 1;
				}
			}
		}		
		cnt++;
	}
	return ans;
}

int main(void)
{
	vector<vector<int>> matrix = { {0,0,0},{0,1,0},{1,1,1} };
	vector<vector<int>> ans = updateMatrix(matrix);
	return 0;

}