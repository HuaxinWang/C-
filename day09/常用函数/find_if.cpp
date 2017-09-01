#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 template<typename T, typename M>
 T find(T first, T last, M predicate)
 {
 	while (first != last)
	{
		if (predicate(*first))
		{
			break;
		}
		first++;
	}
	return first;
 }
 
 */

bool predicate(const int &a)
{
	return a>30;
}

int main(void)
{
	int a[9] = {12,3,4,56,3,61,2, 90, 78};
	vector<int> vec(a, a+9);
	vector<int>::iterator iter;
	iter = find_if(vec.begin(), vec.end(), predicate);
	if (iter != vec.end())
	{
		cout << *iter << endl;
	}
	else
	{
		cout << "no match\n";
	}
#if 0
	int a[9] = {12,3,4,56,3,61,2, 90, 78};
	int *p = find_if(a, a+9, predicate);
	if (p != a+9)
	{
		cout << *p << endl;
	}
	else
	{
		cout << "no match\n";
	}
#endif

	return 0;
}
