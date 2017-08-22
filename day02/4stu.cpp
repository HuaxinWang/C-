#include <iostream>
using namespace std;

class Student
{
public:
#if 1
	Student()
	{
		m_iId = 1000;
		m_strName = "student";
		m_fScore = 100;
		cout << "Student()...\n";
	}
#endif
	Student(int id, const char *name, float score)
	{
		m_iId = id;
		m_strName = name;
		m_fScore = score;
		cout << "Student(int, char*, float)...\n";
	}
	void showInfo()
	{
		cout << "id:" << m_iId 
			 << " name:" << m_strName
			 << " score:" << m_fScore << endl; 
	}

private:
	int m_iId;
	string m_strName;
	float m_fScore;
};


int main(void)
{
	Student *s = new Student;
	s->showInfo();
	
	Student *s2 = new Student(1001, "刘德华", 100);
	s2->showInfo();


	return 0;
}
