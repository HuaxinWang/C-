/*
 * TecPartTime.cpp
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#include "TecPartTime.h"
#include "DataSet.h"

TecPartTime::TecPartTime(string strName, uint uiLevel, float fPerHourPay) :
		Employee(strName, uiLevel)
{
	// TODO Auto-generated constructor stub
	m_fPerHourPay = fPerHourPay;
	m_uiWorkHour = 0;
}

TecPartTime::~TecPartTime()
{
	// TODO Auto-generated destructor stub
}

void TecPartTime::setWorkHour()
{

}

void TecPartTime::info()
{
	Employee::info();
	cout << "工作时间:" << m_uiWorkHour << " 每小时薪水:" << m_fPerHourPay << " 总工资:"
			<< m_uiWorkHour * m_fPerHourPay << " 上级:" << m_uiLeaderId << ' ';
	cout
			<< DataSet::getInstance().getTecManagerMap().find(m_uiLeaderId)->second->getName()
			<< endl;
}

void TecPartTime::setLeader(uint uiLeaderId)
{
	m_uiLeaderId = uiLeaderId;
}

uint TecPartTime::getLeader() const
{
	return m_uiLeaderId;
}

uint& TecPartTime::getLeader()
{
	return m_uiLeaderId;
}

uint TecPartTime::getWorkHour() const
{
	return m_uiWorkHour;
}

uint& TecPartTime::getWorkHour()
{
	return m_uiWorkHour;
}

float TecPartTime::getPerHourPay() const
{
	return m_fPerHourPay;
}

float& TecPartTime::getPerHourPay()
{
	return m_fPerHourPay;
}

void TecPartTime::work()
{
//增加对本身的操作
}
