#include <iostream>
using namespace std;

class Test
{
private:
	Test()
	{
		cout << "Test()" << endl;
	}
	Test(const Test &other)
	{}
public:

	static Test& fun()
	{
		static Test t;
		return t;
	}
};

int main(void)
{
	Test &t1 = Test::fun();

	return 0;
}
