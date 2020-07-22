#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

//阅文科技的笔试题太low了

//找出现次数最多的数组，以AC
//int main(void)
//{
//	map<int, int>mp;
//	pair<int, int>ans;
//
//	int temp = 0;
//	while (cin >> temp)
//	{
//		mp[temp]++;
//		if (mp[temp] > ans.second)
//		{
//			ans.first = temp;
//			ans.second = mp[temp];
//		}
//		else if (mp[temp] == ans.second)
//		{
//			ans.first = max(temp, ans.first);
//		}
//		if (cin.get() == '\n') break;
//	}
//	cout << ans.first << endl;
//	return 0;
//}


//去掉输入的10，注意输入不定长度的写法，直接cin即可
//int main(void)
//{
//	vector<int> num;
//	int n = 0;
//	while (cin >> n)
//	{
//		if (n == 10) continue;
//		num.push_back(n);
//	}
//	if (num.size() > 0) cout << num[0];
//	for (int i=1;i<num.size();i++)
//		cout << ' ' << num[i];
//	return 0;
//}


//struct Point 
//{
//	int x;
//	int y;
//};
//struct cmp
//{
//	bool operator() (Point p1,Point p2)
//	{
//		if (p1.x == p2.x) return p1.y < p2.y;
//		else return p1.x < p2.x;
//	}
//};
//int main(void)
//{
//	int a = 0, b = 0;
//	vector<Point> vec;
//	while (cin >> a >> b)
//	{
//		Point p;
//		p.x = a;
//		p.y = b;
//		vec.push_back(p);
//	}
//	sort(vec.begin(), vec.end(), cmp() );//注意写法
//	for (auto i : vec)	
//		cout << i.x << ' ' << i.y << endl;
//	return 0;
//}

//移动赋值不会写了
//class A
//{
//public:
//	A a(string s) 
//	{
//		*_s = s;
//	}
//	A a()
//	{
//		_s = nullptr;
//	}
//	A(const A& a) = delete;
//	const A & operator=(const A&&a)
//	{
//		*_s = a.s;
//	}	
//	A( A && a)
//	{
//		*_s = a.s;
//	};
//
//	string s()
//	{
//		return *_s;
//	}
//	~A()
//	{
//		_s = nullptr;
//	}
//
//private:
//	string *_s;
//};
//int main(void)
//{
//	string input;
//	cin >> input;
//	A a(input);
//	A b(move(a));
//	cout << b.s() << endl;
//	A c;
//	c = move(b);
//	cout << c.s() << endl;
//
//}


int main(void)
{
	map<string, int>mp;
	string a, b;
	int n = 0;
	vector<string> vec;
	int num = 0;
	cin >> num;
	while (cin >> a >> b)
	{
		if (a == "set")
		{
			cin >> n;
			mp[b] = n;
		}
		if (a == "get")
		{
			if (mp.find(b) != mp.end())
			{
				char cc = mp[b] + '0';
				string ss;
				ss+=cc;
				vec.push_back(ss);
			}				
			else vec.push_back("none");
		}
	}
	for (auto i : vec)
	{
		cout << i << endl;
	}
	return 0;
}