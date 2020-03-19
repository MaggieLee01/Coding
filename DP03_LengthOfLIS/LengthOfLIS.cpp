//����ĵ��������У�Longest Increasing Subsequence����д LIS��
//�Ӵ�һ���������ģ��������в�һ����������
//2019-07-15
//https://mp.weixin.qq.com/s/02o_OPgePjaz3dXnw9TA1w
//����ͨ��LeetCode����

//https://blog.csdn.net/weixin_43557810/article/details/88768360 ��׼�������ж��ַ��ĺ���
//https://blog.csdn.net/qq_37774171/article/details/81203890
#include<vector>
#include<iostream>
#include<algorithm>
using std::vector;
using std::lower_bound;

//********************************δ���𰸵�˼·**********************************
//�������ǰ����ַ������ȸ��ַ�С��ʱ���ڸ��ַ��������ϼ�һ��ʱ�临�Ӷȣ�n*n���ռ临�Ӷȣ�n
//д�귢��ò��û�еݹ�
int LengthOfLIS_dp(std::vector<int> num)
{
	if (num.size() > 0)
	{
		int numLength = num.size();
		//�����е���̳���Ӧ��Ϊ1�����Գ�ʼ��Ϊ1
		std::vector<int> LISLength(numLength, 1);
		for (int i = 0; i < numLength; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (num[j] < num[i])
					//���ʹ��max min ����
					LISLength[i] = (LISLength[j] + 1) > LISLength[i] ? (LISLength[j] + 1) : LISLength[i];
			}
		}
		//���ķ���ֵӦ��Ϊ�����е����ֵ����Ӧ����ĩβ
		//return LISLength[numLength - 1];

		//��̽��׼�⺯����ʹ�ã�res������Ϊiterator��ע�ⷵ������
		auto res = max_element(LISLength.begin(), LISLength.end());
		return *res;
	}
	return 0;	
}

//********************************���𰸵��˿���˼·**********************************
//�˿���˼·���ַ�ʱ��Ӧ������߽磬�����Ƕ��ں����ظ����ֵط�������
//��Ŀ��ֵ��ö����е�top��ͬʱһ���ڷ��ڸö��ϣ����ܱ��ָ�����top�������ԣ�������

//�ܽ᣺Ŭ�������˸��ַ��������ǰ��մ𰸵ķ�����Ѱ����߽��ͳһ����Ƚϼ򵥣�
//������ѭ��������ֱ���жϳ�����λ�ã���ǰ����ѭ������ʵ��û�м���ѭ�������������������жϴ���������Ҫ���ǵ�����̫�࣬������ࡣ

//û�����ֿ��ʱ��д����Ӧ����ȷ�����ǲ���������
int LengthOfLIS_Binary01(std::vector<int> num)
{																  
	if (num.size() > 0)
	{   
		//��ȫ�������ó���ȷ�������飬���ַ���ʱ���Զ�����
		//��Ŀǰ����ƣ������С�Զ�������������ʱ��ѹ�룬�Ƚ��鷳
		std::vector<int> poker;		
		poker.push_back(num[0]);
		for (int i = 1; i < num.size(); i++)
		{
			//��С����ʱ���ȷ��ڵ�һ��
			if (poker[0] >= num[i])			
				poker[0] = num[i];
			else
			{
				//���ַ���ʼ�ҷ��õ�λ�ã����ַ�д���ٿ�
				int length = poker.size();
				int left = 0;
				int right = length - 1;
				while (right >= left)
				{
					int mid =( (right - left) >> 1 ) + left;
					if (left == right)
					{
						poker.push_back(num[i]);
						break;
					}
					//��ͬʱ�÷�����ͬ���ֵĶ� ��������һ�ѣ�����ͬʱӦ�÷�����һ��					
					if (poker[mid] < num[i] && num[i] < poker[mid + 1])//��д���� ����
					{
						poker[mid + 1] = num[i]; break;
					}						
					else if (poker[mid] == num[i] && num[i] < poker[mid + 1])
					{
						poker[mid] = num[i]; break;
					}						
					else if (poker[mid] > num[i])
						right = mid;
					else
						left = mid + 1;
				}
			}
		}
		return poker.size();
	}
	return 0;
}

//���ݴ𰸸�����д��
//����С��������Ҫ�ҳ�С�ڵ���Ŀ��ֵ�ĸ�����
int LengthOfLIS_Binary02(std::vector<int> num)
{
	if (num.size() <= 0) return 0;
	std::vector<int> top(num.size(), 0);
	int piles = 1;//��ʼ���ƶ���Ϊ1
	top[0] = num[0];
	for (int i = 1; i < num.size(); i++)
	{
		int left = 0;
		int right = piles - 1;//������λ����Ϊ0
		while (left <= right)
		{
			int mid = ((right - left) >> 1) + left;
			if (top[mid] == num[i])
				right = mid - 1;
			else if (top[mid] > num[i])
				right = mid - 1;
			else
				left = mid + 1;
		}
		//left��ǰ�������С��Ŀ��ֵ��left��Ϊ�߽�
		//����������
		if (left == piles)	piles++;
		top[left] = num[i];
	}
	return piles;
}

//���ݴ𰸣��Ľ�01����������Ϊ�̶���С�����飻�Ľ����ַ�������߽��д�������ղ��뷽��03��
//top��������ݷ����˿���˼·
int LengthOfLIS_Binary03(std::vector<int> num)
{
	if (num.size() <= 0) return 0;
	std::vector<int> top(num.size(), 0);
	int piles = 1;//��ʼ���ƶ���Ϊ1
	top[0] = num[0];
	for (int i = 1; i < num.size(); i++)
	{
		//��С����ʱ���ȷ��ڵ�һ��
		if (top[0] >= num[i])
			top[0] = num[i];
		else	//���ַ���ʼ�ҷ��õ�λ��
		{			
			int left = 0;
			int right = piles - 1;//������λ����Ϊ0
			while (left <= right)
			{
				int mid = ((right - left) >> 1) + left;
				if (mid == piles - 1) break;
				//��ͬʱ�÷�����ͬ���ֵĶ� ��������һ�ѣ�����ͬʱӦ�÷�����һ��
				if (top[mid] == num[i] && num[i] < top[mid + 1])
				{					
					top[mid] = num[i];
					break;
				}
				else if (top[mid] < num[i] && num[i] < top[mid + 1])
				{
					//Ӧ�÷�����ͬ���ֵĶ� ��������һ��
					top[mid + 1] = num[i];
					break;
				}
				else if (top[mid] > num[i])
					right = mid - 1;
				else
					left = mid + 1;
			}
			//����������
			if (left == piles - 1)
			{
				top[piles] = num[i];
				piles++;
			}
		}
	}
	return piles;	
}
/******************************************************************************************/
//20200314LeetCodeÿ��һ����ҳ����ɣ����ñ�׼�⺯�� �� ��д���ַ� ���ַ�������֮ǰ��ϤһЩ��
int LengthOfLIS_Binary0314_STL(std::vector<int> num)
{
	int Length = num.size();
	if (Length == 0) return 0;
	int ans = 1;
	vector<int> dict(Length, 0);
	dict[0] = num[0];
	for (int i = 0; i < Length; i++)
	{
		auto low = lower_bound(dict.begin(), dict.begin() + ans, num[i]); //ע���׼�⺯����ʹ�ã�����ֵΪ������
		int index = low - dict.begin(); //СС������ܵõ�����ֵ
		dict[index] = num[i];
		if (index >= ans)ans++;
	}
	return ans;
}
int lower_bound(vector<int>& num, int begin, int end, int target);
int LengthOfLIS_Binary0314_self(std::vector<int> num)
{
	int Length = num.size();
	if (Length == 0) return 0;
	int ans = 1;
	vector<int> dict(Length, 0);
	dict[0] = num[0];
	for (int i = 0; i < Length; i++)
	{
		int index = lower_bound(dict, 0, ans, num[i]); // ע��˴�Ϊdict�Ĳ��ң���������д��num����
		dict[index] = num[i];
		if (index >= ans)ans++;
	}
	return ans;	
}
int lower_bound(vector<int>& num, int begin, int end, int target) //���ַ�Ӧ�������˰�
{
	int left = begin;
	int right = end;
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (num[mid] == target) right = mid;
		else if (num[mid] > target) right = mid;
		else if (num[mid] < target) left = mid + 1;
	}
	return left;
}

/**************************************���Դ���********************************************/
void Testdp(const char* Testname, std::vector<int>num, int except)
{
	if (Testname != nullptr)
		std::cout << Testname << "	begins:  ";
	int result = LengthOfLIS_dp(num);
	if (result == except)
		std::cout << "Passed" << std::endl;
	else
		std::cout << "Failed" << std::endl;
}
void Test01(const char* Testname, std::vector<int>num, int except)
{
	if (Testname != nullptr)
		std::cout << Testname << "	begins:  ";
	int result = LengthOfLIS_Binary01(num);
	if (result == except)
		std::cout << "Passed" << std::endl;
	else
		std::cout << "Failed" << std::endl;
}
void Test02(const char* Testname, std::vector<int>num, int except)
{
	if (Testname != nullptr)
		std::cout << Testname << "	begins:  ";
	int result = LengthOfLIS_Binary02(num);
	if (result == except)
		std::cout << "Passed" << std::endl;
	else
		std::cout << "Failed" << std::endl;
}
void Test03(const char* Testname, std::vector<int>num, int except)
{
	if (Testname != nullptr)
		std::cout << Testname << "	begins:  ";
	int result = LengthOfLIS_Binary03(num);
	if (result == except)
		std::cout << "Passed" << std::endl;
	else
		std::cout << "Failed" << std::endl;
}
int main(void)
{
	std::vector<int> nums = { 6,3,5,10,11,2,9,14,13,7,4,8,12 };
	Testdp("Test1", nums, 5);
	Test01("Test1", nums, 5);
	Test02("Test1", nums, 5);
	Test03("Test1", nums, 5);

	nums = {2, 6,3,5,3,2,4};
	Testdp("Test2", nums, 3);
	Test01("Test2", nums, 3);
	Test02("Test2", nums, 3);
	Test03("Test2", nums, 3);

	nums = { 1,2,3,4,5,6,1,2,3 };
	Testdp("Test2", nums, 6);
	Test01("Test2", nums, 6);
	Test02("Test2", nums, 6);
	Test03("Test2", nums, 6);

	nums = {  };
	Testdp("Test3", nums, 0);
	Test01("Test3", nums, 0);
	Test02("Test3", nums, 0);
	Test03("Test3", nums, 0);

	nums = { 1 };
	Testdp("Test4", nums, 1);
	Test01("Test4", nums, 1);
	Test02("Test4", nums, 1);
	Test03("Test4", nums, 1);

	nums = { 7,6,5,4,3,2,1,0 };
	Testdp("Test5", nums, 1);
	Test01("Test5", nums, 1);
	Test02("Test5", nums, 1);
	Test03("Test5", nums, 1);

	nums = { 1,3,5,7,9,2,4,6,8,10,12 };
	Testdp("Test6", nums, 7);
	Test01("Test6", nums, 7);
	Test02("Test6", nums, 7);
	Test03("Test6", nums, 7);

	nums = { 7,6,5,4,3,2,1,0,7,6,5,4,3,2,1 };
	Testdp("Test7", nums, 2);
	Test01("Test7", nums, 2);
	Test02("Test7", nums, 2);
	Test03("Test7", nums, 2);
	return 0;
}