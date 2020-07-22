/* 堆箱子。给你一堆n个箱子，箱子宽 wi、深 di、高 hi。箱子不能翻转，将箱子堆起来时，下面箱子的宽度、高度和深度必须大于上面的箱子。
实现一种方法，搭出最高的一堆箱子。箱堆的高度为每个箱子高度的总和。
输入使用数组[wi, di, hi]表示每个箱子。
https://leetcode-cn.com/problems/pile-box-lcci 
输入：box = [[1, 1, 1], [2, 3, 4], [2, 6, 7], [3, 4, 5]]
输出：10   */

//20200411网易互娱的笔试题，看着和信封的差不多，信封是二维，这个是三维，不能在用信封的二分法了
#include<vector>
#include<algorithm>
using namespace std;
static bool comp(vector<int> box1, vector<int> box2)
{
	if (box1[0] == box2[0])
	{
		if (box1[1] == box2[1]) return box1[2] < box2[2];
		else return box1[1] < box2[1];
	}
	else return box1[0] < box2[0];
}
int pileBox(vector<vector<int>>& box)
{
	if (box.size() == 0) return 0;
	sort(box.begin(), box.end(), comp);
	//int ans = 0; //for从1 开始，先初始化为0的值
	vector<int> height(box.size(), 0); //存储前n个盒子对应的最大高度
	height[0] = box[0][2];
	int ans = height[0];
	for (int i = 1; i < box.size(); i++)
	{
		//题目是要求总和最长，不是求个数最多
		//int maxbefore = 0；
		for (int j = 0; j < i; j++)
		{
			if (box[j][0] < box[i][0] && box[j][1] < box[i][1] && box[j][2] < box[i][2])
			{
				height[i] = max(height[i], height[j] + box[i][2]);
				//maxbefore = max(maxbefore, height[j]);
			}				
		}
		//可以在if条件里面找到i之前的最大值，for循环结束之后直接加i处的高度；而不是两个max比较，因为i之前的最大值要么存在要么为0 
		//height[i] = maxbefore + box[i][2];
		height[i] = max(height[i], box[i][2]);
		ans = max(height[i], ans);
	}
	return ans;
}

//这两天做动态规划，又不会找关系了，看题解，是第一个元素从小到大，第二个第三个元素从大到小，原因是？？
//明白了，由于后两个元素降序，当后面两个元素均大于该盒子时，则一定有第一个元素大于该盒子，减少了一次判断

int main(void)
{
	vector<vector<int>> box = { {1,2,1},{1,2,2},{1,2,3},{2,3,2},{2,3,3},{2,3,4},{3,4,3},{3,4,4},{3,4,5},{4,5,1},{4,5,2},{4,5,3} };
	int ans = pileBox(box);
	return 0;
}