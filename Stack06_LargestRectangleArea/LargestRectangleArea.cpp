/*	���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��
	���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������	
	����: [2,1,5,6,2,3]
	���: 10
	https://leetcode-cn.com/problems/largest-rectangle-in-histogram
*/
//�ͽ���ˮ�����ƣ�������������ı����ⷨ����ϰ����ջ�ķ���
//�򵥱�������Ѱ���������ߵĽ�Сֵ
//�տ�ʼ�벻�������ʹ�õ���ջ�����˼��������Ϥ�ˣ�ǰ�����������۾ͺܺ�
//����ջ����������˳��洢�ģ�ջ��Ԫ����ߵ���Сֵ��Ϊջ����һ��Ԫ�أ��ұߵ���Сֵ���ڲ��ϱ����еõ�����ջ�洢����СԪ�ص���Сֵ�������˱����Ĵ���
//����ļ��ɣ���������Ϊ0���ڱ����õش���
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights)
{	
	int Len = heights.size();
	if (Len == 0) return 0;
	if (Len == 1) return heights[0];
	
	//����ֱ��stk push(0),Ȼ��height push 0,����copy
	vector<int> newHeights(Len+2, 0);//�����ڱ���ʹ��ջ�����е�Ԫ�ض���pop()���ܼ���õ�
	copy(heights.begin(), heights.end(), newHeights.begin() + 1);//STL��׼���copy�㷨������Ϊ������

	stack<int> stk;
	stk.push(0);//��ŵ�����
	int ans = 0;

	for (int i = 1; i < Len+2; i++)
	{
		while (stk.size() && newHeights[stk.top()] > newHeights[i])
		{
			int h = stk.top();
			//�˴���һ��ϸ�ڵĵ���Ҫ�Ĵ��󣬲�Ӧ����i �� top�����������������ȣ���Ϊ��ʱ��֪����ߵĽ�Сֵ������2 1 2�ͻ����1�����Ϊ2
			//Ӧ���뵯����ֵ��ջ��top������������֮���ֵ������ߵĽ�Сֵ
			//ans = max((i - top) * newHeights[top], ans);
			stk.pop();
			ans = max((i - stk.top() - 1) * newHeights[h], ans);
		}
		stk.push(i);
	}
	return ans;
}
int main(void)
{
	vector<int> num = { 2,1,5,6,5,3 };
	int ans = largestRectangleArea(num);
	return 0;
}