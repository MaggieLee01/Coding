/*	����һ�������� target ��������к�Ϊ target ���������������У����ٺ�������������
	�����ڵ�������С�������У���ͬ���а����׸����ִ�С�������С�

	���룺target = 9
	�����[[2,3,4],[4,5]]

	���룺target = 15
	�����[[1,2,3,4,5],[4,5,6],[7,8]]

	https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof */

#include<vector>
#include<algorithm>
#include<cmath>
using std::swap;
using std::vector;
using std::sort;

//bool compare(vector<int> a, vector<int> b)
//{
//	return a[0] < b[0]; //��������
//}
//vector<vector<int> > findContinuousSequence(int target) 
//{
//	vector< vector<int> > ans;
//	int squareRoot = (int)pow(target, 0.5);	
//	int temp = target;
//	
//	for (int m = 2; m <= target>>1; m++)
//	{
//		if (target % m == 0)
//		{
//			int i = m, cnt = 2;//��Ȼ����֮��ñ�i�Ĵ�С��
//			int midSrc = target / i;
//			int mid = target / i;
//			if (mid % 2 == 0 && i % 2 == 0) continue;	//˫ż�� ������
//			if (mid % 2 == 1 && i % 2 == 0) swap(mid, i);
//			while (i % 2 == 1 && i / 2 < mid && cnt > 0)//iΪ��������mid����i��mid���п���Ϊ�м���
//			{
//				vector<int> res(i, 0);
//				res[0] = mid - i / 2;
//				for (int j = 1; j < i; j++)
//					res[j] = res[j - 1] + 1;
//				ans.push_back(res);
//				swap(mid, i);
//				cnt--;
//				if (mid == i) break;
//			}	
//			//iΪż������i�ԣ�����2*i���м�������Ϊmid
//			if (m % 2 == 0 && m <= midSrc / 2)
//			{
//				vector<int> res(2 * m, 0);
//				res[0] = midSrc/ 2 + 1 - m;
//				for (int j = 1; j < 2 * m; j++)
//					res[j] = res[j - 1] + 1;
//				ans.push_back(res);				
//			}			
//		}
//	}
//	if (target % 2 == 1)
//		ans.push_back({ target / 2,target / 2 + 1 });
//	sort(ans.begin(), ans.end(), compare);
//	return ans;
//}

//һ��ʼָ������������������35=7*5������10�������ʶ��������һ��һż
//����ķ����ҳ����������ޣ����磺93�������[[30, 31, 32], [46, 47]]��Ԥ�ڣ�[[13, 14, 15, 16, 17, 18], [30, 31, 32], [46, 47]]
//�����˼·���ԣ��������������������ڣ�����д���ҵ�Ҳ����
//������⣬�б�����������ѧ��ʽ������������������
//������������ ���� �������� ��Ӧ���뵽��������ѽ
vector<vector<int> > findContinuousSequence_answer01(int target)
{
	int left = 1, right = 2;
	vector< vector<int> > ans;
	if (target == 1) ans.push_back({ 1 });
	while (left < right &&  left <= target >> 1)
	{
		int result = ((left + right)*(right - left + 1)) / 2;
		if (result == target)
		{
			vector<int> res;
			for (int i = left; i <= right; i++)
				res.push_back(i);
			ans.push_back(res);
			left++;
		}
		if (result < target)		
			right++;		
		else if (result > target)
			left++;
	}
	return ans;
}
//�������ڿ���һֱ����sum�ļ��㣬���ڻ���ʱsum���仯������ר����͹�ʽ

//�ٿ���⣬
// https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/gen-ju-qu-jian-chang-du-qiu-jie-by-suibianfahui/
//������ҵ��뷨�����ƣ�Ϊɶ��һֱд���ԣ�����

//�ҵ���������ʼִ������Ѱ�����ӱ���������ֹ�ڸ����£�Ȼ�����Ҫ�����������ӣ�����5*7���֣�
//���ʱ�����Ҫ�����Ǹ��������ĸ���ż��������֮�󣬸ı��˱�����i��һֱ�ڴ�����������Ӱ��
//ȥ������֮�󣬷����˸����ص�������Ѱ��������֮����ִ����Ѱ����λ��������һ��������
//���磺93�������[[30, 31, 32], [46, 47]]��Ԥ�ڣ�[[13, 14, 15, 16, 17, 18], [30, 31, 32], [46, 47]]
//����93�� ��ֻ��ͨ�����ӵõ���λ��Ϊ31��������46�����飬���޷��õ�13��ͷ�����飬��ˣ�����У��÷�����������Ѱ�����鳤��

//���leΪ����, ��ôtarget%leӦ��Ϊ0�ſ���, ��target//le��Ϊ�����ĵ�����
//���leΪż��, ��ôtarget / leӦ��Ϊx.5, Ҳ��(target + le//2)%le��ҪΪ0

vector<vector<int> > findContinuousSequence(int target)
{
	vector< vector<int> > ans;
	int start = 0;
	//for (int i = 2; i < (target >> 1) + 1; i++) Ϊ��ʹ�����С�����򳤶ȴӴ�С
	for (int i = (target >> 1) + 1; i > 1; i--)
	{
		if ((i & 1) == 1 && target % i == 0)//��λ�����ж�����
			start = target / i - (i >> 1);

		//if ((i & 1) == 0 && ((target + (i >> 1)) % i == 0) )
		//�˳�ȡģ �Ӽ� ������ ����С�� == λ�� λ��� λ�� �߼��� �߼���
		//ע��˴��õ��ܶࣨ��,λ�� ���ȼ���Ȼ��==�ĺ��棬λ�������ȼ������׳���λ������==�����߼���ǰ
		if (i % 2 == 0 && (target + i /2 ) % i == 0 )//ע��˴��õ��ܶࣨ��,λ�� ���ȼ���Ȼ��==�ĺ���
			start = target / i - (i >> 1) + 1;
		if (start > 0)
		{
			vector<int> findSeq(i, 0);
			findSeq[0] = start;
			for (int j = 1; j < i; j++)
				findSeq[j] = findSeq[j - 1] + 1;
			ans.push_back(findSeq);
			start = 0;
		}
		else continue;
	}
	return ans;
}
//���ᵽһ��������·���
//https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/san-chong-fang-fa-cong-jian-dao-fan-zai-dao-jian-b/
//https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/java-shuang-100-by-vapormax/
//�ҵ�����������ҵ�˼·һģһ������û���ǵ�ż����������λ������
//https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/cchun-shu-xue-bu-jie-er-ci-fang-cheng-100nei-cun-s/
int main(void)
{
	vector< vector<int> > ans = findContinuousSequence(35);
	ans = findContinuousSequence(81);

	ans = findContinuousSequence(10);
	ans = findContinuousSequence(20);
	return 0;
}