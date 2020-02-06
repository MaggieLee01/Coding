//δ��ϵͳ�ϲ��ԣ����Դ���û���� 
//2019-06-11
//����labuladong���£����ַ��Ŀ�ܣ��ұ߽粻ͬ��ֵ�£�ѭ��������ͬ����Ӧ��mid�в�ͬ�ĸ�ֵ

//01�����������������˶��Ǳյģ��� [left, right]�������Ƿ�������mid����Ҫ�ҵ�targetʱ��
//		  ��һ��Ӧ��ȥ���� [left, mid - 1] ���� [mid + 1, right] 
//02����:���������䡹�� [left, right) ����ҿ����� nums[mid] �����֮��
//		  ��һ������������Ӧ��ȥ��mid�ָ���������䣬�� [left, mid) �� [mid + 1, right)

#include<iostream>
#include<vector>

//���ַ����� �����������Ƿ����Ŀ��Ԫ��
int BinarySearch01(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{ 
		int mid = ((right - left) >> 1) + left;//�˴����ӣ���������ʱ����Ľ�����ԣ�������Ϊʲô
		if (nums[mid] == target)return mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	return -1;
}

int BinarySearch02(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size();//�����㣬�˴�right�ĸ�ֵ��ͬ
	while (left < right)	//�˴���ͬ
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)return mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid;		//�˴���ͬ
	}
	return -1;
}

//*********************************************************************************

//����Ԫ�� �� Ѱ���ظ��������ұ߽� ������
//		����Ŀ��ֵʱ�Ĵ���ͬ������Ӧ�ò�����С�����߽磬���Խ� mid��Ӧ�Ĵ��� ��ֵΪleft����right
//		�Ҳ���ʱ������-1�������ͬ


//���ַ����� �����ظ����ֵ������������Ƿ����Ŀ��Ԫ�أ����ޣ�����-1
//���������� nums = [1,2,2,2,3]��target = 2��target �����߽�Ϊ����1��target���Ҳ�߽�Ϊ����3
int BinarySearchLeftBorder01(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			right = mid - 1;
		//�˴�ע�͵�˼·���ԣ������Լ��ʼ���뷨
		//��Ϊ����߽磬���Ŀ��ֵ�ȸ���ֵ�󣬸����Կ���Ϊ��߽磬����mid���ܼ�һ
		//���Ŀ��ֵ�ȸ���ֵС�������������Ϊ�߽磬����mid��һ
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	//target������ֵ����
	if ( left == nums.size() )return -1;
	return nums[left] == target ? left : -1;
}

int BinarySearchLeftBorder02(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size();
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			right = mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid;
	}
	if (left == nums.size())return -1;
	return nums[left] == target ? left : -1;
}

//�������߽�����𣺷���ֵ��ͬ
//01������߽硢02������߽�Ϊ�պϣ����Դ�����ֵ����-1��ʱ�����ַ�������һ��
//01�����ұ߽�Ϊ�պϣ����Խ�β��������������
//02�����ұ߽�Ϊ�����䣬���Խ�β�����������

//���������� nums = [1,2,2,2,3]��target = 2��target �����߽�Ϊ����1��target���Ҳ�߽�Ϊ����3
int BinarySearchRightBorder01(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			left = mid + 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;

	}
	if (right == -1)return -1;
	return nums[right] == target ? right : -1;
}

int BinarySearchRightBorder02(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size();
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			left = mid + 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid;
	}

	//right��Ϊ�����䣬û�л������-1������ 0 ������ѭ��
	//right��Ϊ�����䣬û����õ�nums[right]����ֵ�����Է��� right - 1��
	//�������Ϊ��left�ĸ���Ϊleft = mid + 1�� whileѭ��������nums[left]һ��������target�ˣ��� nums[left - 1] ������target��
	//			��ѭ������ʱ right==left, ���Է���left- 1 Ҳ����
	
	//if (right == -1)return -1;
	if (right == 0)return -1;//��Ŀ��ֵ�������߶���
	return nums[right - 1] == target ? (right - 1) : -1;
}

//�� ���ظ����ֵ����������� ���� һ������ ��������
//�Ͳ��ҵ����𣺲��ң�û��Ŀ��ֵʱ����-1�����룺�ҵ��߽缴��ȷ������λ��

//��߽緵��ֵ���壬�ڸ���������߲���
//�ұ߽緵��ֵ���壬�ڸ��������ұ߲���
//�����ظ����ִ��ȽϺ���⣬ʵ��Ϊ�ظ����ֵı߽�����ֵ��
int BinaryInsertLeftBorder01(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			right = mid - 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	return left;
}

int BinaryInsertLeftBorder02(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size();
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			right = mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid;
	}
	return left;
}

int BinaryInsertRightBorder01(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			left = mid + 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	return right;
}

int BinaryInsertRightBorder02(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size();
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		if (nums[mid] == target)
			left = mid + 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid;
	}
	return right - 1;//��һ����ͬ��
}

//�Լ��Ķ��ַ��뷨
//�趨ͳһ����ֵΪ ������ֵΪ����ֵ�ĺ�����룬��ʱ�������ظ����֣�����Ҳ��
int BinaryInsert03(std::vector<int> nums, int target)
{
	if (nums.size() < 1)return -2;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = ((right - left) >> 1) + left;
		//��ʱ�õ�mid+1������mid����ȡ�����һ����Ϊ���һ��ʱӦ�ý���ѭ��
		if (mid == nums.size() - 1) break;
		if (nums[mid] <= target && target < nums[mid + 1])
			return mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}	
	if (right == -1)//�������߶�С
		return -1;
	if (left == nums.size() - 1)//�������߶���
		return left;
}

//*************************���Դ���*****************************
int main(void)
{
	
	std::vector<int> v = { 1,3,5,7,10,13,17,18,20,27,33,46 };
	int l = BinaryInsert03(v, 3);
	std::cout << l << std::endl;//1
	l = BinaryInsert03(v, 6);
	std::cout << l << std::endl;//2.
	l = BinaryInsert03(v, 19);
	std::cout << l << std::endl;//7
	l = BinaryInsert03(v, 30);
	std::cout << l << std::endl;//9
	l = BinaryInsert03(v, 0);
	std::cout << l << std::endl;//-1
	l = BinaryInsert03(v, 301);
	std::cout << l << std::endl;//11

	v = { 0,3,4,6,9,11,14,15,16,23,25,29,32,35,56,66,76,87 };
	l = BinaryInsert03(v, 3);
	std::cout << l << std::endl;//1
	l = BinaryInsert03(v, 5);
	std::cout << l << std::endl;//2
	l = BinaryInsert03(v, 19);
	std::cout << l << std::endl;//8
	l = BinaryInsert03(v, 30);
	std::cout << l << std::endl;//11
	l = BinaryInsert03(v, -1);
	std::cout << l << std::endl;//-1
	l = BinaryInsert03(v, 301);
	std::cout << l << std::endl;//17

	//��һ��10������ֵΪ8�����һ��10����ֵΪ11
	std::vector<int> nums = { 1,3,3,3,3,3,5,7,10,10,10,10,13,17,18,20,27,33,46 };
	int m = BinarySearchLeftBorder01(nums, 10);
	int n = BinarySearchLeftBorder02(nums, 10);	
	std::cout << ' ' << m << ' ' << n << std::endl;
	m = BinarySearchRightBorder01(nums, 10);
	n = BinarySearchRightBorder02(nums, 10);
	std::cout << ' ' << m << ' ' << n << std::endl;

	//��һ��78������ֵΪ12�����һ��78����ֵΪ14
	nums = { 2,2,4,5,8,8,13,13,13,34,64,67,78,78,78,79,83 };
	m = BinarySearchLeftBorder01(nums, 78);
	n = BinarySearchLeftBorder02(nums, 78);
	std::cout << ' ' << m << ' ' << n << std::endl;
	m = BinarySearchRightBorder01(nums, 78);
	n = BinarySearchRightBorder02(nums, 78);
	std::cout << ' ' << m << ' ' << n << std::endl;

	//�޴�ֵ -1
	nums = { 2,2,4,5,8,8,13,13,13,34,64,67,78,78,78,79,83 };
	m = BinarySearchLeftBorder01(nums, 66);
	n = BinarySearchLeftBorder02(nums, 66);
	std::cout << ' ' << m << ' ' << n << std::endl;
	m = BinarySearchRightBorder01(nums, 66);
	n = BinarySearchRightBorder02(nums, 66);
	std::cout << ' ' << m << ' ' << n << std::endl;

	//��һ��78������ֵΪ12�����һ��78����ֵΪ14
	nums = { 2,2,4,5,8,8,13,13,13,34,64,67,78,78,78,79,83 };
	m = BinarySearchLeftBorder01(nums, 78);
	n = BinarySearchLeftBorder02(nums, 78);
	std::cout << ' ' << m << ' ' << n << std::endl;
	m = BinarySearchRightBorder01(nums, 78);
	n = BinarySearchRightBorder02(nums, 78);
	std::cout << ' ' << m << ' ' << n << std::endl;

	//������ֵΪ11����ߣ�����ֵΪ10���ұ�
	nums = { 2,2,4,5,8,8,13,13,13,34,64,67,78,78,78,79,83 };
	m = BinaryInsertLeftBorder01(nums, 66);
	n = BinaryInsertLeftBorder02(nums, 66);
	std::cout << ' ' << m << ' ' << n << std::endl;
	m = BinaryInsertRightBorder01(nums, 66);
	n = BinaryInsertRightBorder02(nums, 66);
	std::cout << ' ' << m << ' ' << n << std::endl;

	//3����߽�1�� 3���ұ߽�5
	nums = { 1,3,3,3,3,3,5,7,10,10,10,10,13,17,18,20,27,33,46 };
	m = BinaryInsertLeftBorder01(nums, 3);
	n = BinaryInsertLeftBorder02(nums, 3);
	std::cout << ' ' << m << ' ' << n << std::endl;
	m = BinaryInsertRightBorder01(nums, 3);
	n = BinaryInsertRightBorder02(nums, 3);
	std::cout << ' ' << m << ' ' << n << std::endl;

	//�����ˣ����0���ұ�8
	nums = { 1,3,5,7,10,13,27,33,46 };
	m = BinaryInsertLeftBorder01(nums, 0);
	n = BinaryInsertLeftBorder02(nums, 0);
	std::cout << ' ' << m << ' ' << n << std::endl;
	m = BinaryInsertRightBorder01(nums, 100);
	n = BinaryInsertRightBorder02(nums, 100);
	std::cout << ' ' << m << ' ' << n << std::endl;


	nums = { 1,3,5,7,10,13,17,18,20,27,33,46 };
	m = BinarySearch01(nums, 10);
	n = BinarySearch02(nums, 10);
	std::cout << ' ' << m << ' ' << n << std::endl;

	nums = { 1,3,5,7,10,13,17,18,20,27,33,46 };
	m = BinarySearch01(nums, 20);
	n = BinarySearch02(nums, 20);
	std::cout << ' ' << m << ' ' << n << std::endl;
	return 0;
}