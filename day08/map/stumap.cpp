#include <iostream>
#include <map>
#include "student.h"

using namespace std;


typedef map<int, Student *> STU_MAP;
typedef pair<int, Student *> PAIR;

int main(void)
{
	STU_MAP stu_map;
	Student *stu = new Student("张三", 89);
	stu_map.insert(PAIR(stu->getId(), stu));
	
	stu = new Student("李四", 79);
	stu_map.insert(PAIR(stu->getId(), stu));
	
	stu = new Student("王五", 84);
	stu_map.insert(PAIR(stu->getId(), stu));
	
	stu = new Student("赵六", 69);
	stu_map.insert(PAIR(stu->getId(), stu));

	STU_MAP::iterator iter = stu_map.begin();
	for (; iter != stu_map.end(); iter++)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}


	return 0;
}
