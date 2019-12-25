#include <cstdio>
//#include <iostream>
#include <vector>
//#include<algorithm>
// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:             
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字

//基数排序的思路，元素放在索引为该元素的位置，思考：对于不连续的数组，如何基数排序的
bool duplicate(std::vector<int> nums) 
{
	int n = nums.size();
	for (int i = 0; i < n; ++i) {
		while (i != nums[i] - 1) {
			if (nums[i] == nums[nums[i] - 1])
				return nums[i];
			std::swap(nums[i], nums[nums[i] - 1]);
		}
	}
	return -1;

}