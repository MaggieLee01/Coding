// ����һ��ѭ�����飨���һ��Ԫ�ص���һ��Ԫ��������ĵ�һ��Ԫ�أ������ÿ��Ԫ�ص���һ������Ԫ�ء�
//���� x ����һ�������Ԫ���ǰ��������˳���������֮��ĵ�һ�������������������ζ����Ӧ��ѭ��������������һ�������������������ڣ������ -1��
// https://leetcode-cn.com/problems/next-greater-element-ii
// https://mp.weixin.qq.com/s/_b_QzXkL4e0y5241betVSg 2019-05-10 ջ��Ӧ��

#include<vector>
#include<stack>
using std::stack;
using std::vector;

//��������Ĺ���ǳ������û�ж��⹹�����������£�����ȡģ����˻�������ģ��
//��ʱջ�п��Դ�Žϴ����ֵ ������ ����������Ԥ���Ǹ���������Ҫ����ȴ�����
vector<int> nextGreaterElements(vector<int>& nums)
{
	int Length = nums.size();
	vector<int> ans(Length, 0);
	stack<int> NextMax;
	for (int i = (Length << 1) - 1; i >= 0; i--) //�ڴ˴����ӣ��������Ƶ����ȼ��ܵͣ��Ѿ��������ִ���
	{
		while (NextMax.size() && nums[NextMax.top()] <= nums[i % Length])
			NextMax.pop();
		if (NextMax.empty())
			ans[i%Length] = -1;
		else
			ans[i%Length] = nums[NextMax.top()]; //����Ҫ���������е�����
		NextMax.push(i%Length);
	}
	return ans;
}

int main(void)
{
	vector<int> nums = { 1,2,1 };
	nums = nextGreaterElements(nums);
	return 0;
}