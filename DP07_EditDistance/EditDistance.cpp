//��༭����:�������ֲ��������롢ɾ�����滻
//2019-09-01
//δ��ϵͳ�ϲ��ԣ����Դ���û���⣬������������˼·

//����������˼·�൱�� ���ϴӽ������Ƶ������ͷ���Ľ��
//�ܶ�ο���Ϊ���ϴӿ�ͷ���Ƶ�����β���Ľ�������ô���һЩ

//�ݹ�Ҫ�ҽ���������dp�㷨Ҫ��base case ��ʼ����
//�ݹ鱾������ڲ���ѭ�������Բ���Ҫforѭ�������Ƕ���dp��˵������Ҫforѭ�������ϵر�����ά����
//д��д�ţ���ѵݹ��붯̬�滮������ˣ����ǵö�Щ����Ҫһ����λ��dpд����

#include<vector>
#include<iostream>
#include<algorithm>
using std::min;

//min����ֻ��ͬʱ�Ƚ��������ֵĴ�С

//�ݹ鷽�����Զ����£����ӿ�ͷ����
int EditDistance_recursively(const char* str1, const char* str2)
{
	if (str1 == nullptr && str2 == nullptr) return 0;
	if (str1 == nullptr || *str1 == '\0')  return strlen(str2);
	if (str2 == nullptr || *str2 == '\0')  return strlen(str1);
	int str1Length = strlen(str1);
	int ans = 0;

	//��Ҫ�� ���� ����¼��ʽ dp�㷨 �����

	/*for (int i = 0; i < str1Length; i++)
	{*/
		//if (str1[i] == str2[i])
		if (*str1 == *str2)
			ans = EditDistance_recursively(str1 + 1, str2 + 1);
		else
			//�ٶ��༭str1���str2�����·ֱ��ʾ ���롢ɾ�����滻��
			ans = min( min(EditDistance_recursively(str1, str2 + 1),
				EditDistance_recursively(str1 + 1, str2) ),
				EditDistance_recursively(str1 + 1, str2 + 1) ) + 1;
	/*}*/
	return ans;	 
}

//����¼�ĵݹ�
using std::vector;

int ConsultDict(const char* str1, const char* str2, vector<vector<int> >&Dict, int m, int n)
{
	//Ӧ�÷����ж�str1 str2 �Ƿ�����ĺ��棬����ڱ߽紦Ӧ��ֱ�ӷ��أ��˴��ж�Dict��������
	//if (Dict[m][n] != 0) return Dict[m][n];

	//�����ٺ͵ݹ�һ����*str1������ʱ���Ǻ���������ڲ��ϱ仯,���ش�Ҳ��ѽ����Ӧ�÷���strѽ
	/*if ( *str1 == '\0') return strlen(str2);
	if ( *str2 == '\0') return strlen(str1);*/

	//��ѵ�����ܺ͵ݹ��˼·һ������ֱ�Ӹ���ճ��֮����ģ����׺��Ժܶ�ϸ�ڣ����Ƕ���˼���������Լ�д
	if (str1[m] == '\0') return strlen(str2) - n;
	if (str2[n] == '\0') return strlen(str1) - m;

	if (Dict[m][n] != 0) return Dict[m][n];
	

	//�˴�������һ�������صĴ���˼·
	//for��ѭ������ֻ����һ���� Ӧ���� && �߼��������� i j ���жϣ������ö��ű��ʽѽ
	//�����ϳ�ʼ��ʱ�����ʼ��������������ܻ����

	//����˴� ���� dp д���ĵط���ʹ��˫��forѭ����������ͬʱ��һ��forѭ�����棬�����ӻ�©���������ݣ�������ȫ
	//�˴��������ԣ��ڲ�ͣ�ĵݹ飬��dp��Ӧ�ûᵼ����©
	//for (int i = m, j = n; i < str1Length , j < str2Length; i++, j++)
	//for (int i = m, j = n; i < str1Length && j < str2Length; i++, j++)

	/*int str1Length = strlen(str1);
	int str2Length = strlen(str2);	
	for (int i = m,j=n ; i < str1Length &&  j < str2Length; i++ , j++)
	{*/
		/*for (int j = n; j < str2Length; )
		{*/
			/*if (str1[i] == str2[j])
				Dict[i][j] = ConsultDict(str1, str2, Dict, i + 1, j + 1);
			else
				Dict[i][j] = min(min(ConsultDict(str1, str2, Dict, i + 1, j + 1),
					ConsultDict(str1, str2, Dict, i, j + 1)),
					ConsultDict(str1, str2, Dict, i + 1, j)) + 1;*/
		/*}*/		
	/*}*/

	//д������֣��ݹ���ʽ����Ҫforѭ������ô����¼��ʽӦ��Ҳ����Ҫforѭ���ˣ�����¼��ʽ�����ǵݹ���ʽ���ټ������
	if (str1[m] == str2[n])
		Dict[m][n] = ConsultDict(str1, str2, Dict, m + 1, n + 1);
	else
		Dict[m][n] = min(min(ConsultDict(str1, str2, Dict, m + 1, n + 1),
			ConsultDict(str1, str2, Dict, m, n + 1)),
			ConsultDict(str1, str2, Dict, m + 1, n)) + 1;

	return Dict[m][n];
}
int EditDistance_Dict(const char* str1, const char* str2)
{
	if (str1 == nullptr && str2 == nullptr) return 0;
	if (str1 == nullptr || *str1 == '\0') return strlen(str2);
	if (str2 == nullptr || *str2 == '\0') return strlen(str1);
	int str1Length = strlen(str1);
	int str2Length = strlen(str2);
	vector< vector<int> > Dict(str1Length + 1, vector<int>(str2Length + 1, 0));
	int l = ConsultDict(str1, str2, Dict, 0, 0);
	return l;//Ϊ�˷���鿴Dict�����ڴ�
}


//��̬�滮���Ե����ϣ��ӽ�β����ʼ����
int EditDistance_DP(const char* str1, const char* str2)
{
	if (str1 == nullptr && str2 == nullptr) return 0;
	if (str1 == nullptr || *str1 == '\0') return strlen(str2);
	if (str2 == nullptr || *str2 == '\0') return strlen(str1);
	int str1Length = strlen(str1);
	int str2Length = strlen(str2);
	vector< vector<int> > Dict(str1Length + 1, vector<int>(str2Length + 1, 0));
	
	int i = 0, j = 0;
	//�˴��൱��base case����������ѽ����Ȼ�Ļ�����β������ȽϵĶ���0 
	for (i = 0; i < str1Length; i++)
		Dict[i][str2Length] = str1Length - i;
	
	for (j = 0; j < str2Length; j++)
		Dict[str1Length][j] = str2Length - j;
	
	//�˴�Ϊforѭ���Ĵ�����ʶ
	//for (i = str1Length - 1, j = str2Length - 1; i >= 0, j >= 0; j--, i--)
	//for (i = str1Length - 1, j = str2Length - 1; i >= 0 && j >= 0; j--, i--)
	for (i = str1Length - 1; i >= 0 ; i--)
	{
		for (j = str2Length - 1; j >= 0; j--)
		{
			if (str1[i] == str2[j])
				Dict[i][j] = Dict[i + 1][j + 1];
			else
				Dict[i][j] = min(min(Dict[i + 1][j], Dict[i + 1][j + 1]), Dict[i + 1][j + 1]) + 1;
		}		
	}
	//dp��Ҫ��ʼ������������ж��Ƕ���i jͬʱѭ���������i j˫�ر���ʱ����Ҫ��������
	/*if (i == 0) Dict[0][0] = Dict[0][j] + j;
	if (j == 0) Dict[0][0] = Dict[i][0] + i;*/
	//����ѭ����ʱ��i j �ֱ�����һ��1������Ӧ�ò���
	//if (i == -1) Dict[0][0] = Dict[0][j + 1] + j + 1;
	//if (j == -1) Dict[0][0] = Dict[i + 1][0] + i + 1;
	int l = Dict[0][0];
	return l;
}


//ǰ�����ַ����Ѿ���ͨ������£���ʼ����ѹ���洢�ռ䣬���Ҵ���ʼλ���Ƶ�ĩβλ��
//https://blog.csdn.net/xflow_/article/details/8815293
//��������ѹ��Ϊ1ά���飬�ɶ�ά����һά����֪���ܲ���ѹ��ΪO(1)�ռ�
int EditDistance_Dimension(const char* str1, const char* str2)
{
	if (str1 == nullptr && str2 == nullptr) return 0;
	if (str1 == nullptr || *str1 == '\0') return strlen(str2);
	if (str2 == nullptr || *str2 == '\0') return strlen(str1);
	int str1Length = strlen(str1);
	int str2Length = strlen(str2);
	
	int up = 0;
	int down = 0;

	vector<int> Dict(str2Length + 1, 0);
	for (int i = 0; i <= str2Length; i++)
		Dict[i] = i;

	//��0���൱�ڿ��ַ�����һ�ж�Ӧ��һ����ĸ���൱��base case
	for (int i = 0; i < str1Length; i++)
	{
		//�൱�����ַ������һ��
		up = Dict[0];
		Dict[0]++;
		
		for (int j = 0; j < str2Length; j++)
		{
			//dict[j+1]Ҫ���£��Ȱ���ǰ��ֵ��������
			down = Dict[j + 1];
			//�൱�ڵ� i ���ľ���洢�ڵ�i+1��
			if (str1[i] == str2[j])
				Dict[j + 1] = up;
			else			
				Dict[j + 1] = min(min(Dict[j + 1], up), Dict[j]) + 1;
			
			up = down;
		}
	}
	return Dict[str2Length];
}

//���Գ���
int main(void)
{
	const char *str1 = "apple", *str2 = "rad";//���棬���ԣ�*Ӧ�����ַ�������ǰ��ඣ�*ָ���ʾ���ܹ���
	std::cout << EditDistance_recursively(str1, str2) << std::endl;
	std::cout << EditDistance_Dict(str1, str2) << std::endl;
	std::cout << EditDistance_DP(str1, str2) << std::endl;
	std::cout << EditDistance_Dimension(str1, str2) << std::endl;

	const char *str3 = "abc", *str4 = "cbcd";
	std::cout << EditDistance_recursively(str3, str4) << std::endl;
	std::cout << EditDistance_Dict(str3, str4) << std::endl;
	std::cout << EditDistance_DP(str3, str4) << std::endl;
	std::cout << EditDistance_Dimension(str3, str4) << std::endl;

	const char *str5 = "coffee", *str6 = "cafe";
	std::cout << EditDistance_recursively(str5, str6) << std::endl;
	std::cout << EditDistance_Dict(str5, str6) << std::endl;
	std::cout << EditDistance_DP(str5, str6) << std::endl;
	std::cout << EditDistance_Dimension(str5, str6) << std::endl;

	const char *str7 = "kitten", *str8 = "sitting";
	std::cout << EditDistance_recursively(str7, str8) << std::endl;
	std::cout << EditDistance_Dict(str7, str8) << std::endl;
	std::cout << EditDistance_DP(str7, str8) << std::endl;
	std::cout << EditDistance_Dimension(str7, str8) << std::endl;

   	return 0;
}