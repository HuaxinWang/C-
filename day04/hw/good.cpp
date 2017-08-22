#include "good.h"

Good::Good(string name, float price, int num)
{
	m_strName = name;
	m_fPrice = price;
	m_iSaledNum = 0;
	m_iTotalNum = num;
}

bool Good::saled(int num)
{
	bool bSaled = false;
	if (num <= m_iTotalNum)
	{
		m_iSaledNum += num;
		m_iTotalNum -= num;
		bSaled = true;
	}
	return bSaled;
}

void Good::info()
{
	cout << "商品:" << m_strName << " 卖了"
		 << m_iSaledNum << "件，销售额为:"
		 << m_iSaledNum * m_fPrice
		 << " 剩余总量:" << m_iTotalNum << endl;
}

const string & Good::getName()
{
	return m_strName;
}

float Good::getPrice()
{
	return m_fPrice;
}

bool Good::isEmpty()
{
	bool bEmpty = false;
	if (0 == m_iTotalNum)
	{
		bEmpty = true;
	}
	return bEmpty;
}
