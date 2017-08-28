#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void)
{//cin --> istream

	//默认以读的方式打开文件
	//若文件不存在则不会自动创建文件
	ifstream file("./rstu.info");

	if (file.is_open())
	{
		cout << "open file ok\n";
		string strName;
		float fScore;
		file >> strName >> fScore;
		cout << strName << ' ' << fScore << endl;
	}
	else
	{
		cout << "open file failed\n";
	}
	//关闭文件	
	file.close();

	return 0;
}
