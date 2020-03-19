/*	����һ���������� A��ֻ�п��Խ��仮��Ϊ��������ȵķǿղ���ʱ�ŷ��� true�����򷵻� false��
	��ʽ�ϣ���������ҳ����� i+1 < j ������ (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) �Ϳ��Խ��������ȷ֡�
	https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum */

#include<vector>
using std::vector;

//��Ŀ���ѣ��Լ���˼·Ҳ����ǶԵģ�������ͣ�����3��Ȼ�����Ѱ�Һ�Ϊƽ�����Ĵ���
//�������������1. ����������Ϊƽ�������� �� һ�����Ϊ9 ��� 2.��Ϊ0��������������֣��ֱ�Ϊ���� �ĶԵ������10,-10,10,-10��

//���ǹ����������˺ܶ����⣺һ��ʼ�����ź͵���ƽ����ʱ���ͼ�������Ϊ3�ε�ʱ���break������ж��Ƿ�����������ĩ�ˣ��������������1�����
//Ȼ�󿴵�Ⱥ�������Σ�������ȡ�ɣ��ж����ξ�break��Ȼ��������2�������Ȼ�����ŷ���ֵ�жϴ���ӱ�����i����Ϊ���һ��Ԫ�ص������Ȼ��������������һ��Ԫ��Ϊƽ���������
//���˸��ַ�������û�гɹ�������������ˣ�����ʵʵ���¿��Ǽ�����3�����ڰѳ����д����

//����Ҫ�Ĵ���һ��ʼ�����ж�average�Ƿ��Ѿ�����0��Ȼ����жϴ��� ����������ѵĴ���Ӧ������������
//�������ⲻȫ�棬�����������������޸ĳ����߼���ϰ�߿��ǲ�̫��ѽ

//����ķ�������˫ָ�룬���������߷ֱ��ң��м�һ�β����ˣ���Ŷ����
bool canThreePartsEqualSum(vector<int>& A)
{
	if (A.size() == 0) return false;
	int sum = 0;
	for (int temp : A)  sum += temp;
	//if (sum == 0 || sum % 3 != 0) return false; 
	//֮ǰ��Ϊ�˷�ֹAΪ�գ�ʡ���ڴ˴�����sum==0 ��false������������˺;���Ϊ0�����
	if (sum % 3 != 0) return false;

	int average = sum / 3, times = 0;
	for (int i:A)
	{
		average -= i;
		if (average == 0)
		{
			average = sum / 3;
			times++;
		}
		if (times == 3) break;	
		//average -= i; Ӧ���ȼ�ѽ����Ȼ��������һ���޷��жϵ����
	}
	return (times == 3);
}
//bool canThreePartsEqualSum(vector<int>& A)
//{
//	if (A.size() == 0) return false;
//	int sum = 0;
//	for (int temp : A)  sum += temp;
//	//if (sum == 0 || sum % 3 != 0) return false; ֮ǰ��Ϊ�˷�ֹAΪ�գ�ʡ���ڴ˴�����sum==0 ��false������������˺;���Ϊ0 �����
//	if ( sum % 3 != 0) return false;
//
//	int average = sum / 3, times = 0;
//	int Length = A.size(), i = 0;
//	for ( auto i:A)
//	{
//		if (times == 3) break;
//		if (average == 0 && times > 0)
//		{
//			average = sum / 3;
//			times++;
//		}
//		//if (times == 0 && i < Length) break;
//		//if (times == 0) break;
//		average -= i;
//	}
//	return (times == 3);
//}

//bool canThreePartsEqualSum(vector<int>& A)
//{
//	int sum = 0;
//	for (int temp : A)  sum += temp;
//	if (sum == 0 || sum % 3 != 0) return false;
//	int Length = A.size(), average = sum / 3, times = 3, i = 0;
//	for (i = 0; i < Length; i++)
//	{
//		if (average == 0 && times > 0)
//		{
//			average = sum / 3;
//			times--;
//		}
//		else  average -= A[i]; 
//	}
//	return (i == Length && times == 0);
//}


//bool canThreePartsEqualSum(vector<int>& A)
//{
//	int sum = 0;
//	for (int temp : A)  sum += temp;
//	if (sum == 0 || sum % 3 != 0) return false;
//	int Length = A.size(), average = sum / 3, times = 2, i = 0;
//	for (i = 0; i < Length; i++)
//	{
//		if (average == 0 && times >= 0)
//		{
//			average = sum / 3;
//			times--;
//		}
//		average -= A[i];
//	}
//	return (i == Length && times == 0 && average == 0);
//}
int main(void)
{
	vector<int> nums = { 0,2,1,-6,6,-7,9,1,2,0,1 };
	bool n = canThreePartsEqualSum(nums);

	nums = { 0,2,1,-6,6,7,9,-1,2,0,1 };
	n = canThreePartsEqualSum(nums);

	nums = { 18,12,-18,18,-19,-1,10,10 };
	n = canThreePartsEqualSum(nums);

	nums = { 18,-18,18,-18 };
	n = canThreePartsEqualSum(nums);

	nums = { 12,-4,16,-5,9,-3,3,8,0 };//���������������0��λ����ĩβ
	n = canThreePartsEqualSum(nums);

	nums = { 10,-7,13,-14,30,16,-3,-16,-27,27,19 };
	//˼·������ѽ ��Ҫ�ҵ����ξͿ��Խ����ˣ��Ͼ��ܺ�ƽ������������ˣ������ο��ܻ�������һ�Ѻ�Ϊ0�����
	//NONO ѽ�����ǵüǵ�3�Σ���Ȼ�޷�����-10,10,-10,10��
	n = canThreePartsEqualSum(nums);
	return 0;
}