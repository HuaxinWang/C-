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

	const MyString & operator=(const MyString &other)
	{
		//若本身原有数据，先将原数据删除
		if (NULL != m_pData)
		{
			delete []m_pData;
			m_pData = NULL;
		}
		if (NULL != other.m_pData)
		{
			m_pData = new char[strlen(other.m_pData)+1];
			strcpy(m_pData, other.m_pData);
		}			
		cout << "operator=\n";
		return *this;
	}

	char operator[](int pos)
	{
		return m_pData[pos];
	}

	MyString operator+(const MyString &other) const
	{
		MyString str;
		int iLen1 = strlen(m_pData);
		int iLen2 = strlen(other.m_pData);
		int iLen = iLen1 + iLen2 + 1;
		str.m_pData = new char[iLen];
		if (0 == iLen1 && 0 != iLen2)
		{
			strcpy(str.m_pData, other.m_pData);
		}
		else if (0 != iLen1 && 0 == iLen2)
		{
			strcpy(str.m_pData, m_pData);
		}
		else if (0 != iLen1 && 0 != iLen2)
		{
			strcpy(str.m_pData, m_pData);
			strcat(str.m_pData, other.m_pData);
		}
		else
		{
			delete []str.m_pData;
			str.m_pData = NULL;
		}

		return str;
	}

	bool operator<(const MyString &other) const 
	{
		bool bSign = false;
		if (strcmp(m_pData, other.m_pData) < 0)
		{
			bSign = true;
		}
		return bSign;
	}
	bool operator>(const MyString &other) const 
	{
		bool bSign = false;
		if (strcmp(m_pData, other.m_pData) > 0)
		{
			bSign = true;
		}
		return bSign;
	}
	bool operator==(const MyString &other) const 
	{
		bool bSign = false;
		if (strcmp(m_pData, other.m_pData) == 0)
		{
			bSign = true;
		}
		return bSign;
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
	MyString s1("Hello World");
	MyString s2("123");
	
	cout << "s1:" << s1.data() << endl;
	cout << "s2:" << s2.data() << endl;
	
	s2 = s1;  //s2.operator=(s1);
//	int a, b, c;
//	a = b = c = 10;
//	cout << a << ' ' << b << ' ' << c << endl;

	cout << "s1:" << s1.data() << endl;
	cout << "s2:" << s2.data() << endl;

	cout << "s2[0] = " << s2[0] << endl;

	MyString s3;
	s3 = s1 + s2; //s1.operator+(s2);
	cout << s3.data() << endl;

	if (s1 < s3)
	{
		cout << "s1 < s3" << endl;
	}
	if (s1 == s3)
	{
		cout << "s1 == s3\n";
	}
	else
	{
		cout << "s1 != s3\n";
	}

	//MyString s4;
	//s4 = s1 + "123";
	//cout << s4.data() << endl;

	return 0;
}
