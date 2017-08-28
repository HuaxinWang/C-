#include <iostream>
#include <list>
#include "student.h"


using namespace std;

typedef list<Student *> STULIST;

void display(const STULIST &l)
{
	STULIST::const_iterator iter = l.begin();
	for (; iter != l.end(); iter++)
	{
		cout << *iter << '\n';
	}
	cout << endl;

}

bool compare(const Student* s1, const Student* s2)
{
	return  s1->getScore() > s2->getScore();
}

int main(void)
{
	STULIST stu_list;
	stu_list.push_back(new Student("aa", 89));
	stu_list.push_back(new Student("bb", 73));
	stu_list.push_back(new Student("cc", 99));
	stu_list.push_back(new Student("dd", 86));
	stu_list.push_back(new Student("ee", 95));
//	stu_list.sort();
	stu_list.sort(compare);
	display(stu_list);

	return 0;
}
