//���п�����IT����ʵϰ����
//��֪���ӵ�ÿ����ɫ��Ӧ��������Ҫ�ӳ���������ȡ������ֻ���ӣ����ܱ�֤һ������ֻ�������һ�Եġ�

//���룺	��һ������TΪ�������ݵ�����
//		����ÿ�����ݣ���һ������nΪ��ɫ����
//		�ڶ�����n�����֣���i������ai��ʾ��i����ɫ��������ai��

//�����	����ÿ�����ݣ����һ�����ֱ�ʾ�𰸣����޽⣬��Ϊ-1


/*
�� ����
2
2
2 2
3
0 0 0
���
3
-1
*/

//��һ����������������ģ���Ŀ���ѣ����Ǵ���������,�˷Ѻܶ�ʱ�䣬֮ǰһֱ����LeetCode ���ô�������
//��ʱ����������ݲ���Ҫ���棬ֱ�Ӵ���ͺ���
//��ͨ����90%������Ⱥ��֪�����������������ȫΪ1 �� 0 �Ļ���ҲҪ���-1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	vector<int> ans;

	while (n > 0)
	{
		int m = 0;
		cin >> m;

		int temp = 0;
		//vector<int> s;
		int max1 = 0, flag = 0;
		while (cin >> temp)//������֪����������£�����ֱ��forѭ��
		{
			if (temp != 0) max1++;
			//�����ۣ��¼ӵı�־λ
			if (temp > 1) flag = 1;
			/*s.push_back(temp);*/
			if (cin.get() == '\n') break;
		}
		if (max1 <= 0 || flag == 0)
			ans.push_back(-1);
		else
			ans.push_back(max1 + 1);
		n--;
	}
	for (int i : ans)
		cout << i << endl;
	return 0;
}