#include <iostream>  //#include <stdio.h>
#include <string>
using namespace std;

int main(void)
{
	//char a[5] = {'h', 'e', 'l', 'l', '0'};
	//char a1[] = "hello";
	string str = "hello World";
	cout << "--- " << str << " ---\n";
	string str2 = str;  //strcpy
	cout << "str2 = " << str2 << endl;

	string str3 = str2 + " 欢迎大家";  //strcat
	cout << "str3 = " << str3 << endl;

	//字符串拼接时，最开始的两个不能同时是常量
	//string str4 = "123" + "3456"; //error
	string str4 = str + "aas" + "sas";
	//string str4 = "123" + str + "aas" + "sas";

	//strcmp
	if (str > str2)
	{}
	if (str >= str2){}
	if (str < str2){}
	if (str <= str2) {}
	if (str != str2){}


	cout << "Hello World\n";	

	return 0;
}
