#include <iostream>

using namespace std;

template<typename T>
void bubble(T a[], int count)
{
	int i = 0;
	int j = 0;
	T tmp;
	for (; i < count-1; i++)
	{
		for (j = 0; j < count-1-i; j++)
		{
			if (a[j] > a[j+1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}

template<typename T>
void display(const T a[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main(void)
{
	int a[5] = {23, 12, 67, 32, 2};
	bubble(a, 5);
	display(a, 5);

	string str[4] = {"waterapple", "pear"
			        , "banana", "apple"};
	bubble(str, 4);
	display(str, 4);

	return 0;
}
