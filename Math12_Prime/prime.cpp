//https://leetcode-cn.com/problems/count-primes/solution/ru-he-gao-xiao-pan-ding-shai-xuan-su-shu-by-labula/
//ͳ������С�ڷǸ����� n ������������

#include<vector>
using namespace std;
//������λ�Ż���C++ר����bitset�Ŀ⺯��������������һЩ��set����������Ϊ1
//�����ݲ�ʹ�ã�ʹ��bool
int countPrimes(int n) 
{
	vector<bool> vec(n, true);
	int ans = 0;
	for (long i = 2; i < n; i++)
	{
		if (vec[i])
		{
			ans++;
			//������ʱ���Ż�������2*3 3*2���ظ��Ż���vec[i]�ı�����������
			for (long j = i * i; j < n; j += i)
				vec[j] = false;
		}
	}
	return ans;
}
