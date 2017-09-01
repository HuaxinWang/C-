#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void display(const vector<int> &vec)
{
	vector<int>::const_iterator iter = vec.begin();
	for (; iter != vec.end(); iter++)
	{
		cout << " data=" <<*iter << ' ';
	}
	cout << endl;
#if 0
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	}
	cout << endl;
#endif
}

int main(void)
{
	int a[7] = {89, 78, 23, 45, 76, 12, 34};
	int b[7] = {0};
	copy(a, a+7, b);
	for (int i = 0; i<7; i++)
	{
		cout << b[i] << ' ';
	}
	cout << endl;

#if 0
	int a[7] = {89, 78, 23, 45, 76, 12, 34};
	vector<int> vec(7);
	
	//display(vec);
	///cout << vec.size() << ' ' << vec.capacity() << endl;
	
	//vec.clear();
	
	//display(vec);
	//cout << vec.size() << ' ' << vec.capacity() << endl;

	copy(a, a+7, vec.begin());
	display(vec);

	/* 
	strcpy(char *dest, char *src)
	{
	 	while ('\0' != *src)
		{
			*dest = *src;
			dest++;
			src++;
		}	
	}


	 void copy(first, last, start)
	 {
	 	while (first < last && start != end)
		{
			*start = *first;
			first++;
			start++;
		}
	 }
	 
	 
	 */
#endif

	return 0;
}
