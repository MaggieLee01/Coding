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

//���ݵ��������֣������� �� ����Ƿ�����Ƿ���ʱ����forѭ��ѡ�ж�

//�������Ż�
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
vector<vector<int>> ans;

//���߲���track���Ƿ��и�Ԫ�أ�find����vector�е�Ԫ�أ�������׶����Ƿ�ʱһЩ
//���ڽ������������⣺ÿһ�λ����൱�ڶ�index�����Ԫ�ص�����index֮ǰ���Ѿ��洢��track֮��
//���磬���� 1 2 3 4��index=2ʱ���ڶ���ѭ��ʱ��iΪ3�����Ϊ 1 3 ��ͷ�����У�����ʱindex����2û�л��ᱻ�����������Խ���λ�ã�ʹ��3��λ�ù̶�
void backTrack(vector<int> num, int index, vector<int>& track)
{
	if (track.size() == 3)
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


// ���ظ����ֵ����
////���ں��ظ����ֵĻ�����Ƿ���ʱ��Ҫ������
// ���ܶ����������������������ϻ��ı����⣬�������ض������ȫ���У�ŶŶ��ò��Ҳ��������
// ��⻹�漰��map unordered_map ������
// https://leetcode-cn.com/problems/permutations-ii/solution/c-jian-dan-hui-su-by-da-li-wang/

//���磬���� 1 2 2 4 ȫ���У�m �Ѿ��������к��ˣ����ݹ��ʱ��forѭ��ÿ�δ�ͷ��ʼ����������Ԫ���Ѿ������е�ʱ�򣬸������٣�Ϊ0ʱ����ʼ������һ��Ԫ��
//��ÿ��ݹ��forѭ�����棬--��++��push��pop�����ÿһ������������ǰ��Ļ���
void backtrace(map<int, int>&m, int index,int end, vector<int>& v)
{
	if (index == end)
	{
		ans.push_back(v);
		return;
	}
	for (auto &p:m)
	{
		if (p.second == 0)continue;
		p.second--;
		v.push_back(p.first);
		backtrace(m, index + 1, end, v);
		v.pop_back();
		p.second++;
	}
}
vector<vector<int>> permute01(vector<int>& nums)
{
	map<int, int> m;
	for (auto i : nums) ++m[i];
	vector<int> v;
	backtrace(m, 0, nums.size(), v);
	return ans;
}


//�ڵ�һ�����ظ����ַ����Ӽ��д���Ϳ�
//https://leetcode-cn.com/problems/permutations-ii/solution/jin-xu-zeng-jia-san-xing-dai-ma-cong-wu-zhong-fu-s/
void backTrack02(vector<int> num, int index, vector<int>& track)
{
	if (track.size() == num.size())
	{
		ans.push_back(track);
		return;
	}
	set<int> s;
	for (int i = index; i < num.size(); i++)
	{
		//�������к��������ͬ��λ�á���ͬһ��ݹ��forѭ�����桿���ܳ�������һ��������
		if (s.count(num[i]))
			continue;
		s.insert(num[i]);

		//��push �ٽ���ѽ
		track.push_back(num[i]);
		swap(num[i], num[index]);//�����Ĵ�����Ϊ�˱����ظ�Ԫ��
		backTrack02(num, index + 1, track); //ע��ݼ�����indexѽ
		swap(num[index], num[i]);
		track.pop_back();
	}
}
vector<vector<int>> permute02(vector<int>& nums)
{
	vector<int> track;
	backTrack02(nums, 0, track);
	return ans;
}



int main(void)
{
	vector<int> num{ 1,2,4,5 };
	vector<vector<int>> ans = permute02(num);
	return 0;
}
//weiwei���е���⣺�� hash ���� λ���� ������Ƿ��Ѿ����������Ƚ���������һ�£�