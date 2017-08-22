#include <iostream>
#include <string>
using namespace std;

//被虚继承的基类最终由最派生类继承
//并由最派生类来初始化基类的数据
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
//虚继承
class B: virtual public A
{
public:
	B(int b = 0):m_b(b), A(218)
	{
		cout << "B(int)\n";
	}
	int m_b;
	void data()
	{
		cout << m_b << endl;
	}
};
//虚继承
class C: virtual public A
{
public:
	C(int c = 0):m_c(c), A(666)
	{
		cout << "C(int)\n";
	}
	int m_c;
	void data()
	{
		cout << m_c << endl;
	}
};

//1,先调用被虚继承的基类
//2,然后按照继承的先后顺序
//调用普通继承的基类的构造函数
//3,若存在子对象，则接着构造子对象
//4,最后执行本身的构造函数体
class D: public B, public C
{
public:
	D(int d = 0): C(3), B(2), A(888), m_d(d)
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
	cout << "D size=" << sizeof(D) << endl;
	D d(4);
	d.A::data();
	//d.A::data();
	//d.B::(A::data());
	//d.B::data();
	//d.C::data();
	//d.data();
	cout << "C size=" << sizeof(C) << endl;
	C c(89);
	c.A::data();

	cout << "B size=" << sizeof(B) << endl;
	B b(21);
	b.A::data();

	return 0;
}
