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
private:
	string m_strName;
	float m_fScore;
};

#endif
