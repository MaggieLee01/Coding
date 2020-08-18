//网易 求立方体表面积，已AC
#include<iostream>
#include<vector>
using namespace std;

int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

void GetcrubArea(vector<vector<vector<int>>> &crub, int &area, int x, int y, int z)
{
	if (crub[x][y][z] == 2) return;
	crub[x][y][z] = 2;
	for (int i = 0; i < 6; i++)
	{
		int xNew = x + dx[i];
		int yNew = y + dy[i];
		int zNew = z + dz[i];

		if (0 <= xNew && xNew <= 20 && 0 <= yNew && yNew <= 20 && 0 <= zNew && zNew <= 20 && crub[xNew][yNew][zNew] == 1)
			area = area - 2;
	}
}
int main(void)
{
	int n = 0;
	cin >> n;
	vector<vector<vector<int>>> crub(21, vector<vector<int>>(21, vector<int>(21, 0)));
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> z;
		crub[x][y][z] = 1;
	}
	int totalArea = n * 6;
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			for (int k = 0; k < 21; k++)
			{
				if (crub[i][j][k] == 1)
					GetcrubArea(crub, totalArea, i, j, k);
			}
		}
	}
	cout << totalArea << endl;
	return 0;
}