/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。
	
输入：[1,8,6,2,5,4,8,3,7]
输出：49

https://leetcode-cn.com/problems/container-with-most-water */

//看到标签，双指针，难点在于想好指针如何移动。曾考虑记录遍历过的maxLeft maxRight；结果发现移动两边的较小者即可。
#include<vector>
#include<algorithm>
using namespace std;
int maxArea(vector<int>& height)
{
	int Length = height.size();
	int left = 0, right = Length - 1, ans = 0;
	while (left < right)
	{
		//int area = min(height[left], height[right]) * (right - left);//此处可以写在if里面省去了比较的次数
		//ans = max(ans, area);

		//在考虑相等的时候，曾考虑优先保留离端点最近的一遍，看答案之后发现多虑了，因为中间的最大值不确定在哪边出现，可能与离端点近的一遍距离更小
		//if (height[left] < height[right] || height[left] == height[right] && left >= Length - right - 1)
		if (height[left] < height[right])
		{
			left++;
			ans = max(ans, height[left] * (right - left));
		}			
		//else if (height[left] > height[right] || height[left] == height[right] && left < Length - right - 1)
		else
		{
			right--;
			ans = max(ans, height[right] * (right - left));
		}			
	}
	return ans;
}
//看了题解，证明指针的移动规则，提到了消除短板边，
//	其实无论是移动短指针和长指针都是一种可行求解。 只是，一开始就已经把指针定义在两端，如果短指针不动，而把长指针向着另一端移动，
//	两者的距离已经变小了，无论会不会遇到更高的指针，结果都只是以短的指针来进行计算。 故移动长指针是无意义的。
/*	由于面积取决于边长短的那一端假设为m，所以要想得到比当前更大的面积，边长短的那一端必须舍弃，
	因为如果不舍弃，高最大就是m，而随着指针的移动宽会一直减小，因此面积只会越来越小。
*/