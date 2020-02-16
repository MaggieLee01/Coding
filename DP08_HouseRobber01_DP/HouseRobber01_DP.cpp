//��ҽ���ϵ������01�������������ڷ������Ʒ���������ٵ����ֵ
//2019-12-19
//�ھ���༭�������̫���֮�����coding˳��һЩ��û��̫���鷳
//ǰ���ַ�����LeetCode��������ʱ��������OK

#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::max;

//�������Եݹ�
//�ؼ��㣬�Ƚ��Ƿ����ٸ÷���Ĵ�С��ȡ���ֵ

//������������vector�����ǲ�֪������α�ʾvector��ָ������ƶ����������Ը���int *����
//������������ָ�벻�У��޷��ж������Ƿ����
//��ʱ���vectorָ���ƶ�����������һ��������ʾ����
int Rob_Traversal(vector<int> nums, int n)
{
	//�ݹ���ֹͣ����
	/*if (nums.size() == n) return 0;
	if (nums.size() - 1 == n) return nums[n];*/
	//���ݲο����޸�
	if (n >= nums.size()) return 0;
	//�ֱ��ʾ ���ٵ�һ�� �� �����ٵ�һ��
	int ans = max(nums[n] + Rob_Traversal(nums, n + 2),
				Rob_Traversal(nums, n + 1)	);
	return ans;
}
int Rob_recursively(vector<int> nums)
{
	return Rob_Traversal(nums,0);
}

//���ñ���¼��ʽ
//�˷�����LeetCode��������ʱ��������˵���ݹ�ķ�����
int ConsultDict(vector<int> nums, int n, vector<int> & Dict)
{
	/*if (n == nums.size()) return 0;
	if (n == nums.size() - 1) return nums[n];*/
	//ֱ�ӽ�ǰ���������������ˣ��ڶ����жϾ���Ϊ�˷�ֹ�ڽ����ĵڶ�λ���������������
	//��==û�а����ڶ������������д�˵ڶ����жϣ�ֱ����>=���������������
	if (n >= nums.size()) return 0;

	if (Dict[n] != 0) return Dict[n];
	Dict[n] = max(nums[n] + ConsultDict(nums, n + 2, Dict),
				ConsultDict(nums, n + 1, Dict) );
	return Dict[n];
}
int Rob_Dict(vector<int> nums)
{
	int Length = nums.size();
	vector<int> Dict(Length + 1, 0);
	int ans = ConsultDict(nums, 0, Dict);
	return ans;
}

//����dp��ʽ
int Rob_dp(vector<int> nums)
{
	int Length = nums.size();
	if (Length == 0) return 0;//Ϊ�յ������Ҫ����
	if (Length == 1) return nums[0];//�˴��൱��base case �������������Ȼbase case �����
	vector<int> Dict(Length + 1, 0);
	Dict[0] = nums[0];
	Dict[1] = max(nums[0], nums[1]);
	for (int i = 2; i < Length; i++)
		Dict[i] = max(nums[i] + Dict[i - 2], Dict[i - 1]);
	return Dict[Length - 1];
}
//���𰸵�dp��ʽ�����ű�����ǰ������ʼ��Ϊ0
int Rob_dp_answer(vector<int> nums)
{
	int Length = nums.size();
	//�����Գ���
	//if (Length == 0) return 0;//��Ȼforѭ�������-1
	vector<int> Dict(Length + 2, 0);
	for (int i = Length - 1; i >= 0; i--)
		Dict[i] = max(nums[i] + Dict[i + 2], Dict[i + 1]);
	return Dict[0];
}

//dp��ֻ��ǰ�����йأ����Խ�ά
int Rob_dp_Dimension(vector<int> nums)
{
	int Length = nums.size();
	if (Length == 0) return 0;//Ϊ�յ������Ҫ����
	if (Length == 1) return nums[0];//�˴��൱��base case ���������
	if (Length == 2) return max(nums[0],nums[1]);//���ڽ�ά���˴��޷�����forѭ��

	int first = nums[0];	
	int second = max(nums[0], nums[1]);
	int ans = 0;
	for (int i = 2; i < Length; i++)
	{
		ans = max(nums[i] + first, second);
		first = second;
		second = ans;
	}
	return ans;
}
//���𰸵�dp��ʽ�����ű�����ǰ������ʼ��Ϊ0��������ǰ��������ô����ж�����
int Rob_dp_Dimension_answer(vector<int> nums)
{	
	int Length = nums.size();
	//LeetCode������ ���ж� -1 < 0
	//�Ѳ��ԣ�VSҲ���ж� -1 < 0
	//���ԣ������û��Ҫ
	//if (Length == 0) return 0;//��Ȼforѭ�������-1��-1 > 0
	int dp_1 = 0, dp_2 = 0;
	int ans = 0;
	for (int i = Length - 1; i >= 0; i--)
	{
		ans = max(nums[i] + dp_2, dp_1);
		dp_2 = dp_1;
		dp_1 = ans;
	}
	return ans;
}

//���Դ���
int main(void)
{
	vector<int> num = {};
	std::cout << Rob_dp_Dimension_answer(num);

	vector<int> nums = { 1,2,3,1 };
	std::cout << Rob_recursively(nums) << std::endl;
	std::cout << Rob_Dict(nums) << std::endl;
	std::cout << Rob_dp(nums) << std::endl;
	std::cout << Rob_dp_Dimension(nums) << std::endl;

	std::cout << std::endl;

	nums = { 2,7,9,3,1 };
	std::cout << Rob_recursively(nums) << std::endl;
	std::cout << Rob_Dict(nums) << std::endl;
	std::cout << Rob_dp(nums) << std::endl;
	std::cout << Rob_dp_Dimension(nums) << std::endl;

	return 0;
}