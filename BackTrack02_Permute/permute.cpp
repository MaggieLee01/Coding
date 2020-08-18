/*ȫ����
����һ�� û���ظ� ���ֵ����У����������п��ܵ�ȫ���С�
https://leetcode-cn.com/problems/permutations/
����: [1,2,3]
���:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

//��һ�⣬�������ţ��ᵽ�˻����㷨������labuladong������ܣ�����˼·���Լ�дһ��
//labuladong �� weiwei ���е���⣬�������˻��ݷ���ʹ�ó���

//�������Ż�
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> ans;

//���߲���track���Ƿ��и�Ԫ�أ�find����vector�е�Ԫ�أ�������׶����Ƿ�ʱһЩ
//���ڽ����������⣺ÿһ�λ����൱�ڶ�index�����Ԫ�ص�����index֮ǰ���Ѿ��洢��track֮��
//���磬���� 1 2 3 4��index=2ʱ���ڶ���ѭ��ʱ��iΪ3�����Ϊ 1 3 ��ͷ�����У�����ʱindex����2û�л��ᱻ�����������Խ���λ�ã�ʹ��3��λ�ù̶�
void backTrack(vector<int> num, int index, vector<int>& track)
{
	if (track.size() == num.size())
	{
		ans.push_back(vector<int>(track));
		return;
	}

	for (int i = index; i < num.size(); i++)
	{
		track.push_back(num[i]);
		swap(num[i], num[index]);//�����Ĵ�����Ϊ�˱����ظ�Ԫ��
		backTrack(num, index + 1, track);
		swap(num[index], num[i]);
		track.pop_back();
	}
}
vector<vector<int>> permute(vector<int>& nums)
{
	vector<int> track;
	backTrack(nums, 0, track);
	return ans;
}
int main(void)
{
	vector<int> num{ 1,2,3 ,4,5 };
	vector<vector<int>> ans = permute(num);
	return 0;
}
//weiwei���е���⣺�� hash ���� λ���� ������Ƿ��Ѿ����������Ƚ��������һ�£�