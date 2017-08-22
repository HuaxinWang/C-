#include <iostream>
#include <string>
#include <string.h>  //strlen
using namespace std;

//构造函数和析构函数的执行顺序是相反的
class Student
{
public:
	Student(string name, float score
			, const char *note)
	{
		m_strName = name;
		m_fScore = score;
		int iLen = strlen(note)+1;
		m_pNote = new char[99999];
		cout << (void*)m_pNote << endl;
		strcpy(m_pNote, note);
		cout << m_strName << endl;
	}
	void info()
	{
		cout << "name:" << m_strName 
			 << " score:" << m_fScore
		     << " note:" << m_pNote << endl;
	}
	//析构函数
	//在对象释放的时候自动调用
	//没有形参，不能构成重载
	//有且只有一个

	~Student()
	{
		delete []m_pNote;
		cout << m_strName <<" ~Student()" << endl;
	}
private:
	string m_strName;
	float m_fScore;
	char *m_pNote;
};

void fun()
{
Student *p = new Student("aaa", 90, "cascascas");
	delete p;//会自动调用析构函数
}

int main(void)
{
	Student s1("aaa", 90, "aaaa");
	Student s2("bbb", 90, "aaaa");
	Student s3("ccc", 90, "aaaa");
	Student s4("ddd", 90, "aaaa");


	//fun();

#if 0
	int i = 0;
	while (1)
	{
		cout << "i=" << i++ << endl;
		Student stu("张三", 89
	, "888888888888888888_活得真长_66666666666");
		stu.info();
	}
#endif
}
