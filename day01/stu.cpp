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

void bubble(Student stu[5])
{
	int i = 0;
	int j = 0;
	Student tmp;
	for (i = 0; i<5-1; i++)
	{
		for (j=0; j<5-1-i; j++)
		{
			if (stu[j].fScore < stu[j+1].fScore)
			{
				tmp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = tmp;
			}
		}
	}
}


void display(Student stu[5])
{
	for (int i = 0; i < 5; i++)
	{
		stu[i].show();
	}
}

int main(void)
{
	Student stu[5] = {{1001, "张三", 69}
	                  , {1002, "李四", 78}
	                  , {1003, "王五", 62}
	                  , {1004, "赵六", 78}
	                  , {1005, "小七", 56}};

	bubble(stu);
	display(stu);

	return 0;
}
