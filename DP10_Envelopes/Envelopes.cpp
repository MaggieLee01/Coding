//leetcode 354  leetcode-cn.com/problems/russian-doll-envelopes
//2019-08-05 https://mp.weixin.qq.com/s/PSDCjKlTh8MtANdgi-QIug
//����һЩ����˿�Ⱥ͸߶ȵ��ŷ⣬��Ⱥ͸߶�����������ʽ (w, h) ���֡�
//����һ���ŷ�Ŀ�Ⱥ͸߶ȶ�������ŷ���ʱ������ŷ�Ϳ��ԷŽ���һ���ŷ����ͬ����˹����һ����
//�����������ж��ٸ��ŷ������һ�顰����˹���ޡ��ŷ⣨�����԰�һ���ŷ�ŵ���һ���ŷ����棩����������ת�ŷ⡣
/*	����: envelopes = [[5, 4], [6, 4], [6, 7], [2, 3]]
	��� : 3
	���� : ����ŷ�ĸ���Ϊ 3, ���Ϊ : [2, 3] = > [5, 4] = > [6, 7]��*/
//��ͨ��LeetCode����

#include<vector>
#include<algorithm>
using std::vector;

/*ֻ˼�����Ե�һ��Ԫ�������ڴ���ʾ�²���ʶ����һ��Ԫ����ͬ������µڶ���Ԫ�ؽ�������
��Ϊ���������ͬ���ŷⲻ���໥�����ģ�����������֤��w��ͬ�����������ֻѡȡһ������ LIS��*/
//���磬���ڣ�{5,4},{6,4},{6,7},{2,3}���ڶ���Ԫ�ز�����Ļ��������Ϊ4��

//���Ͻ���������Եĵ����£��ӿӰͰ�д���ˡ��˿��ƶ��ַ��߻�������

//��������������ôд���������ֶ�����
static bool WidthSort(vector<int> envelope1, vector<int> envelope2)
{
	if (envelope1[0] == envelope2[0])
		return envelope1[1] > envelope2[1];
	return (envelope1[0] < envelope2[0]);
}
//static bool WidthSort(vector<int> envelope1, vector<int> envelope2)
//{
//	return (envelope1[0] < envelope2[0]) || (envelope1[0] == envelope2[0] && envelope1[1] > envelope2[1]);
//}

//�˿��ƶ��ַ�
int maxEnvelopes(vector<vector<int>>& envelopes) 
{
	int Length = envelopes.size();
	if (Length <= 1) return Length;
	std::sort(envelopes.begin(), envelopes.end(), WidthSort);
	vector<int> poke(Length, 0);

	//��ʼ���ȱ�֤��һ��Ԫ��
	poke[0] = envelopes[0][1];
	int ans = 1;	
	
	for (auto envelop : envelopes)
	{
		int target = envelop[1];
		int left = 0;
		int right = ans - 1;//ֻ��ǰ������򣬺���Ķ���0
		
		while (left <= right)
		{
			int mid = ((right - left) >> 1) + left;//����һλʱ���ӣ���,���㲻��ȷ
			if (target == poke[mid])
				right = mid - 1;
			else if (target < poke[mid])
				right = mid - 1;
			else if (target > poke[mid])
				left = mid + 1;
		}
		/*if (left == ans)
		{
			poke[ans] = target;
			ans++;
		}
		else poke[left] = target;*/

		//�ϲ�����
		if (left == ans)
			ans++;
		poke[left] = target;
	}
	return ans;
}
int main(void)
{
	vector<vector<int>> envelopes = { {5,4},{5,4},{5,4} };
	int ans = maxEnvelopes(envelopes);

	envelopes = { {5,4},{6,4},{6,7},{2,3} };
	ans = maxEnvelopes(envelopes);
}
	