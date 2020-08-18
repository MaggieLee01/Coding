// https://www.nowcoder.com/questionTerminal/360e2abc03fa4c49a21ca9b4d9aef1bf
/*	给出一个整型数组，其中除了两个数字只出现一次之外，其他的数字都出现了两次。请找出这两个只出现一次的数字。
	要求时间复杂度是 O(n) ，空间复杂度是 O(1) 。请简述思路。
*/

/**
对所有数字进行异或操作，得到的最后结果就是两个只出现一次的数字的异或；
这两个数字不相等，所有异或者结果中肯定至少有一位是1；
以这个为1的位为界，划分数组为这位为1和这位为0两组，分别做异或操作，得到的两个结果就是这两个数字 **/

//牛客网答案代码 未来得及修饰
#include<vector>
using std::vector;
vector<int> getOnce(vector<int> arr) {
	vector<int> res;
	if (arr.size() == 0) return res;
	int num1 = 0, num2 = 0;
	int xorAllRes = 0;
	for (auto iter = arr.begin(); iter != arr.end(); ++iter)
	{
		xorAllRes ^= *iter;
	}
	int k = 0;
	while ((xorAllRes & 1) == 0)
		++k; //找到抑或结果最低位的1的位置，记录为k    
	for (auto iter = arr.begin(); iter != arr.end(); ++iter)
	{
		if (((*iter >> k) & 1) == 1)
		{ //第k位为1，则为第"1"类，与num1异或            
			num1 ^= *iter;
		}
		else
		{ //否则，属于第二类，与num2异或            
			num2 ^= *iter;
		}
	}
	res.push_back(num1);
	res.push_back(num2);
	return res;
}