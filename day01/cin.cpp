#include <iostream>  //#include <stdio.h>

using namespace std;

int main(void)
{
	int num = 0;
	cin >> num;
	cout << "num = " << num << endl;
	
	cout << "请输入数组数据：\n";	
	int a[3] = {0};
	cin >> a[0] >> a[1] >> a[2];
	cout << a[0] << ' ' << a[1] << ' '
		 << a[2] << endl;
	cout << "Hello World\n";	

	return 0;
}
