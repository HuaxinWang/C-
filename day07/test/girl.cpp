#include "girl.h"

Girl::Girl(string name, string phone)
{
     m_strName = name;
     m_strPhone = phone;
}

void Girl::getBoyName(Boy &b)
{
	b.getGirlName(*this);
}
