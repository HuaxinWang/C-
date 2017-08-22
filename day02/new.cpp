#include <iostream>

using namespace std;
#if 0
void fun(int a[32]) -->void fun(int *a)
void fun(int a[16][32]) -->void fun(int (*a)[32])
void fun(int a[2][3][4]) 
		-->void fun(int (*a)[3][4])
#endif

int main(void)
{
	//申请空间会将空间置为0
	int *p = new int[20];
	
	for (int i = 0; i < 20; i++)
	{
		cout << p[i] << ' ';
		p[i] = i+10;
	}	
	for (int i = 0; i < 20; i++)
	{
		cout << p[i] << ' ';
	}
	cout << endl;
	delete []p;

	char *p2 = new char[64];
	for (int i = 0; i < 64; i++)
	{
		cout << (int)p2[i] << ' ';
	}
	cout << endl;
//	cin >> p2;
//	cout << p2 << endl;
	delete []p2;

	//只能存放一个整形数据
	int *p3 = new int;
	delete p3;
	//申请空间之后用90初始化
	int *p4 = new int(90); //int a(90)=>int a=90;
	cout << *p4 << endl;
	delete p4;

	int *p5 = new int[1];
	delete []p5;
	p5 = NULL;	

	//int *p6 = new int[4](90);//error
	//int *p6 = new int[4](90, 90, 89, 8);//error

	int *p6 = new int[2];  
	char (*po)[4] = new char[2][4];
	int (*p7)[3] = new int[2][3];
	int (*p8)[3][4] = new int[2][3][4];
	delete []p8;

	return 0;
}
