#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	Student(int id=0, string name="NewStu", float score=0.0f)
	{
		m_iId = id;
		m_strName = name;
		m_fScore = score;
	}

	bool operator<(const Student &stu) const
	{
		return m_fScore < stu.m_fScore;
	}

	int getId()
	{
		return m_iId;
	}

	float getScore() const
	{
		return m_fScore;
	}

	friend ostream &operator<<(ostream &out, const Student &stu);
	friend ostream &operator<<(ostream &out, const Student *stu);

	friend istream &operator>>(istream &in, Student &stu);
	friend istream &operator>>(istream &in, Student *stu);

private:
	int m_iId;
	string m_strName;
	float m_fScore;
};

ostream &operator<<(ostream &out, const Student &stu)
{
	out << stu.m_iId << '\t' << stu.m_strName << '\t' << stu.m_fScore;
	return out;
}

ostream &operator<<(ostream &out, const Student *stu)
{
	out << stu->m_iId << '\t' << stu->m_strName << '\t' << stu->m_fScore;
	return out;
}

istream &operator>>(istream &in, Student &stu)
{
	in >> stu.m_iId >> stu.m_strName >> stu.m_fScore;
	return in;
}

istream &operator>>(istream &in, Student *stu)
{
	in >> stu->m_iId >> stu->m_strName >> stu->m_fScore;
	return in;
}

#endif
