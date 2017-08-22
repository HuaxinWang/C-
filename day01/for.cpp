#include <iostream>
using namespace std;


int main(void)
{
	//允许在for循环第一个表达式中定义循环变量
	//该循环变量只能用于该for循环
	//出了循环则无效，不能使用
	for (int i = 0; i < 10; i++)
	{
		cout << "hello" << endl;
	}

	for (int i = 0; i < 8; i++)
	{
		cout << "world" << endl;
	}
	return 0;
}
