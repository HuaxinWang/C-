/*
 * SaleManager.cpp
 *
 *  Created on: 2017-9-1
 *      Author: sq
 */

#include "SaleManager.h"

SaleManager::SaleManager(string strName, float fSalary)
   : SalePartTime(strName, ENUM_EMPLOYEE_LEVEL_MANAGER_SALE)
     , Employee(strName, ENUM_EMPLOYEE_LEVEL_MANAGER_SALE)
{
	// TODO Auto-generated constructor stub

}

SaleManager::~SaleManager()
{
	// TODO Auto-generated destructor stub
}

void SaleManager::work()
{
	//增加对本身的操作即对下属的增删改查显示
}
