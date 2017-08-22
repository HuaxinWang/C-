#include <iostream>
#include <string>
#include <string.h>  //strlen
using namespace std;

//静态成员变量不属于任何对象
//在对象生成之前就已经存在
//是所有对象共享
class Test
{
public:
	int m_i;
	float m_f;
	double m_lf;
	int m_a;
	static int m_si; //静态成员变量
};
//在类外定义并初始化静态成员变量
int Test::m_si = 0;

class A
{};  //sizeof(A) = ?

int main(void)
{
	cout << sizeof(Test) << endl;
	//若静态成员变量是public
	//则可以通过类名直接访问
	Test::m_si = 890;
	cout << Test::m_si << endl;
	cout << (void*)&(Test::m_si) << endl;

	Test t;
	t.m_si = 90;
	cout << (void*)&(t.m_si) << endl;

	Test t2;
	cout << t2.m_si << endl;
	cout << (void*)&(t2.m_si) << endl;

	return 0;
}
