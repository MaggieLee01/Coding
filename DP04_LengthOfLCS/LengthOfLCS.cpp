//求最长公共子序列（Longest Common Subsequence，简称 LCS）
//子串一定是连续的，而子序列不一定是连续的
//2019-08-28
//https://mp.weixin.qq.com/s/SUJ35XDpTn5OKU7hud-tPw
//dp写法已经通过LeetCode测试，其他方法未在系统上测试，测试代码没问题

//因为子序列类型的问题，穷举出所有可能的结果都不容易，
//动态规划算法做的就是穷举 + 剪枝，它俩天生一对儿。
//所以可以说只要涉及子序列问题，十有八九都需要动态规划来解决，

#include<iostream>
#include<vector>
//以下为自己的尝试，递归的备忘录形式；状态转移方程在答案指点下修正，   
//dict[i][j]代表str1以i开头，str2以j开头的两个子字符串的最长公共子序列。
//在这种情况下，写成dp形式时，应该反向遍历，先求出末尾处的LCS
//也可定义dict[i][j]代表str1以i结束，str2以j结束的两个子字符串的最长公共子序列，此时的dp遍历应为正序
int ConsultDict(const char* str1, const char* str2, std::vector<std::vector<int> >& dict,int I1,int I2)
{
	if (dict[I1][I2] == 0)
	{
		int str1Length = strlen(str1);
		int str2Length = strlen(str2);

		for (int i = I1; i < str1Length; i++)
		{
			for (int j = I2; j < str2Length; j++)
			{
				if (str1[i] == str2[j])
					dict[i][j] = ConsultDict(str1, str2, dict, i + 1, j + 1) + 1;
				else
				{
					//此处转移有误，开始误以为：不相等的时候取决于各右移一位；
					//						此时漏掉的情况，str11移除的位可能和str2移除位的下一位一样
					//dict[i][j] = ConsultDict(str1, str2, dict, i + 1, j + 1);

					//因此应该找到旁边的最大值

					//此时，数组存储的已为最长子序列
					int m = ConsultDict(str1, str2, dict, i, j + 1);
					int n = ConsultDict(str1, str2, dict, i + 1, j);
					dict[i][j] = m > n ? m : n;
				}
					
			}
		}
	}
	return dict[I1][I2];	
}
int LengthOfLCS(const char* str1, const char* str2)
{
	if (str1 == nullptr || str2 == nullptr)
		return 0;
	int str1Length = strlen(str1);
	int str2Length = strlen(str2);
	int max = 0;
	
	std::vector<std::vector<int> > dict(str1Length + 1, std::vector<int>(str2Length + 1, 0));

	max= ConsultDict(str1, str2, dict, 0, 0);
	return max;

	/*ConsultDict(str1, str2, dict, 0, 0);*/

	/*for (int i = 0; i < str1Length; i++)
	{
		for (int j = 0; j < str2Length; j++)
		{
			max < dict[i][j];
			max = dict[i][j];
		}
	}
	return max;	*/
}

//在自己思路下改写成dp形式
int LengthOfLCS_dp(const char* str1, const char* str2)
{
	if (str1 == nullptr || str2 == nullptr)
		return 0;
	int str1Length = strlen(str1);
	int str2Length = strlen(str2);

	std::vector<std::vector<int> > dict(str1Length + 1, std::vector<int>(str2Length + 1, 0));
	for (int i = str1Length - 1; i >= 0; i--)
	{
		for (int j = str2Length - 1; j >= 0; j--)
		{
			if (str1[i] == str2[j])
				dict[i][j] = dict[i + 1][j + 1] + 1;
			else
				dict[i][j] = dict[i + 1][j] > dict[i][j + 1] ? dict[i + 1][j] : dict[i][j + 1];
		}
	}
	return dict[0][0];
}

int main(void)
{
	const char* str1 = "goodmorning";
	const char* str2 = "dormin";
	int m = LengthOfLCS(str1, str2);
	std::cout << m << std::endl;
	m = LengthOfLCS_dp(str1, str2);
	std::cout << m << std::endl;

	const char* str3 = "helloworld";
	const char* str4 = "eloceell";
	m = LengthOfLCS(str3, str4);
	std::cout << m << std::endl;
	m = LengthOfLCS_dp(str3, str4);
	std::cout << m << std::endl;
}
