//���������������Ľ��� https://mp.weixin.qq.com/s/H5eLHsHc7s7UgwmKnjr32g
//LeetCode 986
//����������һЩ��������ɵ��б�ÿ�������б��ǳɶԲ��ཻ�ģ������Ѿ����򡣷��������������б�Ľ�����

#include<vector>
#include<algorithm>

using std::vector;
using std::max;
using std::min;

//�Ѿ��ź����ǹؼ����Լ�˼·coding
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B)
{
	vector<vector<int>> ans;
	int i = 0, j = 0;
	int ALength = A.size();
	int BLength = B.size();
	int begin = 0, end = 0;

	while (i < ALength && j < BLength)
	{
		if (A[i][1] < B[j][0])		//�޽���
			i++;
		else if (A[i][0] > B[j][1])	//�޽���
			j++;
		else						//�н���
		{
			begin = max(A[i][0], B[j][0]);
			end = min(A[i][1], B[j][1]);
			if (A[i][1] >= B[j][1])
				j++;
			else
				i++;
			ans.push_back({ begin,end });
		}
	}
	return ans;
}
/****************************************************************************************************/
//���˴𰸣����԰�ָ���ƶ��ĵط��ϲ����������Ӿ����˴��룬���Ĥ��
//��Ϊ�������޽��� һ�����ƶ�ָ�룬�����ȴ����н�������������ͳһ����ָ���ƶ�
vector<vector<int>> intervalIntersection_answer(vector<vector<int>>& A, vector<vector<int>>& B)
{
	vector<vector<int>> ans;
	int i = 0, j = 0;
	int ALength = A.size();
	int BLength = B.size();
	int begin = 0, end = 0;

	while (i < ALength && j < BLength)
	{
		if (A[i][1] >= B[j][0] && A[i][0] <= B[j][1])	//�н���
		{
			begin = max(A[i][0], B[j][0]);
			end = min(A[i][1], B[j][1]);
			ans.push_back({ begin,end });
		}
		if (A[i][1] > B[j][1])	//��������Ѿ�������û�н���ʱ��A[i][0]>B[j][1]�����
			j++;
		else i++;
	}
	return ans;
}

int main(void)
{
	vector<vector<int>> A = { {0, 2}, {5, 10}, {13, 23}, {24, 25} };
	vector<vector<int>> B = { {1, 5}, {8, 12}, {15, 24}, {25, 26} };
	intervalIntersection(A, B);
}