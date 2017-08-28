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
	friend ofstream &operator<<(ofstream &file
					            , const Student &stu);

private:
	string m_strName;
	float m_fScore;
};

ofstream &operator<<(ofstream &file, const Student &stu)
{
	file << stu.m_strName << ' ' << stu.m_fScore;
	return file;
}

int main(void)
{
	ofstream file;
	file.open("./stu.info");
	if (file.is_open())
	{
		cout << "open file ok\n";
		Student stu("张三", 89);
		file << stu << endl;
	}
	else
	{
		cout << "open file failed\n";
	}
	file.close();

	return 0;
}
