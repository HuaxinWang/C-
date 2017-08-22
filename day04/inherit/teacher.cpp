#include <iostream>
using namespace std;

class People
{
public:
	People(string name="newPeople"
		   , string born = "1988-11-11"
		   , string addr = "china"
		   , string sex = "male")
	{
		m_strName = name;
		m_strBorn = born;
		m_strAddr = addr;
		m_strSex = sex;
		cout << "People(args)...\n";
	}

	void info()
	{
		cout << m_strName << ' ' << m_strSex
			 << ' ' << m_strBorn << ' '
			 << m_strAddr << endl;
	}
private:
	string m_strName;
	string m_strBorn;
	string m_strAddr;
	string m_strSex;
};

class Teacher: public People
{
public:
	Teacher()
	{
		cout << "Teacher()\n";
	}
	Teacher(string name, string born
		    , string addr, string sex
		    , string id, string course
			, string level, float salary)
		: People(name, born, addr, sex)
	{
		m_strId = id;
		m_strCourse = course;
		m_strLevel = level;
		m_fSalary = salary;
		cout << "Teacher(args)\n";
	}

	void info()
	{
		People::info();
		cout << m_strId << ' ' << m_strCourse
			 << ' ' << m_strLevel << ' '
			 << m_fSalary << endl;
	}

private:
	string m_strId;
	string m_strCourse;
	string m_strLevel;
	float m_fSalary;
};

int main(void)
{
//	People p;
//	p.info();
	Teacher tec("孔子", "公元...", "中国", "male"
				, "888888", "语文", "金牌教授"
				, 999999);
	tec.info();

	return 0;
}
