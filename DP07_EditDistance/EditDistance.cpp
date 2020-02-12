//求编辑距离:仅能三种操作：插入、删除、替换
//2019-09-01
//未在系统上测试，测试代码没问题，基本按照文章思路

//本代码整体思路相当于 不断从结束处推导求出开头处的结果
//很多参考答案为不断从开头处推导出结尾处的结果，更好处理一些

//递归要找结束条件；dp算法要找base case 起始条件
//递归本身就是在不断循环，所以不需要for循环；但是对于dp来说，则需要for循环来不断地遍历二维数组
//写着写着，快把递归与动态规划搞混淆了，还是得多些，不要一步到位到dp写法。

#include<vector>
#include<iostream>
#include<algorithm>
using std::min;

//min函数只能同时比较两个数字的大小

//递归方法，自顶向下，即从开头处理
int EditDistance_recursively(const char* str1, const char* str2)
{
	if (str1 == nullptr && str2 == nullptr) return 0;
	if (str1 == nullptr || *str1 == '\0')  return strlen(str2);
	if (str2 == nullptr || *str2 == '\0')  return strlen(str1);
	int str1Length = strlen(str1);
	int ans = 0;

	//不要把 递推 备忘录形式 dp算法 搞混淆

	/*for (int i = 0; i < str1Length; i++)
	{*/
		//if (str1[i] == str2[i])
		if (*str1 == *str2)
			ans = EditDistance_recursively(str1 + 1, str2 + 1);
		else
			//假定编辑str1变成str2，以下分别表示 插入、删除、替换。
			ans = min( min(EditDistance_recursively(str1, str2 + 1),
				EditDistance_recursively(str1 + 1, str2) ),
				EditDistance_recursively(str1 + 1, str2 + 1) ) + 1;
	/*}*/
	return ans;	 
}

//备忘录的递归
using std::vector;

int ConsultDict(const char* str1, const char* str2, vector<vector<int> >&Dict, int m, int n)
{
	//应该放在判断str1 str2 是否结束的后面，如果在边界处应该直接返回，此处判断Dict数组会出界
	//if (Dict[m][n] != 0) return Dict[m][n];

	//不能再和递归一样用*str1啦，此时，是后面的索引在不断变化,返回处也是呀，不应该返回str呀
	/*if ( *str1 == '\0') return strlen(str2);
	if ( *str2 == '\0') return strlen(str1);*/

	//教训：尽管和递归的思路一样，但直接复制粘贴之后更改，容易忽略很多细节，还是独立思考，重新自己写
	if (str1[m] == '\0') return strlen(str2) - n;
	if (str2[n] == '\0') return strlen(str1) - m;

	if (Dict[m][n] != 0) return Dict[m][n];
	

	//此处发现了一个很严重的错误思路
	//for的循环条件只能是一个， 应该用 && 逻辑符号连接 i j 的判断，不能用逗号表达式呀
	//看网上初始化时如果初始化多个变量，可能会出错

	//建议此处 还有 dp 写法的地方，使用双重for循环，而不是同时在一个for循环里面，这样子会漏掉部分数据，遍历不全
	//此处或许还可以，在不停的递归，在dp中应该会导致遗漏
	//for (int i = m, j = n; i < str1Length , j < str2Length; i++, j++)
	//for (int i = m, j = n; i < str1Length && j < str2Length; i++, j++)

	/*int str1Length = strlen(str1);
	int str2Length = strlen(str2);	
	for (int i = m,j=n ; i < str1Length &&  j < str2Length; i++ , j++)
	{*/
		/*for (int j = n; j < str2Length; )
		{*/
			/*if (str1[i] == str2[j])
				Dict[i][j] = ConsultDict(str1, str2, Dict, i + 1, j + 1);
			else
				Dict[i][j] = min(min(ConsultDict(str1, str2, Dict, i + 1, j + 1),
					ConsultDict(str1, str2, Dict, i, j + 1)),
					ConsultDict(str1, str2, Dict, i + 1, j)) + 1;*/
		/*}*/		
	/*}*/

	//写到最后发现，递归形式不需要for循环，那么备忘录形式应该也不需要for循环了，备忘录形式仅仅是递归形式减少计算次数
	if (str1[m] == str2[n])
		Dict[m][n] = ConsultDict(str1, str2, Dict, m + 1, n + 1);
	else
		Dict[m][n] = min(min(ConsultDict(str1, str2, Dict, m + 1, n + 1),
			ConsultDict(str1, str2, Dict, m, n + 1)),
			ConsultDict(str1, str2, Dict, m + 1, n)) + 1;

	return Dict[m][n];
}
int EditDistance_Dict(const char* str1, const char* str2)
{
	if (str1 == nullptr && str2 == nullptr) return 0;
	if (str1 == nullptr || *str1 == '\0') return strlen(str2);
	if (str2 == nullptr || *str2 == '\0') return strlen(str1);
	int str1Length = strlen(str1);
	int str2Length = strlen(str2);
	vector< vector<int> > Dict(str1Length + 1, vector<int>(str2Length + 1, 0));
	int l = ConsultDict(str1, str2, Dict, 0, 0);
	return l;//为了方便查看Dict数组内存
}


//动态规划，自底向上，从结尾处开始处理
int EditDistance_DP(const char* str1, const char* str2)
{
	if (str1 == nullptr && str2 == nullptr) return 0;
	if (str1 == nullptr || *str1 == '\0') return strlen(str2);
	if (str2 == nullptr || *str2 == '\0') return strlen(str1);
	int str1Length = strlen(str1);
	int str2Length = strlen(str2);
	vector< vector<int> > Dict(str1Length + 1, vector<int>(str2Length + 1, 0));
	
	int i = 0, j = 0;
	//此处相当于base case，不能忘记呀，不然的话，结尾处参与比较的都是0 
	for (i = 0; i < str1Length; i++)
		Dict[i][str2Length] = str1Length - i;
	
	for (j = 0; j < str2Length; j++)
		Dict[str1Length][j] = str2Length - j;
	
	//此处为for循环的错误认识
	//for (i = str1Length - 1, j = str2Length - 1; i >= 0, j >= 0; j--, i--)
	//for (i = str1Length - 1, j = str2Length - 1; i >= 0 && j >= 0; j--, i--)
	for (i = str1Length - 1; i >= 0 ; i--)
	{
		for (j = str2Length - 1; j >= 0; j--)
		{
			if (str1[i] == str2[j])
				Dict[i][j] = Dict[i + 1][j + 1];
			else
				Dict[i][j] = min(min(Dict[i + 1][j], Dict[i + 1][j + 1]), Dict[i + 1][j + 1]) + 1;
		}		
	}
	//dp需要起始条件，下面的判断是对于i j同时循环的情况，i j双重遍历时不需要下面的情况
	/*if (i == 0) Dict[0][0] = Dict[0][j] + j;
	if (j == 0) Dict[0][0] = Dict[i][0] + i;*/
	//结束循环的时候，i j 分别多减了一次1，所以应该补上
	//if (i == -1) Dict[0][0] = Dict[0][j + 1] + j + 1;
	//if (j == -1) Dict[0][0] = Dict[i + 1][0] + i + 1;
	int l = Dict[0][0];
	return l;
}


//前面三种方法已经调通的情况下，开始尝试压缩存储空间，并且从起始位置推导末尾位置
//https://blog.csdn.net/xflow_/article/details/8815293
//看到网上压缩为1维数组，由二维降到一维，不知道能不能压缩为O(1)空间
int EditDistance_Dimension(const char* str1, const char* str2)
{
	if (str1 == nullptr && str2 == nullptr) return 0;
	if (str1 == nullptr || *str1 == '\0') return strlen(str2);
	if (str2 == nullptr || *str2 == '\0') return strlen(str1);
	int str1Length = strlen(str1);
	int str2Length = strlen(str2);
	
	int up = 0;
	int down = 0;

	vector<int> Dict(str2Length + 1, 0);
	for (int i = 0; i <= str2Length; i++)
		Dict[i] = i;

	//第0行相当于空字符，第一行对应第一个字母，相当于base case
	for (int i = 0; i < str1Length; i++)
	{
		//相当于首字符上面的一行
		up = Dict[0];
		Dict[0]++;
		
		for (int j = 0; j < str2Length; j++)
		{
			//dict[j+1]要更新，先把以前的值保存下来
			down = Dict[j + 1];
			//相当于第 i 处的距离存储在第i+1行
			if (str1[i] == str2[j])
				Dict[j + 1] = up;
			else			
				Dict[j + 1] = min(min(Dict[j + 1], up), Dict[j]) + 1;
			
			up = down;
		}
	}
	return Dict[str2Length];
}

//测试程序
int main(void)
{
	const char *str1 = "apple", *str2 = "rad";//神奇，所以，*应该在字符串名字前面喽，*指针表示不能共用
	std::cout << EditDistance_recursively(str1, str2) << std::endl;
	std::cout << EditDistance_Dict(str1, str2) << std::endl;
	std::cout << EditDistance_DP(str1, str2) << std::endl;
	std::cout << EditDistance_Dimension(str1, str2) << std::endl;

	const char *str3 = "abc", *str4 = "cbcd";
	std::cout << EditDistance_recursively(str3, str4) << std::endl;
	std::cout << EditDistance_Dict(str3, str4) << std::endl;
	std::cout << EditDistance_DP(str3, str4) << std::endl;
	std::cout << EditDistance_Dimension(str3, str4) << std::endl;

	const char *str5 = "coffee", *str6 = "cafe";
	std::cout << EditDistance_recursively(str5, str6) << std::endl;
	std::cout << EditDistance_Dict(str5, str6) << std::endl;
	std::cout << EditDistance_DP(str5, str6) << std::endl;
	std::cout << EditDistance_Dimension(str5, str6) << std::endl;

	const char *str7 = "kitten", *str8 = "sitting";
	std::cout << EditDistance_recursively(str7, str8) << std::endl;
	std::cout << EditDistance_Dict(str7, str8) << std::endl;
	std::cout << EditDistance_DP(str7, str8) << std::endl;
	std::cout << EditDistance_Dimension(str7, str8) << std::endl;

   	return 0;
}