/*根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。
每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
	如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
	如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
	如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
	如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。
下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。
输入： 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
输出：
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]

进阶：
	你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
	本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？

	https://leetcode-cn.com/problems/game-of-life */

/*
	解法一：额外空间，遍历； 
	解法二：原地使用奇偶性来保存状态；临近有活细胞，则+2，不改变奇偶性，通过奇偶性判断死活；最后遍历可以得到结果
	解法三：原地使用位运算来保存状态；利用位运算存储数据的写法不太熟练
*/
#include<vector>
#include<cmath>
using namespace std;

//自己写的额外空间方法
void gameOfLife(vector<vector<int>>& board)
{
	int row = board.size();
	if (row == 0) return;
	int column = board[0].size();

	int dx[8] = { 0,0,1,-1,-1,1,-1,1 };
	int dy[8] = { 1,-1,0,0,-1,-1,1,1 };
	vector<vector<int>> ans(row, vector<int>(column, 0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			int living = 0;
			for (int k = 0; k < 8; k++)
			{
				int x = i + dx[k], y = j + dy[k];
				if (0 <= x && x < row && 0 <= y && y < column)
					if (board[x][y] == 1) living++;					
			}
			if ((board[i][j] == 1 && 2 == living) || living == 3) ans[i][j] = 1;
			else ans[i][j] = 0;
		}
	}
	board = ans; //注意此处为赋值，运算符重载有赋值也有移动
}

//看了题解，原地算法：增加新状态【变化的状态区分开】；递增2，利用奇偶性；运用位运算

//增加新状态，活细胞到死细胞状态-1；死细胞到活细胞状态为2。我上面的只关注了什么时候为1，什么时候为0。这个地方关心变化
void gameOfLife01(vector<vector<int>>& board)
{
	int row = board.size();
	if (row == 0) return;
	int column = board[0].size();

	int dx[8] = { 0,0,1,-1,-1,1,-1,1 };
	int dy[8] = { 1,-1,0,0,-1,-1,1,1 };
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			int living = 0;
			for (int k = 0; k < 8; k++)
			{
				int x = i + dx[k], y = j + dy[k];
				if (0 <= x && x < row && 0 <= y && y < column)
					if (abs(board[x][y]) == 1) living++;
			}
			if (board[i][j] == 1 && (living < 2 || living>3)) board[i][j] = -1;//活细胞变成了死细胞
			if (board[i][j] == 0 && living == 3) board[i][j] = 2;			
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (board[i][j] == -1) board[i][j] = 0;
			if (board[i][j] == 2) board[i][j] = 1;
		}
	}
}

//位运算：00 01 10 11表示四个状态，然后位运算；或者最后一位保存当前状态，前几个表示周围活细胞的和
//写求和的方法
void gameOfLife02(vector<vector<int>>& board)
{
	int row = board.size();
	if (row == 0) return;
	int column = board[0].size();

	int dx[8] = { 0,0,1,-1,-1,1,-1,1 };
	int dy[8] = { 1,-1,0,0,-1,-1,1,1 };
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			int living = 0;
			for (int k = 0; k < 8; k++)
			{
				int x = i + dx[k], y = j + dy[k];
				if (0 <= x && x < row && 0 <= y && y < column)
					if (board[x][y] & 1 == 1) living++;
			}
			board[i][j] |= living << 1;//这样子写易于理解，将和存在前几位

			//或者直接在遍历8个位置的时候求和  board[i][j] += (board[x][y] & 1) << 1;
			//尤其在求完和之后左移一位，相当于扩大二倍，不如直接一开始就是递增2
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			int cnt = board[i][j] >> 1;
			if (board[i][j] & 1 == 1)
			{				
				if (cnt < 2 || cnt > 3) board[i][j] = 0;
				else board[i][j] = 1;
			}
			else
			{
				if(cnt == 3) board[i][j] = 1;
				else board[i][j] = 0;
			}			
		}
	}
}