/*���˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�2��10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С��Ϊ 0 �����Կ����������֡�A ������Ϊ 14��

����: [1,2,3,4,5]
���: True

����: [0,0,1,2,5]
���: True

https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof */

#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//set��ʽ
bool isStraight01(vector<int>& nums)
{
	set<int> s;
	int min1 = 20;
	int max1 = 0;

	for (int i : nums)
	{
		if (i == 0) continue;
		if (s.count(i)) return false;
		s.insert(i);				//ע��setΪinsert
		min1 = min(min1, i);
		max1 = max(max1, i);
		if (max1 - min1 > 4) return false;
	}
	return max1 - min1 < 5;
}

//����ķ�ʽ����������д�ķǳ�����
bool isStraight(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int cnt = 0;//���ĸ���
	
	for (int i = 0; i < 4; i++)						//ֻ������ǰ4�����������ֱ���ڷ��ش��Ƚ�
	{
		if (nums[i] == 0)
		{
			cnt++;									//ͳ��0�ĸ���
			continue;
		}
		else if (nums[i]==nums[i+1]) 
			return false;							//����ظ�����ǰ����
	}
	return nums[4] - nums[cnt] < 5;					//max �� min���5���ڣ�����Թ���˳��
}