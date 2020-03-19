/*��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
[2,3,4] ����λ���� 3��
[2,3] ����λ���� (2 + 3) / 2 = 2.5

���һ��֧���������ֲ��������ݽṹ��
	void addNum(int num) - �������������һ�����������ݽṹ�С�
	double findMedian() - ����Ŀǰ����Ԫ�ص���λ����

	https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof */

//���ѵȼ�����Ŀ���򵥱����������У��뵽�˶���صĲ��������ǲ��˽����ѣ���̫���ñ�׼������ĺ�������˿���labuladong�����£�֮ǰǷ������
//https://mp.weixin.qq.com/s/o7tdyLiYm668dpUWd-x7Lg 2019-07-30 ͼ��������ѣ�ʵ�����ȼ����� 


#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using std::greater;
using std::vector;
using std::priority_queue;
using std::push_heap;
using std::pop_heap;//������������make_heapҲ��

//ʹ�����ȼ��������ݽṹ���ο����
class MedianFinder {
private:
	priority_queue<int> max;
	priority_queue<int, vector<int>, greater<int> > min;//greater��ͷ�ļ�Ϊfunction
public:
	MedianFinder() {}
	void addNum(int num) 
	{
		//�ұ�Ԫ�ش��ڻ��ߵ������Ԫ�أ�
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

//���ö�����⺯��ʵ�ֶѣ���ָoffer
class MedianFinder01 
{
private:
	vector<int> max;
	vector<int> min;
public:
	MedianFinder01() {}
	void addNum(int num) 
	{
		if (((max.size() + min.size()) & 01) == 0)//��������Ԫ�ز����ұ�min�ѣ�==���� &�����ȼ��г���
		{
			if (max.size() && max[0] > num)//��Ԫ��̫С��Ӧ�÷�����ߵ�max�ѣ�������Ҫ��������
			{
				max.push_back(num);
				push_heap(max.begin(), max.end());//push_heapĬ�ϴ�Ѹ�

				num = max[0];

				pop_heap(max.begin(), max.end());
				max.pop_back();

			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<int>() );//ע��˴���Ҫ�ӣ��������Ŷ��еĸ�ʽ����Ҫ�ӣ��� ��һ��
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
			return min[0];//���������Ŷ��� ��top���˴���vector��Ϊ��һ��ֵ
		else
			return (max[0] + min[0]) / 2.0;
	}
};

//�ֹ�ʵ�����ȼ����У�labuladong��д����Utilities����Ŀ����

void main(void)
{
	MedianFinder01 n;
	n.addNum(1);
	n.addNum(2);
	double m = n.findMedian();
	n.addNum(3);
	m = n.findMedian();
}