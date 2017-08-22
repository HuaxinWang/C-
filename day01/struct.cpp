#include <iostream>

using namespace std;

struct Student
{
	int iId;
	char caName[32];  //c:char  a:array
	float fScore;

	void show()
	{
		cout << "id:" << iId 
			 << " name:" << caName
			 << " score:" << fScore << endl;
	}
};


int main(void)
{
	Student stu = {1001, "张三", 89};
	stu.show();
//	cout << stu.iId << ' ' << stu.caName
//		 << stu.fScore << endl;
//	show();  

	return 0;
}
