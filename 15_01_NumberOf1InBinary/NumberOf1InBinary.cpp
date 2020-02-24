//��ʵ��һ������������һ��������������������Ʊ�ʾ�� 1 �ĸ�����
//���磬�� 9 ��ʾ�ɶ������� 1001���� 2 λ�� 1����ˣ�������� 9����ú������ 2��
// https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof

//����˼·����1�������� ���Ϊ1����0 �����ж����һλ һ������
int numOfBit1(int num)
{
	int ans = 0;
	while (num > 0)
	{
		if (num & 1) ans++;
		num = num >> 1;
	}
	return ans;
}
//���˿α����
//û���Ǹ���
//����0x80000000����һλʱ�����0xC0000000��һֱ���ƵĻ������0xFFFFFFFF
//���Ӧ�ý���������� 1 ���ƣ����ڽ������ʵ������
int numOfBit1_01(int num)
{
	int ans = 0;
	unsigned int flag = 1;//һ��Ҫ����Ϊunsigned
	while (flag)//�Ƴ���
	{
		if (num & flag) ans++;
		flag << 1;
	}
	return ans;
}
//���ŵĽⷨ ����λ����
int numOfBit1_02(int num)
{
	int ans = 0;
	while (num)
	{
		ans++;
		num = num & (num - 1);
	}
	return ans;
}
int main(void)
{
	int ans = numOfBit1(3);
	ans = numOfBit1_02(9);	
}