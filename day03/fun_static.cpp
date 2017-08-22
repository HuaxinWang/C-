#include <iostream>
#include <string>
using namespace std;
//单例模式
class Test
{
public:
	Test(int i): m_i(i)
	{
		cout << "Test(int)" << endl;
	}
	//静态成员函数
	//在静态成员函数中不能直接使用普通的成员变量
	//在静态成员函数中不能直接使用普通的成员函数
	//但可以使用静态成员变量和静态成员函数
	
	//静态的成员函数可以通过类名直接访问
	static void fun()
	{
		//cout << "m_i = " << m_i << endl;//error
		//show();//error
		cout << "m_a=" << m_a << endl;
		test();
	}
	static void test()
	{
		cout << "test()" << endl;
	}
	//在每一个普通的成员函数形参列表中
	//都有一个隐藏的形参
	//该形参的类型为本类的指针类型
	//指针名字为:this
	//当对象调用该函数时，会将对象的地址
	//赋给this 指针,
	//然后通过该指针访问该对象的成员变量
	//void show(Test *this)
	//{
//		cout << "m_i = " << this->m_i << endl;
	
	//}
	void show()
	{
		cout << "m_i = " << m_i << endl;
	}
private:
	int m_i;
	static int m_a;
};
int Test::m_a = 90;

int main(void)
{
	Test t1(11);
	Test t2(22);
	Test t3(33);

	t1.fun();

	t1.show();  //show(&t1)
	t2.show();  //show(&t2)
	t3.show();  //show(&t3)

	Test::fun();

//	Test t(888);
//	t.show();
//	t.fun();
		
	return 0;
}
