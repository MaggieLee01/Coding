//https://www.nowcoder.com/discuss/405862?type=0&order=0&pos=8&page=0 ���׵ı�����
#include<algorithm>
#include<vector>
#include<utility>
#include<iostream>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	vector<int> worker(n, 0);
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		cin >> a;
		worker[i] = a;
	}
	vector<int> task(n, 0);
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		cin >> a;
		task[i] = a;
	}
	int NUM = 0;
	cin >> NUM;

	sort(worker.begin(), worker.end());
	sort(task.begin(), task.end());
	vector<int> choice(n, 0);
	int j = n - 1;
	for (int i = n - 1; i >= 0; i--)
	{
		int cnt = 0;
		while (j >= 0 && worker[j] >= task[i])
		{
			cnt++;
			j--;
		}
		if (i == n - 1) choice[i] = cnt;
		else choice[i] = cnt + choice[i + 1];
	}
	int ans = choice[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		int temp = choice[i] - (n - 1 - i);
		if (temp <= 0)
		{
			ans = 0;
			break;
		}
		ans = ans * temp;
	}

	ans = ans % NUM;
	cout << ans << endl;
	return 0;
}

//�����������Ĵ��룬dp��˼·����ȷ�ġ�
//�ҵĴ���Ӧ�ü򻯣��򻯵ĵط�:��������ĵط���Ѱ��ÿ�����˻���ÿ�������ѡ���ʱ�򣬿���ֱ��ʹ�ö��ֲ��ҵĿ⺯��
//��ͨ����һ����ԭ������Ϊ��������ˣ�Ӧ��ÿ��һ�γ˻�֮ǰ������
int main01(void)
{
	int n = 0;
	cin >> n;
	vector<int> worker(n, 0);
	for (int i = 0; i < n; i++)
	{
		/*	int a = 0;*/
		cin >> worker[i]; //�����м�ı���
		/*worker[i] = a;*/
	}
	vector<int> task(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> task[i];
	}
	int NUM = 0;
	cin >> NUM;

	sort(worker.begin(), worker.end());
	sort(task.begin(), task.end());
	vector<int> choice(n, 0);
	int j = n - 1;
	for (int i = n - 1; i >= 0; i--)
	{
		int cnt = 0;
		while (j >= 0 && worker[j] >= task[i])
		{
			cnt++;
			j--;
		}
		if (i == n - 1) choice[i] = cnt;
		else choice[i] = cnt + choice[i + 1];
	}
	int ans = choice[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		int temp = choice[i] - (n - 1 - i);
		if (temp <= 0)
		{
			ans = 0;
			break;
		}
		ans = ans * temp;
	}

	ans = ans % NUM;
	cout << ans << endl;
	return 0;
}
