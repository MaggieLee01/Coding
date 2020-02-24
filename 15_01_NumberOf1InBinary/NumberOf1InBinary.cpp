//请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。
//例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。
// https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof

//初步思路，与1做与运算 结果为1或者0 即可判断最后一位 一次右移
int numOfBit1(int num)
{
	int ans = 0;
	while (num > 0)
	{
		if (num & 1) ans++;
		num = num >> 1;
	}
	return ans;
}
//看了课本详解
//没考虑负数
//负数0x80000000右移一位时变成了0xC0000000，一直右移的话变成了0xFFFFFFFF
//因此应该将做与运算的 1 左移，优于将输入的实参右移
int numOfBit1_01(int num)
{
	int ans = 0;
	unsigned int flag = 1;//一定要设置为unsigned
	while (flag)//移出界
	{
		if (num & flag) ans++;
		flag << 1;
	}
	return ans;
}
//更优的解法 利用位运算
int numOfBit1_02(int num)
{
	int ans = 0;
	while (num)
	{
		ans++;
		num = num & (num - 1);
	}
	return ans;
}
int main(void)
{
	int ans = numOfBit1(3);
	ans = numOfBit1_02(9);	
}