/*
������������һ�ݴ�СΪ N x N �ġ���ͼ�������� grid�������ÿ�������򡻣���Ԫ�񣩶��� 0 �� 1 ��Ǻ��ˡ�
���� 0 ������1 ����½�أ���֪������½��������Զ�ĺ�������������һ�����뷵�ظú����������������½������ľ��롣
��������˵�ľ����ǡ������پ��롻�� Manhattan Distance����(x0, y0) �� (x1, y1) ����������֮��ľ����� |x0 - x1| + |y0 - y1| ��
������ǵĵ�ͼ��ֻ��½�ػ��ߺ����뷵�� -1��

���룺[[1,0,1],[0,0,0],[1,0,1]]
�����2
���ͣ�
�������� (1, 1) ������½������֮��ľ��붼�ﵽ���������Ϊ 2��
https://leetcode-cn.com/problems/as-far-from-land-as-possible
*/

#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;

//�����뷨���ҵ����еĵ����������ÿ����һ�����󣬼������еľ��룻�ؼ��ǣ������ӣ�û�з��ӹ�ȱ���������ѽ
//���˿����õĽ��ӣ�������뷨�ˣ�ÿһ��������������ɢ֪�����ֺ���ֹͣ��
//˼·���ԣ��������̵���⣬�����ɢ�������ɢ���ĺ��������Զ���򡣰�������뷨д���벻����һ��Ͳ���дѽ

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
	return ans - 1;//ÿ��ɢһ���������1����ȥ�ʼ��һ�εĵ������
}
int main(void)
{
	vector<vector<int>> grid = { {1,0,0},{0,0,0},{0,0,0} };
	int ans = maxDistance(grid);
	return ans;
}