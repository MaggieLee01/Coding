//̰���㷨֮����������� https://mp.weixin.qq.com/s/NH8GFMcRm5UK0HmVhdNjMQ

//������Щ����������м��������ཻ�����䡣
//LeetCode 435 452
//intvs=[[1,3],[2,4],[3,6]]������������������以���ཻ����[[1,3],[3,6]]������㷨Ӧ�÷���2��ע��߽���ͬ�������ཻ��

//������⣬�и�����ʼʱ������ģ��еݹ�ģ�δ��ϸ����
#include<iostream> 
#include<vector>
#include<algorithm>

using std::vector;
using std::cout;
using std::endl;
/***********************************************************************************************************/
//����˼·�Լ�д�ģ�ʱ�������ռ�ÿռ�Ҳ�ߣ���ͨ��LeetCode����

//����staticʱ��vs��ͨ��˳��ִ�У�����LeetCode���벻ͨ������Ҫ��static��������
static bool EndTimeCmp(vector<int> interval1, vector<int> interval2)
{
	return (interval1[1] < interval2[1]);
}
int eraseOverlapIntervals01(vector<vector<int> > & intervals)
{
	if (intervals.size() == 0) return 0;
	//�����ٺ������涨�庯��ѽ
	/*bool EndTimeCmp(vector<int> interval1, vector<int> interval2)
	{	return (interval1[1] < interval2[1]);	}*/

	//����ʹ�ñ�׼���sort����
	std::sort(intervals.begin(), intervals.end(), EndTimeCmp);
	for (int i = 0; i < intervals.size(); i++)
	{
		//�������Ч���������ѹ��һ�����飬i��������Ч������continue���������vectorû�в��ҵĹ��ܺ�����
		//����αܿ���Ч������ܲ�Ӱ�������
		//ʹ��erase()����ѽ
		for (int j = i + 1; j < intervals.size(); j++)
		{
			if (intervals[j][0] < intervals[i][1])
			{
				intervals.erase(intervals.begin() + j);
				j--;
				//�Ƴ��Ļ�������Ĳ��ϣ����Դ�ʱ����j++������©�����ϵĵ�һλ����ʱ��j--һ�£�Ȼ��forѭ����++���ܲ���
				//����ױ�����
			}

		}
	}
	return intervals.size();
}
/*************************************************************************************************************/
//��취�Ż�����Ĵ��룬����jѭ���ı�����ֱ��i+1�ȽϺ���ļ��ɡ���Ϊerase�����Ļ��Զ����ϣ�����i+1���ɡ���
//ò��ʱ��ռ�ռ����Ȼ�ܸߣ�����������
//erase����ռ�ýϸߣ���ʱ������Ĵ�С�ڲ��Ϸ����仯��ռ�þͻ�ϴ󣬴���ֱ�Ӽ�����
int eraseOverlapIntervals02(vector<vector<int> >  intervals)
{
	if (intervals.size() == 0) return 0;
	std::sort(intervals.begin(), intervals.end(), EndTimeCmp);
	for (int i = 0; i < intervals.size() - 1; i++)
	{
		if (intervals[i + 1][0] < intervals[i][1])
		{
			intervals.erase(intervals.begin() + i + 1);
			i--;
		}
	}
	return intervals.size();
}
/*************************************************************************************************************/
//�����˼·�Ƿ�����Ч������޳����޳��Ĺ����˷�ʱ�䣬����ֱ�Ӽ�����˼��������֮��Ѱ����Ч���䲢����
int eraseOverlapIntervals_answer(vector<vector<int> >  intervals)
{
	int Length = intervals.size();
	if (Length == 0) return 0;
	std::sort(intervals.begin(), intervals.end(), EndTimeCmp);
	int endTime = intervals[0][1];
	int ans = 1;
	for (int i = 1; i < Length; i++)
	{
		if (intervals[i][0] >= endTime)
		{
			ans++;
			endTime = intervals[i][1];
		}
	}
	return ans;
}
int main(void)
{
	vector<vector<int> > intervals = { {1,2},{2,3},{3,4},{1,3} };
	int ans = eraseOverlapIntervals02(intervals);//�ββ���Ϊ���ã��ı����βε�Ԫ�أ������������������ٺ��������intervals
	cout << ans << ' ';
	ans = eraseOverlapIntervals_answer(intervals);
	cout << ans << endl;

	intervals = { {1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2} };
	ans = eraseOverlapIntervals02(intervals);
	cout << ans << ' ';
	ans = eraseOverlapIntervals_answer(intervals);
	cout << ans << endl;

	return 0;
}