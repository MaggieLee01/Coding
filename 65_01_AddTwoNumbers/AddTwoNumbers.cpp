//写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
// https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/

//虽然知道要用位运算，但是还是不知道如何操作，看了答案深深佩服，自己想不到
//不考虑进位时，两个二进制数相加，用异或表示；只有1+1才有进位，因此，用 & 后左移表示
//加法的三步走：先计算不考虑进位的和，接着计算进位，然后把进位与 和相加。这便是一个循环过程，直到进位为0结束
int add(int a, int b) 
{
	int sum = 0, carry = 0;
	do
	{
		sum = a ^ b;
		carry = (unsigned int)(a&b) << 1;
		a = sum;
		b = carry;

	} while (b!=0);
	return a;//进位为0则表示计算结束了
}
//看了题解，值得学习的点
//LeetCode c++ 不允许负数左移操作，所以要转换成无符号整数。上面的计算方法适合负数运算
//可以写成递归的形式
int add_Re(int a, int b) 
{
	return b ? add_Re(a^b, (unsigned int)(a&b) << 1) : a;
}

