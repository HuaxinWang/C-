#include <iostream>

using namespace std;

struct Test
{
	int &a;
	char &b;
	double &c;
};

int main(void)
{
	cout << sizeof(Test) << endl;
	int aa = 90;
	char bb = 'B';
	double cc = 3.14;
	cout << "&aa= " << (void*)&aa
		 << " &bb= " << (void*)&bb
		 << " &cc= " << (void*)&cc << endl;
	Test t = {aa, bb, cc};
	cout << (void *)(*((int *)&t)) << endl;
	cout << (void *)(*((int *)&t+1)) << endl;
	cout << (void *)(*((int *)&t+2)) << endl;

	return 0;
}
