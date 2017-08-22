#ifndef MARKET_H
#define MARKET_H

#include "saler.h"
#include "good.h"

#define SALER_NUM 3

class Market
{
public:
	Market(string name, float price, int num);
	void work();
	void initSaler();
private:
	Good m_good;
	Saler *m_pSaler[SALER_NUM];
};

#endif
