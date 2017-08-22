#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	A(int a = 0):m_a(a){cout << "A(int)\n";}
	int m_a;
	void data()
	{
		cout << m_a << endl;
	}
};
class B
{
public:
	B(int b = 0):m_b(b){cout << "B(int)\n";}
	int m_b;
	void data()
	{
		cout << m_b << endl;
	}
};
class C
{
public:
	C(int c = 0):m_c(c){cout << "C(int)\n";}
	int m_c;
	void data()
	{
		cout << m_c << endl;
	}
};

//基类构造函数的执行顺序
//和继承列表中的先后顺序保持一致
//与初始化列表中的顺序无关
//class D: public A, protected B, public C
class D: public A, public B, public C
{
public:
	D(int d = 0): C(3), B(2), A(1), m_d(d)
	{
		cout << "D(int)\n";
	}
	int m_d;
	void data()
	{
		cout << m_d << endl;
	}
};

int main(void)
{
	cout << sizeof(D) << endl;
	D d(4);
	//d.data();
	d.A::data();
	d.B::data();
	d.C::data();

	return 0;
}
