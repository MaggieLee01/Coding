#include<vector>
#include<iostream>
using namespace std;
//��Ϥvector�ĸ�����������û�漰���ڴ���Щ���ӵĶ���
//vectorΪ��ʱ��empty()���� 1
//ţ�����ĸ�ʽ����ͨ����ò�Ʊ߽���Բ���

//while��д�Ƚ�������ʱ������ȱȽϲ��ȣ��ٱȽ���ȣ�Ч�ʻ�������
bool Find1(int target, vector<vector<int> > array) {

	int row = 0;
	int col = array[0].size() - 1;
	int rowCount = array.size();//��Ϊ��while�в��ܽ�int�ͱ�����size_t�������Ƚ�
	if (array.empty() == 1) return false;
	while (row < rowCount && col >= 0)
	{
		if (target == array[row][col])
		{
			return true;
		}
		else if (target > array[row][col])
		{
			row++;
		}
		else
		{
			col--;
		}
	}
	return false;
}
int test0(void)
{
	vector<vector<int> > array = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	bool result = Find1(7, array);
	std::cout<< result << std::endl;
	
	return 0;
}
