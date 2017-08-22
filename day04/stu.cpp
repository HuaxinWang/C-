#include <iostream>
#include <string>
#include <string.h>  //strlen
using namespace std;

class Student
{
public:
	Student()
	{
		m_pNote = NULL;
		cout << "Student()" << endl;
	}
	Student(string name, float score
			, const char *note)
		: m_strName(name), m_fScore(score)
	{
		m_pNote = new char[strlen(note)+1];
		strcpy(m_pNote, note);
		cout << "Student(string,int,string)\n";
	}
	char *getNote()
	{
		return m_pNote;
	}
#if 1
	//拷贝构造函数
	Student(const Student &other)
	{
		m_strName = other.m_strName;
		m_fScore = other.m_fScore;
		m_pNote = NULL;
		if (NULL != other.m_pNote)
		{
			m_pNote = new char[strlen(other.m_pNote)+1];
			strcpy(m_pNote, other.m_pNote);
		}
		cout << "Student(const Student &)\n";	
	}
#endif
	void info()
	{
		cout << "name:" << m_strName 
			 << " score:" << m_fScore << endl;
		if (NULL != m_pNote)
		{
		     cout << " note:" << m_pNote << endl;
		}
	}
	~Student()
	{
		cout << "~Student()\n";
		if (NULL != m_pNote)
		{
			delete []m_pNote;
		}
	}
private:
	string m_strName;
	float m_fScore;
	char *m_pNote;
};


int main(void)
{
	Student s1("aaa", 90, "1988-11-17");
	s1.info();
#if 0
	//使用一个旧的对象初始化一个新的对象
	//调用拷贝构造函数
	//不管有没有定义其他类型的构造函数
	//拷贝构造都会默认生成
	Student s2 = s1; //Student s2(s1);
	s2.info();

	cout << (void*)s1.getNote() << ' '
		 << (void*)s2.getNote() << endl;
#endif
	Student s3;
	s3 = s1;
	cout << (void*)s1.getNote() << ' '
		 << (void*)s3.getNote() << endl;


	return 0;
}
