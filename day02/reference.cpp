#include <iostream>

using namespace std;


int main(void)
{
	//int &a = 90;  error
	const int &a = 90;
	//const int tmp = 90;
	//const int &a = tmp;

	cout << (void *)&a << endl;
	int *p = (int *)&a;
	cout << *p << endl;

	return 0;
}
