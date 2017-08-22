#include "market.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

Market::Market(string name, float price, int num)
	: m_good(name, price, num)
{
	initSaler();
}

void Market::work()
{
	srand((unsigned int)time(NULL));
	int num = 0;
	while (1)
	{
		num = rand() % SALER_NUM;
		m_pSaler[num]->sale();
		m_good.info();
		if (m_good.isEmpty())
		{
			break;
		}
		sleep(1);
	}
}

void Market::initSaler()
{
	string strName = "";
	for (int i = 0; i < SALER_NUM; i++)
	{
		cout << "请输入销售员名字:";
		cin >> strName;
		m_pSaler[i] = new Saler(strName, m_good);
	}
}






