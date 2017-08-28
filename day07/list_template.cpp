#include <iostream>
using namespace std;


class Student
{
public:
	Student(string name="", float score=0.0f)
	{
		m_strName = name;
		m_fScore = score;
		m_iId = m_iBaseId++;
	}


	bool operator<(const Student &other) const
	{
		return m_fScore < other.m_fScore;
	}

	int getId() const
	{
		return m_iId;
	}
	const string &getName() const
	{
		return m_strName;
	}
	float getScore() const
	{
		return m_fScore;
	}

	void setName(const string &name)
	{
		m_strName = name;
	}
	void setScore(float score)
	{
		m_fScore = score;
	}

private:
	static int m_iBaseId;
	int m_iId;
	string m_strName;
	float m_fScore;
};

int Student::m_iBaseId = 1000;

ostream &operator << (ostream &out, const Student &stu)
{
	out << "学号:" << stu.getId() 
		 << " 名字:" << stu.getName()
		 << " 成绩:" << stu.getScore();
	return out;
}

ostream &operator << (ostream &out, const Student *stu)
{
	out << "学号:" << stu->getId() 
		 << " 名字:" << stu->getName()
		 << " 成绩:" << stu->getScore();
	return out;
}

istream &operator >> (istream &in, Student &stu)
{
	string strName = "";
	float fScore = 0.0f;
	cout << "请输入名字\n";
	in >> strName;
	cout << "请输入分数\n";
	in >> fScore;
	stu.setName(strName);
	stu.setScore(fScore);

	return in;
}
#if 0
bool operator<(const Student *s1, const Student *s2)
{
	return s1->getScore() < s2->getScore();
}
#endif

template<typename T>
class MyLess
{
public:
	bool operator()(T &a, T &b)
	{
		return a < b;
	}
};

template<typename T>
class MyGreater
{
public:
	bool operator()(T &a, T &b)
	{
		return a > b;
	}
};


template<typename T>
class Node
{
public:
	Node(T data)
	{
		m_data = data;
		m_pNext = NULL;
	}

	T m_data;
	Node *m_pNext;
};
#if 1
template<typename T>
ostream &operator<<(ostream &out, const Node<T> &node)
{
	out << node.m_data;

	return out;
}
#endif

template<typename T, typename M = MyLess<T> >
class List
{
public:
	List()
	{
		m_iLen = 0;
		m_pFirstNode = NULL;
	}
	void insert(T data)
	{
		Node<T> *node = new Node<T>(data);
		node->m_pNext = m_pFirstNode;
		m_pFirstNode = node;
		m_iLen++;
	}

	Node<T> *getFirstNode()
	{
		return m_pFirstNode;
	}

	void sort()
	{
		int i = 0;
		int j = 0;
		T data;
		Node<T> *node = NULL;
		M com;
		for (; i < m_iLen-1; i++)
		{
			node = m_pFirstNode;
			for (j = 0; j < m_iLen-1-i; j++)
			{
				if (com(node->m_data
					    , node->m_pNext->m_data))
				{
					data = node->m_data;
					node->m_data = node->m_pNext->m_data;
					node->m_pNext->m_data = data;
				}
				node = node->m_pNext;
			}
		}
	}

private:
	int m_iLen;
	Node<T> *m_pFirstNode;	
};

template<typename T>
ostream &operator << (ostream &out, List<T> &list)
{
	Node<T> *node = list.getFirstNode();
	while (NULL != node)
	{
		out << *node << endl;
		node = node->m_pNext;
	}

	return out;
}

int main(void)
{
	List<int> int_list;
	//List<int, MyGreater<int> > int_list;
	int_list.insert(78);
	int_list.insert(88);
	int_list.insert(98);
	int_list.insert(68);
	cout << int_list << endl;	

	int_list.sort();
	cout << int_list << endl;
#if 0
	List<Student *> stu_list;
	stu_list.insert(new Student("张三", 89));
	stu_list.insert(new Student("李四", 79));
	stu_list.insert(new Student("王五", 99));
	stu_list.insert(new Student("赵六", 88));
	cout << stu_list << endl;
#endif
	List<Student> stu_list;
	stu_list.insert(Student("张三", 89));
	stu_list.insert(Student("李四", 79));
	stu_list.insert(Student("王五", 99));
	stu_list.insert(Student("赵六", 88));
	cout << stu_list << endl;
	stu_list.sort();
	cout << stu_list << endl;

	return 0;
}
