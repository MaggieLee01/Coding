  /*����һ���������� nums ��һ������ k��
���ĳ�� ���� ��������ǡ���� k ���������֣����Ǿ���Ϊ����������ǡ����������项��
�뷵����������С����������项����Ŀ��

ʾ�� 1��
���룺nums = [1,1,2,1,1], k = 3
�����2
���ͣ����� 3 ���������������� [1,1,2,1] �� [1,2,1,1] ��

ʾ�� 2��
���룺nums = [2,4,6], k = 1
�����0
���ͣ������в������κ����������Բ��������������顣

ʾ�� 3��
���룺nums = [2,2,2,1,2,2,1,2,2,2], k = 2
�����16

https://leetcode-cn.com/problems/count-number-of-nice-subarrays  */

#include<vector>
#include<iostream>
using namespace std;


//int numberOfSubarrays(vector<int>& nums, int k)
//{
//	int num = nums.size();
//	if (num < k) return 0;
//
//	int left = 0, right = 0, rightMin = 0, rightMax = 0;
//	int ans = 0, cnt = 0;
//	if (nums[left] & 1 == 1) cnt++;
//
//	while (left <= right && right <= num)
//	{		
//		if (cnt <= k)
//		{
//			right++;
//			if (right < num&&(nums[right] & 1 == 1 )) cnt++;
//		}
//		if (cnt < k) rightMin = right + 1;
//		if (cnt > k || right == num && cnt == k)
//		{
//			rightMax = right - 1;
//			ans += rightMax - rightMin + 1;
//			cout << ans << endl;
//			if (left < num && (nums[left] & 1 == 1)) cnt--;
//			left++;
//		}
//	}
//	return ans;
//}

//˫ָ��һֱû�д���ã����𰸣��ٷ����
//��¼�������ڵ�λ�ã���������֮��ľ��뼴Ϊ��ѡ�������
int numberOfSubarrays(vector<int>& nums, int k)
{
	int num = nums.size();
	vector<int> odd(num + 2, 0);
	
	int cnt = 0, ans = 0;	//��¼�����ĸ���
	for (int i = 0; i < num; i++)
	{
		if ((nums[i] & 1) == 1) odd[++cnt] = i;
	}
	//�������������˶�����������ֹԽ������
	odd[0] = -1;
	odd[++cnt] = num;
	for (int i = 1; i <= cnt - k; i++)
	{
		ans += (odd[i] - odd[i - 1])*(odd[i + k] - odd[i + k - 1]);
	}
	return ans;
}

//������һ�ַ���,��̫�����ѽ�������ر�����
int numberOfSubarrays01(vector<int>& nums, int k)
{
	int num = nums.size();
	vector<int> cnt(num + 1, 0);
	int odd = 0, ans = 0;
	cnt[0] = 1;
	for (int i = 0; i < num; i++)
	{
		odd += nums[i] & 1;//oddΪiʱ�������ĸ���
		ans += odd >= k ? cnt[odd - k] : 0;
		cnt[odd] += 1;//��������洢���ǵ�odd�������м���ѡ��
	}
	return ans;
}
int main(void)
{
	vector<int> nums = { 2,2,2,1,2,2,1,2,2,2 };
	//nums = { 2,4,6 };
	nums = { 1,1,2,1,1 };
	int ans = numberOfSubarrays01(nums, 3);
	return ans;
}