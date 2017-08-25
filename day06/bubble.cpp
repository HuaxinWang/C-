#include <iostream>
using namespace std;

template<typename T>
class MyLess
{
public:
	bool operator()(T &a, T &b)
	{
		return a < b;
	}
};

template<typename T>
class MyGreater
{
public:
	bool operator()(T &a, T &b)
	{
		return a > b;
	}
};

template<typename T, typename M>
class Sort
{
public:
	void sort(T *addr, int count, M &com)
	{
		int i = 0;
		int j = 0;
		T tmp;
		for (; i < count-1; i++)
		{
			for (j = 0 ; j < count-1-i; j++)
			{
				if (com(addr[j], addr[j+1]))
				{
					tmp = addr[j];
					addr[j] = addr[j+1];
					addr[j+1] = tmp;
				}
			}
		}
	}
};



template<typename T>
void display(T *addr, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << addr[i] << endl;
	}
	cout << "-----------------------------\n";
}

int main(void)
{
	int a[6] = {12, 45, 23, 8, 67, 13};
	display(a, 6);
#if 1
	Sort<int, MyLess<int> > s;
	MyLess<int> less;
	s.sort(a, 6, less);

	display(a, 6);
#endif

#if 0
	Sort<int, MyGreater<int> > s;
	MyGreater<int> greater;
	s.sort(a, 6, greater);
	display(a, 6);
#endif

	return 0;
}
