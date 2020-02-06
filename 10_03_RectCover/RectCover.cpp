//剑指offer扩展
//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
#include<iostream>
#include<vector>

int RectCover(int number)
{
	//2*n的大矩形
	//target > 2 分为两步考虑： 
	//第一次摆放一块 2 * 1 的小矩阵【即竖着放】，则摆放方法总共为f(target - 1)
	//第一次摆放一块 1 * 2 的小矩阵【即横着放】，则摆放方法总共为f(target-2) 
	//即斐波那契数列
}