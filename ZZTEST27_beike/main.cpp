#include<iostream>
#include<vector>
#include<limits>
#include<string>
#include<algorithm>


//int main(void)
//{
//	int N = 0;
//	cin >> N;
//	vector<int> nums(N);
//	for (int i = 0; i < N; i++)
//		cin >> nums[i];
//
//	int left = 0;
//	int right = 0;
//	int maxv = 0;
//	int minlength = INT_MAX;
//	int temp = nums[left];
//
//	for (int i = 0; i < N; i++)
//	{
//		int temp = nums[i];
//		for (int j = i; j < N; j++)
//		{
//			temp = temp | nums[j];
//			if (temp == nums[i])
//			{
//				minlength = 1;
//				i = j;
//			}
//			if (temp == maxv)
//			{
//				minlength = min(j - i + 1, minlength);
//				i = j;
//
//			}
//			if (temp > maxv)
//			{
//				minlength = j - i + 1;
//				maxv = temp;
//			}	
//		}
//	}
//	cout << minlength << endl;
//	return 0;
//}

//int main(void)
//{
//	int N = 0;
//	cin >> N;
//	string str;
//	cin >> str;
//	int ans = 0;
//	int i = 0;
//	if (N % 2 == 0) 
//		i = N / 2;
//	else 
//		i = N / 2 + 1;
//	for (; i < N; i++)
//	{
//		if (str[i] != str[N - 1 - i]) ans++;
//	}
//	cout << ans << endl;
//}
//int main(void)
//{
//	int T = 0;
//	cin >> T;
//	for (int j = 0; j < T; j++)
//	{
//		int N = 0, M = 0;
//		cin >> N >> M;
//		if (N % 2 == 1 && M % 2 == 1)
//		{
//			int ans = min(M, N);
//			vector<int> nums = { 3,5,7,11,13,17,19,21,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149 };
//			for (int i = 0; i < nums.size(); i++)
//			{
//				if (ans % nums[i] == 0)
//					ans = nums[i];
//			}
//			cout << ans << endl;
//		}
//		else
//			cout << 2 << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <memory> 
#include <mutex>  
using namespace std;

#include <iostream>
#include <memory> // shared_ptr
#include <mutex>  // mutex

class Singleton {
public:
	typedef std::shared_ptr<Singleton> Ptr;	//共享指针在对象消亡时会自动调用析构函数
	~Singleton() {
		std::cout << "destructor called!" << std::endl;
	}

	//外界唯一获取该对象的public方法
	static Ptr get_instance() 
	{
		if (m_instance_ptr == nullptr)
		{
			std::lock_guard<std::mutex> lk(m_mutex);
			if (m_instance_ptr == nullptr)
			{
				m_instance_ptr = std::shared_ptr<Singleton>(new Singleton);
			}
		}
		return m_instance_ptr;
	}

private:
	//构造函数私有化
	Singleton() {
		std::cout << "constructor called!" << std::endl;
	}
	Singleton& operator=(const Singleton&) = delete;		//禁用默认重载赋值运算符函数
	Singleton(const Singleton&) = delete;
	//指针对象私有化，类内声明
	static Ptr m_instance_ptr;
	//互斥锁
	static std::mutex m_mutex;
};

// 类外初始化静态成员，定义mutex锁
Singleton::Ptr  Singleton::m_instance_ptr = nullptr;
//类型  类名::m_mutex 
std::mutex  Singleton::m_mutex;


int main() {
	Singleton::Ptr instance = Singleton::get_instance();
	Singleton::Ptr instance2 = Singleton::get_instance();
	return 0;
}


