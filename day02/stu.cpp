#include <iostream>
using namespace std;

class Student
{
public:
	void setInfo(int id, const char *name
				 , float score)
	{
		m_iId = id;
		m_strName = name;
		m_fScore = score;
	}
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
	Student s;
	s.setInfo(1001, "张三", 90);
	s.showInfo();

	return 0;
}
