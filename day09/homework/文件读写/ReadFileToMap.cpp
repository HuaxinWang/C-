#include <iostream>
#include <map>
#include "student.h"
#include <fstream>

using namespace std;

typedef map<int, Student *> STU_MAP;
typedef pair<int, Student *> STU_PAIR;

void display(const STU_MAP &stu_map)
{
	STU_MAP::const_iterator iter = stu_map.begin();
	for (; iter != stu_map.end(); iter++)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}
}

int main(void)
{
	STU_MAP stu_map;

	ifstream file("stu.info");
	Student *stu = NULL;
	while (1)
	{
		stu = new Student;
		file >> stu;
		if (file.eof())
		{
			delete stu;
			break;
		}
		stu_map.insert(STU_PAIR(stu->getId(), stu));
	}
	file.close();

	display(stu_map);



	return 0;
}
