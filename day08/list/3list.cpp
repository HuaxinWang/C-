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


int main(void)
{
	int a[5] = {12, 45, 5, 20, 17};
	list<int> l1(a, a+5);
	l1.sort();
	cout << "l1:";
	display(l1);
	
	int a2[5] = {2, 55, 15, 16, 7};
	list<int> l2(a2, a2+5);
	l2.sort();
	cout << "l2:";
	display(l2);

	//将l2合并到l1中
	l1.merge(l2);
	cout << "l1 size = " << l1.size()
		 << "  l2 size = " << l2.size() << endl;

	cout << "l1: ";
	display(l1);

	return 0;
}
