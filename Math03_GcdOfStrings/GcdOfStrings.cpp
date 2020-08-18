/*	�����ַ��� S �� T��ֻ���� S = T + ... + T��T ���������� 1 �λ��Σ�ʱ�����ǲ��϶� ��T �ܳ��� S����
	������ַ��� X��Ҫ������ X �ܳ��� str1 �� X �ܳ��� str2��

	���룺str1 = "ABCABC", str2 = "ABC"
	�����"ABC"

	https://leetcode-cn.com/problems/greatest-common-divisor-of-strings */

#include<string>
#include<algorithm>
using std::swap;
using std::string;

//��ҳ�༭һ��ɣ�����
string gcdOfStrings(string str1, string str2)
{
	int Length2 = str2.size();
	int Length1 = str1.size();

	//Ѱ�ҹ�Լ��       
	if (Length1 < Length2) swap(Length1, Length2); //ʹlength1��
	while (Length1 % Length2 != 0)
	{
		int temp = Length2;
		Length2 = Length1 % Length2;
		Length1 = temp;
	}
	int divisor = Length2;

	//�ҹ���ʽ������ֱ����substr����
	string ans;
	int i = 0, j = 0, k = 0;//str1 str2 ans������
	while (i < divisor)
	{
		if (str1[i] != str2[j]) return "";
		ans += str1[i];
		i++; j++;
	}
	//�պ�ǰ��ļ������������֤�����
	Length1 = str1.size();
	Length2 = str2.size();
	while (i < Length1)
	{
		if (k == divisor) k = 0;
		if (str1[i] != ans[k]) return "";
		i++; k++;
	}
	while (j < Length2)
	{
		if (k == divisor) k = 0;
		if (str2[j] != ans[k]) return "";
		j++; k++;
	}
	return ans;
}

//��ѧ֪ʶ�������ҵ����߳��ȵ����ֵ���ó��ȵ��ַ�����Ϊans
//������⣬�����Լ�д�Ĵ��벢����࣬�������ܶ����Լ�ʵ�ֵģ����磬�����Լ�������Ӵ�
//���ֵ��ѧϰ�ĵ㣺
//	Ѱ��ans�Ĺ��̿�����substr������Ȼ���� == �ж��������Ӵ��Ƿ���ȣ�������������һ�����жϣ�ʱ�临�Ӷ�һ��
//	�����Լ���ķ�������շת���������ֻ�᷽����û�ж���������֣�������ר�ŵı�׼�⺯����__gcd(len1,len2)���ݹ��д��
//	��� str1 �� str2 ƴ�Ӻ���� str2�� str1 ƴ���������ַ�����ע��ƴ��˳��ͬ������ôһ�����ڷ����������ַ��� X��֤��û��
//�������һЩ������������Ϊ�˷�ʱ�䣺string�� + �����´����µ��ַ������ܶ඼����+ƴ���ַ��� ��ԭ�����ж�

//�ٷ����棺�ռ�On
//string gcdOfStrings01(string str1, string str2) 
//{
//	if (str1 + str2 != str2 + str1) return "";								//�����Ƿ��й�����
//	//return str1.substr(0, __gcd((int)str1.length(), (int)str2.length())); // __gcd() Ϊc++�Դ��������Լ���ĺ�����
//	//�ҵ�vs��ͨ�� __gcdѽ��
//}


// https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/solution/1xing-c-z-by-zrita/
int gcd(int a, int b)
{
	if (a < b)       swap(a, b);
	return b == 0 ? a : gcd(b, a % b);
}
int main(void)
{
	return 0;
}