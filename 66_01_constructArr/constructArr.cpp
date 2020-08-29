#include<vector>
using namespace std;

/*����һ������ A[0,1,��,n-1]���빹��һ������ B[0,1,��,n-1]��
���� B �е�Ԫ�� B[i]=A[0]��A[1]������A[i-1]��A[i+1]������A[n-1]������ʹ�ó�����
https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof */


//�Լ�д�ģ���ȷ���ǳ�ʱ
vector<int> constructArr(vector<int>& a)
{
	int len = a.size();
	vector<int> ans(len, 1);
	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			ans[j] *= a[(j + i) % len];
		}
	}
	return ans;
}

//��������⣬��Ҫ˫�ر���
vector<int> constructArr01(vector<int>& a)
{
	int len = a.size();
	vector<int> ans(len, 1);
	if (len == 0) return ans;
	int left = 1, right = 1;
	for (int i = 0; i < len; i++)
	{
		//���������εķ������պöԽ��ߴ�Ϊ1
		ans[i] *= left;
		left *= a[i];

		ans[len - i - 1] *= right;
		right *= a[len - i - 1];
	}
	return ans;
}


int main(void)
{
	vector<int> ans = { 1,2,3,4,5 };
	constructArr01(ans);
	return 0;
}