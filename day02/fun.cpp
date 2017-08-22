#include <iostream>

using namespace std;
//不允许定义函数不写返回值类型
//fun() //error
//{}
//定义了返回值类型但是没有写返回值
//则返回一个随机值，会造成程序混乱
int fun1()
{}

int main(void)
{
	int ret = 0;
	ret = fun1();
	cout << ret << endl;

	return 0;
}
