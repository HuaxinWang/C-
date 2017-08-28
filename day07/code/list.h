#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
	Node(T data)
	{
		m_data = data;
		m_pNext = NULL;
	}	
	const T &data()
	{
		return m_data;
	}
	Node<T>* &next()
	{
		return m_pNext;
	}

	void swap(Node<T> &node)
	{
		T data = m_data;
		m_data = node.m_data;
		node.m_data = data;
	}

	bool operator< (const Node<T> &node)
	{
		return m_data < node.m_data;
	}

private:
	T m_data;
	Node<T> *m_pNext;
};

template<typename T>
bool myLess(T &a, T &b)
{
	return a < b;
}

template<typename T>
class List
{
public:
	class Iterator
	{
	public:
		Iterator(Node<T> *node = NULL)
		{
			m_pNode = node;
		}
		void operator++()
		{
			m_pNode = m_pNode->next();	
		}

		T operator*()
		{
			return m_pNode->data();
		}

		bool operator!=(const Iterator &iter)
		{
			return m_pNode != iter.m_pNode;
		}

		Iterator operator++(int)
		{
			Iterator iter = *this;
			m_pNode = m_pNode->next();	
			return iter;	
		}
	private:
		Node<T> *m_pNode;
	};
	typedef Iterator iterator;	
public:
	List()
	{
		m_iLen = 0;
		m_pFirstNode = NULL;
	}
	void insert(T data)
	{
		Node<T> *node = new Node<T>(data);
		node->next() = m_pFirstNode;
		m_pFirstNode = node;
		m_iLen++;
	}

	void sort()
	{
		int i = 0;
		int j = 0;
		Node<T> *node = NULL;
		for (int i = 0; i < m_iLen-1; i++)
		{
			node = m_pFirstNode;
			for (int j = 0; j < m_iLen-1-i; j++)
			{
				if (myLess(node->data(), node->next()->data()))
				{
					node->swap(*(node->next()));
				}
				node = node->next();
			}
		}
	}

	template<typename M>
	void sort(M com)
	{
		int i = 0;
		int j = 0;
		Node<T> *node = NULL;
		for (int i = 0; i < m_iLen-1; i++)
		{
			node = m_pFirstNode;
			for (int j = 0; j < m_iLen-1-i; j++)
			{
				if (com(node->data(), node->next()->data()))
				{
					node->swap(*(node->next()));
				}
				node = node->next();
			}
		}
	}

	Iterator begin()
	{
		Iterator iter(m_pFirstNode);
		return iter;
	}

	Iterator &end()
	{
		static Iterator iter;
		return iter;
	}

private:
	int m_iLen;
	Node<T> *m_pFirstNode;
};

#endif
