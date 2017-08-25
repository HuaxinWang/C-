#include <iostream>
#include <string>
using namespace std;

class Teacher
{
public:
	Teacher(string name
			, string level = "讲师"
			, float salary = 0.0f
			, int work = 0
			, float subsidy = 0.0f)
	{
		m_strName = name;
		m_strLevel = level;
		m_fSalary = salary;
		m_iWork = work;
		m_fSubsidy = subsidy;		
	}
	void info()
	{
		cout << "名字:" << m_strName << " 职称:" << m_strLevel 
			 << " 基本工资:" << m_fSalary 
			 << " 课时量:" << m_iWork
			 << " 课时补贴:" << m_fSubsidy
			 << " 实发工资:" << m_fSalary+m_iWork*m_fSubsidy << endl;
	}
private:
	string m_strName;
	string m_strLevel;
	float m_fSalary;
	int m_iWork;
	float m_fSubsidy;
};

class Docent: public Teacher
{
public:
	Docent(string name, int work=0)
		: Teacher(name, "讲师", 2000, work, 20)
	{}
};
class Professor: public Teacher
{
public:
	Professor(string name, int work=0)
		: Teacher(name, "教授", 5000, work, 50)
	{}
};
class AssociateProfessor: public Teacher
{
public:
	AssociateProfessor(string name, int work=0)
		: Teacher(name, "副教授", 3000, work, 30)
	{}
};

void info(Teacher *tec)
{
	tec->info();
}

int main(void)
{
	Docent docent("张三", 10);
	info(&docent); //docent.info();

	Professor pro("李四", 10);
	info(&pro);//pro.info();

	AssociateProfessor ap("王五", 10);
	info(&ap);//ap.info();

	return 0;
}













