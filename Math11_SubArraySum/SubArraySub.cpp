/*����һ�����������һ������ k������Ҫ�ҵ��������к�Ϊ k ��������������ĸ�����

	����:nums = [1, 1, 1], k = 2
	��� : 2, [1, 1] ��[1, 1] Ϊ���ֲ�ͬ�������

	����ĳ���Ϊ [1, 20,000]��
	������Ԫ�صķ�Χ�� [-1000, 1000] �������� k �ķ�Χ�� [-1e7, 1e7]��
	https://leetcode-cn.com/problems/subarray-sum-equals-k
 */ 

#include<vector>
#include<unordered_map>
using namespace std;

//����ʹ�û������ڣ����ֲ����������и�����������θĽ���

//int subarraySum(vector<int>& nums, int target)
//{
//	if (nums.size() == 0) return 0;
//	int left = 0;
//	int right = 0;
//	int sum = nums[0];
//	int ans = 0;
//	while (right < nums.size() && left < nums.size())
//	{
//		if (sum < target)
//		{
//			right++;
//			sum += nums[right];
//		}
//		else if (left <= right)
//		{
//			if (sum == target) ans++;
//			sum -= nums[left];
//			left++;
//		}
//	}
//	return ans;
//}

//weiwei���У������и��ص��ǣ��̶�����߽��Ժ��ұ߽��ҵ���һ�����н��Ժ��ұ߽��ٿ��ұߵĸ��������϶�������Ŀ��ֵ��
//			���ԲŽ���߽�������һ��������������Ȼû��������ʡ�
//			���е����������ڲ��ʺϡ�

//����ǩ��hash�������ԣ�������⣬�������˼·��hash��洢���Ǵ�0������ʼ�����Ͷ�Ӧ�ĸ���
int subarraySum(vector<int>& nums, int target)
{
	unordered_map<int, int> mp;
	mp[0] = 1;
	int count = 0, pre = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		pre += nums[i];
		//�ܹؼ���һ����Ѱ����iΪ�����Ƿ��к�Ϊtarget�������飬��Ϊmp�洢��ȫ�Ǵӵ�0����ʼ�ĺ�
		if (mp.find(pre - target) != mp.end()) 
			count += mp[pre - target];
		mp[pre]++;
	}
	return count;
}