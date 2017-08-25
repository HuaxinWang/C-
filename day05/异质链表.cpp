#include <iostream>

using namespace std;

class Base
{};

class Node
{
public:
	Node(Base *base = NULL)
		:m_pData(base), m_pNext(NULL)
	{}
	Base *m_pData;
	Node *m_pNext;
};

class List
{
public:
	List():m_pFirstNode(NULL), m_iLen(0)
	{}
	void insert(Base *base)
	{
		Node *node = new Node(base);
		node->m_pNext = m_pFirstNode;
		m_pFirstNode = node;
		m_iLen++;
	}
	Node *m_pFirstNode;
	int m_iLen;
};

class Student: public Base
{
public:
	Student(string name="newStu"
			, float score=60)
	{
		m_strName = name;
		m_fScore = score;
	}
	void show()
	{
		cout << "name:" << m_strName
			 << " score:" << m_fScore << endl;
	}
private:
	string m_strName;
	float m_fScore;
};
class Teacher: public Base
{
public:
	Teacher(string name="newTec"
			, float salary=6000)
	{
		m_strName = name;
		m_fSalary = salary;
	}
	void show()
	{
		cout << "name:" << m_strName
			 << " salary:" << m_fSalary << endl;
	}
private:
	string m_strName;
	float m_fSalary;
};

int main(void)
{
	List stuList;
	stuList.insert(new Student("aa", 90));
	stuList.insert(new Student("bb", 91));
	stuList.insert(new Student("cc", 92));
	stuList.insert(new Student("dd", 93));

	List tecList;
	tecList.insert(new Teacher("tec", 6000));
	tecList.insert(new Teacher("tec1", 7000));
	tecList.insert(new Teacher("tec2", 8000));
	tecList.insert(new Teacher("tec3", 9000));

	return 0;
}
