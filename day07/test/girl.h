#ifndef GIRL_H
#define GIRL_H

#include <iostream>
using namespace std;

#include "boy.h"


class Girl
{
public:
	Girl(string name="girl"
	     , string phone="123456789");

	//friend class Boy;
	friend void Boy::getGirlName(Girl &a);
	void getBoyName(Boy &b);

private:
	string m_strName;
	string m_strPhone;
};


#endif
