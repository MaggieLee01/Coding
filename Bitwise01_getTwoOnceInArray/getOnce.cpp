// https://www.nowcoder.com/questionTerminal/360e2abc03fa4c49a21ca9b4d9aef1bf
/*	����һ���������飬���г�����������ֻ����һ��֮�⣬���������ֶ����������Ρ����ҳ�������ֻ����һ�ε����֡�
	Ҫ��ʱ�临�Ӷ��� O(n) ���ռ临�Ӷ��� O(1) �������˼·��
*/

/**
���������ֽ������������õ����������������ֻ����һ�ε����ֵ����
���������ֲ���ȣ���������߽���п϶�������һλ��1��
�����Ϊ1��λΪ�磬��������Ϊ��λΪ1����λΪ0���飬�ֱ������������õ������������������������ **/

//ţ�����𰸴��� δ���ü�����
#include<vector>
using std::vector;
vector<int> getOnce(vector<int> arr) {
	vector<int> res;
	if (arr.size() == 0) return res;
	int num1 = 0, num2 = 0;
	int xorAllRes = 0;
	for (auto iter = arr.begin(); iter != arr.end(); ++iter)
	{
		xorAllRes ^= *iter;
	}
	int k = 0;
	while ((xorAllRes & 1) == 0)
		++k; //�ҵ��ֻ������λ��1��λ�ã���¼Ϊk    
	for (auto iter = arr.begin(); iter != arr.end(); ++iter)
	{
		if (((*iter >> k) & 1) == 1)
		{ //��kλΪ1����Ϊ��"1"�࣬��num1���            
			num1 ^= *iter;
		}
		else
		{ //�������ڵڶ��࣬��num2���            
			num2 ^= *iter;
		}
	}
	res.push_back(num1);
	res.push_back(num2);
	return res;
}