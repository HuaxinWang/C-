#include <iostream>
#include <algorithm>

using namespace std;

/*
 int count_if(first, last, predicate)
 {
 	int num = 0;
	while (first != last)
	{
		if (predicate(*first))
		{
			num++;
		}
		first++;
	}
	return num;
 }
 
 */

bool predicate(int &a)
{
	return 1 == a%2;
}

int main(void)
{
	int a[7] = {1,2,3,4,5,6,7};
	cout << count_if(a, a+7, predicate) << endl;


	return 0;
}
