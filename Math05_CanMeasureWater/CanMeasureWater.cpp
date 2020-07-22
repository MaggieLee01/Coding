/*	有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？
	如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。
	你允许：
	装满任意一个水壶
	清空任意一个水壶
	从一个水壶向另外一个水壶倒水，直到装满或者倒空
	
	输入: x = 3, y = 5, z = 4；输出: True	
	输入: x = 2, y = 6, z = 5；输出: False
*/

//该题目，没思路，看题解
//#include<bits/stdc++.h>
#include<utility>
#include<unordered_set>
#include<stack>
#include<functional>
#include<algorithm>
using std::swap;
using std::min;
using std::hash;
using std::unordered_set;
using std::stack;
using std::pair;

//DFS算法，运用了很多不常用的C++特性，目前 unordered_set 默认的hash函数仅支持build-in类型及string等少数类型。其他类型或用户自定义类型，需要自己编写hash函数
//题解里有状态转换

using PII = pair<int, int>;
bool canMeasureWater(int x, int y, int z) 
{
	stack<PII> stk;
	stk.emplace(0, 0);
	//注意下面一句hash函数的定义，很多C++11的语法：
	//auto自动推测类型；
	//[]匿名函数，所以函数体内的语句应该以；结束
	//template <class T> struct hash;  std::hash是一个模板类，所以 hash<int>()在typename加上()为产生临时对象，然后hash重载了()，返回参数的hash值
	//正常使用hash函数的方法：
	/*	char nts1[] = "Test";
		std::hash<char*> ptr_hash;
		ptr_hash(nts1);//得到了Test的哈希值
	*/
	auto hash_function = [](const PII &o) {return hash<int>() (o.first) ^ hash<int>() (o.second); };
	//此处为decltype关键字，hash_function相当于是一个function object，通过decltype获得其type
	unordered_set<PII, decltype(hash_function) > seen(0, hash_function);//括号里面也一定要加hash_function
	while (stk.size())
	{
		if (seen.count(stk.top()))
		{
			stk.pop();
			continue;
		}
		seen.emplace(stk.top());
		//auto[remain_x, remain_y] = stk.top(); 答案上这样，我的编译器推导不出来
		auto remain = stk.top();
		stk.pop();
		if (remain.first == z || remain.second == z || remain.first + remain.second == z)
			return true;
		//把6种可以进行的操作表示出来，循环进行
		stk.emplace(x, remain.second);		//把X壶灌满
		stk.emplace(remain.first, y);		//把y壶灌满
		stk.emplace(0, remain.second);		//把x壶倒空
		stk.emplace(remain.first, 0);		//把y壶倒空
		stk.emplace(remain.first - min(remain.first, y - remain.second), 
					remain.second + min(remain.first, y - remain.second));		// 把 X 壶的水灌进 Y 壶，直至灌满或倒空。
		stk.emplace(remain.first + min(x - remain.first, remain.second), 
					remain.second - min(x - remain.first, remain.second));		// 把 Y 壶的水灌进 X 壶，直至灌满或倒空。
	}
	return false;
}
//数学方法，以两壶水的总量来分析，变化为 增减x、增减y
//贝祖定理告诉我们，ax + by = z 有解当且仅当 z 是 x y 的最大公约数的倍数。因此我们只需要找x, y 的最大公约数并判断 z 是否是它的倍数即可。
int gcd(int x, int y)//已经保证 x > y
{
	if (x % y == 0) return y;
	gcd(y, x % y);
}
bool canMeasureWater01(int x, int y, int z)
{
	if (x + y < z) return false;
	if (x == 0 || y == 0) return (z == 0 || x + y == z);
	if (x < y) swap(x, y);
	return z % gcd(x, y) == 0;
}

//这个题解很有意思，图片解释了数学方法，同时也使用了BFS(路径最短）算法，但队列中的元素不是pair，而是两个壶水的总量
//https://leetcode-cn.com/problems/water-and-jug-problem/solution/hu-dan-long-wei-liang-zhang-you-yi-si-de-tu-by-ant/
//https://leetcode-cn.com/problems/water-and-jug-problem/solution/cjian-dan-hui-su-si-chong-zhuang-tai-by-zhuangmeng/
int main()
{
	bool ans = canMeasureWater(3, 5, 4);
	ans = canMeasureWater01(3, 5, 4);
	return 0;
}