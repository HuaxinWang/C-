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


//基类数据的初始化必须
//在派生类的构造函数的初始化列表中
//调用基类的构造函数进行初始化

//若没有显式的调用基类的构造函数
//则默认调用基类的无参构造函数
class Student: private People
{
public:
	Student(string name, string born
			, string addr, string sex
		    , string face, string school
			, string sclass, float score)
		: People(name, born, addr, sex, face)
	{
		m_strSchool = school;
		m_strClass = sclass;
		m_fScore = score;

		cout << "Student(args)\n";
	}

	Student()
	{
		cout << "Student()\n";
	}

	//若派生类中存在
	//和基类函数原型相同的普通成员函数
	//则在派生类中调用函数时
	//会将基类的函数隐藏掉，
	//优先调用派生类的函数
	void info()
	{
		People::info();
		cout << m_strSchool << ' ' << m_strClass
			 << ' ' << m_fScore << endl;
	}
private:
	string m_strSchool;
	string m_strClass;
	float m_fScore;
};

int main(void)
{
	Student s("张三", "1988-11-11", "上海"
			  , "male", "cool", "复旦附属小学"
			  , "三年级", 99);
	s.info();

	return 0;
}
