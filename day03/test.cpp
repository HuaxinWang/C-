#include <iostream>
using namespace std;

class Test
{
public:
	Test(int a)
	{
		//cout << a << " Test(int)\n";
		cout << " Test(int)\n";
	}
	~Test()
	{
		cout << "~test() \n";
	}
};

//类的成员变量的初始化顺序和申明的顺序保持一致
//与在初始化列表中的顺序无关
class A
{
public:
	A(int i): m_b(i), m_a(m_b), m_t(m_b)
	{
		cout << "A(int)\n";
	}
	~A()
	{
		cout << "~A()" << endl;
	}
	int m_a;
	int m_b;
	Test m_t;
};

int main(void)
{
	A a(10);
	//cout << a.m_a << ' ' << a.m_b << endl;
	cout << sizeof(Test) << endl;
	cout << sizeof(a) << endl;
	cout << sizeof(A) << endl;

	A *p = NULL;
	cout << sizeof(p) << endl;
	cout << sizeof(*p) << endl;

	double *q = NULL;
	cout << sizeof(q) << endl;
	cout << sizeof(*q) << endl;

	cout << sizeof(3) << endl;
	cout << sizeof(300) << endl;
	cout << sizeof(300000) << endl;


	return 0;
}
