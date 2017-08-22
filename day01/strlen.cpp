#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	//string 是一个类似于结构体的一种数据类型
	string str = "Hello World";
	cout << sizeof(string) << ' ' << sizeof(str)
		 << endl;	
	//length()是string 的成员函数
	//用来获得实际的字符串长度
	cout << str.length() << endl;

	cout << str[0] << ' ' << str[1] << endl;

	cout << "Hello World\n";	

	return 0;
}
