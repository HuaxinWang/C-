/*
 * Employee.cpp
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#include "Employee.h"

uint Employee::m_suiId = 10000;

Employee::Employee(string strName, uint uiLevel)
{
	// TODO Auto-generated constructor stub
	m_strName = strName;
	m_uiLevel = uiLevel;
	m_strPwd = "123456";
	m_strNote = "表现良好";
	m_uiId = m_suiId++;
}

Employee::~Employee()
{
	// TODO Auto-generated destructor stub
}

void Employee::info()
{
	cout << "编号:" << m_uiId << " 名字:" << m_strName << endl;
	switch (m_uiLevel)
	{
	case ENUM_EMPLOYEE_LEVEL_PARTTIME_TEC:
		cout << "--级别:兼职技术人员" << endl;
		break;
	case ENUM_EMPLOYEE_LEVEL_MANAGER_TEC:
		cout << "--级别:技术经理" << endl;
		break;
	case ENUM_EMPLOYEE_LEVEL_PARTTIME_SALE:
		cout << "--级别:兼职销售人员" << endl;
		break;
	case ENUM_EMPLOYEE_LEVEL_MANAGER_SALE:
		cout << "--级别:销售经理" << endl;
		break;
	case ENUM_EMPLOYEE_LEVEL_BOSS:
		cout << "--级别:老板" << endl;
		break;
	default:
		break;
	}
	cout << "--密码:" << m_strPwd << " 说明:" << m_strNote << endl;
}

void Employee::modifyPwd()
{

}

void Employee::setBaseId(uint uiId)
{
}

uint Employee::getId() const
{
	return m_uiId;
}

uint& Employee::getId()
{
	return m_uiId;
}

void Employee::setNote()
{
}

ostream &operator<<(ostream &out, const Employee &employee)
{
	out << "编号:" << employee.m_uiId << " 名字:" << employee.m_strName
			<< " 级别:兼职技术人员" << " 密码:" << employee.m_strPwd << " 说明:"
			<< employee.m_strNote;
	return out;
}

void Employee::work()
{

}
