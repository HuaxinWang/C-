#include <iostream>
#include <string>
#include <string.h>  //strlen
using namespace std;

class Student
{
public:
	Student(string name, float score
			, string born)
		: m_strName(name), m_fScore(score)
		  , m_strBorn(born)
	{
//		m_strName = name;
//		m_fScore = score;
	}
	void info()
	{
		cout << "name:" << m_strName 
			 << " score:" << m_fScore
		     << " born:" << m_strBorn << endl;
	}
private:
	string m_strName;
	float m_fScore;
	const string m_strBorn;
};


int main(void)
{
	Student s1("aaa", 90, "1988-11-17");
	s1.info();

	return 0;
}
