#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	Student(string name="", float score = 0.0f)
	{
		m_strName = name;
		m_fScore = score;
	}

	bool operator<(const Student &stu)
	{
		return m_fScore < stu.m_fScore;
	}

	float getScore() const
	{
		return m_fScore;
	}

	friend ostream &operator<< (ostream &out, const Student &stu);
	friend ostream &operator<< (ostream &out, const Student *stu);

private:
	string m_strName;
	float m_fScore;
};

ostream &operator<< (ostream &out, const Student &stu)
{
	out << stu.m_strName << ' ' << stu.m_fScore;

	return out;
}

ostream &operator<< (ostream &out, const Student *stu)
{
	out << stu->m_strName << ' ' << stu->m_fScore;

	return out;
}

bool compare(const Student *s1, const Student *s2)
{
	return s1->getScore() < s2->getScore();
}


#endif
