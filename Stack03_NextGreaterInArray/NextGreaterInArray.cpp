//��������û���ظ�Ԫ�ص����� nums1 �� nums2 ������nums1 �� nums2 ���Ӽ����ҵ� nums1 ��ÿ��Ԫ���� nums2 �е���һ��������ֵ��
//nums1 ������ x ����һ������Ԫ����ָ x �� nums2 �ж�Ӧλ�õ��ұߵĵ�һ���� x ���Ԫ�ء���������ڣ���Ӧλ����� - 1��
/*	����: nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2].
	��� : [-1, 3, -1]
	����num1�е�����4�����޷��ڵڶ����������ҵ���һ����������֣������� - 1��
	����num1�е�����1���ڶ�������������1�ұߵ���һ���ϴ������� 3��
	����num1�е�����2���ڶ���������û����һ����������֣������� - 1
	https://leetcode-cn.com/problems/next-greater-element-i
*/
#include<vector>
#include<stack>
#include<unordered_map>
#include<map>
using std::unordered_map;
using std::map;
using std::stack;
using std::vector;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
	stack<int> NextGreater;//�������� �ǲ��� Ҫ����ջ map
	unordered_map<int, int> GreaterMap;
	int Length = nums2.size();
	for (int i = Length - 1; i >= 0; i--)
	{
		while (NextGreater.size() && nums2[NextGreater.top()] < nums2[i])
			NextGreater.pop();
		if (NextGreater.empty())
			GreaterMap.emplace(nums2[i], -1);
		else
			GreaterMap.emplace(nums2[i], nums2[NextGreater.top()]);
		NextGreater.push(i);
	}
	/*for (auto num : nums1)//�������޷��ı�����Ԫ�ص�����
	{
		auto GetIndex = GreaterMap.find(num);
		if (GetIndex == GreaterMap.end())
			num = -2;
		else
			num = GetIndex->second;
	}*/
	int nums1Length = nums1.size();
	for (int i = 0; i < nums1Length; i++)
	{
		auto GetIndex = GreaterMap.find(nums1[i]);
		if (GetIndex == GreaterMap.end())
			nums1[i] = -2;
		else
			nums1[i] = GetIndex->second;
	}
	return nums1;
}
//������⣬ջ��д�����Ծ���һ�£�map��д��Ҳ���Ծ���һ��
//��ʱ ջ������Դ�� �ϴ����ֵ ������ �����ˣ����������Ǹ���Ϊ�˼���ȴ�����
vector<int> nextGreaterElement_answer(vector<int>& nums1, vector<int>& nums2)
{
	stack<int> NextGreater;
	unordered_map<int, int> GreaterMap;
	for (int value : nums1)
		GreaterMap[value] = -1;  //map���������Ӳ���Ԫ�أ����Ե�ʱ��mapÿ����һ��������������������������õ���һ�У���Ҫ����Ϊ����������
	int nums2Length = nums2.size();
	for (int i = nums2Length - 1; i >= 0; i--)
	{
		while (NextGreater.size() && NextGreater.top() < nums2[i])
			NextGreater.pop();
		if (NextGreater.size())	//ջΪ��ʱ��Ϊ��ʼ����-1��ʡ����Ϊ�յ��ж�		
			GreaterMap[nums2[i]] = NextGreater.top();
		NextGreater.push(nums2[i]);
	}
	int nums1Length = nums1.size();
	for (int i = 0; i < nums1Length; i++)
		nums1[i] = GreaterMap[nums1[i]];
	return nums1;
}
int main(void)
{
	vector<int> nums1 = { 4,1,2 };
	vector<int> nums2 = { 1,3,4,2 };
	nextGreaterElement_answer(nums1, nums2);
}