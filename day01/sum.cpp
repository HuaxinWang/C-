#include <iostream>  //#include <stdio.h>

using namespace std;

int main(void)
{
	int a[5] = {12, 45, 12, 4, 21};
	int i = 0;
	int sum = 0;
	//for (; i<(sizeof(a)/sizeof(int)); i++)
	for (; i<5; i++)
	{
		sum += a[i];
	}
	//cout << "sum = " << sum << '\n';
	cout << "sum = " << sum << endl;

	cout << "Hello World\n";	

	return 0;
}
