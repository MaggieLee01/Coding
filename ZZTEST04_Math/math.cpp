#include<iostream>
using namespace std;
//注意输入的数据范围 改为longlong即可AC
int main(void)
{
	int n;
	cin >> n;
	int ans = (n*(n - 1)) - 1;
	cout << ans;
	return 0;
}