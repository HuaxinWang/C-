/*
 * TecPartTime.cpp
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#include "TecPartTime.h"

TecPartTime::TecPartTime(string strName, uint uiLevel
		, float fPerHourPay)
	: Employee(strName, uiLevel)
{
	// TODO Auto-generated constructor stub
	m_fPerHourPay = fPerHourPay;
	m_uiWorkHour = 0;
}

TecPartTime::~TecPartTime() {
	// TODO Auto-generated destructor stub
}

void TecPartTime::setWorkHour(){

}

void TecPartTime::setLeader(uint uiLeaderId){
	m_uiLeaderId = uiLeaderId;
}

uint TecPartTime::getLeader(){
	return m_uiLeaderId;
}

