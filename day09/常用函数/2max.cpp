#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include <list>

using namespace std;

/*
 template<typename T>
 T max(T a, T b)
 {
 	return a < b? b:a;
 }
 
 template<typename T, typename M>
 T max(T a, T b, M com)
 {
 	return com(a, b)? b:a;
 }
 */
class Student
{
public:
	Student(string name="", float score=0.0f)
	{
		m_strName = name;
		m_fScore = score;
	}

	const string &getName() const
	{
		return m_strName;
	}
	float getScore() const 
	{
		return m_fScore;
	}


private:
	string m_strName;
	float m_fScore;
};

ostream &operator<<(ostream &out, const Student &stu)
{
	out << stu.getName() << ' ' << stu.getScore();
	return out;
}

bool compare(const Student &s1, const Student &s2)
{
	return s1.getScore() < s2.getScore();
}

int main(void)
{
	cout << max(3, 4) << endl;
	cout << max(string("hello"), string("abdssasa")) << endl;
	
	cout << min(3, 4) << endl;
	cout << min(string("hello"), string("abdssasa")) << endl;


	Student s1("aa", 90);
	Student s2("bb", 91);

	cout << max(s1, s2, compare) << endl;

	return 0;
}
