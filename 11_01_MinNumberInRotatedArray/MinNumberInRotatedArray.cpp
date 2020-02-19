// ������11����ת�������С����
// ��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
// ����һ����������������һ����ת�������ת�������СԪ�ء���������
// {3, 4, 5, 1, 2}Ϊ{1, 2, 3, 4, 5}��һ����ת�����������СֵΪ1��

#include<vector>
#include<iostream>
#include<algorithm>
using std::min;
using std::vector;

// ��Ϊ��ת��������򣬱���һ�Σ�ʱ��On
// LeetCode���β�Ϊ�������ͣ�����ֱ�ӷ�������Ԫ�أ�VS�п���
int minArray01(vector<int> & numbers) 
{
	int Length = numbers.size();
	if (Length == 0) return 0;
	int i = 0;
	for (i = 1; i < Length; i++)
	{
		if (numbers[i] < numbers[i - 1])
			return numbers[i];
	}
	if (i == Length) return numbers[0];	
}

// ˼������ʱ�䣬���ַ����Σ�ͨ����������ֵ�ıȽ�ȷ����С��һ��ķ�Χ
//�ѵ㣺��δ�������ͬԪ�ص��������γ���δ��������
//int minArray02(vector<int> & numbers)
//{
//	int Length = numbers.size();
//	if (Length == 0) return 0;
//	if (Length == 1) return numbers[0];
//	if (Length == 2) return min(numbers[0], numbers[1]);
//
//	int left = 0;
//	int right = Length - 1;
//	int ans = 0;
//	while (left <= right)
//	{
//		int mid = ((right - left) >> 1) + left;
//		if (mid >= Length - 1 || mid == 0)
//		{
//			ans = min(numbers[0], numbers[Length - 1]);
//			break;
//		}
//		if (numbers[mid] < numbers[mid + 1] && numbers[mid] < numbers[mid - 1])	//	�ҵ��������С�����ߵ�ֵ
//		{
//			ans = numbers[mid];
//			break;
//		}
//		else if (numbers[mid] < numbers[right])	//	��λ��mid�����
//			right = mid - 1;
//		else if (numbers[mid] >= numbers[right])
//			left = mid + 1;
//	}
//	return ans;
//}

//�Ϸ��ĳ����ѳɹ���ʶ�����Ҷ˵�ȽϽϺ�
//�����޷�������ͬԪ�ص����ѣ����˴𰸣����ڴ������Ѷ������⴦�����ܲ��ö��ַ�˼��
//���ϴ𰸣��ж�left right mid�������ʱ����һ���º�����
//���𰸣����ʱ��right-- ���� left++
int minArray02(vector<int> & numbers)
{
	int Length = numbers.size();
	if (Length == 0) return 0;

	int left = 0;
	int right = Length - 1;
	int ans = 0;

	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (numbers[mid] == numbers[right])	
			right--;
		else if (numbers[mid] < numbers[right])	
			right = mid;
		else if (numbers[mid] > numbers[right])
			left = mid + 1;
	}
	return numbers[right];
}
//���ɻ��һ���㣬�����룬while������ left <= right,Ȼ�� right = mid-1;���ǽ�����ԡ�˼��Ϊʲô
//���ַ��������㹻����

//Ӧ����ֻ��ͨ���������߲��Ϻ��Ҷ˵�Ƚϣ����������˵�һ����һ��С ���ƽ�����һ����Ϊ��λ
//��mid��Ԫ�غ��Ҷ˵���ͬʱ��������С�ұߵķ�Χ
// ��ǰ��д����numbers[mid] < numbers[right]ʱ���п���mid��������ֵ����Ӧ��mid-1�����Թ�ȥ
//��Ϊ������һ���н⣬���Կ��Դ� left < right,�� left == right ʱ����Ԫ�ؼ�Ϊ��

//������������ һ��Ԫ�� Ԫ����ͬ Ԫ��ȫ������
int main(void)
{
	vector<int> numbers = {};
	int ans = minArray02(numbers);

	numbers = { 1 };
	ans = minArray02(numbers);

	numbers = { 1,1,1,1,1,1 };
	ans = minArray02(numbers);

	numbers = { 2,2,2,2,0,1 };
	ans = minArray02(numbers);

	numbers = { 1,3,5 };
	ans = minArray02(numbers);

	numbers = { 10,1,10,10,10 };
	ans = minArray02(numbers);

}
