/*如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
[2,3,4] 的中位数是 3；
[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：
	void addNum(int num) - 从数据流中添加一个整数到数据结构中。
	double findMedian() - 返回目前所有元素的中位数。

	https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof */

//困难等级的题目，简单暴力的排序不行，想到了堆相关的操作，但是不了解二叉堆，不太会用标准库里面的函数，因此看了labuladong的文章，之前欠了文章
//https://mp.weixin.qq.com/s/o7tdyLiYm668dpUWd-x7Lg 2019-07-30 图文详解二叉堆，实现优先级队列 


#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using std::greater;
using std::vector;
using std::priority_queue;
using std::push_heap;
using std::pop_heap;//看这样，不用make_heap也行

//使用优先级队列数据结构，参考题解
class MedianFinder {
private:
	priority_queue<int> max;
	priority_queue<int, vector<int>, greater<int> > min;//greater的头文件为function
public:
	MedianFinder() {}
	void addNum(int num) 
	{
		//右边元素大于或者等于左边元素，
		min.push(num);
		max.push(min.top());
		min.pop();
		if (max.size() > min.size())
		{
			min.push(max.top());
			max.pop();
		}
	}
	double findMedian() 
	{
		if (min.size() == max.size())
			return (max.top() + min.top()) / 2.0;
		else
			return min.top();
	}
};

//利用堆排序库函数实现堆，剑指offer
class MedianFinder01 
{
private:
	vector<int> max;
	vector<int> min;
public:
	MedianFinder01() {}
	void addNum(int num) 
	{
		if (((max.size() + min.size()) & 01) == 0)//第奇数个元素插在右边min堆，==高于 &，优先级有出错
		{
			if (max.size() && max[0] > num)//该元素太小，应该放在左边的max堆，所以需要交换数据
			{
				max.push_back(num);
				push_heap(max.begin(), max.end());//push_heap默认大堆根

				num = max[0];

				pop_heap(max.begin(), max.end());
				max.pop_back();

			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<int>() );//注意此处需要加（）和最优队列的格式不需要加（） 不一样
		}
		else
		{
			if ( (min.size() && min[0]) < num)
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());

				num = min[0];

				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end());
		}
	}

	double findMedian() 
	{
		int size = max.size() + min.size();
		if (size == 0) return -1;
		if ((size & 1) == 1)
			return min[0];//上面是最优队列 有top，此处是vector，为第一个值
		else
			return (max[0] + min[0]) / 2.0;
	}
};

//手工实现优先级队列，labuladong，写在了Utilities的项目里面

void main(void)
{
	MedianFinder01 n;
	n.addNum(1);
	n.addNum(2);
	double m = n.findMedian();
	n.addNum(3);
	m = n.findMedian();
}