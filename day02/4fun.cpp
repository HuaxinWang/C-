#include <iostream>

using namespace std;

struct Student
{
	int iId;
	string strName;
	float fScore;
};

//函数模板
template<typename T>
void myswap(T &a, T &b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

//函数模板特例化
void myswap(float &a, float &b)
{
	cout << "@@@@@@@@@@@@@\n";
}

int main(void)
{
	int a = 90, b = 89;
	cout << "a=" << a << "  b=" << b << endl;
	myswap(a, b);
#if 0
	//根据函数模板生成的函数称之为模板函数
	void myswap(int &a, int &b)
	{
		int tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
#endif
	cout << "a=" << a << "  b=" << b << endl;

	Student s1 = {1001, "aaa", 89};
	Student s2 = {1002, "bbb", 79};
	cout << "id:" << s1.iId 
		 << " name:" << s1.strName
		 << " score:" << s1.fScore << endl;
	cout << "id:" << s2.iId 
		 << " name:" << s2.strName
		 << " score:" << s2.fScore << endl;
	myswap(s1, s2);
#if 0
	void myswap(Student & a, Student & b)
	{
		Student tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
#endif
	cout << "id:" << s1.iId 
		 << " name:" << s1.strName
		 << " score:" << s1.fScore << endl;
	cout << "id:" << s2.iId 
		 << " name:" << s2.strName
		 << " score:" << s2.fScore << endl;

	float fa, fb;
	myswap(fa, fb);

	return 0;
}
