//求最长回文子序列的长度。
//子串一定是连续的，而子序列不一定是连续的
//2019-11-13
//https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA
//已通过LeetCode测试，只与周围的有关系，可以进行空间优化

//三步法:
//明确dp[i][j]表示的是什么，ij之间的长度 还是 ij为起始位置？
//		例如：bbbbab dp[0][4]应该为多少？目前假设为4 
//		暂定长度方便找出相互之间的关系
//起始位置
//转移方程

#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::max;

int LengthOfLPS(const char* str)
{
	if (str == nullptr) return 0;
	int length = strlen(str);
	vector< vector<int> > dict(length + 1, vector<int>(length + 1, 0));
	//困难点：计算第i行的时候，i+1行还没有计算出来 咋整？
	//		画出二维矩阵 更好看清遍历方向
	//		转移方程目前也有难点，对于重复数字【起始值为1】、非重复数字情况【起始值为0】不太一样	//此坑为自己理解回文序列长度有误。
	//画出二维矩阵，思考后的遍历顺序基本没问题，和答案一样
	for (int i = length - 1; i >= 0; i--)   
	{
		dict[i][i] = 1;
		for (int j = i + 1; j < length; j++)
		{			
			if (str[i] == str[j])
				dict[i][j] = dict[i + 1][j - 1] + 2;
						
			else			
				dict[i][j] = max(dict[i + 1][j], dict[i][j - 1]);			
		}
	}
	return dict[0][length - 1];
}

int main(void)
{
	const char* str1 = "babbbb";
 	std::cout << LengthOfLPS(str1) << std::endl;

	const char* str2 = "abcdecnambl";//注意beb的回文长度为3，不是2，掉在此坑太久了
	std::cout << LengthOfLPS(str2) << std::endl;

	const char* str3 = "abcdecnbmal";
	std::cout << LengthOfLPS(str3) << std::endl;

	const char* str4 = "bababaccababab";
	std::cout << LengthOfLPS(str4) << std::endl;

	const char* str5 = "baba";
	std::cout << LengthOfLPS(str5) << std::endl;
}