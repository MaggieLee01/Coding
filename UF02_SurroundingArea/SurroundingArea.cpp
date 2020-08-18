//https://mp.weixin.qq.com/s/K_oV5JWYpBo9cWTHz6e35Q 练习
/*给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:
X X X X
X O O X
X X O X
X O X X

运行你的函数后，矩阵变为：
X X X X
X X X X
X X X X
X O X X

解释:
被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

https://leetcode-cn.com/problems/surrounded-regions */


#include<vector>
using namespace std;

//看完题解方法，练习并查集
class UF
{
private:
	//记录分量的个数
	int count;
	//用数组的形式储存一棵树，想到了堆排序，类似
	vector<int> parents;
	//树的重量
	vector<int> size;
public:
	UF(int n) :count(n)
	{
		//parents.reserve(n);//cap变成n，size依然为0，reserve之后仍不可访问
		parents.resize(n);//cap变成n，size依然为0，reserve之后仍不可访问
		size.resize(n);
		for (int i = 0; i < n; i++)
		{
			//自己的父类是自己，自己的节点大小为1 
			parents[i] = i;
			size[i] = 1;
		}
	}
	//查找父节点的过程中进行路径压缩，使该节点成为父节点的父节点的子节点，即减少一层
	int find(int x)
	{
		while (parents[x] != x)
		{
			parents[x] = parents[parents[x]];
			x = parents[x];
		}
		return x;
	}
	bool BeConnected(int x, int y)
	{
		int xp = find(x);
		int yp = find(y);
		return xp == yp;
	}
	void Conn(int p, int q)
	{
		int rootP = find(p);
		int rootQ = find(q);
		if (rootP == rootQ) return;

		if (size[p] > size[q])
		{
			parents[rootQ] = rootP;
			/*size[p] += size[q];*/ //应该用根节点的大小，合并的也是根节点大小
			size[rootP] += parents[rootQ];
		}
		else
		{
			parents[rootP] = rootQ;
			size[rootQ] += size[rootP];
		}
		count--;
	}
};

void solve(vector<vector<char>>& board)
{
	int row = board.size();
	if (row == 0) return;
	int column = board[0].size();
	UF u(row * column + 1);
	int dummy = row * column;

	//转换为一维数组应该是 横坐标* 列数 + 纵坐标
	//而不是 横坐标 * 行数 + 纵坐标
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == 'O')
			u.Conn(i*column, dummy);
		if (board[i][column - 1] == 'O')
			u.Conn(i*column + column - 1, dummy);
	}
	for (int i = 0; i < column; i++)
	{
		if (board[0][i] == 'O')
			u.Conn(i, dummy);
		if (board[row - 1][i] == 'O')
			u.Conn((row - 1)*column + i, dummy);
	}
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	for (int i = 1; i < row - 1; i++)//注意此处不能遍历边界了
	{
		for (int j = 1; j < column - 1; j++)
		{
			//将O的上下左右联通
			if (board[i][j] == 'O')
			{
				for (int k = 0; k < 4; k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					if (0 <= x && x < row && 0 <= y && y < column &&board[x][y] == 'O')
						u.Conn(x*column + y, i*column + j);
				}
			}
		}
	}
	for (int i = 1; i < row - 1; i++)//注意此处不能遍历边界了
	{
		for (int j = 1; j < column - 1; j++)
		{
			if (!u.BeConnected(i*column + j, dummy))
				board[i][j] = 'X';
		}
	}
}

/*给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。

示例 1：
输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。

示例 2：
输出：["b==a","a==b"]
输入：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。

示例 3：
输入：["a==b","b==c","a==c"]
输出：true

示例 4：
输入：["a==b","b!=c","c==a"]
输出：false

示例 5：
输入：["c==c","b==d","x!=z"]
输出：true

https://leetcode-cn.com/problems/satisfiability-of-equality-equations */

bool equationsPossible(vector<string>& equations)
{
	int num = equations.size();
	UF u(26);
	for (int i = 0; i < num; i++)
	{
		if (equations[i][1] == '=')
			u.Conn(equations[i][0] - 'a', equations[i][3] - 'a');
	}
	for (int i = 0; i < num; i++)
	{
		if (equations[i][1] == '!')
			if (u.BeConnected(equations[i][0] - 'a', equations[i][3] - 'a')) return false;
	}
	return true;
}







int main(void)
{
	vector<vector<char>> board =
	{ {'X','O','X','X'},
		{'O','X','O','X'},
		{'X','O','X','O'},
		{'O','X','O','X'},
		{'X','O','X','O'},
		{'O','X','O','X'} };
	solve(board);
	return 0;
}