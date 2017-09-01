#include <iostream>
#include <map>
#include "student.h"

using namespace std;

class Compare
{
public:
	bool operator()(Student *s1, Student *s2)
	{
		return s1->getScore() > s2->getScore();
	}
};

//指定排序中两个数据的比较方式
typedef map<Student *, int, Compare> STU_MAP;
typedef pair<Student *, int> STU_PAIR;


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
	stu_map.insert(STU_PAIR(new Student(1009, "zhangsan", 89), 1009));
	stu_map.insert(STU_PAIR(new Student(1002, "lisi", 79), 1002));
	stu_map.insert(STU_PAIR(new Student(1006, "wangwu", 98), 1006));
	stu_map.insert(STU_PAIR(new Student(1001, "zhaoliu", 86), 1001));
	stu_map.insert(STU_PAIR(new Student(1004, "xiaoqi", 93), 1004));
	display(stu_map);

	return 0;
}
