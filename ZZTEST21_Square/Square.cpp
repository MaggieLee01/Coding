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
		vector<int> Len(cnt, 0);		//ľ������
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
		//�ҵ��ĸ���Ϊaverage���ɣ�Ӧ���ȳ����������ң�Ȼ����С���䣿��
		sort(Len.begin(), Len.end());

		int flag = 0;//���ɹ���־
		int size = 0;//�ɹ��ĸ���
		for (int k = cnt - 1; k >= 0 && flag == 0; k--)
		{
			if (Len[k] == 0) 
				continue;
			if (Len[k] > average)			
				flag = 1;//���ɹ���־
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