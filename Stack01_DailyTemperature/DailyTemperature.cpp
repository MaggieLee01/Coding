// https://mp.weixin.qq.com/s/_b_QzXkL4e0y5241betVSg 2019-05-10
//����ÿ�� ���� �б�����������һ���б���Ӧλ�õ�����������Ҫ�ٵȴ�����¶ȲŻ����߳������յ����������֮�󶼲������ߣ����ڸ�λ���� 0 �����档
//���磬����һ���б� temperatures = [73, 74, 75, 71, 69, 72, 76, 73]��������Ӧ����[1, 1, 4, 2, 1, 1, 0, 0]��
//��ʾ������ �б��ȵķ�Χ��[1, 30000]��ÿ�����µ�ֵ�ľ�Ϊ���϶ȣ�������[30, 100] ��Χ�ڵ�������
// https://leetcode-cn.com/problems/daily-temperatures
//����ջһ��������ȡ��һ�����ֵ�����

#include<vector>
#include<stack>
#include<algorithm>
using std::vector;
using std::max;
using std::stack;

//������ѵ㣺���������ظ�Ԫ�أ��ظ�Ԫ���м�����ظ�Ԫ��Ϊ���ֵ
vector<int> dailyTemperatures(vector<int>& T)
{
	int Length = T.size();
	vector<int> ans(Length, 0);
	if (Length < 1) return ans; //�Ѿ�ѹ��ջһ��Ԫ���ˣ�������
	//ջ����������ȴ洢��Ӧ�ľ������ݸ����ڲ�������Ȼ�����ҵ�ջ��Ԫ���������е�λ��
	stack<int> MaxTemp;
	MaxTemp.push(Length - 1);
	for (int i = Length - 2; i >= 0; i--)//��һ�����ֵ������Ӧ�õ������
	{
		int NextMax = MaxTemp.top();
		/*if (T[NextMax] == T[i])
		{
			if (MaxTemp.size() == 1)
			{
				ans[i] = 0;
				continue;
			}
			else
			{
				MaxTemp.pop();
				NextMax = MaxTemp.top();
			}
		}*/
		while (T[NextMax] <= T[i])//��ʼ��< =����ֿ��ˣ�д��˳��
		{
			MaxTemp.pop();
			if (MaxTemp.empty() == 1)
			{
				MaxTemp.push(i);
				NextMax = MaxTemp.top();
				break;
			}
			NextMax = MaxTemp.top();
		}
		ans[i] = NextMax - i;//topΪ��һ�����Ԫ�ص�����ֵ��-iΪ�ȴ�������
		if (T[NextMax] > T[i])
			MaxTemp.push(i);
	}
	return ans;
}
//���˴𰸣�˼·һ������������д�鷳�ˣ��ɶ��Բ�������Ŀ�ܣ�����ֱ����top()�����Ļ�������
vector<int> dailyTemperatures_answer(vector<int>& T)
{
	int Length = T.size();
	vector<int> ans(Length, 0);
	stack<int> NextMax;
	for (int i = Length - 1; i >= 0; i--)
	{
		while (!NextMax.empty() && T[i] >= T[NextMax.top()])
			NextMax.pop();
		if (NextMax.empty())  //ans�����Ѿ���ʼ��Ϊ-1��ֻ����ջ��Ϊ�յ�����¸�ֵ����
			ans[i] = 0;
		else
			ans[i] = NextMax.top() - i;
		NextMax.push(i);
	}
	return ans;
}
int main(void)
{
	vector<int> num = { 73, 74, 75, 71, 69, 72, 76, 73 };
	num = dailyTemperatures(num);

	num = { 10,9,8,7,6,5,4,3,2,1 };
	num = dailyTemperatures(num);

	num = { 89,62,70,58,47,47,46,76,100,70 };
	num = dailyTemperatures(num);

	num = { 34,80,80,34,34,80,80,80,80,34 };
	num = dailyTemperatures(num);
	return 0;
}