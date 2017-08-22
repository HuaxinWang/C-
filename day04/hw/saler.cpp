#include "saler.h"

Saler::Saler(string name, Good &good)
	: m_refGood(good)
{
	m_strName = name;
}

void Saler::sale()
{
	int num = 0;
	cout << "请输入销售件数:\n";
	cin >> num;
	if (m_refGood.saled(num))
	{
		cout << m_strName << "成功销售"
			 << m_refGood.getName()
			 << ' ' << num << "件\n";
		m_iSaledNum += num;
	}
	else
	{
		cout << "库存不足，销售失败\n";
	}
	info();
}

void Saler::info()
{
	cout << "售货员:" << m_strName
		 << " 共销售" << m_refGood.getName()
		 << m_iSaledNum << "件，销售额为:"
		 << m_iSaledNum*m_refGood.getPrice() 
		 << endl;

}
