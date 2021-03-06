#include<iostream>
#include<functional>
typedef std::function<void(int, int)> Functor;
class Blas
{
public:
	void setCallBack(const Functor& cb)
	{
		functor = cb;
	};

	void printFunctor()
	{
		functor(x, y);
	};

private:
	int x = 10;
	int y = 10;
	Functor functor;
};
class Atlas
{
public:
	Atlas(int x_, int y_) : x(x_), y(y_)
	{
		//使用当前类的非静态成员函数
		blas.setCallBack(std::bind(&Atlas::add, this, std::placeholders::_1, std::placeholders::_2));
	}
	void print()
	{
		blas.printFunctor();
	}
private:
	void add(int a, int b)
	{
		std::cout << y << std::endl;
		std::cout << a + b << std::endl;
	}

	Blas blas;
	int x, y;
};

int main(int argc, char** argv)
{
	Atlas atlas(5, 10);
	atlas.print();
	return 0;
}
