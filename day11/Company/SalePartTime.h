/*
 * SalePartTime.h
 *
 *  Created on: 2017-9-1
 *      Author: sq
 */

#ifndef SALEPARTTIME_H_
#define SALEPARTTIME_H_

#include "Employee.h"

class SalePartTime: virtual public Employee
{
public:
	SalePartTime(string strName = "NewSalePP", uint uiLevel =
			ENUM_EMPLOYEE_LEVEL_PARTTIME_SALE);
	virtual ~SalePartTime();
	//设置销售额
	void setSales(float fSales = 0);
	//获得销售额
	float getSales();
	//显示信息
	void info();

	void work();

private:
	float m_fSales;
};

#endif /* SALEPARTTIME_H_ */
