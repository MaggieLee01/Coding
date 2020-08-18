/*
С����ϲ���������������� N ���������� i ������ p[i] ���������������뿪�ˣ����� H Сʱ�������
С�������Ծ��������������ٶ� K ����λ����/Сʱ����ÿ��Сʱ��������ѡ��һ�����������гԵ� K ������������������ K ���������Ե���ѵ�����������Ȼ����һСʱ�ڲ����ٳԸ����������
С����ϲ�������ԣ�����Ȼ���������˻���ǰ�Ե����е�������
������������ H Сʱ�ڳԵ�������������С�ٶ� K��K Ϊ��������

��������:
��һ������Ϊ�������飬�Կո�ָ���N���������ڶ�������ΪHСʱ��

�������:
��С�ٶ�K

��������1:
3 6 7 11
8

�������1:
4*/
#include <sstream>        //istringstream ����������ͷ�ļ�
#include <iostream>
#include <vector>
#include <climits> //INT_MIN��ͷ�ļ�
#include <algorithm>
using namespace std;
bool canFinish(vector<int>food, int hours, int speed)
{
	int times = 0;
	for (int i : food)
	{
		int time = (((i%speed) == 0) ? (i / speed) : (i / speed + 1));
		times += time;
		if (times > hours) return false;
	}
	return true;
}
int eatFood(vector<int>food, int hours)
{
	int max1 = 0;
	for (int i : food) max1 = max(max1, i);
	int left = 1, right = max1;
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (canFinish(food, hours, mid))
			right = mid;
		else left = mid + 1;
	}
	return left;
}
int main()
{
	vector<int> food;
	int a, hours;
	//while (cin >> a)
	//{
	//	food.push_back(a); //һ��Ҫ������������������
	//}
	//cin >> hours;
	//�����Ӵ�������������У�����⣬�����е����붼ѹ�����飬�ٰ����һ������hour�ٵ���
	//����ͨ��ţ����ϵͳ�����ǲ�֪���Լ������VS�ϵ���

	while (cin >> a)
	{
		food.push_back(a); //һ��Ҫ������������������
	}
	hours = food.back();
	food.pop_back();
	int ans = eatFood(food, hours);
	cout << ans << endl;
	return 0;
}

//�µĴ�����
/*	 while(cin>>x)
	{
		a.push_back(x);
		if(cin.get()=='\n')break;
	}
	int h;
	cin>>h;  */

	/*	while(1)
		{
			int t;
			cin>>t;
			arr.push_back(t);
			sum+=t;
			maxk=max(maxk,t);//����ʳ�ٶ�
			if(cin.get()=='\n')
				break;
		}  */

		/*	string line;
			getline(cin, line);
			istringstream iss(line);
			while(iss >> tmp)  //tmpΪint����
			{
				arr.push_back(tmp);
				mmax = max(mmax, tmp);
				sum += tmp;
			}  */