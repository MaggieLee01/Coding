//������ N ���㽶���� i ������ piles[i] ���㽶�������Ѿ��뿪�ˣ����� H Сʱ�������
//������Ծ��������㽶���ٶ� K ����λ���� / Сʱ����ÿ��Сʱ��������ѡ��һ���㽶�����гԵ� K ����
//�������㽶���� K ���������Ե���ѵ������㽶��Ȼ����һСʱ�ڲ����ٳԸ�����㽶��
//����ϲ�������ԣ�����Ȼ���ھ�������ǰ�Ե����е��㽶��
//������������ H Сʱ�ڳԵ������㽶����С�ٶ� K��K Ϊ��������
//leetcode-cn.com/problems/koko-eating-bananas LeetCode 875

//2019-10-29 https://mp.weixin.qq.com/s/QC24hyg0ZgjR7-LgnEzMYg 

//��ȫû˼·�󿴴�˼·���ֽ�д
#include<vector>
#include<algorithm>
using std::min;
using std::vector;

//��ʱ Ӧ���Ǵ˴�������Ҫ���򣬻��ɳ���������OK
bool CanBeate(vector<int>piles, int n, int m)
{
	int times = 0;
	for (auto temp : piles)
		times += ( temp / m + (temp % m == 0 ? 0 : 1) );
	//return times > n ? false : true;
	return times <= n;
	/*for (int i = 0; i < Length; i++)
	{
		if (times > n) break;
		times++;
		if (piles[i] > m) 
		{
			piles[i] = piles[i] - m;
			i--;
		}			
	}
	if (times > n) return false;
	else  return true;*/
}

//ͨ���ٶ� �� ʱ�䣬ֱ����˻���piles���������Ƚϣ��˷��ȽϷ�ʱ�䣬���ɼӷ����
//�˷�������ѽ���������ݼ���ϴ����� ������
//nΪʱ��
//bool CanBeate(int amount, int n, int m)
//{
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (sum >= amount) break;
//		sum = sum + m;
//	}
//	if (sum >= amount) return true;
//	else return false;
//}
int MinEatingSpeed(vector<int> piles, int n)
{
	if (piles.size() == 0) return 0;
	int max = 0;
	for (auto temp : piles)
	{		
		if (max < temp)	max = temp;
	}
	int left = 1;
	int right = max+1;//����max��//�����棬����ط���1 ����1 ���У����ַ���ܵĽ���ò�Ʋ��ܽ������ط�������
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (CanBeate(piles, n, mid))
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
int main(void)
{
	vector<int> nums = { 3,6,7,11 };
	bool n = CanBeate(nums, 8, 4);
	int ans = MinEatingSpeed(nums, 8);

	nums = { 30,11,23,4,20 };
	n = CanBeate(nums, 6, 24);
	ans = MinEatingSpeed(nums, 5);
	return 0;
}