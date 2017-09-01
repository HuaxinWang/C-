#include <iostream>
using namespace std;

namespace myspace
{
void fun()
{
	cout << "fun()...\n";
}
};

int main(void)
{
	//using namespace myspace;
	myspace::fun();
	
	cout << "Hello World" << endl;

	return 0;
}
