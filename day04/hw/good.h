#ifndef GOOD_H
#define GOOD_H

#include "public.h"

class Good
{
public:
	Good(string name, float price, int num);
	bool saled(int num);
	void info();
	const string &getName();
	float getPrice();
	bool isEmpty();

private:
	string m_strName;
	float m_fPrice;
	int m_iSaledNum;
	int m_iTotalNum;
};

#endif
