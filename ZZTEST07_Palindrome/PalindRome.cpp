#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	while (n > 0)
	{
		string S;
		cin >> S;
		bool result = false;//cassidӮ
		vector<int> num(26, 0);
		for (auto i : S) num[i - 'a']++;
		sort(num.begin(), num.end());

		int odd = 0, sum = 0;
		for (int i : num)
		{
			sum += i;
			if (i % 2 == 1 && odd==0) odd = i;
		}
		result = (sum - odd) % 2;
				



		if (result) cout << "Eleanore" << endl;
		else cout << "Cassidy" << endl;
		n--;		
	}
}