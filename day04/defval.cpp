#include <iostream>
using namespace std;

//形参带有默认值的函数
//一般将带有默认值的形参放在参数列表最后
//实参传值给形参：从左往右依次赋值
void fun2(int a = 90, int b)
{}

void fun(const char *p = "Hello")
{
	cout << p << endl;
}

void fun()
{}

int main(void)
{
	//fun2(89);将89赋值给a,b没有实参,报错
	//fun2(34, 89);
	//fun2(20, 89);

	//fun();
	fun("world");

	return 0;
}
