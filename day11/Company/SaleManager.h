/*
 * SaleManager.h
 *
 *  Created on: 2017-9-1
 *      Author: sq
 */

#ifndef SALEMANAGER_H_
#define SALEMANAGER_H_

#include "SalePartTime.h"

class SaleManager: public SalePartTime
{
public:
	SaleManager(string strName = "销售经理", float fSalary = 5000);
	virtual ~SaleManager();

	void work();

private:
	float m_fSalary;
};

#endif /* SALEMANAGER_H_ */
