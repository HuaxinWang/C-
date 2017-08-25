#include <iostream>

using namespace std;

class A
{
public:
	int m_a;
	//虚函数
	//若类中存在虚函数
	//则系统会自动生成一个虚函数表
	//该表中存放该类的虚函数的入口地址
	//并且类中会自动添加一个指针
	//该指针指向虚函数表
	//称该指针为虚函数表指针
	virtual void show()
	{
		cout << "this is A::show()\n";
	}
};

class B: public A
{
public:
	int m_b;
	//若派生类中含有和
	//基类虚函数函数A::show原型相同的函数B::show
	//则该函数B::show默认为虚函数

	//会使用派生类中虚函数B::show地址
	//覆盖掉虚函数表中
	//相对应的基类虚函数A::show的地址
	//将该种情况称之为函数覆盖

	//并且会将派生类中新增的虚函数地址
	//添加到虚函数表中
	void show()
	{
		cout << "this is B::show()\n";
	}
	virtual void test()
	{
		cout << "this is B::test()\n";
	}
};

void fun(A *p)
{
	p->show();
}

int main(void)
{
	fun(new A);
	fun(new B);
		
		
	//cout << "A size = " << sizeof(A) << endl;

   	//通过基类的指针来访问函数时
	//若该函数为虚函数
	//则到虚函数表中查找其入口地址
	//然后执行	
	//A *p = new B;
	//p->show();
	//p->test();

	return 0;
}
