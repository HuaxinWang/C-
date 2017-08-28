#include "boy.h"
#include "girl.h"

Boy::Boy(string name)
{
	m_strName = name;
}

void Boy::getGirlName(Girl &g)
{
	cout << g.m_strName << endl;
}
void Boy::getGirlPhone(Girl &g)
{
	cout << g.m_strPhone << endl;
}
