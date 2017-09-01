#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

class Student
{
public:
	Student(string name="", float score=0.0f)
	{
		m_strName = name;
		m_fScore = score;
	}
	void setInfo(string name="", float score=0.0f)
	{
		m_strName = name;
		m_fScore = score;
	}

	const string &getName() const
	{
		return m_strName;
	}
	float getScore() const 
	{
		return m_fScore;
	}

	bool operator<(const Student &stu) const
	{
		return m_fScore < stu.m_fScore;
	}

private:
	string m_strName;
	float m_fScore;
};

ostream &operator<<(ostream &out, const Student &stu)
{
	out << stu.getName() << ' ' << stu.getScore();
	return out;
}
ostream &operator<<(ostream &out, const Student *stu)
{
	out << stu->getName() << ' ' << stu->getScore();
	return out;
}

int main(void)
{
	int a = 90;
	int b = 78;
	cout << "a=" << a << " b=" << b << endl;
	swap(a, b);
	cout << "a=" << a << " b=" << b << endl;

	Student s1("aa", 89);
	Student s2("bb", 79);
	cout << "s1=" << s1 << " s2=" << s2 << endl;
	swap(s1, s2);
	cout << "s1=" << s1 << " s2=" << s2 << endl;


	return 0;
}







