#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

//�������� ������û����� ������
int main()
{
	int n = 0, ans = 0;
	cin >> n;
	//�������
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	////���-300~300 ��Χ�ڵ�����������
	///*int total = 601;
	//unordered_set<int> cuter;	
	//int temp = -300;
	//for (int i = 0; i <= total; i++)
	//{
	//	int multiply = temp * temp * temp;
	//	cuter.insert(multiply);
	//	temp++;
	//}*/

	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			bool flag = false;
			sum += nums[j];
			if (sum < 0)
			{
				sum = -sum;
				flag = true;
			}
			int s = pow((double)sum, 1.0 / 3);
			cout << pow((double)sum, 1.0 / 3) << endl;
			if (s * s * s == sum) 
				ans++;
			if (flag)
				sum = -sum;
		}
	}

	cout << ans << endl;
	return 0;
}