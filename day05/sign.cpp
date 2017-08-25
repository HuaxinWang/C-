#include <iostream>

using namespace std;

class A
{
public:
	int m_a;
	void show()
	{
		cout << "this is A::show()\n";
	}
};

class B: public A
{
public:
	int m_b;
	void show()
	{
		cout << "this is B::show()\n";
	}
	void test()
	{}
};

int main(void)
{
	//B *p = new A;  //error
#if 0
	B *p = (B *)new A;
	p->show();
	p->m_a = 90;
	cout << p->m_a << endl;
#endif
#if 0
	//通过基类指针来操作派生类对象
	//只能访问基类有的成员
	//派生类中新增的成员，基类指针无法访问		
	//即指针的访问范围受类型限制	
	A *p = new B;
	p->show();
	p->m_a = 90;
	cout << p->m_a << endl;
	//p->m_b = 89;  //error
	//p->test();    //error
#endif
#if 0
	A a;
	a.m_a = 11;
	cout << a.m_a << endl;
	a.show();

	B b;
	b.m_a = 22;
	b.m_b = 33;
	b.show();

	//在默认情况下，派生类对象可以赋给基类对象
	a = b;
	//cout << a.m_a << endl;
	a.show();

	//在默认情况下，基类对象不可以赋给派生类对象
	//b = a;//error
#endif
	return 0;
}
