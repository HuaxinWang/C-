/*
 * TecManager.cpp
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#include "TecManager.h"
#include "DataSet.h"

TecManager::TecManager(string strName, float fSalary)
	: TecPartTime(strName, ENUM_EMPLOYEE_LEVEL_MANAGER_TEC)
{
	// TODO Auto-generated constructor stub
	m_fSalary = fSalary;
}

TecManager::~TecManager() {
	// TODO Auto-generated destructor stub
}

void TecManager::info() {

}

void addTecPartTime() {
	//TecPartTime *pTecPT = new TecPartTime("aa");
	//DataSet::getInstance().getTecPartMap().insert(PAIR_TECPART(pTecPT->getId(), pTecPT));
}




