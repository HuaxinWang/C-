#ifndef SALER_H
#define SALER_H

#include "good.h"

class Saler
{
public:
	Saler(string name, Good &good);
	void sale();
	void info();

	Good &m_refGood;
private:
	string m_strName;
	int m_iSaledNum;
};

#endif
