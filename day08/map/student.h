#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	Student(string name = "NewStu", float score = 0.0f)
	{
		m_strName = name;
		m_fScore = score;
		m_iId = m_iBaseId++;
	}

#if 0
	bool operator<(const Student &other) const
	{
		return m_fScore < other.m_fScore;
	}
#endif
	int getId() const 
	{
		return m_iId;
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
				               , const Student &stu);
private:
	static int m_iBaseId;
	int m_iId;
	string m_strName;
	float m_fScore;
};

int Student::m_iBaseId = 1000;
	
ostream &operator<<(ostream &out, const Student &stu)
{
	out << "学号:" << stu.m_iId 
	    << " 名字:" << stu.m_strName
	    << " 成绩:" << stu.m_fScore;
}

ostream &operator<<(ostream &out, const Student *stu)
{
	out << "学号:" << stu->getId() 
	    << " 名字:" << stu->getName()
	    << " 成绩:" << stu->getScore();
}

#endif
