#include <iostream>

using namespace std;

struct Student
{
	int iId;
	char caName[32];  //c:char  a:array
	float fScore;
};

void display1(Student stu)
{
	cout << "id:" << stu.iId 
		 << " name:" << stu.caName
		 << " score:" << stu.fScore << endl;
}

void display2(const Student *stu)
{
	cout << "id:" << stu->iId 
		 << " name:" << stu->caName
		 << " score:" << stu->fScore << endl;
}

void display3(const Student &stu)
{
	cout << "id:" << stu.iId 
		 << " name:" << stu.caName
		 << " score:" << stu.fScore << endl;
}

int main(void)
{
	Student stu = {1005, "小七", 56};
	display1(stu);
	display2(&stu);
	display3(stu);
	Student &ref = stu;
	cout << sizeof(ref) << endl;

	return 0;
}
