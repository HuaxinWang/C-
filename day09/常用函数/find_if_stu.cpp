#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Student
{
public:
	Student(string name="", float score=0.0f)
	{
		m_strName = name;
		m_fScore = score;
	}
	float getScore() const 
	{
		return m_fScore;
	}

	const string &getName() const
	{
		return m_strName;
	}

	void info()
	{
		cout << "name:" << m_strName 
			 << " score:" << m_fScore << endl;
	}

	static string m_strTmpName;
private:
	string m_strName;
	float m_fScore;
};

string Student::m_strTmpName = "Student";

bool predicate(const Student *stu)
{
	return stu->getName() == Student::m_strTmpName;
}

int main(void)
{
	vector<Student *> vec;
	vec.push_back(new Student("张三", 89));
	vec.push_back(new Student("李四", 23));
	vec.push_back(new Student("王五", 90));
	vec.push_back(new Student("赵六", 32));
	vec.push_back(new Student("小七", 16));
	vec.push_back(new Student("老八", 66));
	vec.push_back(new Student("久久", 58));

	cout << "请输入要查找的学生的名字:";
	cin >> Student::m_strTmpName;

	vector<Student *>::iterator iter;
	iter = find_if(vec.begin(), vec.end(), predicate);
	if (iter != vec.end())
	{
		(*iter)->info();
	}
	else
	{
		cout << "不存在" << Student::m_strTmpName
			 << "这个学生\n";
	}

	return 0;
}
