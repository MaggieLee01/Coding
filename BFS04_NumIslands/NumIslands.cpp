/*200. ��������
����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������
�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γɡ�
���⣬����Լ��������������߾���ˮ��Χ��
ʾ�� 1:
����:
11110
11010
11000
00000
���: 1

ʾ�� 2:
����:
11000
11000
00100
00011
���: 3
����: ÿ������ֻ����ˮƽ��/����ֱ���������ڵ�½�����Ӷ��ɡ�
https://leetcode-cn.com/problems/number-of-islands/
*/

#include<vector>
#include<queue>
using namespace std;

//�Լ�д�Ĵ��˼·���ҵ�һ��½�غ�������ɢ�����Ϊ½������ӣ�ֱ������Ϊ�գ�����ӵ�½���γ�һ������
//��������̫�࣬Ӱ������
//Ϊ�˷�ֹ�ظ�����������е�ʱ���Ҫ���ѷ��ʱ��
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
//����⣬ѧϰ���鼯��д����д����UF�Ĺ�������