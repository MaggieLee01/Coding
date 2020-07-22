/*
���� n ���Ǹ����� a1��a2��...��an��ÿ�������������е�һ���� (i, ai) ��
�������ڻ� n ����ֱ�ߣ���ֱ�� i �������˵�ֱ�Ϊ (i, ai) �� (i, 0)��
�ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��
˵�����㲻����б�������� n ��ֵ����Ϊ 2��
	
���룺[1,8,6,2,5,4,8,3,7]
�����49

https://leetcode-cn.com/problems/container-with-most-water */

//������ǩ��˫ָ�룬�ѵ��������ָ������ƶ��������Ǽ�¼��������maxLeft maxRight����������ƶ����ߵĽ�С�߼��ɡ�
#include<vector>
#include<algorithm>
using namespace std;
int maxArea(vector<int>& height)
{
	int Length = height.size();
	int left = 0, right = Length - 1, ans = 0;
	while (left < right)
	{
		//int area = min(height[left], height[right]) * (right - left);//�˴�����д��if����ʡȥ�˱ȽϵĴ���
		//ans = max(ans, area);

		//�ڿ�����ȵ�ʱ�����������ȱ�����˵������һ�飬����֮���ֶ����ˣ���Ϊ�м�����ֵ��ȷ�����ı߳��֣���������˵����һ������С
		//if (height[left] < height[right] || height[left] == height[right] && left >= Length - right - 1)
		if (height[left] < height[right])
		{
			left++;
			ans = max(ans, height[left] * (right - left));
		}			
		//else if (height[left] > height[right] || height[left] == height[right] && left < Length - right - 1)
		else
		{
			right--;
			ans = max(ans, height[right] * (right - left));
		}			
	}
	return ans;
}
//������⣬֤��ָ����ƶ������ᵽ�������̰�ߣ�
//	��ʵ�������ƶ���ָ��ͳ�ָ�붼��һ�ֿ�����⡣ ֻ�ǣ�һ��ʼ���Ѿ���ָ�붨�������ˣ������ָ�벻�������ѳ�ָ��������һ���ƶ���
//	���ߵľ����Ѿ���С�ˣ����ۻ᲻���������ߵ�ָ�룬�����ֻ���Զ̵�ָ�������м��㡣 ���ƶ���ָ����������ġ�
/*	�������ȡ���ڱ߳��̵���һ�˼���Ϊm������Ҫ��õ��ȵ�ǰ�����������߳��̵���һ�˱���������
	��Ϊ�������������������m��������ָ����ƶ����һֱ��С��������ֻ��Խ��ԽС��
*/