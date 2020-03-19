// https://leetcode-cn.com/problems/trapping-rain-water/ LeetCode 42
//���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��������ͼ��
//������������ [0,1,0,2,1,0,1,3,2,1,2,1] ��ʾ�ĸ߶�ͼ������������£����Խ� 6 ����λ����ˮ����ɫ���ֱ�ʾ��ˮ����

//�������������һֱջ�ķ�����������ƥ������ƣ���û������������
//https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
//�͵���ջ�����ƣ��Ժ��ٿ�

#include<vector>
#include<algorithm>
#include<stack>
using std::stack;
using std::vector;
using std::max;
using std::min;

//ƾ������˼·��ÿ��λ�õ���ˮ������min(������ֵ���ұ����ֵ��- ��λ�ø߶�
//����д����ʱ��ռ��Ϊ���ԣ���ͨ��LeetCode����
//��Ϊ��һ�ֱ���д����ʱ�任�ռ䣬O(n*n)ʱ�䣬O(1)�ռ䣬һ����forѭ��������ֵ��ѭ��Ƕ���ڴ�forѭ�����棬
int trap(vector<int>& height)
{
	int Length = height.size();
	if (Length < 3) return 0;
	vector<int>left(Length, 0);
	vector<int>right(Length, 0);
	for (int i = 0; i < Length - 1; i++)	
		left[i + 1] = max(left[i], height[i]);
	
	for (int i = Length - 1; i > 0; i--)
		right[i - 1] = max(right[i], height[i]);

	int sum = 0;
	for (int i = 0; i < Length; i++)
	{
		int store = min(left[i], right[i]) - height[i];
		if (store > 0)
			sum = sum + store;
	}		
	return sum;	
}
//��˫ָ��ķ����Ż���ʱ��O(n)��һ�α�����O(1)�Ŀռ�
int trap_DoublePointer(vector<int>& height)
{
	int Length = height.size();
	if (Length < 3) return 0;

	int left = 0, right = Length - 1;
	int lMax = height[0];
	int rMax = height[right];
	int ans = 0;
	while (left <= right)
	{
		lMax = max(height[left], lMax);
		rMax = max(height[right], rMax);
		//�������洢״̬����Ѱ��min(������ֵ���ұ����ֵ)�Ĺ��̣�ȷ�����λ�õ�min��ֱ�����㣬
		if (lMax < rMax)
		{
			ans += lMax - height[left];
			//��ʱ��lMaxһ����height[left]��ߵ����ֵ��rMaxһ����height[right]��ߵ����ֵ��
			//rMax����height[left]�ұ����ֵ���� lMax < rMax,����lMaxһ��С���ұߵ����ֵ
			left++;
		}
		else
		{
			ans += rMax - height[right];
			right--;
		}
	}
	return ans;
}

//�ǵ���������ᵽջ�ķ��������ԣ��ռ临�Ӷ�ΪO(n)����ϰջ��ʹ��
//����ջʱ�޷�����ˮ������Ҫ����ջ������ʱ���ܽ�ˮ
int trap_Stack(vector<int>& height)
{
	stack<int> s;//�������
	int ans = 0;
	for (int i = height.size() - 1; i >= 0; i--)
	{
		/*while (s.size() && height[s.top()] < height[i])
		{			 
			int temp = s.top();
			s.pop();
			if (s.empty()) break;
			ans += min(height[temp], height[s.top()]);
		}*/
		/*if (!s.empty()) 
			ans += height[s.top()] - height[i];*/

		//������⣬�޸ģ�û�аѿ�ȿ��ǽ�ȥ���Լ�д��ʱ��������һ���԰Ѹ�������������ڰ�͹�ͣ���ĵط�����һ������ֵ�й�ϵѽ
		while (s.size() && height[s.top()] < height[i])
		{
			int temp = s.top();
			s.pop();
			if (s.empty()) break;
			int distance = (s.top() - i - 1);
			int h = min(height[i], height[s.top()]);//��ջ�� �� ��ǰԪ�ص���Сֵ
			ans += distance * (h - height[temp]);
		}
		s.push(i);
	}
	return ans;
}
int main(void)
{
	vector<int> heights = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int ans = trap_Stack(heights);
	return 0;
}