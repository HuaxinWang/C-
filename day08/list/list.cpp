#include <iostream>
#include <list>

using namespace std;

typedef list<int> LIST;

void display(const LIST &l)
{
	LIST::const_iterator iter = l.begin();
	for (; iter != l.end(); iter++)
	{
		cout << *iter << ' ';
	}
	cout << endl;

}

bool compare(const int &a, const int &b)
{
	return a>b;
}

int main(void)
{
	int a[5] = {12, 45, 5, 20, 17};
	list<int> l(a, a+5);
	display(l);

#if 0
	list<int> l;
	
	l.push_back(11);
	l.push_back(22);
	l.push_back(33);
	l.push_back(44);
	
	l.push_front(1111);
	l.push_front(2222);
	l.push_front(3333);
	l.push_front(4444);
	display(l);

//	l.sort();
	l.sort(compare);
	display(l);
#endif

	return 0;
}
