#include<iostream>
#include<vector>
#include<limits>
#include<string>
#include<algorithm>
using namespace std;

//输出回文字符串，已经AC
//int Palindrome(string str, int i, int j)
//{
//	int Length = str.size();
//	while (i >= 0 && j <= Length && str[i] == str[j])
//	{
//		i--;
//		j++;
//	}
//	if (j == Length) return i;
//	return Length;
//}
//int main(void)
//{
//	string str;
//	cin >> str;
//	int len = str.size();
//	int start = len - 2;
//	for (int i = len - 1; i >= 0; i--)
//	{
//		int start1 = Palindrome(str, i, i);
//		int start2 = Palindrome(str, i, i + 1);
//		start = min(start1, start);
//		start = min(start2, start);
//	}
//	for (int i = start; i >= 0; i--)
//	{
//		str += str[i];
//	}
//	cout << str;
//	return 0;
//}


//找出和相等的两组数据，使其舍弃的数据最小，30%
bool cmp(int num1, int num2)
{
	return num1 > num2;
}
int main(void)
{
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int num = 0, sum = 0, ans = 0, temp = 0, sumInit = 0;
		cin >> num;
		vector<int> vec(num);
		vector<int> sumvec;
		for (int j = 0; j < num; j++)
		{
			cin >> vec[j];
			sum += vec[j];
		}
		sumInit = sum;
		ans = sum;
		sort(vec.begin(), vec.end(), cmp);
		for (int j = 0; j < num; j++)
		{
			if (vec[j] > sum / 2)
			{
				sum -= vec[j];
				sumvec.push_back(vec[j]);
				continue;
			}
			if ((sum % 2 == 0)  && (vec[j] == sum / 2))
			{
				sumvec.push_back(vec[j]);
				sumvec.push_back(vec[j]);
				break;
			}
	
			if ((temp + vec[j]) > (sum / 2))
			{
				sumvec.push_back(temp);
				//sum -= temp;			
				temp = vec[j];
			}
			else
				temp += vec[j];	
		}
		for (int N = 0; N < sumvec.size()-1; N++)
		{
			if (sumvec[N] == sumvec[N + 1])
			{
				ans = (sumInit - sumvec[N] * 2);
				break;
			}			
		}
		cout << ans << endl;
	}
	return 0;
}