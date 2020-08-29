//https://leetcode-cn.com/problems/count-primes/solution/ru-he-gao-xiao-pan-ding-shai-xuan-su-shu-by-labula/
//统计所有小于非负整数 n 的质数的数量

#include<vector>
using namespace std;
//可以用位优化，C++专门有bitset的库函数，操作更方便一些，set方法就是置为1
//本次暂不使用，使用bool
int countPrimes(int n) 
{
	vector<bool> vec(n, true);
	int ans = 0;
	for (long i = 2; i < n; i++)
	{
		if (vec[i])
		{
			ans++;
			//遍历的时候优化，避免2*3 3*2的重复优化，vec[i]的倍数不是素数
			for (long j = i * i; j < n; j += i)
				vec[j] = false;
		}
	}
	return ans;
}
