#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

class Student
{
public:
	Student(const char* name = "NewStu"
			, float score = 0.0f)
	{
		strcpy(m_caName, name);
		m_fScore = score;
	}

	void info()
	{
		cout << m_caName << ' ' << m_fScore << endl;
	}


private:
	char m_caName[32];
	float m_fScore;
};

int main(void)
{
	ifstream file;
	file.open("./stu.info");
	if (file.is_open())
	{
		cout << "open file ok\n";
		Student stu;
		file.read((char *)&stu, sizeof(Student));
		stu.info();
	}
	else
	{
		cout << "open file failed\n";
	}
	file.close();

	return 0;
}
