#include <iostream>
#include <string>
#include <string.h>  //strlen
using namespace std;

class A
{};

class B
{
	A m_a;  //子对象
};

class Date
{
public:
	Date():m_iYear(0), m_iMonth(0), m_iDay(0)
	{}
	Date(int year, int month, int day)
		: m_iYear(year), m_iMonth(month)
		  , m_iDay(day)
	{}
	void showDate()
	{
		cout << m_iYear << "-" << m_iMonth
			 << "-" << m_iDay << endl;
	}
	int m_iYear;
	int m_iMonth;
	int m_iDay;
};

//子对象的初始化必须在初始化列表中
//调用其构造函数进行初始化
class Student
{
public:
	//若没有在初始化列表中显式对子对象进行初始化
	//则默认调用子对象的无参构造函数对其初始化
	Student(string name, float score)
		: m_strName(name), m_fScore(score)
	{
	}
	Student() //: m_date()//调用无参构造函数
	{
		cout << "student()" << endl;
	}
	Student(string name, float score
			, int year, int month, int day)
		: m_strName(name), m_fScore(score)
		  , m_date(year, month, day)
	{
	}
	void info()
	{
		cout << "name:" << m_strName 
			 << " score:" << m_fScore
		     /*<< " born:" << m_strBorn*/ << endl;
		m_date.showDate();
	}
private:
	string m_strName;
	float m_fScore;
	Date m_date;
};


int main(void)
{
	Student s1;//调用无参构造函数
	s1.info();
	
	Student s2("aa", 89);
	s2.info();
	
	Student s3("aa", 89, 1988, 11, 11);
	s3.info();

	return 0;
}
