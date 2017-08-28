#include "student.h"
#include <vector>

int main(void)
{
	vector<Student> vec(10);
	vec.clear();
	vec.push_back(Student("1aa", 89));
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << "-------------------" << endl;
	
	vec.push_back(Student("2bb", 79));
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << "-------------------" << endl;
	
	vec.push_back(Student("3cc", 69));
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << "-------------------" << endl;
	
	vec.push_back(Student("4dd", 99));
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << "-------------------" << endl;
	
	vec.push_back(Student("5ee", 75));
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << "-------------------" << endl;

	cout << "Hello World" << endl;

	return 0;
}
