#include <iostream>
using namespace std;

//若没有自定义构造函数，则会生成一个默认的无参构造函数

//若自定义了构造函数，则不会生成一个默认的无参构造函数
//在这种情况，若想调用无参构造函数，则必须自定义一个


class Student
{
public:
	//构造函数:在生成对象时自动调用
#if 0
	Student()
	{
		m_iId = 1000;
		m_strName = "student";
		m_fScore = 100;
		cout << "Student()...\n";
	}
#endif
	Student(int id, const char *name, float score)
	{
		m_iId = id;
		m_strName = name;
		m_fScore = score;
	}
#if 0
	void setInfo(int id, const char *name
				 , float score)
	{
		m_iId = id;
		m_strName = name;
		m_fScore = score;
	}
#endif
	void showInfo()
	{
		cout << "id:" << m_iId 
			 << " name:" << m_strName
			 << " score:" << m_fScore << endl; 
	}

private:
	int m_iId;
	string m_strName;
	float m_fScore;
};


int main(void)
{
	//对象后面没有跟参数，默认调用无参构造函数
	Student s;
	//s.setInfo(1001, "张三", 90);
	s.showInfo();
	
	//对象后面跟了参数，根据参数的不同调用不同有参构造函数
	Student s2(1001, "张三", 78);
	s2.showInfo();

	return 0;
}
