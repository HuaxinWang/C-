#include <iostream>
using namespace std;

int fun(int a)
{}
int & fun(int a)
{
	int a = 90;
	return a;
}

int main(void)
{
	int &a = fun();
	a = 190;
	cout << "a=" << a << endl;

	return 0;
}
