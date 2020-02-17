//������������У�Longest Common Subsequence����� LCS��
//�Ӵ�һ���������ģ��������в�һ����������
//2019-08-28
//https://mp.weixin.qq.com/s/SUJ35XDpTn5OKU7hud-tPw
//dpд���Ѿ�ͨ��LeetCode���ԣ���������δ��ϵͳ�ϲ��ԣ����Դ���û����

//��Ϊ���������͵����⣬��ٳ����п��ܵĽ���������ף�
//��̬�滮�㷨���ľ������ + ��֦����������һ�Զ���
//���Կ���˵ֻҪ�漰���������⣬ʮ�а˾Ŷ���Ҫ��̬�滮�������

#include<iostream>
#include<vector>
//����Ϊ�Լ��ĳ��ԣ��ݹ�ı���¼��ʽ��״̬ת�Ʒ����ڴ�ָ����������   
//dict[i][j]����str1��i��ͷ��str2��j��ͷ���������ַ���������������С�
//����������£�д��dp��ʽʱ��Ӧ�÷�������������ĩβ����LCS
//Ҳ�ɶ���dict[i][j]����str1��i������str2��j�������������ַ���������������У���ʱ��dp����ӦΪ����
int ConsultDict(const char* str1, const char* str2, std::vector<std::vector<int> >& dict,int I1,int I2)
{
	if (dict[I1][I2] == 0)
	{
		int str1Length = strlen(str1);
		int str2Length = strlen(str2);

		for (int i = I1; i < str1Length; i++)
		{
			for (int j = I2; j < str2Length; j++)
			{
				if (str1[i] == str2[j])
					dict[i][j] = ConsultDict(str1, str2, dict, i + 1, j + 1) + 1;
				else
				{
					//�˴�ת�����󣬿�ʼ����Ϊ������ȵ�ʱ��ȡ���ڸ�����һλ��
					//						��ʱ©���������str11�Ƴ���λ���ܺ�str2�Ƴ�λ����һλһ��
					//dict[i][j] = ConsultDict(str1, str2, dict, i + 1, j + 1);

					//���Ӧ���ҵ��Աߵ����ֵ

					//��ʱ������洢����Ϊ�������
					int m = ConsultDict(str1, str2, dict, i, j + 1);
					int n = ConsultDict(str1, str2, dict, i + 1, j);
					dict[i][j] = m > n ? m : n;
				}
					
			}
		}
	}
	return dict[I1][I2];	
}
int LengthOfLCS(const char* str1, const char* str2)
{
	if (str1 == nullptr || str2 == nullptr)
		return 0;
	int str1Length = strlen(str1);
	int str2Length = strlen(str2);
	int max = 0;
	
	std::vector<std::vector<int> > dict(str1Length + 1, std::vector<int>(str2Length + 1, 0));

	max= ConsultDict(str1, str2, dict, 0, 0);
	return max;

	/*ConsultDict(str1, str2, dict, 0, 0);*/

	/*for (int i = 0; i < str1Length; i++)
	{
		for (int j = 0; j < str2Length; j++)
		{
			max < dict[i][j];
			max = dict[i][j];
		}
	}
	return max;	*/
}

//���Լ�˼·�¸�д��dp��ʽ
int LengthOfLCS_dp(const char* str1, const char* str2)
{
	if (str1 == nullptr || str2 == nullptr)
		return 0;
	int str1Length = strlen(str1);
	int str2Length = strlen(str2);

	std::vector<std::vector<int> > dict(str1Length + 1, std::vector<int>(str2Length + 1, 0));
	for (int i = str1Length - 1; i >= 0; i--)
	{
		for (int j = str2Length - 1; j >= 0; j--)
		{
			if (str1[i] == str2[j])
				dict[i][j] = dict[i + 1][j + 1] + 1;
			else
				dict[i][j] = dict[i + 1][j] > dict[i][j + 1] ? dict[i + 1][j] : dict[i][j + 1];
		}
	}
	return dict[0][0];
}

int main(void)
{
	const char* str1 = "goodmorning";
	const char* str2 = "dormin";
	int m = LengthOfLCS(str1, str2);
	std::cout << m << std::endl;
	m = LengthOfLCS_dp(str1, str2);
	std::cout << m << std::endl;

	const char* str3 = "helloworld";
	const char* str4 = "eloceell";
	m = LengthOfLCS(str3, str4);
	std::cout << m << std::endl;
	m = LengthOfLCS_dp(str3, str4);
	std::cout << m << std::endl;
}
