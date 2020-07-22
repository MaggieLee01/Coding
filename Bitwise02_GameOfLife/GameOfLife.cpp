/*���� �ٶȰٿ� ��������Ϸ�����Ϊ��������Ӣ����ѧ��Լ�����ζ١������� 1970 �귢����ϸ���Զ�����
����һ������ m �� n �����ӵ���壬ÿһ�����Ӷ����Կ�����һ��ϸ����
ÿ��ϸ��������һ����ʼ״̬��1 ��Ϊ��ϸ����live������ 0 ��Ϊ��ϸ����dead����ÿ��ϸ������˸�����λ�ã�ˮƽ����ֱ���Խ��ߣ���ϸ������ѭ�����������涨�ɣ�
	�����ϸ����Χ�˸�λ�õĻ�ϸ�����������������λ�û�ϸ��������
	�����ϸ����Χ�˸�λ����������������ϸ�������λ�û�ϸ����Ȼ��
	�����ϸ����Χ�˸�λ���г���������ϸ�������λ�û�ϸ��������
	�����ϸ����Χ������������ϸ�������λ����ϸ�����
���ݵ�ǰ״̬��дһ���������������������ϸ������һ����һ�θ��º�ģ�״̬��
��һ��״̬��ͨ������������ͬʱӦ���ڵ�ǰ״̬�µ�ÿ��ϸ�����γɵģ�����ϸ���ĳ�����������ͬʱ�����ġ�
���룺 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
�����
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]

���ף�
	�����ʹ��ԭ���㷨�����������ע�⣬��������и�����Ҫͬʱ�����£��㲻���ȸ���ĳЩ���ӣ�Ȼ��ʹ�����ǵĸ��º��ֵ�ٸ����������ӡ�
	�����У�����ʹ�ö�ά��������ʾ��塣ԭ���ϣ���������޵ģ�������ϸ����ռ�����߽�ʱ��������⡣�㽫��ν����Щ���⣿

	https://leetcode-cn.com/problems/game-of-life */

/*
	�ⷨһ������ռ䣬������ 
	�ⷨ����ԭ��ʹ����ż��������״̬���ٽ��л�ϸ������+2�����ı���ż�ԣ�ͨ����ż���ж�������������Եõ����
	�ⷨ����ԭ��ʹ��λ����������״̬������λ����洢���ݵ�д����̫����
*/
#include<vector>
#include<cmath>
using namespace std;

//�Լ�д�Ķ���ռ䷽��
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
	board = ans; //ע��˴�Ϊ��ֵ������������и�ֵҲ���ƶ�
}

//������⣬ԭ���㷨��������״̬���仯��״̬���ֿ���������2��������ż�ԣ�����λ����

//������״̬����ϸ������ϸ��״̬-1����ϸ������ϸ��״̬Ϊ2���������ֻ��ע��ʲôʱ��Ϊ1��ʲôʱ��Ϊ0������ط����ı仯
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
			if (board[i][j] == 1 && (living < 2 || living>3)) board[i][j] = -1;//��ϸ���������ϸ��
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

//λ���㣺00 01 10 11��ʾ�ĸ�״̬��Ȼ��λ���㣻�������һλ���浱ǰ״̬��ǰ������ʾ��Χ��ϸ���ĺ�
//д��͵ķ���
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
			board[i][j] |= living << 1;//������д������⣬���ʹ���ǰ��λ

			//����ֱ���ڱ���8��λ�õ�ʱ�����  board[i][j] += (board[x][y] & 1) << 1;
			//�����������֮������һλ���൱���������������ֱ��һ��ʼ���ǵ���2
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