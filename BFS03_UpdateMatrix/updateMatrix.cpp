//https://leetcode-cn.com/problems/01-matrix/
/*����һ���� 0 �� 1 ��ɵľ����ҳ�ÿ��Ԫ�ص������ 0 �ľ��롣
��������Ԫ�ؼ�ľ���Ϊ 1 ��
����:
0 0 0
0 1 0
1 1 1
���:
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
//Ϊɶ�Ӽ��첻дBFS�Ͳ�����ѽ��
//�����ӵ�dfs�в�ͨѽ��������д�Ĳ���
//��������ѭ��������{ {0,0,0},{0,1,0},{1,1,1} }�ģ�1,1��ȡ���ڣ�2,1������2,1��ȡ���ڣ�2,2������2,2��ȡ���ڣ�2,1��
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
		if (min1 == 1) break; //�����Ϊ0 ����1�Ѿ�Ϊ��Сֵ
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
//			//getDIstance(matrix, row, column, i, j, ans);   DSFд��ͨ
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

//������⣬�͵���һ���������е�0ѹ����У�ֵΪ1��Ȼ��BFS����Ѱ��1��һ��Ҫ����Ƿ񱻷��ʹ�
//BFS�����ò�����ѽ
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
					if (matrix[x][y] == 1)				//0ȫ����ѹ������ˣ����ʱ��϶���1ѽ
						ans[x][y] = ans[top[0]][top[1]] + 1;
					/*else*/    //��ÿ�ֱ������Ľڵ�ѹ����У����������һ�ֵ���ɢ
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