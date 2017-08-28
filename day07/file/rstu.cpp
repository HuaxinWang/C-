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

	friend ifstream& operator>>(ifstream &file
					            , Student &stu);
	friend ostream& operator<<(ostream &out
					            , const Student &stu);

private:
	string m_strName;
	float m_fScore;
};

ifstream& operator>>(ifstream &file, Student &stu)
{
	file >> stu.m_strName >> stu.m_fScore;
	return file;
}
ostream& operator<<(ostream &out, const Student &stu)
{
	out << stu.m_strName << ' ' << stu.m_fScore;
	return out;
}

int main(void)
{
	ifstream file;
	file.open("./stu.info");
	if (file.is_open())
	{
		cout << "open file ok\n";
		Student stu;
		file >> stu;
		cout << stu << endl;	
	}
	else
	{
		cout << "open file failed\n";
	}
	file.close();

	return 0;
}
