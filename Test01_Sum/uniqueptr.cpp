#include<memory>
#include<string>
#include<utility>
#include<iostream>
using namespace std;
int main(void)
{
	unique_ptr<string> pu1(new string("hello world"));
	std::cout << 'a' << pu1 << endl;
	unique_ptr<string> pu2;
	std::cout << 'a' << pu2 << endl;
	//pu2 = pu1; // #1 not allowed
	unique_ptr<string> pu3;
	pu3 = unique_ptr<string>(new string("You"));
	pu2 = std::move(pu1);
	std::cout << 'a' << pu1 <<'a'<< pu2 <<'a' << pu3 << 'a' << std::endl;
	//std::cout << 'a' << *pu1 <<'a'<< *pu2 <<'a' << *pu3 << 'a' << std::endl;

	return 0;
}
