#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(void)
{
	int num = 0;
	cin >> num;
	vector<string>ans(num,"");
	for (int i = 0; i < num; i++)
	{
		int cnt = 0;
		cin >> cnt;
		vector<int> Len(cnt, 0);		//木棍长度
		int sum = 0;
		for (int j = 0; j < cnt; j++)
		{
			cin >> Len[j];
			sum += Len[j];
		}		
		if (sum % 4 != 0)
		{
			ans[i] = "NO";
			continue;
		}
		int average = sum / 4;
		int temp = average;
		//找到四个和为average即可，应该先出大数里面找，然后找小数配？？
		sort(Len.begin(), Len.end());

		int flag = 0;//不成功标志
		int size = 0;//成功的根数
		for (int k = cnt - 1; k >= 0 && flag == 0; k--)
		{
			if (Len[k] == 0) 
				continue;
			if (Len[k] > average)			
				flag = 1;//不成功标志
			else if (temp - Len[k] >= 0)
			{
				temp -= Len[k];
				Len[k] = 0;
			}
			else
			{
				int m = k - 1;
				for (m = k - 1; m >= 0; m--)
				{
					if (temp - Len[m] >= 0)
					{
						temp -= Len[m];
						Len[m] = 0;
					}
				}
				if (m == 0 && temp != 0) flag = 1;
			}
			if (temp == 0)
			{
				size++;
				temp = average;
			}
			if (size == 3) break;
		}		
		if (size == 3) ans[i] = "YES";
		else ans[i] = "NO";
	}
	for (string s : ans)
		cout << s << endl;
	return 0;
}