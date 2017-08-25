#include <iostream>
using namespace std;

class Test
{
public:
	void operator()(void)
	{
		cout << "Test::operator()\n";
	}
};

int main(void)
{
	Test t;
	//一般将重载了()的类对象称之为函数对象
	t();  //t.operator()();


	return 0;
}
