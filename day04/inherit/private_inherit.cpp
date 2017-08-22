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

class Student: private People
{
public:
	void access()
	{
		cout << m_strFace << endl;
		cout << m_iAge << endl;
		cout << m_strName << endl;
	}
private:
	string m_strSchool;
	string m_strClass;
	float m_fScore;
};

int main(void)
{
	Student p;
	//cout << p.m_strFace << endl;
	//cout << p.m_iAge << endl;
	//cout << p.m_strName << endl;
	p.access();

	return 0;
}
