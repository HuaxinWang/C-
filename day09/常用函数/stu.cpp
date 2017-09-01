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
private:
	string m_strName;
	float m_fScore;
};

bool predicate(const Student *stu)
{
	return stu->getScore() < 60;
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

	cout << count_if(vec.begin(), vec.end(), predicate) << endl;;


	return 0;
}
