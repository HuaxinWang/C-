#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	Student(string name="", float score=0.0f)
	{
		m_strName = name;
		m_fScore = score;
		m_iId = m_iBaseId++;
	}


	bool operator<(const Student &other) const
	{
		return m_fScore < other.m_fScore;
	}

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

	void setName(const string &name)
	{
		m_strName = name;
	}
	void setScore(float score)
	{
		m_fScore = score;
	}

private:
	static int m_iBaseId;
	int m_iId;
	string m_strName;
	float m_fScore;
};

int Student::m_iBaseId = 1000;

//ostream  --> cout
//istream  --> cin
//iostream --> cout cin

ostream &operator << (ostream &out, const Student &stu)
{
	out << "学号:" << stu.getId() 
		 << " 名字:" << stu.getName()
		 << " 成绩:" << stu.getScore();
	return out;
}

istream &operator >> (istream &in, Student &stu)
{
	string strName = "";
	float fScore = 0.0f;
	cout << "请输入名字\n";
	in >> strName;
	cout << "请输入分数\n";
	in >> fScore;
	stu.setName(strName);
	stu.setScore(fScore);

	return in;
}

void bubble(Student* (&stu)[3])
{
	Student *tmp = NULL;
	int i = 0;
	int j = 0;
	for (; i < 3-1; i++)
	{
		for (j = 0; j < 3-1-i; j++)
		{
			if (*stu[j] < *stu[j+1])
			{
				tmp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = tmp;
			}
		}
	}
}

void show(Student * (&stu)[3])
{
	for (int i = 0 ; i < 3; i++)
	{
		cout << *stu[i] << endl;
	}
}
//cout << a << 23 << "hello" << endl;
int main(void)
{
	Student *pStu[3] = {NULL};
	for (int i = 0; i < 3; i++)
	{
		pStu[i] = new Student;
		cin >> *pStu[i];
	}
//	Student stu[3];

	bubble(pStu);

	show(pStu);

	return 0;
}
