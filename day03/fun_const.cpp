#include <iostream>
#include <string>
using namespace std;
class Test
{
public:
	Test(int i): m_i(i)
	{
		cout << "Test(int)" << endl;
	}
	static void test()
	{
		cout << "test()" << endl;
	}
	void show()
	{
		cout << "m_i = " << m_i << endl;
	}

	//const成员函数
	//不能修改普通的成员变量
	//不能调用普通的成员函数
	//this指针为const 类型
	//void fun(const Test *this)
	void fun() const
	{
		cout << m_i << endl;
		//m_i = 999; //error
		//this->m_i = 999;
		//fun3();//error  //fun3(this);
//const成员函数可以访问和修改静态的成员变量
		//可以调用静态的成员函数
		cout << m_a << endl;
		m_a = 19998;
		test();
	}
	//void fun3(Test *this)
	void fun3()
	{}
	//返回值类型为const 
	const string & fun2()
	{}


private:
	int m_i;
	static int m_a;
};
int Test::m_a = 90;

int main(void)
{
	const Test t(100);
	t.fun();  //fun(&t);

  //	t.show();//error  //show(&t);
	//const对象不能调用普通成员函数
	//可以调用静态成员函数
	t.test();
 
	return 0;
}
