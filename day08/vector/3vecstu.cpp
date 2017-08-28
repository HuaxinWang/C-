#include "student.h"
#include <vector>

int main(void)
{
	vector<Student *> vec;
	vec.push_back(new Student("1aa", 89));
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << "-------------------" << endl;
	
	vec.push_back(new Student("2bb", 79));
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << "-------------------" << endl;
	
	vec.push_back(new Student("3cc", 69));
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << "-------------------" << endl;
	
	vec.push_back(new Student("4dd", 99));
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << "-------------------" << endl;
	
	vec.push_back(new Student("5ee", 75));
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << "-------------------" << endl;

	cout << "Hello World" << endl;

	return 0;
}
