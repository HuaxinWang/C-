#include <iostream>

using namespace std;

struct Student
{
	int iId;
	char caName[32];
	float fScore;
};

Student &mymax(Student &s1, Student &s2)
{
	if (s1.fScore > s2.fScore)
	{
		return s1;
	}
	return s2;
}

int mymax(int a, int b)
{
	return a>b? a:b;
}

int main(void)
{
	int a = 90;
	int b = 78;
	cout << mymax(a, b) << endl;

	Student s1 = {1001, "aa", 89};
	Student s2 = {1002, "bb", 99};
	Student &s = mymax(s1, s2);
	cout << s.iId << ' ' << s.caName 
		 << ' ' << s.fScore << endl;




	return 0;
}
