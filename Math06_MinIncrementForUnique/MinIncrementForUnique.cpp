/*给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。返回使 A 中的每个值都是唯一的最少操作次数。

输入：[1,2,2]
输出：1
解释：经过一次 move 操作，数组将变为 [1, 2, 3]。

输入：[3,2,1,2,1,7]
输出：6
解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。
https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique */

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using std::min;
using std::sort;
using std::unordered_set;
using std::vector;

//自己写的，最后几个大的测试样例不通过
int minIncrementForUnique(vector<int>& A)
{
	vector<int> needChange;
	unordered_set<int> store;
	int ans = 0;
	for (int i : A)
	{
		if (store.count(i) == 1) needChange.push_back(i);
		store.insert(i);
	}
	for (int i : needChange)
	{
		while (store.count(i) == 1)
		{
			ans++;
			i++;
		}
		store.insert(i);
	}
	return ans;
}

//最后几个大的测试样例不通过，看题解

//排序的方法，对于重复数字不断加1大于前面是数字即可，此处使用了优化的方法
//优化的方法：当我们找到一个没有出现过的数的时候，将之前某个重复出现的数增加成这个没有出现过的数。
//注意，这里 「之前某个重复出现的数」 是可以任意选择的，它并不会影响最终的答案，因为将 P 增加到 X 并且将 Q 增加到 Y，与将 P 增加到 Y 并且将 Q 增加到 X 都需要进行 (X + Y) - (P + Q) 次操作。
//优化的操作方法是，直接减去重复元素的值，然后直接加上最小的没出现的数字
int minIncrementForUnique01(vector<int>& A)
{
	if (A.empty()) return 0;
	sort(A.begin(), A.end());
	int ans = 0, taken = 0;
	int Length = A.size();
	for (int i = 1; i < Length; i++)
	{
		if (A[i] <= A[i - 1])
		{
			taken++;
			ans -= A[i];//减去重复的元素值，并增加重复元素的计数值
		}
		else 
		{
			int give = min(taken, A[i] - 1 - A[i - 1]);//最多在在此处增加的元素个数
			ans += give * A[i - 1] + give * (give + 1) / 2;
			taken -= give;
		}
	}
	if (taken > 0)//
		ans += taken * A.back() + taken * (taken + 1) / 2;
	return ans;
}
//看了其他的题解，貌似感觉上面的优化意义不太大
int minIncrementForUnique0102(vector<int>& A)
{
	if (A.empty()) return 0;
	sort(A.begin(), A.end());
	int ans = 0;
	int Length = A.size();
	for (int i = 1; i < Length; i++)
	{
		if (A[i] <= A[i - 1])
		{
			ans += A[i - 1] + 1 - A[i];
			A[i] = A[i - 1] + 1;
		}
	}
	return ans;
}
//计数的方法，和排序的优化思路一样，不是一点一点地增加；评论里也有计数的逐步增加的方法；还可以记录最大值进一步优化
//数据范围40000
int minIncrementForUnique02(vector<int>& A) 
{
	if (A.empty()) return 0;
	int cnt[80000] = { 0 };
	for (int i : A) cnt[i]++;
	int ans = 0, taken = 0;
	for (int i = 0; i < 80000; i++)
	{
		if (cnt[i] > 1)
		{
			taken += cnt[i] - 1;
			ans -= i * (cnt[i] - 1);
		}
		else if (taken > 0 && cnt[i] == 0)
		{
			taken--;
			ans += i;
		}
	}
	return ans;
}

//压缩路径的线性探测方法，解决hash的方法之一，此方法值得借鉴
//https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/solution/ji-shu-onxian-xing-tan-ce-fa-onpai-xu-onlogn-yi-ya/
//下面程序的写法，vector作为函数的引用形参，已通过LeetCode测试。

//在评论的提示下，还发现一个关于vector作为全局变量时，初始化的问题。目前不知道为什么，已在评论中问
/* 评论的说法：	1.类似楼主的写法， 先声明int pos[80000]; ，后边再初始化 memset(pos, -1, sizeof(int)*80000);
				2.使用 vector<int> ，但是不能直接使用vector<int>pos(80000, -1); ，因为这会调用vector的带参构造函数进行初始化，
				需要先输入类型符，可以这样 vector<int>pos {vector<int> (80000, -1)}; ，
				或者先声明 vector<int>pos; ，后边在构造函数再进行初始化： pos = vector<int>(80000,-1);
*/

//下面在尝试使得vector作为全局变量，而不是作为函数的引用形参。在LeetCode中测试，
//	1. vector<int> pos(80000, -1);不能写在class的类体内，无法通过编译
//	2. vector<int> pos(80000, -1);写在了class的外面，个别测试样例能通过
//  3. vector<int>pos {vector<int> (80000, -1)}; 写在了class的外面，个别测试样例能通过；写在class类体内，能通过测试
//	4. vector<int>pos; 声明在class外面，main函数中写pos = vector<int>(80000,-1); OK


// 线性探测寻址（含路径压缩）
int findPos(int a, vector<int>& pos)
{
	int b = pos[a];
	if (b == -1) 
	{
		pos[a] = a;
		return a;
	}
	// 否则向后寻址
	// 因为pos[a]中标记了上次寻址得到的空位，因此从pos[a]+1开始寻址就行了（不需要从a+1开始）。
	b = findPos(b+1,pos);
	pos[a] = b; // 寻址后的新空位要重新赋值给pos[a]哦，路径压缩就是体现在这里。
	return b;
}
int minIncrementForUnique_hash(vector<int>& A)
{
	if (A.empty()) return 0;
	int ans = 0;
	vector<int> pos(80000, -1);
	// 遍历每个数字a对其寻地址得到位置b, b比a的增量就是操作数。
	for (int a : A)
	{
		int b = findPos(a, pos);
		ans += b - a;
	}
	return ans;
}


//引入了并查集，也有压缩路径的方法，并查集是一种数据结构，暂时还没仔细研究，以后再看
//https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/solution/tan-xin-suan-fa-bing-cha-ji-java-by-liweiwei1419/

//struct node 
//{
//	node* p = new node; // error: use of implicit or defaulted node::node() 
//};
struct A
{
	A() = default;          // OK
	A(int v) : v(v) { }     // OK
	const int& v = 42;      // OK
};
int main(void)
{
	A a1;    
	A a2(a1);// error: ill-formed binding of temporary to reference
			 
	//把A的构造参数改为引用，然后将int行变量初始化a2可以。

	std::cout << a1.v << std::endl;
	std::cout << a2.v << std::endl;

	return 0;
}