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
	int num = 90;
	int *p = &num;
	
	//底层生成一个指针并将num的地址赋给该指针
	int &ref = num;	
	ref = 998;//通过底层的指针找到num,将998给num
	cout << num << endl;
	cout << ref << endl;
	cout << sizeof(ref) << endl;

	int tmp = 1998;
	ref = tmp;//将tmp的值给了ref代表的变量
	//并不是重新作为temp的别名

	cout << "num=" << num << " tmp=" << tmp
	     << " &num=" << (void*)&num
	     << " &tmp=" << (void*)&tmp
	     << " &ref=" << (void*)&ref << endl;	 


	return 0;
}
