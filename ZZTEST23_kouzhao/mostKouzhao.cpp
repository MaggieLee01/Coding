//���ű����⣬�ܼ򵥣�û�����ݽṹ�㷨��˼��
#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<sstream>
using namespace std;

//11 10Ϊ��������Ŀ�Ƚϼ򵥣����Ǽ򵥵ıȽϵ��ۣ����ݱȽ��٣���������
//int main(void)
//{
//	int money = 0;
//	cin >> money;
//	int ans = 0;
//	if (money >= 1)
//	{
//		ans += 5;
//		money -= 1;
//		if (money >= 2)
//		{
//			ans += 3;
//			money -= 2;
//			if (money >= 2)
//			{
//				ans += 3;
//				money -= 2;
//				if (money >= 2)
//				{
//					ans += 2;
//					money -= 2;
//					if (money >= 5)
//					{
//						ans += 4;
//						money -= 5;
//						if (money >= 3)
//						{
//							ans += 1;
//							money -= 3;
//						}
//					}
//				}
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


//��Ҫ�����ԣ��ָ�����룬֮ǰ����ϰ���ǿո�Ϊ�ָcinֻʶ��ո�

//��Ҫǰ���ֱ�Ӱ�iss�ĳ�cin���У������ӻ�������ѭ�����޷���������
	//����ֵ��ǣ������cin.get�����ж��Ƿ�����������������к�whileѭ����������ʹ���ˣ��ڶ��ζ�ȡ��strΪ��
	//���ϣ�ֻ�� getline �ȶ�ȡһ�У�ת��Ϊstream֮������getline���ж��ŵķָ�
//if (cin.get() == '\n') break;

int main(void)
{
	string line;
	getline(cin, line);
	istringstream iss(line);

	vector<int> nums;
	string str;
	while (getline(iss, str, ','))
	{
		nums.push_back(stoi(str));
	}

	//scanf�ǿ���ʶ�𶺺ŷָ�ģ�����ķ������
	/*vector<int> nums(9);
	scanf_s("%d,%d,%d,%d,%d,%d,%d,%d,%d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4], &nums[5], &nums[6], &nums[7], &nums[8]);*/

	//����ķ������У�cin>> ֻʶ��ո�
	//for (int i = 0; i < 9; i++)
	//{
	//	cin >> nums[i];
	//	scanf("%d", &nums[i]);
	//}

	int sum1 = nums[0] + nums[1] + nums[2] + nums[3];
	int sum2 = nums[3] + nums[4] + nums[5] + nums[6];
	int sum3 = nums[6] + nums[7] + nums[8] + nums[0];
	bool ans = sum1 == sum2 ? sum2 == sum3 : false;
	if (ans) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}