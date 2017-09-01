/*
 * Employee.cpp
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#include "Employee.h"


Employee::Employee(string strName, uint uiLevel) {
	// TODO Auto-generated constructor stub
	m_strName = strName;
	m_uiLevel = uiLevel;
	m_strPwd = "123456";
}

Employee::~Employee() {
	// TODO Auto-generated destructor stub
}

void Employee::info(){

}

void Employee::modifyPwd(){

}

void Employee::setBaseId(uint uiId){
}

uint Employee::getId()
{
	return m_uiId;
}
