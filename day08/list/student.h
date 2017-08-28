#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	Student(string name="NewStu"
			, float score = 0.0f)
	{
		m_strName = name;
		m_fScore = score;
		cout << "Student(string,float)...\n";
	}
	Student(const Student &other)
	{
		m_strName = other.m_strName;
		m_fScore = other.m_fScore;
		cout << "Student(const Student &)...\n";
	}
	~Student()
	{
		cout << "~Student()...\n";
	}

	const string &getName() const
	{
		return m_strName;
	}

	float getScore() const
	{
		return m_fScore;
	}
	friend ostream &operator<<(ostream &out
				               , const Student *stu);

private:
	string m_strName;
	float m_fScore;
};

ostream &operator<<(ostream &out, const Student *stu)
{
	out << stu->m_strName << ' ' << stu->m_fScore;
	return out;
}

#endif
