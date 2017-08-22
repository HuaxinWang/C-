#include <iostream>
#include <string.h>  //strlen
#include <stdlib.h>

using namespace std;

class MyString
{
public:
	MyString()
	{
		m_pData = NULL;
		cout << "MyString()\n";
	}
	MyString(const char *pData)
	{
		m_pData = NULL;
		if (NULL != pData)
		{
			m_pData = new char[strlen(pData)+1];
			if (NULL == m_pData)
			{
				exit(EXIT_FAILURE);
			}
			strcpy(m_pData, pData);
		}
		cout << "MyString(const char *)\n";
	}
	MyString(const MyString &other)
	{
		m_pData = NULL;
		if (NULL != other.m_pData)
		{
			m_pData = new char[strlen(other.m_pData)+1];
			if (NULL == m_pData)
			{
				exit(EXIT_FAILURE);
			}
			strcpy(m_pData, other.m_pData);
		}
		cout << "MyString(const MyString&)\n";
	}
	const char *data()
	{
		return m_pData;
	}

	int length()
	{
		int iLen = 0;
		if (NULL != m_pData)
		{
			iLen = strlen(m_pData);
		}
		return iLen;
	}

	~MyString()
	{
		cout << "~MyString()\n";
		if (NULL != m_pData)
		{
			delete []m_pData;
		}
	}
private:
	char *m_pData;
};


int main(void)
{
	cout << sizeof(MyString) << endl;

	//MyString s1("Hello World");
	MyString s1 = "Hello World";
	cout << s1.data() << endl;

	//MyString s2(s1);
	MyString s2 = s1;
	cout << s2.data() << endl;

	cout << s2.length() << endl;

	return 0;
}
