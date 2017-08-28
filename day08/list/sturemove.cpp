#include <iostream>
#include <list>
#include "student.h"

using namespace std;

typedef list<Student *> LIST;

void display(const LIST &l)
{
	LIST::const_iterator iter = l.begin();
	for (; iter != l.end(); iter++)
	{
		cout << *iter << '\n';
	}
	cout << endl;

}

string g_strName = "";

bool delByName(const Student *stu)
{
	return g_strName == stu->getName();
}

bool delByScore(const Student *stu)
{
	return stu->getScore() < 60;
}

int main(void)
{
	LIST stu_list;
	stu_list.push_back(new Student("aa", 9));
	stu_list.push_back(new Student("bb", 19));
	stu_list.push_back(new Student("cc", 89));
	stu_list.push_back(new Student("dd", 89));
	stu_list.push_back(new Student("ee", 29));

	display(stu_list);
	cout << "------------------------\n";

	//cout << "请输入要删除学生的名字:\n";
	//cin >> g_strName;

	//stu_list.remove_if(delByName);
	stu_list.remove_if(delByScore);
	display(stu_list);

	cout << "Hello World\n";

	return 0;
}
