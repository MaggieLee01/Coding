#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//bool comp(vector<int> coder1, vector<int> coder2)
//{
//	if (coder1[0] == coder2[0])
//		return coder1[1] > coder2[1];
//	return coder1[0] > coder2[0];
//}

//int main() 
//{	
//	int n, ans = 0;
//	cin >> n;
//	vector<vector<int>> coder(n,  vector<int>(2,0));
//	//Â³°ôÖµ
//	for (int i = 0; i < n; i++) 
//	{
//		cin >> coder[i][0];		
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cin >> coder[i][1];
//	}
//	sort(coder.begin(),coder.end(),comp);
//	for (int i = 0; i < n; i++)
//	{
//		cout << coder[i][0] <<' ' << coder[i][1] << endl;
//	}
//	return 0;
//}

int main() 
{	
	int n, ans = 0;
	cin >> n;
	vector<string> str(n);
	
	for (int i = 0; i < n; i++) 
	{
		cin >> str[i];		
	}
	
	
	
	return 0;
}