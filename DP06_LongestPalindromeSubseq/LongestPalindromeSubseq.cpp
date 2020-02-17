//������������еĳ��ȡ�
//�Ӵ�һ���������ģ��������в�һ����������
//2019-11-13
//https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA
//��ͨ��LeetCode���ԣ�ֻ����Χ���й�ϵ�����Խ��пռ��Ż�

//������:
//��ȷdp[i][j]��ʾ����ʲô��ij֮��ĳ��� ���� ijΪ��ʼλ�ã�
//		���磺bbbbab dp[0][4]Ӧ��Ϊ���٣�Ŀǰ����Ϊ4 
//		�ݶ����ȷ����ҳ��໥֮��Ĺ�ϵ
//��ʼλ��
//ת�Ʒ���

#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::max;

int LengthOfLPS(const char* str)
{
	if (str == nullptr) return 0;
	int length = strlen(str);
	vector< vector<int> > dict(length + 1, vector<int>(length + 1, 0));
	//���ѵ㣺�����i�е�ʱ��i+1�л�û�м������ զ����
	//		������ά���� ���ÿ����������
	//		ת�Ʒ���ĿǰҲ���ѵ㣬�����ظ����֡���ʼֵΪ1�������ظ������������ʼֵΪ0����̫һ��	//�˿�Ϊ�Լ����������г�������
	//������ά����˼����ı���˳�����û���⣬�ʹ�һ��
	for (int i = length - 1; i >= 0; i--)   
	{
		dict[i][i] = 1;
		for (int j = i + 1; j < length; j++)
		{			
			if (str[i] == str[j])
				dict[i][j] = dict[i + 1][j - 1] + 2;
						
			else			
				dict[i][j] = max(dict[i + 1][j], dict[i][j - 1]);			
		}
	}
	return dict[0][length - 1];
}

int main(void)
{
	const char* str1 = "babbbb";
 	std::cout << LengthOfLPS(str1) << std::endl;

	const char* str2 = "abcdecnambl";//ע��beb�Ļ��ĳ���Ϊ3������2�����ڴ˿�̫����
	std::cout << LengthOfLPS(str2) << std::endl;

	const char* str3 = "abcdecnbmal";
	std::cout << LengthOfLPS(str3) << std::endl;

	const char* str4 = "bababaccababab";
	std::cout << LengthOfLPS(str4) << std::endl;

	const char* str5 = "baba";
	std::cout << LengthOfLPS(str5) << std::endl;
}