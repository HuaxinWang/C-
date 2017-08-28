#ifndef BOY_H
#define BOY_H

#include <iostream>
using namespace std;

class Girl;

class Boy
{
public:
	Boy(string name="");
	void getGirlName(Girl &g);
	void getGirlPhone(Girl &g);
private:
	string m_strName;
};


#endif
