#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void)
{//cout --> ostream

	ofstream file("./stu.info");

	//ofstream file;
	//默认以写,截断的方式打开文件
	//若文件不存在则创建文件
	//file.open("./stu.info");
	//判断文件是否打开
	//若文件已经打开了，返回true
	//若文件没有打开，返回false
	if (file.is_open())
	{
		cout << "open file ok\n";
		file << "Hello World" << " ^_^ \n";
		file << 123456 << ' ' << 3.14 << endl;
	}
	else
	{
		cout << "open file failed\n";
	}
	//关闭文件	
	file.close();

	return 0;
}
