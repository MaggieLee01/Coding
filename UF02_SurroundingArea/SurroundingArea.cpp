//https://mp.weixin.qq.com/s/K_oV5JWYpBo9cWTHz6e35Q ��ϰ
/*����һ����ά�ľ��󣬰��� 'X' �� 'O'����ĸ O����
�ҵ����б� 'X' Χ�Ƶ����򣬲�����Щ���������е� 'O' �� 'X' ��䡣

ʾ��:
X X X X
X O O X
X X O X
X O X X

������ĺ����󣬾����Ϊ��
X X X X
X X X X
X X X X
X O X X

����:
��Χ�Ƶ����䲻������ڱ߽��ϣ����仰˵���κα߽��ϵ� 'O' �����ᱻ���Ϊ 'X'�� �κβ��ڱ߽��ϣ�����߽��ϵ� 'O' ������ 'O' ���ն��ᱻ���Ϊ 'X'���������Ԫ����ˮƽ��ֱ�������ڣ���������ǡ��������ġ�

https://leetcode-cn.com/problems/surrounded-regions */


#include<vector>
using namespace std;

//������ⷽ������ϰ���鼯
class UF
{
private:
	//��¼�����ĸ���
	int count;
	//���������ʽ����һ�������뵽�˶���������
	vector<int> parents;
	//��������
	vector<int> size;
public:
	UF(int n) :count(n)
	{
		//parents.reserve(n);//cap���n��size��ȻΪ0��reserve֮���Բ��ɷ���
		parents.resize(n);//cap���n��size��ȻΪ0��reserve֮���Բ��ɷ���
		size.resize(n);
		for (int i = 0; i < n; i++)
		{
			//�Լ��ĸ������Լ����Լ��Ľڵ��СΪ1 
			parents[i] = i;
			size[i] = 1;
		}
	}
	//���Ҹ��ڵ�Ĺ����н���·��ѹ����ʹ�ýڵ��Ϊ���ڵ�ĸ��ڵ���ӽڵ㣬������һ��
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
			/*size[p] += size[q];*/ //Ӧ���ø��ڵ�Ĵ�С���ϲ���Ҳ�Ǹ��ڵ��С
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

	//ת��Ϊһά����Ӧ���� ������* ���� + ������
	//������ ������ * ���� + ������
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
	for (int i = 1; i < row - 1; i++)//ע��˴����ܱ����߽���
	{
		for (int j = 1; j < column - 1; j++)
		{
			//��O������������ͨ
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
	for (int i = 1; i < row - 1; i++)//ע��˴����ܱ����߽���
	{
		for (int j = 1; j < column - 1; j++)
		{
			if (!u.BeConnected(i*column + j, dummy))
				board[i][j] = 'X';
		}
	}
}

/*����һ���ɱ�ʾ����֮���ϵ���ַ���������ɵ����飬ÿ���ַ������� equations[i] �ĳ���Ϊ 4�����������ֲ�ͬ����ʽ֮һ��"a==b" �� "a!=b"�������a �� b ��Сд��ĸ����һ����ͬ������ʾ����ĸ��������
ֻ�е����Խ�������������������Ա��������и����ķ���ʱ�ŷ��� true�����򷵻� false��

ʾ�� 1��
���룺["a==b","b!=a"]
�����false
���ͣ��������ָ����a = 1 �� b = 1����ô���������һ�����̣����޷�����ڶ������̡�û�а취�������ͬʱ�������������̡�

ʾ�� 2��
�����["b==a","a==b"]
���룺true
���ͣ����ǿ���ָ�� a = 1 �� b = 1 �������������������̡�

ʾ�� 3��
���룺["a==b","b==c","a==c"]
�����true

ʾ�� 4��
���룺["a==b","b!=c","c==a"]
�����false

ʾ�� 5��
���룺["c==c","b==d","x!=z"]
�����true

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