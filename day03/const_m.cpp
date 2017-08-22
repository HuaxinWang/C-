#include <iostream>
#include <string>
using namespace std;

class Test
{
public:
	//1,给成员变量申请空间
	//2,使用初始化列表中的数据初始化成员变量
	//3,执行函数体
	Test(float f, float g) 
		 : m_b(89), m_i(88), m_f(f), m_lf(g)
	{}
	int m_i;
	float m_f;
	double m_lf;
	//成员变量为引用时必须在初始化列表中初始化
	//const 成员变量属于类对象
	//const 成员变量只能在初始化列表中初始化
	const int m_b;  //const 成员变量
};
int main(void)
{
	cout << sizeof(Test) << endl;
	Test t(3.4f, 4.5f);
	cout << t.m_b << endl;
#if 0
	const int a = 90;
	*(int *)&a = 999;
	int *p = (int *)&a;
	*p = 999;
	cout << a << endl;
	cout << *p << endl;

	cout << (void *)&a << endl;
   	cout << (void *)p << endl;	
	
	cout << a << endl;
	cout << *p << endl;
#endif
	return 0;
}
