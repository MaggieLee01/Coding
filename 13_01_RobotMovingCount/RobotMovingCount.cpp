/*地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
请问该机器人能够到达多少个格子？
输入：m = 2, n = 3, k = 1；输出：3
输入：m = 3, n = 1, k = 0；输出：1
1 <= n,m <= 100，0 <= k <= 20
https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof  */

//看完题目，考察点，遍历矩阵的顺序，还是统计数字呢，写了部门矩阵，通过观察数字各个位求规律暂时解决不了
//还有一点注意，一定能从[0][0]到达，遍历的话，不存在该问题

//妈呀 按照思路一遍通过LeetCode，思考优化

//看了书本答案，部分地方仅适合1 <= n,m <= 100，0 <= k <= 20的样例，需要完善
//例如，求各个位之和[我的仅适合不超过两位数]；判断输入是否为0，用小于等于比用等于更佳；
//但是，答案上四个方向扩散，个人认为没有必要，右下两个方向即可，因为出发点为左上角
//答案上，满足小于k之后，flag才变为1，个人认为，只要遍历过即可置为1，减少遍历次数

//看了题解，通篇在说，bfs，dfs，还有用栈 队列写法的，以后再看
//看到自己写的调用递归函数不管返回值，将计数结果作为引用形参，不断传递，
//明白了12题目字符串路径一个题解疑惑，那个是将全局变量作为结果，不关心递归函数的返回值

#include<vector>
#include<iostream>
using std::cout;
using std::endl;
using std::vector;

//看了答案 新增
int getDigitSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number = number / 10;
	}
	return sum;
}

//书本答案命名为movingCountCore，值得借鉴
//可以将count作为全局变量，貌似static也有此功能？？减少形参个数
//已测试，main中定义局部static时，无法在EnterCount中使用，static的用法是？？
//粗略看了一下，静态局部变量只能被其作用域内的变量或函数访问。
//也就是说虽然它会在程序的整个生命周期中存在，由于它是static的，它不能被其他的函数和源文件访问

int EnterCount(int c, int r, vector<vector<int> >&flag, int &count,int m, int n, int k)
{
	if (c < m && r < n && flag[c][r] == 0)
	{
		flag[c][r] = 1;//来过即标记，无论成功与否
		//if ((c % 10 + c / 10 + r / 10 + r % 10) <= k )
		if (getDigitSum(c) + getDigitSum(r) <= k)
		{
			count++;			
			EnterCount(c + 1, r, flag, count, m, n, k);
			EnterCount(c, r + 1, flag, count, m, n, k);
			/*EnterCount(c + 1, r, flag, m, n, k);
			EnterCount(c, r + 1, flag, m, n, k);*/
		}
	}
	return 0;
}
int movingCount(int m, int n, int k) 
{
	//if (m == 0 || n == 0) return 0;
	if (m <= 0 || n <= 0 || k < 0) return 0;
	vector<vector<int> >flag(m + 1, vector<int>(n + 1, 0));
	static int count = 0;
	EnterCount(0, 0, flag, count, m, n, k);
	//EnterCount(0, 0, flag, m, n, k);
	return count;
}

int main(void)
{
	int m = 2, n = 3, k = 1;
	int ans = movingCount(m, n, k);
	cout << ans << endl;

	m = 3, n = 1, k = 0;
	ans = movingCount(m, n, k);
	cout << ans << endl;

	m = 10, n = 10, k = 7;
	ans = movingCount(m, n, k);
	cout << ans << endl;
	return 0;
}