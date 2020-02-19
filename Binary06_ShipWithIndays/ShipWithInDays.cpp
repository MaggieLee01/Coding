/*���ʹ��ϵĵ� i ������������Ϊ weights[i]��ÿһ�죬���Ƕ��ᰴ����������˳�������ʹ���װ�ذ�����
����װ�ص��������ᳬ�������������������
�������� D ���ڽ����ʹ��ϵ����а����ʹ�Ĵ����������������
https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days
*/

//2019-10-29 https://mp.weixin.qq.com/s/QC24hyg0ZgjR7-LgnEzMYg 
//������һ����㽶��˼·�����ַ��ķ�Χ����������ֵ������ĺ�

#include<vector>
#include<algorithm>
using std::max;
using std::min;
using std::vector;
//�Լ�д�ģ�OK��˼·��ͳ����������Ϊloadʱ������ȫ���������������������Ѿ�����D��ֱ��break
//�𰸸����һЩ��˼·��ͳ����������Ϊloadʱ��D�������صİ�����
//bool Canbeship(vector<int>&weight, int D, int load)
//{
//	int surplus = load-weight[0];
//	int day = 1;
//	int Length = weight.size();
//	for (int i = 0; i < Length - 1; i++)//������һ�����ñ������������1��������day����ʼֵ
//	{
//		surplus -= weight[i+1];
//		if (surplus < 0)
//		{
//			day++;
//			surplus = load - weight[i + 1];
//		}		
//		if (day > D)
//			break;
//	}
//	return (day <= D);
//}

//����D���������صİ�����
bool CanFinish(vector<int>&weight, int D, int load)
{
	int pack = 0;
	for (int i = 0; i < D; i++)
	{
		int maxload = load;
		while ((maxload -= weight[pack]) >= 0)   //һ��whileѭ���ó���pack��һ���İ�����Ҫ����һ�δ���
		{
			pack++;
			if (pack == weight.size()) return true;
		}
	}
	return false;
}

int shipWithinDays(vector<int>& weights, int D) 
{
	int Length = weights.size();
	if (Length == 0) return 0;
	int max = 0, sum = 0;
	for (auto temp : weights)
	{
		sum += temp;
		if (max < temp)	max = temp;
	}

	int left = max;
	int right = sum;
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (CanFinish(weights, D, mid))
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
int main(void)
{
	vector<int> weights = { 1,2,3,4,5,6,7,8,9,10 };
	bool n = CanFinish(weights, 5, 14);
	n = CanFinish(weights, 5, 15);
	int m = shipWithinDays(weights, 5);

	weights = { 3,2,2,4,1,4 };
	n = CanFinish(weights, 3, 6);
	n = CanFinish(weights, 3, 5);
	m = shipWithinDays(weights, 3);
	return 0;
}