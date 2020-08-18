
#include<algorithm>
#include<vector>
using namespace std;
bool comp(vector<int> box1, vector<int> box2)
{
	if (box1[0] == box2[0])
	{
		if (box1[1] == box2[1])	return box1[2] > box2[2];
		else return box1[1] < box2[1];
	}
	return (box1[0] < box2[0]);
}

int maxBoxes(int** boxes, int boxesRowLen, int* boxesColLen)
{
	int column = *boxesColLen;
	vector<vector<int>> boxSize(boxesRowLen, vector<int>(3, 0));
	for (int i = 0; i < boxesRowLen; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			boxSize[i].push_back(boxes[i][j]);
		}
	}
	sort(boxSize.begin(), boxSize.end(), comp);
	/*vector<int> min = boxSize[0];
	int ans = 0;
	for (int i = 0; i < boxesRowLen; i++)
	{
		if (min[0] == boxSize[i][0]) continue;
		if (min[1] <= boxSize[i][1]) continue;
		if (min[2] <= boxSize[i][2]) continue;
		min = boxSize[i];
		ans++;
	}
	return ans;*/

	vector<int>poker(boxesRowLen, 0);
	poker[0] = boxSize[0][2];
	int ans = 1;
	for (auto box : boxSize)
	{
		int target = box[2];
		int left = 0;
		int right = ans - 1;//只有前面的有序，后面的都是0

		while (left <= right)
		{
			int mid = ((right - left) >> 1) + left;//左移一位时不加（）,计算不正确
			if (target == poker[mid])
				right = mid - 1;
			else if (target < poker[mid])
				right = mid - 1;
			else if (target > poker[mid])
				left = mid + 1;
		}

		if (left == ans)
			ans++;
		poker[left] = target;
	}
	return ans;
}