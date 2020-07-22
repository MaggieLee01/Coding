/*����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�
�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
�ж����Ƿ��ܹ��������һ��λ�á�

����: [2,3,1,1,4]
���: true
����: ���ǿ������� 1 ������λ�� 0 ���� λ�� 1, Ȼ���ٴ�λ�� 1 �� 3 ���������һ��λ�á�

����: [3,2,1,0,4]
���: false
����: �������������ܻᵽ������Ϊ 3 ��λ�á�����λ�õ������Ծ������ 0 �� ��������Զ�����ܵ������һ��λ�á�
https://leetcode-cn.com/problems/jump-game */
//https://mp.weixin.qq.com/s/hMrwcLn01BpFzBlsvGE2oQ  ����û�ио�ѽ

#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//���һ���ܴ�ܴ�����ݲ���ͨ����ʱ�����ƣ���֪������Ż�
bool canJump(vector<int>& nums, int index, vector<int>& visited)
{
	if (index >= (nums.size() - 1) || visited[index] == 1) return true;
	if (visited[index] == 2) return false;
	int opt = nums[index];

	for (int i = opt; i >= 1; i--)
	{
		if (canJump(nums, index + i, visited))
		{
			visited[index] = 1;
			return true;
		}
	}
	visited[index] = 2;
	return false;
}
bool canJump(vector<int>& nums)
{
	int Len = nums.size();
	if (Len == 0) return false;
	if (Len == 1) return true;
	vector<int> visited(Len);
	bool ans = canJump(nums, 0, visited);
	return ans;
}

//��ѽ�����д��̫����ˣ���д��Ч��̫�ͣ�˼·����ȷ
//�ж��ܵ�������λ���ܷ񵽴�
bool canJump01(vector<int>& nums)
{
	int Len = nums.size();
	int rightMax = 0;
	for (int i = 0; i < Len; i++)
	{
		if (i > rightMax) return false;
		else
		{
			rightMax = max(rightMax, i + nums[i]);
			if (rightMax >= Len - 1) return true;
		}			
	}
	return false;
}
//����labulading�ĸĽ�
bool canJump02(vector<int>& nums)
{
	int Len = nums.size();
	int rightMax = 0;
	for (int i = 0; i < Len - 1; i++)
	{
		rightMax = max(rightMax, i + nums[i]);
		if (rightMax >= Len - 1) return true;
		if (rightMax <= i) return false;	//������֮����ܵ���i�������޷�ǰ����	
	}
	return (rightMax >= Len - 1);
}

/*����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�
�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�

����: [2,3,1,1,4]
���: 2
����: �������һ��λ�õ���С��Ծ���� 2��
     ���±�Ϊ 0 �����±�Ϊ 1 ��λ�ã��� 1 ����Ȼ���� 3 ��������������һ��λ�á�
*/
//80/92 ͨ���ʣ���ʱ
int jump(vector<int>& nums) 
{
	int Len = nums.size();
	if (Len == 1) return 0;
	queue<int> q;
	q.push(0);
	int ans = 0;
	while (q.size())
	{
		int num = q.size();
		for (int i = 0; i < num; i++)
		{
			int top = q.front();//����ֵ
			q.pop();
			for (int j = nums[top]; j > 0; j--)
			{
				if (top + j >= Len - 1)return ans+1;
				else q.push(top + j);
			}							
		}
		ans++;
	}
	return ans;
}
//�����̰��ѡ�����ʣ����ǲ���Ҫ���ݹ�ء����������ѡ��ľ�����Ȼ��Ƚ�����ֵ��
//��ֻ��Ҫ�����Ǹ����С�Ǳ���������������ŵ�ѡ�񼴿ɡ�
//Ѱ����һ�ο���Ծ���������
int  jump01(vector<int>& nums)
{
	int Len = nums.size();
	if (Len == 0) return 0;
	int LastMax = 0;
	int RightMax = 0;
	int ans = 0;

	for (int i = 0; i <= Len; i++)
	{
		RightMax = max(i + nums[i], RightMax);
		if (RightMax >= Len - 1) return (ans + 1);
		if (i == LastMax)
		{
			LastMax = RightMax;
			ans++;
		}
	}
	return ans;	
}
int main(void)
{
	vector<int> num1{ 2,3,1,1,4 };
	vector<int> num{ 7,0,9,6,9,6,1,7,9,0,1,2,9,0,3 };
	int ans = jump(num);
	ans = jump(num1);
	return 0;
}