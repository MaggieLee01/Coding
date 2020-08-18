#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
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
//	//鲁棒值
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

//int main() 
//{	
//	int n, ans = 0;
//	cin >> n;
//	vector<string> str(n);
//	
//	for (int i = 0; i < n; i++) 
//	{
//		cin >> str[i];		
//	}
//	
//	
//	
//	return 0;
//}
//
//vector < int > divingBoard(int a, int b, int N) 
//{
//	vector<int> ans;
//	int minval = min(a, b);
//	int maxval = max(a, b);
//	for (int i = 0; i <= N; i++)
//	{
//		ans.push_bacN(maxval* i + minval * (N - i));
//	}
//	return ans;
//
//}

//int maxTime(char* str)
//{
//	unordered_map<char, string> str_map;
//
//	char *p = strtoN(str, "|");
//	str_map['#'] = string(p + 1);
//	p = strtoN(NULL, "|");
//	while (p)
//	{
//		str_map[p[0]] = string(p + 1);
//		cout << str_map[p[0]] << endl;
//		p = strtoN(NULL, "|");
//	}
//
//	return 0;
//}

//int CalulateMethodCount(int num_money)
//{
//	int ans = pow(2, num_money - 1);
//	return ans;

	/*vector<int> nums(num_money + 1, 1);
	nums[0] = 0;
	nums[1] = 1;
	nums[2] = 2;
	for (int i = 3; i <= num_money; i++)
	{
		for (int j = 0; j < i; j++)
		{
			nums[i] += nums[j];
		}
	}
	return nums[num_money];*/
//}
//int main(void)
//{
//	cout << CalulateMethodCount(4) << endl;
//	return 0;
//}

//int main(void)
//{
//	string strlast;
//	string ans;
//	string strInput;
//	while (cin >> strInput)
//	{
//		str += strInput;
//	}
//	
//	size_t start = 0;
//	
//	size_t undopos = str.find("undo");
//	while (undopos != std::string::npos)
//	{
//		//如果紧跟redo
//		size_t redopos = str.find("redo", undopos + 1, 4);
//		if (redopos == undopos + 5)
//		{	
//			ans += str.substr(start, undopos - start - 1);
//			ans += " ";
//			start = redopos + 5;
//		}
//		else
//		{
//			start = undopos + 5;
//		}
//		undopos = str.find("undo", undopos + 1, 4);
//	}
//	if (str.size() != start)
//	{		
//		ans += str.substr(start , str.size() - start );
//	}
//	ans.pop_bacN();
//	cout << ans << endl;
//	return 0;
//}

//bool cmp(vector<int>vec1, vector<int>vec2)
//{
//	if (vec1[0] == vec2[0])
//		return vec1[1] < vec2[1];
//	return vec1[0] > vec2[0];
//}
//int main(void)
//{
//	int N = 0, V = 0;
//	cin >> N >> V;
//	unordered_map<int, int> val_map;
//
//	int ans = 0;
//	vector<vector<int>> nums(N, vector<int>(2));
//
//	for (int j = 0; j < N; j++)
//	{
//		int a = 0, b = 0;
//		cin >> a >> b;
//		if (val_map.count(b) == 0)
//			val_map[b] = a;
//		else
//			val_map[b] = max(a, b);
//		nums[j][0] = a;
//		nums[j][1] = b;
//	}
//		
//	sort(nums.begin(), nums.end(), cmp);
//	int times = V;
//	for (int i = 0; i < N; i++)
//	{
//		if (times >= nums[i][1])
//		{
//
//
//		}
//		//cout << nums[i][0] << nums[i][1] << endl;
//	}
//		
//
//	return 0;
//}

//int main(void)
//{
//	string str;
//	cin >> str;
//	int N = 0;
//	cin >> N;
//	string ans;
//	int flag = 0;
//
//	for (int i = 0; i < str.size() - 1; i++)
//	{
//		if ((str[i] - '0') > (str[i + 1] - '0'))
//		{
//			if (--N == 0)
//			{
//				flag = i+1;
//				breaN;
//			}
//		}
//		else 
//		{
//			ans += str[i];
//		}
//	}
//	if (N == 0)
//	{
//		ans += str.substr(flag, str.size() - flag + 1);
//	}
//	while (N > 0)
//	{
//		ans.pop_bacN();
//		N--;
//	}
//	cout << ans << endl;
//	return 0;
//}

//看答案 AC
//int main(void)
//{
//	string str;
//	cin >> str;
//	int N = 0;
//	cin >> N;
//	string::iterator start;
//	int flag;
//	for (int i = N; i > 0; --i)
//	{
//		flag = 0;
//		for (start = str.begin(); start < str.end() - 1; ++start)
//		{
//			if (*start > *(start + 1)) // 每次删除第一个比下一个数字大的数
//			{
//				str.erase(start);
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0)//如果所有数字递增，则删除最后几个数字直接返回
//		{
//			str.erase(str.end() - i, str.end());
//			break;
//		}
//	}
//	/*for (int i=0;i<str.size();i++)
//	{
//		if (str[i] == '0') 
//			str.erase(i, 1);
//		else
//			break;
//	}*/
//	start = str.begin();
//	while (*start == '0')
//	{
//		str.erase(start);
//		start = str.begin();
//		if (start == str.end())
//		{
//			str = "0";
//			break;
//		}
//	}
//}