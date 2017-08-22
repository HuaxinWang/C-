#include <iostream>

using namespace std;

class A
{};

class B : virtual public A
{};

int main(void)
{
	cout << sizeof(B) << endl; 

	return 0;
}
