#include <cstdio>
//#include <iostream>
#include <vector>
//#include<algorithm>
// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
//        duplication: (���) �����е�һ���ظ�������
// ����ֵ:             
//        true  - ������Ч�����������д����ظ�������
//        false - ������Ч������������û���ظ�������

//���������˼·��Ԫ�ط�������Ϊ��Ԫ�ص�λ�ã�˼�������ڲ����������飬��λ��������
bool duplicate(std::vector<int> nums) 
{
	int n = nums.size();
	for (int i = 0; i < n; ++i) {
		while (i != nums[i] - 1) {
			if (nums[i] == nums[nums[i] - 1])
				return nums[i];
			std::swap(nums[i], nums[nums[i] - 1]);
		}
	}
	return -1;

}