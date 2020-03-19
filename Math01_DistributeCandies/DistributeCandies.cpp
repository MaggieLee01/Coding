/*�����������ǹ���

��������һЩ�ǹ� candies����������Ƿָ��źöӵ� n = num_people ��С���ѡ�

����һ��С���� 1 ���ǹ����ڶ���С���� 2 �ţ��������ƣ�ֱ�������һ��С���� n ���ǹ���
Ȼ�������ٻص��������㣬����һ��С���� n + 1 ���ǹ����ڶ���С���� n + 2 �ţ��������ƣ�ֱ�������һ��С���� 2 * n ���ǹ���
�ظ��������̣�ÿ�ζ�����һ�ζ����һ���ǹ�������������յ���ٴδӶ�����㿪ʼ����ֱ�����Ƿ������е��ǹ���ע�⣬�����������е�ʣ���ǹ�������������ǰһ�η������ǹ��ࣩ����Щ�ǹ�Ҳ��ȫ��������ǰ��С���ѡ�
����һ������Ϊ num_people��Ԫ��֮��Ϊ candies �����飬�Ա�ʾ�ǹ������շַ�������� ans[i] ��ʾ�� i ��С���ѷֵ����ǹ�������

���룺candies = 7, num_people = 4
�����[1,2,3,1]
���ͣ�
��һ�Σ�ans[0] += 1�������Ϊ [1,0,0,0]��
�ڶ��Σ�ans[1] += 2�������Ϊ [1,2,0,0]��
�����Σ�ans[2] += 3�������Ϊ [1,2,3,0]��
���ĴΣ�ans[3] += 1����Ϊ��ʱֻʣ�� 1 ���ǹ��������������Ϊ [1,2,3,1]��

 https://leetcode-cn.com/problems/distribute-candies-to-people */

#include<vector>
#include<algorithm>
using std::min;
using std::vector;
//���֮ǰȡģģ�⻷������ķ�������
vector<int> distributeCandies(int candies, int num_people) 
{	
	vector<int> ans(num_people, 0);	
	int i = 0, need = 0;
	while (candies > 0)
	{
		//int need = ans[(i - 1) % num_people] + 1;//ans�������Ƕ�ηַ��ĺͣ��˴�������һ�εķַ������ϼ�һ
		need += 1;
		if (need >= candies)
		{
			ans[i % num_people] += candies;
			break;
		}
		ans[i % num_people] += need;
		candies -= need;
		i++;
	}
	return ans;
}
//������⣬�����ڱ��������Լ�д�鷳��ѽ��need������i+1��һ�������Ϳ�����
vector<int> distributeCandies(int candies, int num_people)
{
	vector<int> ans(num_people, 0);
	int i = 0;
	while (candies > 0)
	{
		ans[i%num_people] = min(candies, i + 1);
		candies -= (i + 1);
		i++;
	}
	return ans;
}
//�ٷ���⻹��������ѧ��ʽ��⣬���õȲ����У�������������ѧ�ص㣻
//��14_01_CuttingRope�ļ���������ѧ������࣬���һ��ǰһ���˺ͺ�һ���˷��䷨��һ������ֹ��ͨ���������õ�
int main(void)
{
	vector<int> ans = distributeCandies(10, 3);
	ans = distributeCandies(10, 3);
	ans = distributeCandies(60, 4);
	return 0;
}