#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void)
{
	fstream file;
	//默认以读写的方式打开文件,或者以读的方式打开文件
	//若文件不存在不会自动创建文件，打开失败
	file.open("test.data");
	//file.open("test.data", ios_base::in);

	//以写方式打开文件，若文件不存在则创建文件
	//file.open("test.data", ios_base::out);
	

	//istream(seekg, tellg)->ifstream
	//ostream(seekp, tellp)->ofstream

	//istream+ostream --> iostream --> fstream

	if (file.is_open())
	{
		cout << "open file ok\n";

		file << "我爱上海...\n";
		//获得读写位置
		cout << file.tellp() << endl;
		cout << file.tellg() << endl;
		
		string str = "";
		//beg, cur, end
		//将读的位置设置在文件首部
		//file.seekg(0, ios_base::beg);
		//将写的位置设置在文件首部
		file.seekp(0, ios_base::beg);
		file >> str;
		cout << str << endl;

		file.close();
	}
	else
	{
		cout << "open file failed\n";
	}

	return 0;
}
