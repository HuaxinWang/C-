#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A()\n";
	}
	//~A()
	virtual ~A()
	{
		cout << "~A()\n";
	}
};

class B: public A
{
public:
	B()
	{
		cout << "B()\n";
	}
	~B()
	{
		cout << "~B()\n";
	}
};


int main(void)
{
	//1,B b;
	//2,B *b = new B;
	//  delete b;
	A *a = new B;
	delete a;

	return 0;
}


