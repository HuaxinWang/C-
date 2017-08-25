#include <iostream>

using namespace std;

class Base
{
public:
	virtual void show()
	{}
};

class Node
{
public:
	Node(Base *base = NULL)
		:m_pData(base), m_pNext(NULL)
	{}
	void show()
	{
		m_pData->show();
	}
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
	void display()
	{
		Node *tmp = m_pFirstNode;
		while (NULL != tmp)
		{
			tmp->show();
			tmp = tmp->m_pNext;
		}
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
	stuList.display();

	List tecList;
	tecList.insert(new Teacher("tec", 6000));
	tecList.insert(new Teacher("tec1", 7000));
	tecList.insert(new Teacher("tec2", 8000));
	tecList.insert(new Teacher("tec3", 9000));
	tecList.display();

	List list;
	list.insert(new Student("mm", 90));
	list.insert(new Student("nn", 90));
	list.insert(new Student("dd", 90));
	list.insert(new Teacher("tecmm", 90000));
	list.insert(new Teacher("tecnn", 90909));
	list.insert(new Teacher("tecdd", 9089));

	list.display();

	return 0;
}
