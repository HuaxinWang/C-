#include <iostream>
using namespace std;

class A
{
void fun()
{}
};

class B
{
	void fun()
	{}
};

namespace project1
{
//A
void fun()
{
	cout << "A->fun()...\n";
}
}

namespace project2
{
//B
void fun()
{
	cout << "B->fun()...\n";
}
}

int main(void)
{
	project1::fun();
	project2::fun();

	cout << "Hello World" << endl;

	return 0;
}
