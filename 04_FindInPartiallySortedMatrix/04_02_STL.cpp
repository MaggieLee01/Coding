#include<vector>
#include<iostream>
using namespace std;
//熟悉vector的各个函数，还没涉及到内存这些复杂的东西
//vector为空时，empty()返回 1
//牛客网的格式，已通过；貌似边界测试不够

//while内写比较条件的时候如果先比较不等，再比较相等，效率会有提升
bool Find1(int target, vector<vector<int> > array) {

	int row = 0;
	int col = array[0].size() - 1;
	int rowCount = array.size();//因为在while中不能将int型变量与size_t变量作比较
	if (array.empty() == 1) return false;
	while (row < rowCount && col >= 0)
	{
		if (target == array[row][col])
		{
			return true;
		}
		else if (target > array[row][col])
		{
			row++;
		}
		else
		{
			col--;
		}
	}
	return false;
}
int test0(void)
{
	vector<vector<int> > array = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	bool result = Find1(7, array);
	std::cout<< result << std::endl;
	
	return 0;
}
