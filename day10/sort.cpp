#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include <list>

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

bool compare(const int &a, const int &b)
{
	return a>b;
}

bool comByScore(const Student *s1, const Student *s2)
{
	return s1->getScore() < s2->getScore();
}

int main(void)
{
	Student *stu[3] = {NULL};
	string strName;
	float fScore;
	for (int i = 0; i < 3; i++)
	{
		cout << "请输入名字:\n";
		cin >> strName;
		cout << "请输入分数:\n";
		cin >> fScore;
		stu[i] = new Student(strName, fScore);
	}

	sort(stu, stu+3, comByScore);

	for (int i = 0; i < 3; i++)
	{
		cout << stu[i] << endl;
	}

#if 0
	Student stu[3];
	stu[0].setInfo("aa", 89);
	stu[1].setInfo("bb", 69);
	stu[2].setInfo("cc", 79);

	sort(stu, stu+3);

	for (int i = 0; i < 3; i++)
	{
		cout << stu[i] << endl;
	}
#endif

#if 0
	int a[7] = {12, 78, 53, 3, 14, 66, 44};
		
	//sort(a, a+7);  //[)
	sort(a, a+7, compare);  //[)
	for (int i = 0; i < 7; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
#endif
	return 0;
}







