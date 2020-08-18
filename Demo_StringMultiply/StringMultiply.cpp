/*�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��

ʾ�� 1:
����: num1 = "2", num2 = "3"
���: "6"

ʾ�� 2:
����: num1 = "123", num2 = "456"
���: "56088"

https://leetcode-cn.com/problems/multiply-strings */

#include<string>
#include<vector>
using namespace std;

string multiply(string num1, string num2)
{
	int m = num1.size(), n = num2.size();
	//���m+nλ
	vector<int> res(m + n, 0);
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)//ע�⵹�򣬴����λ��ʼ����
		{
			int multi = (num1[i] - '0')*(num2[j] - '0');
			int p1 = i + j, p2 = i + j + 1;
			int sum = multi + res[p2];
			res[p2] = sum % 10;
			res[p1] += sum / 10;//�˴����ܴ���10������һ��ѭ���Ǳ���˵ڶ�λ�ۼӵ�sum�����ˣ�����ú�����
		}
	}
	//����ͷ��0
	int i = 0;
	while (i < res.size() && res[i] == 0)
		i++;
	string str;
	for (; i < res.size(); i++)
	{
		str.push_back(res[i] + '0');//��һ����0��Ҫ����
	}
	//Ϊ0 �Ļ����ܷ��ؿ�
	return str.size() == 0 ? "0" : str;//ע��˴��жϵ���str����
}

int main(void)
{
	string n1 = "99999999";
	string n2 = "9999";
	string ans = multiply(n1, n2);
	return 0;
}