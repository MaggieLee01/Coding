/*����һ�� ɽ������ mountainArr�����㷵���ܹ�ʹ�� mountainArr.get(index) ���� target ��С ���±� index ֵ��
����������������±� index�����뷵�� -1�� 

��Ϊɽ�����飿������� A ��һ��ɽ������Ļ���������������������
���ȣ�A.length >= 3
��Σ��� 0 < i < A.length - 1 �����£����� i ʹ�ã�
	A[0] < A[1] < ... A[i-1] < A[i]
	A[i] > A[i+1] > ... > A[A.length - 1]
 

�㽫 ����ֱ�ӷ��ʸ�ɽ�����飬����ͨ�� MountainArray �ӿ�����ȡ���ݣ�
	MountainArray.get(k) - �᷵������������Ϊk ��Ԫ�أ��±�� 0 ��ʼ��
	MountainArray.length() - �᷵�ظ�����ĳ��� 

ע�⣺
�� MountainArray.get ���𳬹� 100 �ε��õ��ύ������Ϊ����𰸡����⣬�κ���ͼ�������ϵͳ�Ľ�����������ᵼ�±����ʸ�ȡ����

ʾ�� 1��
���룺array = [1,2,3,4,5,3,1], target = 3
�����2
���ͣ�3 �������г��������Σ��±�ֱ�Ϊ 2 �� 5�����Ƿ�����С���±� 2��

ʾ�� 2��
���룺array = [0,1,2,4,2,1], target = 3
�����-1
���ͣ�3 ��������û�г��֣����� -1��

https://leetcode-cn.com/problems/find-in-mountain-array */
//ɽ������

#include<vector>
using namespace std;
class MountainArray 
{
public:
	MountainArray(vector<int> n)
	{
		nums = n;
	}
	int get(int index) 
	{
		return nums[index];
	}
	int length() 
	{
		return nums.size();
	}
private:
	vector<int> nums;
};

//������  weiwei���е���⣬���ҵ��ⶥ��Ȼ�����߶��ַ�

//����ҿ�������
int binarySearch(int target, MountainArray &mountainArr, int l, int r,bool asc)//һ������һ������
{
	int left = l;
	int right = r;
	while (left < right)
	{
		int mid = (right - left) / 2 + left;
		if (mountainArr.get(mid) == target)
			return mid;
		else if (mountainArr.get(mid) > target)
		{
			right = asc ? mid : right;
			left = asc ? left : mid + 1;
		}
		else
		{
			right = asc ? right : mid;
			left = asc ? mid + 1 : left;
		}
	}
	//����ҿ�������ʱleft = mid + 1��right = mid
	//����ҿ����ұ߳�ֵΪ���һ������һ��ʱ��ֱ�ӿ��Է���-1��
	//����ҿ����ұ߳�ֵΪ���һ��Ԫ��ʱ��ѭ��֮����Ҫȷ�����һ��ֵ�Ƿ�Ϊtarget
	//�����������ڣ���һ�ֱ��������е�Ԫ�أ���������������left = right = num.size();�ڶ��ֿ������һ��ֵû��������
	return -1;
}

//���ַ�������Ҫ����right left �ĸ�ֵ���⣬��Ҫ����right�ĳ�ֵ
MountainArray nums({ 1,2,3,4,5,3,1 });
int findInMountainArray(int target, MountainArray &mountainArr)
{
	int left = 0;
	//�ҵ�ɽ��������ʱ����������Ϊleft=right������right�ĳ�ֵӦ��ȡ�õ�
	//ѡ�����λ�õ�ʱ�򣬿��ܲ������һ��Ԫ�ص�ĩβ������right�ĳ�ֵΪsize��С
	int right = mountainArr.length() - 1;	
	while (left < right)
	{
		int mid = (right - left) / 2 + left;
		if (mountainArr.get(mid) < mountainArr.get(mid + 1))
			left = mid + 1;
		else
			right = mid;
	}
	//�ҵ��˷ⶥ���������� while(left + 1 < right)�ķ�����left  right��������Ԫ�أ��Ƚϴ�С��Ϊ�ⶥ
	//��������Ѱ��ֵ
	int leftIndex = binarySearch(target, mountainArr, 0, left + 1, true);//�������䡢����ұ�
	if (leftIndex != -1) return leftIndex;
	else
	{
		int rightIndex = binarySearch(target, mountainArr, left + 1, mountainArr.length(), false);
		return rightIndex;
	}
}
//���ַ�������right�ĳ�ֵ������left right�ĵݽ�