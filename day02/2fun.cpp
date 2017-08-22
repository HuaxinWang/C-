#include <iostream>

using namespace std;
#if 0
void swapint(int *a, int *b){}
void swapchar(char *a, char *b){}
void swapfloat(float *a, float *b){}
void swapdouble(double *a, double *b){}
#endif

struct Student
{
	int iId;
	char caName[32];
	float fScore;
};
//函数重载：允许定义函数时函数名相同
//但是形参必须不一样(类型不一样，或者个数不一样)
//函数重载取决于形参的不同，和返回值类型无关
//void swapii(int a, int b)
void swap(int a, int b)
{
	cout << "int, int" << endl;
}
//void swapff(float a, float b)
void swap(float a, float b)
{
	cout << "float, float" << endl;
}
void swap(Student s1, Student s2)
{
	cout << "student, Student" << endl;
}
void swap(float a, int b)
{}

int main(void)
{
	float m; int n;
	swap(m, n);

	
	int a, b;
	//swapii(a, b);
	swap(a, b);

	float c, d;
	//swapff(c,d);
	swap(c,d);
	
	Student s1, s2;
	swap(s1, s2);


	return 0;
}
