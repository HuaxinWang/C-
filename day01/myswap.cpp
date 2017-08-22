#include <iostream>

using namespace std;
#if 0
void myswap(int a, int b)
{
	cout << "$$:a=" << a << " b=" << b << endl;
	int tmp = a;
	a = b;
	b = tmp;
	cout << "$$:a=" << a << " b=" << b << endl;
}
void myswap(int *a, int *b)
{
	cout << "$$:a=" << *a << " b=" << *b << endl;
	int tmp = *a;
	*a = *b;
	*b = tmp;
	cout << "$$:a=" << *a << " b=" << *b << endl;
}
#endif
void myswap(int &a, int &b)
{
	cout << "$$:a=" << a << " b=" << b << endl;
	int tmp = a;
	a = b;
	b = tmp;
	cout << "$$:a=" << a << " b=" << b << endl;
}

int main(void)
{
	int a = 90;
	int b = 89;
	cout << "a=" << a << " b=" << b << endl;
	//myswap(a,b);
	//myswap(&a,&b);
	myswap(a, b);
	cout << "a=" << a << " b=" << b << endl;

	return 0;
}
