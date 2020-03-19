/*�ڸ����������У�ÿ����Ԫ���������������ֵ֮һ��
	ֵ 0 ����յ�Ԫ��
	ֵ 1 �����������ӣ�
	ֵ 2 �����õ����ӡ�
ÿ���ӣ��κ��븯�õ����ӣ��� 4 ���������ϣ����ڵ��������Ӷ��ḯ�á�
����ֱ����Ԫ����û����������Ϊֹ�����뾭������С����������������ܣ����� -1��
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
//	//if (grid[r][c] == 0 || grid[r][c] == 3) //����������û�н���ʱ������0 
//	//	return ;
//	
//	if (grid[r][c] == 1)	
//		grid[r][c] = 2;			
//	if (grid[r][c] == 2)
//	{
//		ans++;//һ�θ����ĸ��������ڴ˴�++
//		grid[r][c] = 3;	//�����ظ�����
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
//	//Ѱ�ҵ�һ�������Ľ���
//	int i = 0, j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < column; j++)
//		{
//			if (grid[i][j] == 2) break;
//		}
//		if (j < column) break;
//	}
//	if (i >= row || j >= column) return 0;//û�и��ܵĽ���
//
//	int ans = -1;
//	orangesRotting_Core(grid, row, column, i, j, ans);
//	//�ڱ���һ�Σ���������ʽ����򷵻�-1
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

//�����˼·Ϊ���ҵ�һ������������������ɢ�ݹ飬��������dfs������˼·���ԣ�
//bfs���������и�������ͬʱ��ɢ�����ܵݹ飬�ݹ�����dfs
//˼·���ҵ����еĻ����ӣ�����У����Σ����ݰ���δ�ӡ��������˼·�뵽���е����ݽṹ
int orangesRotting(vector<vector<int>>& grid)
{
	int row = grid.size();
	if (row == 0) return 0;
	int column = grid[0].size();

	//ʲô�������ݽṹ��ʾ����㣬������Ԫ�ص����飿
	queue<vector<int> > OnceRotPosition;
	int ans = -1;//�ʼ�ĸ������Ӳ���Ҫʱ�䣬���Ǽ����м�++��

	//Ѱ�Ҹ����Ľ���
	int fresh = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{	
			if (grid[i][j] == 1) fresh++;
			if (grid[i][j] == 2) OnceRotPosition.push({i,j});			
		}
	}
	if (OnceRotPosition.empty())//û������ƻ��
	{
		if (fresh > 0) return -1;//�����ʵ�ˮ��
		else return 0;
	}
	OnceRotPosition.push({ -1,-1 });
	while (OnceRotPosition.size())
	{
		vector<int> top = OnceRotPosition.front();
		OnceRotPosition.pop();
		int r = top[0], c = top[1];
		if (r == -1 && c == -1  )//ÿ������ɢ������־
		{
			ans++;
			if (OnceRotPosition.empty()) break;//��������û����
			OnceRotPosition.push({ -1,-1 });
			continue;
		}
		//if (grid[r][c] == 1) grid[r][c] = 2;//ѹ����е�ʱ���Ӧ�ñ�Ϊ2��������һ�����ظ�����ĳ���ڵ㣬����ʱ��δ�������ýڵ㣬��δ���ü���Ϊ2
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
	//�ڱ���һ�Σ���������ʽ����򷵻�-1
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
//�о��Լ�д���е㷱��������⣬�󲿷ֶ��Ƕ��д������ִ���ϸ�ڲ�ͬ�����д��Ϊ��ͬ����ϸ�ڵ����
//���ĸ����ʾ�ĸ����򣬼������ĸ�������ɢ�Ĵ�����
//������pair��ʾ����㣬���õ��������ʾ��������
//�����֮������ַ���������ÿ��ĩβ����{-1,-1}��Ϊ���������е�����ʱqueue������n��Ȼ��forѭ������ǰn����
//�Ƿ���δ���������Ľ��ӣ����Ը��ݽ��ӵ������жϣ����������±�����һ������

//bfs�����л����Ŀ�ܡ��� BFS �������·���Ļ�����������е� 1 ��͵� 2 ��Ľ��������һ���޷����֡�
//��ˣ�������Ҫ��΢�޸�һ�´��룬��ÿһ�������ʼǰ����¼�����еĽ������ nnn ��Ȼ��һ������������һ��� nnn ����㡣
// https://leetcode-cn.com/problems/rotting-oranges/solution/li-qing-si-lu-wei-shi-yao-yong-bfsyi-ji-ru-he-xie-/

//�������ĸ��ִ������������Լ��Ĵ���
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
				for (auto n : dy){*/ //ֻ��4������ѽ�������������16��
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