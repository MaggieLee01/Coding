#include<string>
#include<sstream>
using namespace std;
string add(string num1, string num2)
{
	auto it1 = num1.find('.');
	auto it2 = num2.find('.');
	int point1 = it1, point2 = it2;
	if (point1 == -1) it1 = num1.size();
	if (point2 == -1) it2 = num2.size();

	string ans;
	int flag = 0;
	while (it1 > 0 && it2 > 0)
	{

		int sum = (num1[it1 - 1] - '0') + (num2[it2 - 1] - '0') + flag;
		int num = sum;
		if (sum > 9)
		{
			flag = 1;
			num = sum - 9;
		}
		else flag = 0;

		char c = num + '0';
		ans.insert(ans.begin(), c);
		it1--;
		it2--;
	}
	while (it1 > 0)
	{
		int sum = (num1[it1 - 1] - '0') + flag;
		int num = sum;
		if (sum > 9)
		{
			flag = 1;
			num = sum - 9;
		}
		else flag = 0;

		char c = num + '0';
		ans.insert(ans.begin(), c);
		it1--;
	}
	while (it2 > 0)
	{
		int sum = (num1[it2 - 1] - '0') + flag;
		int num = sum;
		if (sum > 9)
		{
			flag = 1;
			num = sum - 9;
		}
		else flag = 0;

		char c = num + '0';
		ans.insert(ans.begin(), c);
		it2--;
	}

	int m = num1.size() - 1, n = num2.size() - 1;
	if (point1 != -1 || point2 != -1)
	{
		if (point1 == -1) point1 = num1.size() - 1;
		if (point2 == -1) point2 = num2.size() - 1;

		int pointans = ans.size();
		ans.push_back('.');

		while (m >= point1 && n >= point2)
		{
			while ((m - point1) > (n - point2))
			{
				ans.insert(ans.end() - 1, num1[m]);
				m--;
			}
			while ((m - point1) < (n - point2))
			{
				ans.insert(ans.end() - 1, num2[n]);
				n--;
			}
			int sum = (num1[m] - '0') + (num2[n] - '0') + flag;
			int num = sum;
			if (sum > 9)
			{
				flag = 1;
				num = sum - 9;
			}
			else flag = 0;

			char c = num + '0';
			ans.insert(ans.end() - 1, c);
			n--;
			m--;



		}

	}
	return ans;

}

int main(void)
{
	//string s1 = "15";
	//string s2 = "25";
	string ans = add("25.2", "15.23");
	return 0;
}