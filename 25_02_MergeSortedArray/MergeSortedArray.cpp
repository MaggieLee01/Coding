/*������������������ A �� B������ A ��ĩ�����㹻�Ļ���ռ����� B�� ��дһ���������� B �ϲ��� A ������		
	��ʼ�� A �� B ��Ԫ�������ֱ�Ϊ m �� n��
	����:	A = [1,2,3,0,0,0], m = 3
			B = [2,5,6],       n = 3
	���:	[1,2,2,3,5,6]
	https://leetcode-cn.com/problems/sorted-merge-lcci */

#include<vector>
using std::vector;
void merge(vector<int>& A, int m, vector<int>& B, int n)
{
	int aIndex = m - 1, bIndex = n - 1, ansIndex = n + m - 1;
	while (bIndex >= 0)
	{		
		//�˴�Ӧ����������ʣ���aIndexΪ-1֮���߼����ʽֱ��Ϊ1������Ĳ������жϣ����Բ����������Խ������
		if (aIndex == -1 || A[aIndex] <= B[bIndex]) 
		{
			A[ansIndex] = B[bIndex];
			bIndex--;
		}
		else
		{
			A[ansIndex] = A[aIndex];
			aIndex--;
		}
		ansIndex--;
	}
}
//������⣬��û�и��õķ���
int main(void)
{
	vector<int> a = { 7,8,9,0,0,0 };
	vector<int> b = { 1,2,3 };
	merge(a, 3, b, 3);
	return 0;
}