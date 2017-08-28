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

bool isOdd(const int &a)
{
	return 1 == a%2;
}

int main(void)
{
	int a[6] = {12, 45, 5, 20, 5, 17};
	list<int> l(a, a+6);
	display(l);

	//l.remove(5);
	l.remove_if(isOdd);
	display(l);
	
	cout << "Hello World\n";

	return 0;
}
