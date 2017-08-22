#include <iostream>
using namespace std;

class People
{
public:
	People(string name="newPeople"
		   , string born = "1988-11-11"
		   , string addr = "china"
		   , string sex = "male"
		   , string face = "cool")
	{
		m_strName = name;
		m_strBorn = born;
		m_strAddr = addr;
		m_strSex = sex;
		m_strFace = face;
		cout << "People(args)...\n";
	}

	void info()
	{
		cout << m_strName << ' ' << m_strSex
			 << ' ' << m_strBorn << ' '
			 << m_strAddr << ' ' << m_strFace
			 << endl;
	}
	string m_strFace;
private:
	string m_strName;
	string m_strBorn;
	string m_strAddr;
	string m_strSex;
protected:
	int m_iAge;
};

//class Student: People//默认为private继承
//继承后，基类的成员成了派生类的一部分
class Student: public People
//class Student: protected People
//class Student: private People
{
public:
	void access()
	{
//		cout << m_strName << endl;
		m_iAge = 90;
		cout << m_iAge << endl;
	}
private:
	string m_strSchool;
	string m_strClass;
	float m_fScore;
};

class A
{};
//sizeof(A) = ?
class B: A
{};
//sizeof(B) = ?

int main(void)
{
//	cout << sizeof(People) << endl;
//	People p;
//	p.info();
//	cout << sizeof(Student) << endl;

	Student s;
//在public继承下，
	//派生类对象可以直接访问基类public成员
	//不能直接访问基类private成员
	//也不能通过派生类接口访问基类private成员
	cout << s.m_strFace << endl;
	s.info();
//	cout << s.m_strName << endl;
	s.access();
//	s.m_iAge = 90;

	return 0;
}
