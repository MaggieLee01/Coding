#include<vector>
using namespace std;

/*给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof */


//自己写的，正确但是超时
vector<int> constructArr(vector<int>& a)
{
	int len = a.size();
	vector<int> ans(len, 1);
	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			ans[j] *= a[(j + i) % len];
		}
	}
	return ans;
}

//看大神题解，不要双重遍历
vector<int> constructArr01(vector<int>& a)
{
	int len = a.size();
	vector<int> ans(len, 1);
	if (len == 0) return ans;
	int left = 1, right = 1;
	for (int i = 0; i < len; i++)
	{
		//上下三角形的方法，刚好对角线处为1
		ans[i] *= left;
		left *= a[i];

		ans[len - i - 1] *= right;
		right *= a[len - i - 1];
	}
	return ans;
}


int main(void)
{
	vector<int> ans = { 1,2,3,4,5 };
	constructArr01(ans);
	return 0;
}