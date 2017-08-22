#include <iostream>

using namespace std;


//引用:是变量的别名，底层是通过指针来实现
//对引用的操作即是对所代表的变量的操作
//引用具有专一性，作为一个变量的别名后
//不能再次作为其他变量的别名
//引用必须初始化


//引用没有独立的存储空间
//但是底层是通过指针来进行实现的
int main(void)
{
	//存在指针的引用
	char *p = "Hello";
	char* &ref = p;
	cout << ref << endl;

	//不存在引用的引用
	int a = 90;
	int &r1 = a;
	//int& &r2 = r1; //error

	//不存在引用的数组
	int aa = 90;
	int bb = 90;
	//int &refa[2] = {aa, bb};

	//数组的引用
	int array[] = {11,22,33,44,55};
	int (*pa)[5] = &array; //数组指针
	int (&pref)[5] = array;  //数组的引用
	for (int i = 0; i < 5; i++)
	{
		cout << pref[i] << ' ';
	}
	cout << endl;

	return 0;
}
