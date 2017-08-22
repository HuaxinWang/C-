#include <iostream>  //#include <stdio.h>

using namespace std;

int main(void)
{
	int a[2][3];
	int i = 0;
	int j = 0;
	int *p = &a[0][0];
	for (; i < 6; i++)
	{
		cin >> *(p+i);
	}
#if 0
	for (; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cin >> a[i][j];
		}
	}
#endif

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		{
			cout << a[j][i] << ' ';
		}
		cout << endl;
	}

	return 0;
}
