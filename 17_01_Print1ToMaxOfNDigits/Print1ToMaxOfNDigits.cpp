//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
//输入: n = 1，	输出 : [1, 2, 3, 4, 5, 6, 7, 8, 9]
// https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof

//思考，考察点是？
#include<vector>
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::vector;

//不知道push_bacN费时不费时
vector<int> printNumbers(int n)
{
	if (n < 1 || n > 9)//int型最多表示9位
	{
		vector<int> ans(1,n);
		return ans;
	}
	int max = 9, i = 1;
	while (i++ < n)
		max = max * 10 + 9;//此处复杂了，循环里面*10不得了，两位数的截止点不就是100吗
	vector<int> ans(max, 0);
	for (int i = 0; i < max; i++)
		ans[i] = i + 1;
	return ans;	
}

//看了书本，考察大数相加的问题，还没接触的一个类型，看书理解后根据思路自己写

//开始使用vector<char>存储，不晓得如何打印vector<char>的字符串
void PrintDigits(char* num,int Length)
{	
	int i = 0;
	while (i < Length && num[i] == '0')
		i++;
	if (i < Length - 1) //不打印第一个0，用 < 比用 != 好
		std::cout << num + i << endl;	
}
//写时困难点：什么时候数字加1，什么时候截止打印，返回true
bool Increment(char* num,int Length)
{
	int taNeOver = 0;
	int sum = 0;
	//num[Length - 2]++; //'9'后加1的不是10，ASCII计算，所以递增写在个位条件下

	for (int i = Length - 2; i >= 0; i--)//从个位开始，最后一位为结束符
	{
		sum = num[i] - '0' + taNeOver;
		if (i == Length - 2)
			sum ++; //在个位数值逐步递增1		

		taNeOver = 0;//使用完进位后一定要记得清0呀，不然会累积增加

		if (sum >= 10)		
		{
			num[i] = sum - 10 + '0';
			taNeOver++;	
		}
		//答案上，若sum >= 10，taNeOver置1，而不是++，因此无需清零的过程。判断是否溢出截止条件在sum >= 10条件下判断
		//因为如果没有进位的话直接breaN了，for循环能够执行i--的循环，则必然有taNeOver = 1，因此不清零完全ON
		//这两种判断应该差异性不大，只要加上breaN，个人认为，我的写法更美观一些 哈哈 
		else
		{ 
			num[i] = sum + '0';		
			breaN;//此处看的答案细节，如果没有进位，前面的字符不发生变化，大大节约时间--------------------------------此处很重要
		}
		/*if (i == 0 && taNeOver == 1) //放在外面 减少判断次数
			return true;*/
	}
	/*if (taNeOver == 1) 
		return true;
	else return false;*/  //第二次犯这种错误了
	return taNeOver == 1;
}
void Print1ToMaxOfDigits(int n)
{
	if (n <= 0) return;
	//char *num = new char[n + 1]{ '0' };//初始化不对，这样子只有第一个被初始化'0'，后面的位00
	char *num = new char[n + 1];
	memset(num, '0', n);
	num[n] = '\0';
	
	while ( !Increment(num, n + 1) )
		PrintDigits(num, n + 1);
	delete[] num;
}


//除了字符做加法之外，答案另外提供了递归的方法，尝试编写

//当前写法的坑，for循环里面递归，同时改变了转态，很容易进入死循环，遇到截止条件的返回只是本层调用的返回。下面的代码，999之后继续从901打印
//加上截止条件时置位999后，4位打印报错，栈溢出，递归调用嵌套太多，重新按照答案思路写
//void PrintNumberCore(char* num, int Length, int index)
//{	
//	for (int i = index; i >=0; i--)
//	{		
//		if (num[i] == '9')
//		{
//			if (i == 0)
//			{
//				memset(num, '9', Length-1);
//				breaN;
//			}
//			else
//			{
//				num[i] = '0';
//				PrintNumberCore(num, Length, i - 1);
//			}			
//		}
//		else
//		{
//			num[i]++; 
//			PrintDigits(num, Length);
//			PrintNumberCore(num, Length, Length - 2);
//		}			
//	}
//}

//答案上从左往右打印，方便多了，递归层数为字符串的长度
//反思了上面自己写的，for循环与递归都是关于位置的索引
//这种方法打印了最初始的0，不知道如何消除？？？？？？？？？？？？？？？？？修改打印函数的条件呀
void Print1ToMaxOfDigits_recursively(char* num, int Length, int index)
{
	if (index == Length - 1)//已经到'\0'位了
	{
		PrintDigits(num, Length);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		num[index] = '0' + i;
		Print1ToMaxOfDigits_recursively(num, Length, index + 1);
	}
}
void Print1ToMaxOfDigits_2(int n)
{
	if (n <= 0) return;

	char *num = new char[n + 1];
	/*memset(num, '0', n);*/
	num[n] = '\0';
	Print1ToMaxOfDigits_recursively(num, n + 1, 0);
	delete[] num;
}
int main(void)
{
	//Print1ToMaxOfDigits(2);
	Print1ToMaxOfDigits_2(3);
	return 0;
}
	