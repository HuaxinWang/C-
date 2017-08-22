#include <iostream>

using namespace std;

class StuNode
{
public:
	StuNode()
	{
		m_iId = 10000;
		m_strName = "newStudent";
		m_fScore = 60;
		m_pNext = NULL;
	}
	StuNode(int id, const char *name, float score)
	{
		m_iId = id;
		m_strName = name;
		m_fScore = score;
		m_pNext = NULL;
	}
	void info()
	{
		cout << "id:" << m_iId << " name:" << m_strName
			 << " score:" << m_fScore << endl;
	}
	
	StuNode *m_pNext;
		
private:
	int m_iId;
	string m_strName;
	float m_fScore;
};

class StuList
{
public:
	StuList()
	{
		m_pFirstNode = NULL;
		m_iLen = 0;
	}
	void insert(StuNode *node)
	{
		node->m_pNext = m_pFirstNode;
		m_pFirstNode = node;
		m_iLen++;
	}
	void display()
	{
		StuNode *node = m_pFirstNode;
		while (NULL != node)
		{
			node->info();
			node = node->m_pNext;
		}
	}
private:
	StuNode *m_pFirstNode;
	int m_iLen;
};


int main(void)
{
	StuList list;
	list.insert(new StuNode(1001, "张三", 67));
	list.insert(new StuNode(1002, "李四", 78));
	list.insert(new StuNode(1003, "王五", 66));
	list.insert(new StuNode(1004, "赵六", 88));
	list.display();

	return 0;
}
