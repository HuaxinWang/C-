/*
 * SalePartTime.cpp
 *
 *  Created on: 2017-9-1
 *      Author: sq
 */

#include "SalePartTime.h"

SalePartTime::SalePartTime(string strName, uint uiLevel) :
		Employee(strName, uiLevel)
{
	// TODO Auto-generated constructor stub
	m_fSales = 0;
}

SalePartTime::~SalePartTime()
{
	// TODO Auto-generated destructor stub
}

//设置销售额
void SalePartTime::setSales(float fSales)
{
}
//获得销售额
float SalePartTime::getSales()
{
	return m_fSales;
}
//显示信息
void SalePartTime::info()
{

}

void SalePartTime::work()
{
	//增加对本身的操作
}
