/*������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ���
��ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
���磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18���������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19��
���ʸû������ܹ�������ٸ����ӣ�
���룺m = 2, n = 3, k = 1�������3
���룺m = 3, n = 1, k = 0�������1
1 <= n,m <= 100��0 <= k <= 20
https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof  */

//������Ŀ������㣬���������˳�򣬻���ͳ�������أ�д�˲��ž���ͨ���۲����ָ���λ�������ʱ�������
//����һ��ע�⣬һ���ܴ�[0][0]��������Ļ��������ڸ�����

//��ѽ ����˼·һ��ͨ��LeetCode��˼���Ż�

//�����鱾�𰸣����ֵط����ʺ�1 <= n,m <= 100��0 <= k <= 20����������Ҫ����
//���磬�����λ֮��[�ҵĽ��ʺϲ�������λ��]���ж������Ƿ�Ϊ0����С�ڵ��ڱ��õ��ڸ��ѣ�
//���ǣ������ĸ�������ɢ��������Ϊû�б�Ҫ�������������򼴿ɣ���Ϊ������Ϊ���Ͻ�
//���ϣ�����С��k֮��flag�ű�Ϊ1��������Ϊ��ֻҪ������������Ϊ1�����ٱ�������

//������⣬ͨƪ��˵��bfs��dfs��������ջ ����д���ģ��Ժ��ٿ�
//�����Լ�д�ĵ��õݹ麯�����ܷ���ֵ�������������Ϊ�����βΣ����ϴ��ݣ�
//������12��Ŀ�ַ���·��һ������ɻ��Ǹ��ǽ�ȫ�ֱ�����Ϊ����������ĵݹ麯���ķ���ֵ

#include<vector>
#include<iostream>
using std::cout;
using std::endl;
using std::vector;

//���˴� ����
int getDigitSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number = number / 10;
	}
	return sum;
}

//�鱾������ΪmovingCountCore��ֵ�ý��
//���Խ�count��Ϊȫ�ֱ�����ò��staticҲ�д˹��ܣ��������βθ���
//�Ѳ��ԣ�main�ж���ֲ�staticʱ���޷���EnterCount��ʹ�ã�static���÷��ǣ���
//���Կ���һ�£���̬�ֲ�����ֻ�ܱ����������ڵı����������ʡ�
//Ҳ����˵��Ȼ�����ڳ�����������������д��ڣ���������static�ģ������ܱ������ĺ�����Դ�ļ�����

int EnterCount(int c, int r, vector<vector<int> >&flag, int &count,int m, int n, int k)
{
	if (c < m && r < n && flag[c][r] == 0)
	{
		flag[c][r] = 1;//��������ǣ����۳ɹ����
		//if ((c % 10 + c / 10 + r / 10 + r % 10) <= k )
		if (getDigitSum(c) + getDigitSum(r) <= k)
		{
			count++;			
			EnterCount(c + 1, r, flag, count, m, n, k);
			EnterCount(c, r + 1, flag, count, m, n, k);
			/*EnterCount(c + 1, r, flag, m, n, k);
			EnterCount(c, r + 1, flag, m, n, k);*/
		}
	}
	return 0;
}
int movingCount(int m, int n, int k) 
{
	//if (m == 0 || n == 0) return 0;
	if (m <= 0 || n <= 0 || k < 0) return 0;
	vector<vector<int> >flag(m + 1, vector<int>(n + 1, 0));
	static int count = 0;
	EnterCount(0, 0, flag, count, m, n, k);
	//EnterCount(0, 0, flag, m, n, k);
	return count;
}

int main(void)
{
	int m = 2, n = 3, k = 1;
	int ans = movingCount(m, n, k);
	cout << ans << endl;

	m = 3, n = 1, k = 0;
	ans = movingCount(m, n, k);
	cout << ans << endl;

	m = 10, n = 10, k = 7;
	ans = movingCount(m, n, k);
	cout << ans << endl;
	return 0;
}