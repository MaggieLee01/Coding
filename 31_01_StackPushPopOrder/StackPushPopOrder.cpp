/*	输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
	假设压入栈的所有数字均不相等。

	输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
	输出：true
	解释：我们可以按以下顺序执行：
	push(1), push(2), push(3), push(4), pop() -> 4,
	push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

	输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
	输出：false
	解释：1 不能在 2 之前弹出。

	https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof */

#include<vector>
#include<stack>
using std::stack;
using std::vector;

// 这个题目之前脑子里没印象了，自己的思路，双指针，按照push的顺序入栈，当遇到pop的数组时弹出
// 细节点：pushed遍历完后不能马上返回，应该判断栈中的数据是否和popped数组中的一样
bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
	stack<int> simu;
	int i = 0, j = 0;
	int iLength = pushed.size();
	int jLength = popped.size();
	if (iLength != jLength) return false;
	while (i <= iLength && j < jLength)
	{
		if (simu.size() && simu.top() == popped[j])
		{
			simu.pop();
			j++;
		}
		else if (i < iLength)
		{
			simu.push(pushed[i]);
			i++;
		}
		else break;
	}
	return (i == iLength && j == jLength && simu.empty());
}

//看了题解，有和我方法类似的，辅助模拟栈操作,写法不一样，原来这种遇见相同的pop()出来，就叫做贪心算法
bool validateStackSequences_01(vector<int>& pushed, vector<int>& popped)
{
	stack<int> simu;
	int j = 0;
	if (pushed.size() != popped.size()) return false;
	for (auto i : pushed)
	{
		simu.push(i);
		while (simu.size() && simu.top() == popped[j])//  一定有 j < popped.size() 
		{
			simu.pop();
			j++;
		}
	}
	return (j == popped.size());
}
//还有一个时间换去空间的方法，寻找秘诀：向后随便找，向前不能跳。思路已理解，个人感觉较麻烦，未尝试其代码
//https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/solution/zhao-gui-lu-by-xixihahag/
/*对popped进行遍历，对其中的每一个数字到pushed中进行查找，把找到的置为-1。
比如popped第一个数字为4，那么就把pushed中4的位置变为-1。
现在在pushed中找popped的第二个数字5，记住刚才数字4在pushed中的位置，以此位置为界，
按照口诀，5可以出现在这个位置的后面，无论跳过几个数字都行。
但是如果出现在这个位置的前面，就不能跳过未访问过的数字（既，不能跳过不为-1的数字） */

int main(void)
{
	vector<int> m = { 1,2,3,4,5 };
	vector<int> n = { 4,5,3,2,1 };
	bool l = validateStackSequences(m, n);

	m = { 1,2,3,4,5 };
	n = { 4,3,5,1,2 };
	l = validateStackSequences(m, n);
	return 0;
}
