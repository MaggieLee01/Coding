//求两个整数之和，不能使用四则运算

int Add(int num1, int num2)
{
	int sum = 0;
	int flag = 1;
	int flagsum = 1;

	while (flag <= num1 && flag <= num2)
	{
		int dig1 = num1 & flag;
		int dig2 = num2 & flag;
		if (dig1 & dig2 == 1)//两个都是1
		{
			if (sum & flagsum == 1)
			{
				
			}
			else
			{
				
			}
		}
		else if (dig1 | dig2 == 1)//只有一个1
		{

		}
		else if (dig1 | dig2 == 0) //两个都是0
		{

		}
		flag << 1;
	}
}