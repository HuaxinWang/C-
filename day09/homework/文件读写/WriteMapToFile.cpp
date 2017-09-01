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
	stu_map.insert(STU_PAIR(1009, new Student(1009, "zhangsan", 89)));
	stu_map.insert(STU_PAIR(1002, new Student(1002, "lisi", 79)));
	stu_map.insert(STU_PAIR(1006, new Student(1006, "wangwu", 98)));
	stu_map.insert(STU_PAIR(1001, new Student(1001, "zhaoliu", 86)));
	stu_map.insert(STU_PAIR(1004, new Student(1004, "xiaoqi", 93)));
	display(stu_map);

	ofstream file("stu.info");
	STU_MAP::iterator iter = stu_map.begin();
	for (; iter != stu_map.end(); iter++)
	{
		file << iter->second << endl;
	}
	file.close();


	return 0;
}
