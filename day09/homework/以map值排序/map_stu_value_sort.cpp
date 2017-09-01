#include <iostream>
#include <map>
#include <list>
#include "student.h"

using namespace std;


typedef map<int , Student *> STU_MAP;
typedef pair<int, Student *> STU_PAIR;


void display(const STU_MAP &stu_map)
{
	STU_MAP::const_iterator iter = stu_map.begin();
	for (; iter != stu_map.end(); iter++)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}
}

bool compare(const STU_PAIR &p1, const STU_PAIR &p2)
{
	return p1.second->getScore() > p2.second->getScore();
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

	cout << "--------------------" << endl;
	list<STU_PAIR> stu_list;
	STU_MAP::iterator iter_map = stu_map.begin();
	for (; iter_map != stu_map.end(); iter_map++)
	{
		stu_list.push_back(*iter_map);
	}

	stu_list.sort(compare);

	list<STU_PAIR>::iterator iter_list = stu_list.begin();
	for (; iter_list != stu_list.end(); iter_list++)
	{
		cout << iter_list->first << ' ' << iter_list->second << endl;
	}

	return 0;
}
