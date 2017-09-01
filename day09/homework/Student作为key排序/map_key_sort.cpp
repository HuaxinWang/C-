#include <iostream>
#include <map>
#include "student.h"

using namespace std;

typedef map<Student, int> STU_MAP;
typedef pair<Student, int> STU_PAIR;


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
	stu_map.insert(STU_PAIR(Student(1009, "zhangsan", 89), 1009));
	stu_map.insert(STU_PAIR(Student(1002, "lisi", 79), 1002));
	stu_map.insert(STU_PAIR(Student(1006, "wangwu", 98), 1006));
	stu_map.insert(STU_PAIR(Student(1001, "zhaoliu", 86), 1001));
	stu_map.insert(STU_PAIR(Student(1004, "xiaoqi", 93), 1004));
	display(stu_map);

	return 0;
}
