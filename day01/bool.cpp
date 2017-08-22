#include <iostream>  //#include <stdio.h>
#include <string.h>

using namespace std;

int main(void)
{
	bool b = 123;//true;
	bool b2 = "abcd"; //false;
	cout << b << ' ' << b2 << endl;
	//占空间大小为一个字节
	cout << sizeof(bool) << endl;
	//不推荐该写法
	if (true == b)
	{}
	//建议用该写法
	if (b)	
	{}

	int num = 0;   //if (num) //不推荐
	if (0 == num){}

	char *p2 = NULL;  //if (p2)//不推荐
	if (NULL == p2){}

	double dl = 0;
	if (0 == dl){}   //不推荐
	if (-0.000001 <= dl && dl <= 0.000001)
	{}

	cout << "Hello World\n";	
#if 0
	char *p = (char *)&b;
	*p = 123;
	cout << (int)(*p) << endl;
#endif
	int num = 123;
	memcpy(&b, &num, 1);
	cout << b << endl;

	return 0;
}
