#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student
{
public:
	Student(string name = "NewStu"
			, float score = 0.0f)
	{
		m_strName = name;
		m_fScore = score;
	}

	const string &getName()
	{
		return m_strName;
	}
	float getScore()
	{
		return m_fScore;
	}
private:
	string m_strName;
	float m_fScore;
};

int main(void)
{
	ofstream file;
	file.open("./stu.info");
	if (file.is_open())
	{
		cout << "open file ok\n";
		Student stu("张三", 89);
		file << stu.getName() 
			 << ' ' << stu.getScore() << endl;
	}
	else
	{
		cout << "open file failed\n";
	}
	file.close();

	return 0;
}
