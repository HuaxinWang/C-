#include "list.h"
#include "student.h"


int main(void)
{
	List<int> int_list;
	int_list.insert(67);
	int_list.insert(87);
	int_list.insert(72);
	int_list.insert(79);
	int_list.sort();

	List<int>::iterator iter = int_list.begin();
	for (; iter != int_list.end(); iter++)
	{
		cout << *iter << endl; 
	}

	List<Student *> stu_list;
	stu_list.insert(new Student("aa", 79));
	stu_list.insert(new Student("bb", 89));
	stu_list.insert(new Student("cc", 85));
	stu_list.insert(new Student("dd", 81));
	stu_list.sort(compare);
	List<Student *>::iterator iter2 = stu_list.begin();
	for (; iter2 != stu_list.end(); iter2++)
	{
		cout << *iter2 << endl; 
	}



	return 0;
}
