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

bool compare(const int &a, const int &b)
{
	return a>b;
}

bool comByScore(const Student *s1, const Student *s2)
{
	return s1->getScore() < s2->getScore();
}

template<typename T>
void display(const vector<T> &vec)
{
	typename vector<T>::const_iterator iter;
	iter = vec.begin();
	for (; iter != vec.end(); iter++)
	{
		cout << *iter << endl;
	}
}

int main(void)
{
	vector<Student *> stu_vec;
	stu_vec.push_back(new Student("aa", 90));
	stu_vec.push_back(new Student("bb", 78));
	stu_vec.push_back(new Student("cc", 99));
	stu_vec.push_back(new Student("dd", 63));
	stu_vec.push_back(new Student("ee", 76));

	sort(stu_vec.begin(), stu_vec.end(), comByScore);

	display<Student *>(stu_vec);

#if 0
	vector<int> int_vec;
	int_vec.push_back(90);
	int_vec.push_back(78);
	int_vec.push_back(99);
	int_vec.push_back(63);
	int_vec.push_back(76);

	//sort(int_vec.begin(), int_vec.end());
	sort(int_vec.begin(), int_vec.end(), compare);

	display<int>(int_vec);
#endif

	return 0;
}







