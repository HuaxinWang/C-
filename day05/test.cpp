#include <iostream>
using namespace std;

class A
{
public:
	A(){cout << "A()\n";}
	A(const A &a){cout << "A(const A &)\n";}
	void test()
	{
		cout << (void *)this << endl;
	}
};

void fun(A a)
{}

A fun2()
{
	A a;
	//a.test();
	cout << (void *)&a << endl;
	return a;
}

int main(void)
{
	//A a;
	//A b = a;  //A b(a);

	//fun(a);
	A aa = fun2();
	//aa.test();
	cout << (void *)&aa << endl;

	return 0;
}
